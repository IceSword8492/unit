// Author: �����G��
// �w���`��֐���`

#ifndef DISPLAYSHOP
#define DISPLAYSHOP

void displayShop ()
{
    // printf("�c�莞��: %03ds                                                                               �w�N: %d\n%s%s\n�m��: %d\n%s\n#DEBUG SHOP (Press any key to continue...)\n",
    //     (calcRemain() / 1000),
    //     player.pos[0] / 2 + 1,
    //     showFps ? "FPS: " : "",
    //     showFps ? fpsString : "",
    //     player.intelligence,
    //     message
    // );
    using namespace std;

    cout << "�c�莞��: " << setw(3) << setfill('0') << (calcRemain() / 1000) << setfill(' ') << "s                  �w�N: " << (player.pos[0] / 2 + 1) << "\n"
        << setfill(' ') << (showFps ? "FPS: " : "") << (showFps ? fpsString : "") << "\n"
        << "HP: " << setw(5) << (int) player.hp << " / " << setw(5) << (int) player.maxHp << "           �m��: " << setw(5) << player.intelligence << "\n"
        << "������: " << setw(4) << player.money;
    if (cursor.pos != 0)
    {
        cout << "                ������: " << setw(3) << player.item[cursor.pos - 1] << "\n" << "���i: " << setw(4) << (shops[player.getGradeId()].prices[cursor.pos - 1]) << "                   �c��: " << setw(4) << shops[player.getGradeId()].amount[cursor.pos - 1];
    }
    else
    {
        cout << "\n";
    }
    cout << "\n|" << (cursor.pos == 0 ? ">" : " ") << "�߂�|" << (cursor.pos == 1 ? ">" : " ") << "�G�i�W�[�h�����N(�񕜃A�C�e��)|" << (cursor.pos == 2 ? ">" : " ") << "���|�[�g�p��(5��)|";
    if (player.pos[0] / 2 == 3)
    {
        cout << (cursor.pos == 3 ? ">" : " ") << "������|";
    }
    cout << "\n";
}

#endif