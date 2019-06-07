// Author: 中村宥哉
// 変数宣言

#ifndef VARIABLES
#define VARIABLES

#define LIMIT_TIME 900000

int startTime;      // 開始時間
int limitTime;      // 制限時間
int prevTime;       // フレームレート制御用変数
int now;            // フレームレート制御用変数
int baseTime;       // フレームレート制御用変数
int count;          // フレームレート制御用変数
float fps;          // フレームレート保持変数
int tmpAttack;      // 攻撃力計算用変数
bool win;           // 買ったか
bool lose;          // 負けたか
bool trueClear;     // 裏ボスを倒したか
float score;        // スコア
Student player;     // プレイヤー変数
Room dungeon[8][5]; // ダンジョン変数
Enemy* enemies;     // 敵配列
bool isInShop;      // 購買にいるか
int state;          // ゲームの状態 (displayinformationより参照)

#endif