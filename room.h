// Author: íÜë∫óGç∆
// Define room struct and constructor

#ifndef ROOM
#define ROOM

typedef struct Room
{
    struct Room* self;
    int id;
    char name[256];
    void* event;
    int direction;
    int popProbabilty;
} Room;

Room new_Room(int id, const char* name, void* event, int direction, int popProb)
{
    Room r = {
        &r,
        id,
        "",
        event,
        direction,
        popProb
    };
    strcpy(r.name, name);
    return r;
}

#endif