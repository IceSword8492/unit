# Unit


## 準備


### コンパイル


```sh
g++ ./main.cpp -lwinmm
```


## 実行


### 実行コマンド


```sh
./a.exe ([option]...)
```


### オプション


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
--extremely-very-high-fps
```


教授のスポーン確率を0に変更 (Scoreは0に固定されます)
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