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
char fpsString[256];
float tmpAttack;      // 攻撃力計算用変数
bool win;           // 買ったか
bool lose;          // 負けたか
bool trueClear;     // 裏ボスを倒したか
float score;        // スコア
Student player;     // プレイヤー変数
Room dungeon[8][5]; // ダンジョン変数
Enemy enemies[9];     // 敵配列
bool isInShop;      // 購買にいるか
int state;          // ゲームの状態
int prevState;      // 変遷前のゲームの状態
bool showFps;       // setting用変数
char message[256];  // 画面にメッセージを出すための変数
Cursor cursor;      // カーソルポジションを保持する変数
bool textBooks[4];  // 各階層のテキストブック取得状況保持変数
bool nextGradeFlag; // 学年が上がった時にエンカウントしないようにするための変数
int refreshSpeed;
bool enemyPop;
Shop shops[4];
Scores scores;
bool debug;
int debugTime;
int s_argc;
const char** s_argv;

#endif