//学生の初期化by吉岡誇太郎

// fixed by Yuya Nakamura
// fixed "char name;" to "char name[256];"
// fixed "newStudent" to "new_Student"
// added #ifndef~#endif
#ifndef INITSTUDENT
#define INITSTUDENT

void initializeStudent ()
{
    char name[256];
    printf("名前を入力してね(▽◕ ᴥ ◕▽)\n> ");
    scanf("%s", name);
    player = new_Student(name);
}

#endif