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

![자](https://user-images.githubusercontent.com/46588549/59303407-1f23bc80-8cd1-11e9-83d4-c5613f621716.png)

### 모든 pellet을 먹으면 다음 스테이지로 넘어간다.

![아](https://user-images.githubusercontent.com/46588549/59303416-20ed8000-8cd1-11e9-9e70-cd572c62b24f.png)

![사](https://user-images.githubusercontent.com/46588549/59303414-20ed8000-8cd1-11e9-8e37-aca6ee1da330.png)

### 목숨을 다 쓰면 게임이 끝난다.

![바](https://user-images.githubusercontent.com/46588549/59303413-2054e980-8cd1-11e9-9a8c-6937ccbd142e.png)

### spacebar를 누르면 게임을 일시정지할 수 있다.(추가)

![라](https://user-images.githubusercontent.com/46588549/59303411-2054e980-8cd1-11e9-863c-d739d48ebca8.png)
<center>게임을 하다보면 잠시 중지하고 싶은 경우가 있기 마련이다. 그래서 우리는 일시정지 기능을 추가해 게임을 계속할지 결정할 수 있도록 했다.</center>

## 2. 2player Mode(기존 코드에서 수정)

### 들어가면 남은 시간을 확인할 수 있다.

![다](https://user-images.githubusercontent.com/46588549/59303410-1fbc5300-8cd1-11e9-8fa7-fe42ba136d77.png)

### 시간이 다 되거나 모든 pellet을 먹거나 한 쪽이 목숨을 다 쓰면 게임이 끝나며,

### 게임 종료 시 게임을 계속할 지 결정할 수 있다.

![나](https://user-images.githubusercontent.com/46588549/59303409-1fbc5300-8cd1-11e9-9f86-4a7b6faa2796.png)

<center>기존에는 결과만 보여줬지만, 우리는 게임을 계속할 지에 대한 결정을 할 수 있게 구현했다.</center>

### 마찬가지로 spacebar를 누르면 게임을 일시정지할 수 있다.

## 3. Online Mode

### 먼저 방을 만든다.

<img src="https://i.imgur.com/KIFCRXe.png">

<center>메뉴에서 ONLINE으로 접속시 보이는 화면</center>

<img src="https://i.imgur.com/q6efYLy.png">

<center>MAKE ROOM 선택 후 보이는 화면</center>

### 방을 만든 PC의 IP를 입력하고 다른 사람이 접속을 한다.

<img src="https://i.imgur.com/P9jAkpH.png">

<center>커서를 JOIN ROOM 에 두고 IP 를 입력한다. </center>

<center>게임 방식은 2player와 같다. 단, 일시정지 기능은 넣지 않았다.</center>

<center>왜냐하면 online모드는 컴퓨터 두 대로 하는 모드인데, 한 명이 일시중지하면 다른 사람이 못하는 경우가 발생하기 때문이다.</center>

## 4. Help(도움말, 추가한 부분)

### Help창에는 게임의 역사 및 조작법, 아이템 등에 대한 정보를 확인할 수 있다.

![ezgif com-gif-maker](https://user-images.githubusercontent.com/46588549/59305520-5dbb7600-8cd5-11e9-805e-02f2c6efaf15.gif)

<center>아무리 pacman이 유명한 게임이라 해도 여전히 이 게임을 낯설어 하는 사람이 있다. 그래서, 우리는 그런 사람들을 위해 도움말을 직접 만들었다. 이를 통해 초보자도 누구나 쉽게 게임을 할 수 있기 바란다. </center>

## 5. Settings(환경설정, 추가한 부분)

<center>환경설정은 사용자가 원하는 방향키로 바꿀 수 있게 도와준다. 키를 바꿈으로써 사용자만의 방향키로 편리한 게임을 즐겨보자.</center>

### 바꾸고 싶은 키를 선택하고 Enter를 누른다.

![ㄷㄱㅎㄹ](https://user-images.githubusercontent.com/46588549/59302901-fe0e9c00-8ccf-11e9-98d4-697374f05d00.png)

### 바꾸고자 하는 키를 입력한다.

![ㄷㅎㄴㅅㄱ](https://user-images.githubusercontent.com/46588549/59302916-05ce4080-8cd0-11e9-897a-18de42c634f8.png)

### 입력을 했으면, Enter를 누르고 위 아래 방향키로 바꾸고자 하는 키를 선택할 수 있다.

![ㅏㅑㅕㅛ](https://user-images.githubusercontent.com/46588549/59302931-0cf54e80-8cd0-11e9-9a78-805a9324a8f6.png)

## License

This project is licensed under the MIT License - see the [pacman/LICENSE.md](/pacman/LICENSE) file for details
