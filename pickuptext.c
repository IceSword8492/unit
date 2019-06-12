//教科書を拾って知識を上昇させる。textBooks[player.pos[0]/2]をfalseにする　by上杉大地
#ifndef PICKUPTEXT
#define PICKUPTEXT

void pickUpText(){
    addIntelligence(50);
    textBooks[player.pos[0]/2] = false;
    printf("%d\n", player.pos[0]);
}

#endif 