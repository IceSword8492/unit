//熊澤祐希
//所持金の追加

// fixed by Yuya Nakamura
// added #ifndef~#endif
// fixed "player.money = money" to "player.money += money"

#ifndef ADDMONEY
#define ADDMONEY

void addMoney(int money) {
    player.money += money;
}

#endif