// 熊澤祐希
// ルールの表示

// fixed by Yuya Nakamura
// added #ifndef~#endif
// bug fixed (couldnt print "予習")

#ifndef DISPLAYRULE
#define DISPLAYRULE

void displayRule() {
    printf("プレーヤーができること\n・攻撃(レポート提出、履歴書提出、論文提出)\n・低確率でクリティカルヒット\n・アイテム使用(エナジードリンク)\n・ドロップアイテムの拾得\n・スキルの使用(深呼吸 - HP回復、予\習 - 攻撃力上昇、復習 - ダメージ軽減、研究室訪問 - すばやさ上昇)\n・リキャストタイム有\n");
}

#endif