//w¶Ìú»bygªÖ¾Y

// fixed by Yuya Nakamura
// fixed "char name;" to "char name[256];"
// fixed "newStudent" to "new_Student"
// added #ifndef~#endif
#ifndef INITSTUDENT
#define INITSTUDENT

void initializeStudent ()
{
    cls();
    player = new_Student("");
}

void initializeStudentName ()
{
    char name[256];
    printf("¼OðüÍµÄË(¼pp)\n> ");
    scanf("%s", name);
    strcpy(player.name, name);
}

#endif