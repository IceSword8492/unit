// fixed by Yuya Nakamura
// added #ifndef~#endif
// added type of key

#ifndef INPUTDIRECTION
#define INPUTDIRECTION

#define LEFT 4
#define UP 2
#define RIGHT 1
//ˆÚ“®•ûŒü‚Ì“ü—Íby‹g‰ªŒÖ‘¾˜Y
void inputDirection (char key)
{
    if(key=='w'){
        move(UP);
    }
    else if(key=='W'){
        move(UP);
    }
    else if(key=='a'){
        move(LEFT);
    }
    else if(key=='A'){
        move(LEFT);
    }
    else if(key=='d'){
        move(RIGHT);
    }
    else if(key=='D'){
        move(RIGHT);
    }
}

#endif