//ダンジョンの初期化 上杉大地
// added Room* getRoom (void) by Yuya Nakamura
#ifndef DUNGEON
#define DUNGEON

void initializeDungeon () // fixed by Yuya Nakamura (bug fixed)
{
    Room d[8][5] = {
        {
            new_Room(00, "KC1001", pickUpText, "pickUpText", 0b001, .5f),
            new_Room(01, "講A302", NULL, "", 0b101, .5f),
            new_Room(02, "講A303", NULL, "", 0b111, .5f),
            new_Room(03, "KE102", NULL, "", 0b101, .5f),
            new_Room(04, "購買", goShop, "goShop", 0b100, .0f)
        },
        {
            new_Room(10, "", NULL, "", 0b000, .0f),
            new_Room(11, "", NULL, "", 0b000, .0f),
            new_Room(12, "研A304", NULL, "", 0b010, 1)
        },
        {
            new_Room(20, "購買", goShop, "goShop", 0b001, .0f),
            new_Room(21, "研A201", NULL, "", 0b101, .5f),
            new_Room(22, "研A202", NULL, "", 0b111, .5f),
            new_Room(23, "研A203", NULL, "", 0b101, .5f),
            new_Room(24, "研A204", pickUpText, "pickUpText", 0b100, .5f)
        },
        {
            new_Room(30,"", NULL, "", 0b000, .0f),
            new_Room(31,"", NULL, "", 0b000, .0f),
            new_Room(32,"研B301", NULL, "", 0b010, 1)
        },
        {
            new_Room(40, "KE101", pickUpText, "pickUpText", 0b001, .5f),
            new_Room(41, "講B201", NULL, "", 0b101, .5f),
            new_Room(42, "研A403", NULL, "", 0b111, .5f),
            new_Room(43, "研D101", NULL, "", 0b101, .5f),
            new_Room(44, "購買", goShop, "goShop", 0b100, .0f)
        },
        {
            new_Room(50, "", NULL, "", 0b000, .0f),
            new_Room(51, "", NULL, "", 0b000, .0f),
            new_Room(52, "研A303", NULL, "", 0b010, 1)
        },
        {
            new_Room(60, "購買", goShop, "goShop", 0b001, .0f),
            new_Room(61, "購A202", NULL, "", 0b101, .5f),
            new_Room(62, "研A503", NULL, "", 0b111, .5f),
            new_Room(63, "研B201", NULL, "", 0b101, .5f),
            new_Room(64, "研302", pickUpText, "pickUpText", 0b100, .5f)
        },
        {
            new_Room(70, "", NULL, "", 0b000, .0f),
            new_Room(71, "卒業", gameClear, "gameClear", 0b000, .0f),
            new_Room(72, "講A301", NULL, "", 0b101, 1),
            new_Room(73, "面接室", NULL, "", 0b000, 1)
        }
    };
    memcpy(dungeon, d, sizeof(d));
}

Room* getRoom ()
{
    return &dungeon[player.pos[0]][player.pos[1]];
}

#endif