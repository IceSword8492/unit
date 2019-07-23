# Unit

![BUILDSTATUS](https://img.shields.io/badge/build-passing-success.svg) ![VERSION](https://img.shields.io/badge/version-0.3.17b-orange.svg) ![DOCUMENT](https://img.shields.io/badge/documents-unavailable-red.svg) ![STABLE](https://img.shields.io/badge/stable-N%2FA-red.svg)

## 準備


### コンパイル


```sh
g++ ./main.cpp -lwinmm -lws2_32
```


## 実行


### 実行コマンド


```sh
./a.exe ([option]...)
```


### オプション


debugモードで起動 (Scoreは0に固定されます)
```sh
--debug
```


fpsを表示
```sh
--show-fps
```


2fpsで実行
```sh
--very-low-fps
```


10fpsで実行
```sh
--low-fps
```


60fpsで実行
```sh
--high-fps
```


120fpsで実行
```sh
--very-high-fps
```


240fpsで実行
```sh
--extremely-high-fps
```


教授のスポーン確率を0に変更
```sh
--no-enemy
```


任意のフレームレートで実行
```sh
--set-fps <fps: int>
```


開始地点を設定
```sh
--set-start-position <floor: int> <room: int>
```


開始時の知識量を設定
```sh
--set-intelligence <intelligence: int>
```


開始時に所持しているアイテム量を設定
```sh
--set-items <energyDrinkCount: int> <paperCount: int> <esCount: int>
```


クリティカル確率を設定
```sh
--set-critical <probability: integer>
```
`probability`は0~100で指定 (それ以外は実行時エラーとなる)


開始時の残り時間(秒)を設定
```sh
--set-time <time: integer>
```