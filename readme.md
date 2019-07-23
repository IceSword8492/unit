# Unit

![BUILDSTATUS](https://img.shields.io/badge/build-passing-success.svg) ![VERSION](https://img.shields.io/badge/version-0.3.15b-orange.svg) ![DOCUMENT](https://img.shields.io/badge/documents-unavailable-red.svg) ![STABLE](https://img.shields.io/badge/stable-N%2FA-red.svg)

## ����


### �R���p�C��


```sh
g++ ./main.cpp -lwinmm -lws2_32
```


## ���s


### ���s�R�}���h


```sh
./a.exe ([option]...)
```


### �I�v�V����


debug���[�h�ŋN�� (Score��0�ɌŒ肳��܂�)
```sh
--debug
```


fps��\��
```sh
--show-fps
```


2fps�Ŏ��s
```sh
--very-low-fps
```


10fps�Ŏ��s
```sh
--low-fps
```


60fps�Ŏ��s
```sh
--high-fps
```


120fps�Ŏ��s
```sh
--very-high-fps
```


240fps�Ŏ��s
```sh
--extremely-high-fps
```


�����̃X�|�[���m����0�ɕύX
```sh
--no-enemy
```


�C�ӂ̃t���[�����[�g�Ŏ��s
```sh
--set-fps <fps: int>
```


�J�n�n�_��ݒ�
```sh
--set-start-position <floor: int> <room: int>
```


�J�n���̒m���ʂ�ݒ�
```sh
--set-intelligence <intelligence: int>
```


�J�n���ɏ������Ă���A�C�e���ʂ�ݒ�
```sh
--set-items <energyDrinkCount: int> <paperCount: int> <esCount: int>
```


�N���e�B�J���m����ݒ�
```sh
--set-critical <probability: integer>
```
`probability`��0~100�Ŏw�� (����ȊO�͎��s���G���[�ƂȂ�)


�J�n���̎c�莞��(�b)��ݒ�
```sh
--set-time <time: integer>
```