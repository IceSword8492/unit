// �F�V�S��
// ���[���̕\��

// fixed by Yuya Nakamura
// added #ifndef~#endif
// bug fixed (couldnt print "�\�K")

#ifndef DISPLAYRULE
#define DISPLAYRULE

namespace display
{
    void displayRule() {
        // printf("�v���[���[���ł��邱��\n�E�U��(���|�[�g��o�A��������o�A�_����o)\n�E��m���ŃN���e�B�J���q�b�g\n�E�A�C�e���g�p(�G�i�W�[�h�����N)\n�E�h���b�v�A�C�e���̏E��\n�E�X�L���̎g�p(�[�ċz - HP�񕜁A�\\�K - �U���͏㏸�A���K - �_���[�W�y���A�������K�� - ���΂₳�㏸)\n�E���L���X�g�^�C���L\n");
        cls();
        printf("�T�v\n\t�E��������P�ʂ��擾���đ��Ƃ�ڎw����\n���[��\n\t�E�v���C���[���ł��邱��\n\t\t�E�U��(�ʏ�A���|�[�g��o(���|�[�g�p����1�������)�A��������o�A�_����o)\n\t\t\t�E��m���ŃN���e�B�J���q�b�g������\n\t\t�E�A�C�e���g�p(�G�i�W�[�h�����N)\n\t\t�E�h���b�v�A�C�e���̏E��\n\t\t�E�X�L���̎g�p(���L���X�g�^�C���L)\n\t\t\t�E�퓬���I������ƑS�X�L���̃��L���X�g��0�ɖ߂�܂��\n\t\t\t\t�E�\\�K: �U���͏㏸�i���L���X�g�@4�j\n\t\t\t\t�E���K: �_���[�W�y���i���L���X�g�@5�j\n\t\t\t\t�E�[�ċz: HP�S�񕜁i���L���X�g�@2�j\n\t\t\t\t�E�������K��: �S�X�L���̃��L���X�g��1�^�[���Z�k�i���L���X�g�@5�j\n��������\n\t�E�{�X������|��\n�s�k����\n\t�E�G�ɓ|�����\n������@\n\t�E�J�[�\\���ړ�: A(��), W(��), D(�E)\n\t�E����: Enter\n\t�E���j���[: ESC\n\t�E�G�i�W�[�h�����N�g�p: H\n\t�E�A�C�e���c�ʃ`�F�b�N: I\n\nPress any key to continue...\n"); // Author: �����G��
        getch();
        cls();
        printf("Tips\n\t�E\"������@���킩��Ȃ��Ȃ�����ESC�L�[�������Ɗm�F�ł��܂��B\"\n\t�E���|�[�g��o�U���͒m���ʂɉ����čU���͂��㏸���܂��B\n\t�E������|���ƒm���ʂ��㏸���܂��B\n\t�E���ȏ��������Ă��镔���ɓ���ƒm���ʂ��㏸���܂��B\n\t�E�\\�K�X�L���͐ϋɓI�Ɏg���܂��傤�B\n\t�E�i������Ɛi���j�������l���ł��܂��B\n\t�E�i������Ǝg����X�L���������܂��B\n\nPress any key to continue...\n"); // Author: �����G��
    }
}

#endif