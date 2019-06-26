// Author: 中村宥哉
// 購買描画関数定義

#ifndef DISPLAYSHOP
#define DISPLAYSHOP

void displayShop ()
{
    // printf("残り時間: %03ds                                                                               学年: %d\n%s%s\n知識: %d\n%s\n#DEBUG SHOP (Press any key to continue...)\n",
    //     (calcRemain() / 1000),
    //     player.pos[0] / 2 + 1,
    //     showFps ? "FPS: " : "",
    //     showFps ? fpsString : "",
    //     player.intelligence,
    //     message
    // );
    using namespace std;

    cout << "残り時間: " << setw(3) << setfill('0') << (calcRemain() / 1000) << setfill(' ') << "s                  学年: " << (player.pos[0] / 2 + 1) << "\n"
        << setfill(' ') << (showFps ? "FPS: " : "") << (showFps ? fpsString : "") << "\n"
        << "HP: " << setw(5) << (int) player.hp << " / " << setw(5) << (int) player.maxHp << "           知識: " << setw(5) << player.intelligence << "\n"
        << "所持金: " << setw(4) << player.money;
    if (cursor.pos != 0)
    {
        cout << "                所持数: " << setw(3) << player.item[cursor.pos - 1] << "\n" << "価格: " << setw(4) << (shops[player.getGradeId()].prices[cursor.pos - 1]) << "                   残数: " << setw(4) << shops[player.getGradeId()].amount[cursor.pos - 1];
    }
    else
    {
        cout << "\n";
    }
    cout << "\n|" << (cursor.pos == 0 ? ">" : " ") << "戻る|" << (cursor.pos == 1 ? ">" : " ") << "エナジードリンク(回復アイテム)|" << (cursor.pos == 2 ? ">" : " ") << "レポート用紙(5枚)|";
    if (player.pos[0] / 2 == 3)
    {
        cout << (cursor.pos == 3 ? ">" : " ") << "履歴書|";
    }
    cout << "\n";
}

#endif