// Author: 中村宥哉
// ESCメニュー描画関数の定義

#ifndef DISPLAYESCMENU
#define DISPLAYESCMENU

void displayEscMenu ()
{
    const char messages[2][1024] = {
        "操作方法\n\t・カーソ\ル移動: A(左), W(上), D(右)\n\t・決定: Enter\n\t・メニュー: ESC\n\t・エナジードリンク使用: H\n\t・アイテム一覧: I\n・スキル説明\n\t・予\習: 攻撃力上昇\n\t・復習: ダメージ軽減\n\t・深呼吸: HP全回復\n\t・研究室訪問: 全スキルのリキャストを1ターン短縮\n",
        "Tips\n\t・レポート提出攻撃は知識量に応じて攻撃力が上昇します。\n\t・教授を倒すと知識量が上昇します。\n\t・教科書が落ちている部屋に入ると知識量が上昇します。\n\t・予\習スキルは積極的に使いましょう。\n\t・進級すると進級祝い金を獲得できます。\n\t・進級すると使えるスキルが増えます。"
    };
    // printf("Menu\nTime: %03ds\n\n|%sResume |%sQuit |\n\n%s", (calcRemain() / 1000), cursor.pos == 0 ? ">" : " ", cursor.pos == 1 ? ">" : " ", 

    // );

    using namespace std;

    cout << "Menu" << "\n"
        << "残り時間: " << setw(3) << setfill('0') << (calcRemain() / 1000) << "s" << "\n\n"
        << "|" << (cursor.pos == 0 ? ">" : " ") << "Resume |" << (cursor.pos == 1 ? ">" : " ") << "Quit |" << "\n\n"
        << messages[(calcRemain() / 1000) % 10 > 5] << "\n";
}

#endif