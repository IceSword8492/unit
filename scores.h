// Author: íÜë∫ óGç∆
// Scores

#ifndef SCORESDEF
#define SCORESDEF

typedef struct Scores {
    char names[10][256];
    int scores[10];
} Scores;

void updateScores ()
{
    request("unit-server.glitch.me", "test", 1);
    FILE *fp = fopen("./data.csv", "r");
    if (fp == NULL)
    {
        printf("not found: data.csv");
        safeExit(1); // not found
    }
    char name[4096];
    int score;
    while (fscanf(fp, "%s:%d", name, score) != EOF)
    {
        printf("%s:%d", name, score);
    }
    fclose(fp);
}

#endif