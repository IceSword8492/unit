// Author: ’†‘º—GÆ
// İ’è‰Šú‰»ŠÖ”‚Ì’è‹`

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
        if (strcmp(argv[i], "-lfps") == 0) // target: 10fps
        {
            refreshSpeed = 100;
        }
        if (strcmp(argv[i], "-vlfps") == 0) // target: 2fps
        {
            refreshSpeed = 500;
        }
        if (strcmp(argv[i], "-hfps") == 0) // target: 60fps (59fps)
        {
            refreshSpeed = 17;
        }
        if (strcmp(argv[i], "-vhfps") == 0) // target: 144fps (143fps)
        {
            refreshSpeed = 7;
        }
        if (strcmp(argv[i], "-vvhfps") == 0) // target: 240fps (250fps)
        {
            refreshSpeed = 4;
        }
    }
}

#endif