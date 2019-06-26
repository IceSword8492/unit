// Author: íÜë∫óGç∆
// Define room struct and constructor

#ifndef ROOM
#define ROOM

typedef struct Room
{
    int id;
    char name[256];
    void (*event)();
    char eventName[256];
    int direction;
    float popProbability;
} Room;

Room new_Room(int id, const char* name, void (*event)(), const char* eventName, int direction, float popProb)
{
    Room r = {
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