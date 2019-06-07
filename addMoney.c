//ŒFàV—SŠó
//Š‹à‚Ì’Ç‰Á

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed "player.money = money" to "player.money += money"

#ifndef ADDMONEY
#define ADDMONEY

void addMoney(int money) {
    player.money += money;
}

#endif