//���ȏ����E���Ēm�����㏸������BtextBooks[player.pos[0]/2]��false�ɂ���@by�㐙��n
#ifndef PICKUPTEXT
#define PICKUPTEXT

void pickUpText(){
    addIntelligence(50);
    textBooks[player.pos[0]/2] = false;
    printf("%d\n", player.pos[0]);
}

#endif 