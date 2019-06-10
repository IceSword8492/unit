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
    }
}

#endif