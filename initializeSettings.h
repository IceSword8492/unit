// Author: �����G��
// �ݒ菉�����֐��̒�`

#ifndef INITSETTINGS
#define INITSETTINGS

void initializeSettings (int argc, const char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-fps") == 0)
        {
            showFps = true;
        }
    }
}

#endif