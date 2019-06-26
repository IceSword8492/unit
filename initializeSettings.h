// Author: ’†‘º—GÆ
// İ’è‰Šú‰»ŠÖ”‚Ì’è‹`

#ifndef INITSETTINGS
#define INITSETTINGS

void initializeSettings (int argc, const char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-fps") | strcmp(argv[i], "--show-fps") == 0)
        {
            showFps = true;
        }
        else if (strcmp(argv[i], "--low-fps") | strcmp(argv[i], "-lfps") == 0) // target: 10fps
        {
            refreshSpeed = 100;
        }
        else if (strcmp(argv[i], "--very-low-fps") | strcmp(argv[i], "-vlfps") == 0) // target: 2fps
        {
            refreshSpeed = 500;
        }
        else if (strcmp(argv[i], "--high-fps") | strcmp(argv[i], "-vhfps") == 0) // target: 60fps (59fps)
        {
            refreshSpeed = 17;
        }
        else if (strcmp(argv[i], "--very-high-fps") | strcmp(argv[i], "-vhfps") == 0) // target: 144fps (143fps)
        {
            refreshSpeed = 7;
        }
        else if (strcmp(argv[i], "--extremely-very-high-fps") | strcmp(argv[i], "-evhfps") | strcmp(argv[i], "-vvhfps") == 0) // target: 240fps (250fps)
        {
            refreshSpeed = 4;
        }
        else if (strcmp(argv[i], "--no-Enemy") | strcmp(argv[i], "-noEnemy") == 0)
        {
            enemyPop = false;
        }
        else if (strcmp(argv[i], "--set-fps") | strcmp(argv[i], "-sfps") == 0)
        {
            refreshSpeed = (1000 / atoi(argv[++i]));
        }
        else
        {
            std::cerr << "Unknown option: " << argv[i] << std::endl;
            safeExit(1);
        }
    }
}

#endif