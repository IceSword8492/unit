//ƒL[“ü—Íby‹g‰ªŒÖ‘¾˜Y

 // fixed by Yuya Nakamura
 // added type of key
 // fixed "exit 0;" to "exit(0);"
 // added #ifndef~#endif

#ifndef INPUTKEY
#define INPUTKEY

void inputKey(char key){
    if(key=='w'){
        inputDirection('w');
    }
    else if(key=='W'){
        inputDirection('W');
    }
    else if(key=='a'){
        inputDirection('a');
    }
    else if(key=='A'){
        inputDirection('A');
    }
    else if(key=='d'){
        inputDirection('d');
    }
    else if(key=='D'){
        inputDirection('D');    
    }
    else if(key=='h'){
        useItem();
    }
    else if(key=='H'){
        useItem();
    }
    else if(key==0x1B){
        exit(0);
    }
}

#endif