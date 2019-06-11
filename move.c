//�F�V�S��
//�w���̈ړ�

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed indent
// added if (chec...

#ifndef MOVE
#define MOVE

void move (int inputDirection)
{
    int direction = getRoom()->direction;
    bool moved = false;
    if (inputDirection & direction)
    {
        switch (inputDirection)
        {
        case 1:
            player.pos[1]++; //�E
            break;

        case 2:
            player.pos[0]++; //��
            break;

        case 4:
            player.pos[1]--; //��
            break;
        }
        moved = true;
    }
    if (moved)
    {
        // �G���J�E���g����������
        if (checkEncount())
        {
            state = D_BATTLE;
            setCursor(0);
        }
    }
}

#endif