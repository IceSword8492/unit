//�_���W�����̏����� �㐙��n
#ifndef DUNGEON
#define DUNGEON
void initializeDungeon () // fixed by Yuya Nakamura (bug fixed)
{
    Room d[8][5] = {
        {
            new_Room(00, "KC1001", pickUpText, 0b001, .5f),
            new_Room(01, "�uA302", NULL, 0b101, .5f),
            new_Room(02, "�uA303", NULL, 0b111, .5f),
            new_Room(03, "KE102", NULL, 0b101, .5f),
            new_Room(04, "�w��", goShop, 0b100, .0f)
        },
        {
            new_Room(10, "", NULL, 0b000, .0f),
            new_Room(11, "", NULL, 0b000, .0f),
            new_Room(12, "��A304", NULL, 0b010, 1)
        },
        {
            new_Room(20, "�w��", goShop, 0b001, .0f),
            new_Room(21, "��A201", NULL, 0b101, .5f),
            new_Room(22, "��A202", NULL, 0b111, .5f),
            new_Room(23, "��A203", NULL, 0b101, .5f),
            new_Room(24, "��A204", pickUpText, 0b100, .5f)
        },
        {
            new_Room(30,"", NULL, 0b000, .0f),
            new_Room(31,"", NULL, 0b000, .0f),
            new_Room(32,"��B301", NULL, 0b010, 1)
        },
        {
            new_Room(40, "KE101", pickUpText, 0b001, .5f),
            new_Room(41, "�uB201", NULL, 0b101, .5f),
            new_Room(42, "��A403", NULL, 0b111, .5f),
            new_Room(43, "��D101", NULL, 0b101, .5f),
            new_Room(44, "�w��", goShop, 0b100, .0f)
        },
        {
            new_Room(50, "", NULL, 0b000, .0f),
            new_Room(51, "", NULL, 0b000, .0f),
            new_Room(52, "��A303", NULL, 0b010, 1)
        },
        {
            new_Room(60, "�w��", goShop, 0b001, .0f),
            new_Room(61, "�wA202", NULL, 0b101, .5f),
            new_Room(62, "��A503", NULL, 0b111, .5f),
            new_Room(63, "��B201", NULL, 0b101, .5f),
            new_Room(64, "��302", pickUpText, 0b100, .5f)
        },
        {
            new_Room(71, "����", gameClear, 0b000, .0f),
            new_Room(72, "�uA301", NULL, 0b101, 1),
            new_Room(73, "�ʐڎ�", NULL, 0b000, 1)
        }
    };
    memcpy(dungeon, d, sizeof(d));
}
#endif