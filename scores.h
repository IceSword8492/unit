// Author: ���� �G��
// Scores

#ifndef SCORESDEF
#define SCORESDEF

typedef struct Scores {
    char names[10][256];
    int scores[10];
} Scores;

void updateScores ()
{
    /********************
    ��������"test"�Ńf�o�b�O
    ��������"load"�Ŗ{�Ԋ�
    ********************/
    request("unit-server.glitch.me", "test", 1);
    FILE *fp = fopen("./scores.dat", "r");
    if (fp == NULL)
    {
        printf("can't open: scores.dat");
        safeExit(1);
    }
    char name[4096], score[256];
    int i = 0;
    while (fscanf(fp, "%[^:]:%s\n", name, score) != EOF)
    {
        // printf("%s:%s\n", name, score);
        strcpy(scores.names[i], name);
        scores.scores[i] = atoi(score);
        i++;
    }
    fclose(fp);
}

void saveScore ()
{
    request("unit-server.glitch.me", "push", 0);
}

#endif