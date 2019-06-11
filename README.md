# Lemonwater 조

## 2019-1학기 OSSP



## 팀원

- 2013111294 광고홍보학과 이영재
- 2013110423 수학과 이인모
- 2014112431 수학과 박재식



## Description

* 동국대학교 융합소프트웨어연계전공 오픈소스소프트웨어프로젝트 2019-1 학기 프로젝트 원격저장소.
  * 리눅스 SDL을 이용한 Pacman Game
  * 소스코드 출처
    * Pacman_original  : <https://github.com/TroyShaw/Pacman>  
    * Pacman_2017_ver : https://github.com/CSID-DGU/2017-2-OSSP-Awkward-3
    * Pacman_2018_ver : https://github.com/CSID-DGU/2018-1-OSSP-Cantata-2
    


## Getting Started

### 1. Install SDL

```
sudo apt-get update
```

* 필요한 SDL 라이브러리 설치

```
sudo apt-get install libsdl-ttf2.0-0 libsdl-sound1.2 libsdl-mixer1.2
```

```
sudo apt-get install libsdl-image1.2 libsdl-gfx1.2-5 libsdl1.2-dev
```

### 2. Compile

* 먼저 make 파일이 있는 폴더로 이동함
  ```ㅁㄴㅇㅁㅇ 
  cd pacman
  ```

* make 파일을 이용하여 컴파일

  ```
  make
  ```

### 3. Execute

* 게임파일 실행한다.

  ````
  ./game_Debug
  ````

## Menu window

<center>맨 처음 실행시 보이는 화면, 다섯 가지를 선택할 수 있다.</center>

![menuwindow](https://user-images.githubusercontent.com/46588549/59299598-fea33480-8cc7-11e9-8e6f-27c09e563d64.png)

## 1. Single Mode

### 들어가면 바로 게임이 시작된다.

![스크린샷, 2019-06-12 04-39-05](https://user-images.githubusercontent.com/46588549/59302344-bafff900-8cce-11e9-85fd-e7615ec702f0.png)

### 모든 pellet을 먹으면 다음 스테이지로 넘어간다.

![스크린샷, 2019-06-12 04-45-51](https://user-images.githubusercontent.com/46588549/59302366-cc490580-8cce-11e9-9dfd-9189a19d783d.png)

![스크린샷, 2019-06-12 04-45-55](https://user-images.githubusercontent.com/46588549/59302394-dec33f00-8cce-11e9-816c-ae6cd5aae134.png)

### 목숨을 다 쓰면 게임이 끝난다.

![스크린샷, 2019-06-12 04-47-33](https://user-images.githubusercontent.com/46588549/59302446-f3073c00-8cce-11e9-8fa1-dc09f8249846.png)

### spacebar를 누르면 게임을 일시정지할 수 있다.

![스크린샷, 2019-06-12 04-47-59](https://user-images.githubusercontent.com/46588549/59302466-fac6e080-8cce-11e9-9f3e-db880405d9f5.png)

## 2. 2player Mode

### 들어가면 남은 시간을 확인할 수 있다.

![스크린샷, 2019-06-12 04-49-11](https://user-images.githubusercontent.com/46588549/59302477-03b7b200-8ccf-11e9-9daf-7e70b411b0ac.png)

### 시간이 다 되거나 모든 pellet을 먹거나 한 쪽이 목숨을 다 쓰면 게임이 끝나며,

### 게임 종료 시 게임을 계속할 지 결정할 수 있다.

![스크린샷, 2019-06-12 04-49-36](https://user-images.githubusercontent.com/46588549/59302499-103c0a80-8ccf-11e9-924e-f54b5d104a42.png)

## 3. Online Mode

### 먼저 방을 만든다.

<img src="https://i.imgur.com/KIFCRXe.png">

<center>메뉴에서 ONLINE으로 접속시 보이는 화면</center>

<img src="https://i.imgur.com/q6efYLy.png">

<center>MAKE ROOM 선택 후 보이는 화면</center>

### 방을 만든 PC의 IP를 입력하고 다른 사람이 접속을 한다.

<img src="https://i.imgur.com/P9jAkpH.png">

<center>커서를 JOIN ROOM 에 두고 IP 를 입력한다. </center>

### 게임 방식은 2player와 같다.

## 4. Help(도움말)

### Help창에는 게임의 역사 및 조작법, 아이템 등에 대한 정보를 확인할 수 있다. </center>

![헬프움짤](https://user-images.githubusercontent.com/46588549/59303110-77a68a00-8cd0-11e9-83cd-f4f70ed47319.gif)

## 5. Settings(환경설정)

### 바꾸고 싶은 키를 선택하고 Enter를 누른다. </center>

![ㄷㄱㅎㄹ](https://user-images.githubusercontent.com/46588549/59302901-fe0e9c00-8ccf-11e9-98d4-697374f05d00.png)

### 바꾸고자 하는 키를 입력한다. </center>

![ㄷㅎㄴㅅㄱ](https://user-images.githubusercontent.com/46588549/59302916-05ce4080-8cd0-11e9-897a-18de42c634f8.png)

### 입력을 했으면, Enter를 누르고 위 아래 방향키로 바꾸고자 하는 키를 선택할 수 있다. </center>

![ㅏㅑㅕㅛ](https://user-images.githubusercontent.com/46588549/59302931-0cf54e80-8cd0-11e9-9a78-805a9324a8f6.png)

## License

This project is licensed under the MIT License - see the [pacman/LICENSE.md](/pacman/LICENSE) file for details
