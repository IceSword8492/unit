// Author: íÜë∫óGç∆
// Define room struct and constructor

#ifndef ROOM
#define ROOM

typedef struct Room
{
    struct Room* self;
    int id;
    char name[256];
    void (*event)();
    char eventName[256];
    int direction;
    int popProbabilty;
} Room;

Room new_Room(int id, const char* name, void (*event)(), const char* eventName, int direction, int popProb)
{
    Room r = {
        &r,
        id,
        "",
        event,
        "",
        direction,
        popProb
    };
    strcpy(r.name, name);
    strcpy(r.eventName, eventName);
    return r;
}

#endif