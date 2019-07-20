let term = new Terminal;
term.open(document.getElementById("terminal"));
fit.fit(term);

const D_RULE        =  0;
const D_DUNGEON     =  1;
const D_BATTLE      =  2;
const D_SHOP        =  3;
const D_SKILL       =  4;
const D_ITEM        =  5;
const D_CLEAR       =  6;
const D_GAMEOVER    =  7;
const D_ESC_MENU    = 99;

// sub state of D_RULE
const SD_NAME       = 0;
const SD_RULE1      = 1;
const SD_RULE2      = 2;

let state = D_RULE;
let subState = SD_NAME;

let player = {
    name: "",
    pos: [0, 2],
    hp: 10000
};

let buf = "";

term._initialized = true;
term.prompt = _ => term.write("");
cls = _ => term.reset();
print = str => term.write(str);

remain = 900000;

displayInformation = _ => {
    switch (state)
    {
    case D_DUNGEON:
        print(`残り時間: ${("" + Math.floor(remain / 1000)).padStart(3, "0")}s                  学年: ${Math.floor(player.pos[0] / 2) + 1}\r\n\r\nHP: ${("" + player.hp).padStart(5, " ")}`);
        break;
    }
};

term.write("名前を入力してね(半角英数字)\r\n> ");

term.on("key", (key, ev) => {
    const printable = !ev.altKey && !ev.altGraphKey && !ev.ctrlKey && !ev.metaKey;
    if (state)
    {
        cls();
        displayInformation();
        switch (ev.keyCode)
        {
        case 13: // enter
            console.log("enter");
            break;
        case 27: // esc
            console.log("esc");
            break;
        case 37: // ←
            console.log("←");
            break;
        case 38: // ↑
            console.log("↑");
            break;
        case 39: // →
            console.log("→");
            break;
        }
        switch (key)
        {
        case "a":
        case "A":
            console.log("a");
            break;
        case "w":
        case "W":
            console.log("w");
            break;
        case "d":
        case "D":
            console.log("d");
            break;
        case "h":
        case "H":
            console.log("h");
            break;
        case "i":
        case "I":
            console.log("i");
            break;
        }
    }
    else
    {
        if (subState === SD_RULE1)
        {
            subState = SD_RULE2;
            cls();
            term.write("Tips\r\n\t・\"操作方法がわからなくなったらESCキーを押すと確認できます。\"\r\n\t・レポート提出攻撃は知識量に応じて攻撃力が上昇します。\r\n\t・教授を倒すと知識量が上昇します。\r\n\t・教科書が落ちている部屋に入ると知識量が上昇します。\r\n\t・予習スキルは積極的に使いましょう。\r\n\t・進級すると進級祝い金を獲得できます。\r\n\t・進級すると使えるスキルが増えます。\r\n\nPress any key to continue...\r\n");
            return;
        }
        else if (subState === SD_RULE2)
        {
            subState = -1;
            state = D_DUNGEON;
            cls();
            displayInformation();
            setInterval(_ => {
                remain -= 1000;
                cls();
                displayInformation();
            }, 1000);
            return;
        }
        if (ev.keyCode === 13)
        {
            if (buf.length)
            {
                player.name = buf;
                buf = "";
                if (!subState)
                {
                    subState = SD_RULE1;
                    cls();
                    term.write("概要\r\n\t・教授から単位を取得して卒業を目指そう\r\nルール\r\n\t・プレイヤーができること\r\n\t\t・攻撃(通常、レポート提出(レポート用紙を1枚消費する)、履歴書提出、論文提出)\r\n\t\t\t・低確率でクリティカルヒットが発生\r\n\t\t・アイテム使用(エナジードリンク)\r\n\t\t・ドロップアイテムの拾得\r\n\t\t・スキルの使用(リキャストタイム有)\r\n\t\t\t・戦闘が終了すると全スキルのリキャストは0に戻ります。\r\n\t\t\t\t・予習: 攻撃力上昇（リキャスト　4）\r\n\t\t\t\t・復習: ダメージ軽減（リキャスト　5）\r\n\t\t\t\t・深呼吸: HP全回復（リキャスト　2）\r\n\t\t\t\t・研究室訪問: 全スキルのリキャストを1ターン短縮（リキャスト　5）\r\n勝利条件\r\n\t・ボス教授を倒す\r\n敗北条件\r\n\t・敵に倒される\r\n操作方法\r\n\t・カーソル移動: A(左), W(上), D(右)\r\n\t・決定: Enter\n\t・メニュー: ESC\r\n\t・エナジードリンク使用: H\r\n\t・アイテム残量チェック: I\r\n\nPress any key to continue...\r\n");
                    return;
                }
            }
        }
        else if (ev.keyCode === 8)
        {
            if (term._core.buffer.x > 2)
            {
                buf = buf.substring(0, buf.length - 1);
                term.write("\b \b");
            }
        }
        else if (printable)
        {
            buf += key;
            term.write(key);
        }
    }
});