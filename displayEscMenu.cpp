// Author: �����G��
// ESC���j���[�`��֐��̒�`

#ifndef DISPLAYESCMENU
#define DISPLAYESCMENU

void displayEscMenu ()
{
    const char messages[2][1024] = {
        "������@\n\t�E�J�[�\\���ړ�: A(��), W(��), D(�E)\n\t�E����: Enter\n\t�E���j���[: ESC\n\t�E�G�i�W�[�h�����N�g�p: H\n\t�E�A�C�e���ꗗ: I\n�E�X�L������\n\t�E�\\�K: �U���͏㏸\n\t�E���K: �_���[�W�y��\n\t�E�[�ċz: HP�S��\n\t�E�������K��: �S�X�L���̃��L���X�g��1�^�[���Z�k\n",
        "Tips\n\t�E���|�[�g��o�U���͒m���ʂɉ����čU���͂��㏸���܂��B\n\t�E������|���ƒm���ʂ��㏸���܂��B\n\t�E���ȏ��������Ă��镔���ɓ���ƒm���ʂ��㏸���܂��B\n\t�E�\\�K�X�L���͐ϋɓI�Ɏg���܂��傤�B\n\t�E�i������Ɛi���j�������l���ł��܂��B\n\t�E�i������Ǝg����X�L���������܂��B"
    };
    // printf("Menu\nTime: %03ds\n\n|%sResume |%sQuit |\n\n%s", (calcRemain() / 1000), cursor.pos == 0 ? ">" : " ", cursor.pos == 1 ? ">" : " ", 

    // );

    using namespace std;

    cout << "Menu" << "\n"
        << "�c�莞��: " << setw(3) << setfill('0') << (calcRemain() / 1000) << "s" << "\n\n"
        << "|" << (cursor.pos == 0 ? ">" : " ") << "Resume |" << (cursor.pos == 1 ? ">" : " ") << "Quit |" << "\n\n"
        << messages[(calcRemain() / 1000) % 10 > 5] << "\n";
}

#endif