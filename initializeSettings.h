// Author: ’†‘º—GÆ
// İ’è‰Šú‰»ŠÖ”‚Ì’è‹`

#ifndef INITSETTINGS
#define INITSETTINGS

void initializeSettings ()
{
    int argc = s_argc;
    const char** argv = s_argv;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--debug") == 0 | strcmp(argv[i], "-d") == 0)
        {
            debug = true;
        }
        else if (strcmp(argv[i], "-fps") == 0 | strcmp(argv[i], "--show-fps") == 0)
        {
            showFps = true;
        }
        else if (strcmp(argv[i], "--low-fps") == 0 | strcmp(argv[i], "-lfps") == 0) // target: 10fps
        {
            refreshSpeed = 100;
        }
        else if (strcmp(argv[i], "--very-low-fps") == 0 | strcmp(argv[i], "-vlfps") == 0) // target: 2fps
        {
            refreshSpeed = 500;
        }
        else if (strcmp(argv[i], "--high-fps") == 0 | strcmp(argv[i], "-vhfps") == 0) // target: 60fps (59fps)
        {
            refreshSpeed = 17;
        }
        else if (strcmp(argv[i], "--very-high-fps") == 0 | strcmp(argv[i], "-vhfps") == 0) // target: 144fps (143fps)
        {
            refreshSpeed = 7;
        }
        else if (strcmp(argv[i], "--extremely-high-fps") == 0 | strcmp(argv[i], "-ehfps") == 0 | strcmp(argv[i], "-vvhfps") == 0) // target: 240fps (250fps)
        {
            refreshSpeed = 4;
        }
        else if (strcmp(argv[i], "--set-critical") == 0 | strcmp(argv[i], "-critical") == 0)
        {
            if (debug)
            {
                criticalWeight = 100 / atoi(argv[++i]);
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else if (strcmp(argv[i], "--no-enemy") == 0 | strcmp(argv[i], "-noEnemy") == 0)
        {
            if (debug)
            {
                enemyPop = false;
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else if (strcmp(argv[i], "--set-fps") == 0 | strcmp(argv[i], "-sfps") == 0)
        {
            refreshSpeed = (1000 / atoi(argv[++i]));
        }
        else if (strcmp(argv[i], "--set-start-position") == 0 | strcmp(argv[i], "-ssp") == 0)
        {
            if (debug)
            {
                player.pos[0] = atoi(argv[++i]);
                player.pos[1] = atoi(argv[++i]);
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else if (strcmp(argv[i], "--set-intelligence") == 0 | strcmp(argv[i], "-sint") == 0)
        {
            if (debug)
            {
                player.intelligence = atoi(argv[++i]);
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else if (strcmp(argv[i], "--set-items") == 0 | strcmp(argv[i], "-sitem") == 0)
        {
            if (debug)
            {
                player.item[0] = atoi(argv[++i]);
                player.item[1] = atoi(argv[++i]);
                player.item[2] = atoi(argv[++i]);
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else if (strcmp(argv[i], "--set-time") == 0 | strcmp(argv[i], "-time") == 0)
        {
            if (debug)
            {
                debugTime = 900000 - atoi(argv[++i]) * 1000;
            }
            else
            {
                printf("you must use --debug option");
                safeExit(1);
            }
        }
        else
        {
            std::cerr << "Unknown option: " << argv[i] << std::endl;
            safeExit(-1);
        }
    }
}

#endif