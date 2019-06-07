//É_ÉìÉWÉáÉìÇÃèâä˙âª è„êôëÂín
#ifndef DUNGEON
#define DUNGEON
void initializeDungeon () // fixed by Yuya Nakamura (bug fixed)
{
    Room d[8][5] = {
        {
            new_Room(00, "KC1001", pickUpText, 0b001, .5f),
            new_Room(01, "çuA302", NULL, 0b101, .5f),
            new_Room(02, "çuA303", NULL, 0b111, .5f),
            new_Room(03, "KE102", NULL, 0b101, .5f),
            new_Room(04, "çwîÉ", goShop, 0b100, .0f)
        },
        {
            new_Room(10, "", NULL, 0b000, .0f),
            new_Room(11, "", NULL, 0b000, .0f),
            new_Room(12, "å§A304", NULL, 0b010, 1)
        },
        {
            new_Room(20, "çwîÉ", goShop, 0b001, .0f),
            new_Room(21, "å§A201", NULL, 0b101, .5f),
            new_Room(22, "å§A202", NULL, 0b111, .5f),
            new_Room(23, "å§A203", NULL, 0b101, .5f),
            new_Room(24, "å§A204", pickUpText, 0b100, .5f)
        },
        {
            new_Room(30,"", NULL, 0b000, .0f),
            new_Room(31,"", NULL, 0b000, .0f),
            new_Room(32,"å§B301", NULL, 0b010, 1)
        },
        {
            new_Room(40, "KE101", pickUpText, 0b001, .5f),
            new_Room(41, "çuB201", NULL, 0b101, .5f),
            new_Room(42, "å§A403", NULL, 0b111, .5f),
            new_Room(43, "å§D101", NULL, 0b101, .5f),
            new_Room(44, "çwîÉ", goShop, 0b100, .0f)
        },
        {
            new_Room(50, "", NULL, 0b000, .0f),
            new_Room(51, "", NULL, 0b000, .0f),
            new_Room(52, "å§A303", NULL, 0b010, 1)
        },
        {
            new_Room(60, "çwîÉ", goShop, 0b001, .0f),
            new_Room(61, "çwA202", NULL, 0b101, .5f),
            new_Room(62, "å§A503", NULL, 0b111, .5f),
            new_Room(63, "å§B201", NULL, 0b101, .5f),
            new_Room(64, "å§302", pickUpText, 0b100, .5f)
        },
        {
            new_Room(71, "ë≤ã∆", gameClear, 0b000, .0f),
            new_Room(72, "çuA301", NULL, 0b101, 1),
            new_Room(73, "ñ ê⁄é∫", NULL, 0b000, 1)
        }
    };
    memcpy(dungeon, d, sizeof(d));
}
#endif