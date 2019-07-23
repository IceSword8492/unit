//学生の初期化by吉岡誇太郎

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
    printf("名前を入力してね(半角英数字)\n> ");
    scanf("%s", name);
    strcpy(player.name, name);
}

#endif