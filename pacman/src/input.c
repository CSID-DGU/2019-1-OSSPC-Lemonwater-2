#include "input.h"

//does a check to ensure the given keycode is within the bounds of valid keys
//stops the program with an error if it is out of bounds
static void check_keycode(int keycode);

//gets the frame this direction was pressed.
//Uses both wasd and arrow keys.
static int frame_for_direction(Direction dir);

static bool keysHeld[MAX_KEYS] = {false};
static unsigned int keysPressedFrame[MAX_KEYS] = {0};
static unsigned int keysReleasedFrame[MAX_KEYS] = {0};

//#25 클라이언트의 키 를 받는곳을 따로 만들어야할 듯?
static bool Client_keysHeld[MAX_KEYS] = {false};

static unsigned int Client_keysPressedFrame[MAX_KEYS] = {0};
static unsigned int Client_keysReleasedFrame[MAX_KEYS] = {0};
static int Client_frame_for_direction(Direction dir);

static unsigned int curKeyFrame = 1;
void get_key(client_key *key);
void insert_key(client_key *key);



unsigned int Change_keys_1[4] = {SDLK_y, SDLK_h, SDLK_g, SDLK_j}; //lemonwater 5.13 키배열

unsigned int Change_keys_2[4] = {SDLK_w, SDLK_s, SDLK_a, SDLK_d};


int Change_keys_array1(int i) //lemonwater 5.13 키배열을 받는 함수..renderer.c에서 사용
{	
	return Change_keys_1[i];
}

int Change_keys_array2(int i)
{
	return Change_keys_2[i];
}	


void get_Change_Key(int i,int s_c_num)
{
	if(s_c_num>=8 && s_c_num<=11)
		Change_keys_1[s_c_num-8] = i;
	else if(s_c_num>=12 && s_c_num <16)
		Change_keys_2[s_c_num-12] = i;
}

void keyevents_finished(void)
{
	curKeyFrame++;
}

void handle_keydown(int keycode)
{
	check_keycode(keycode);

	if (!keysHeld[keycode]) keysPressedFrame[keycode] = curKeyFrame;

	keysHeld[keycode] = true;
}

void handle_keyup(int keycode)
{
	check_keycode(keycode);

	if (keysHeld[keycode]) keysReleasedFrame[keycode] = curKeyFrame;

	keysHeld[keycode] = false;
}

bool dir_key_held(Direction direction,int player_num)
{
	if (player_num==0)
	{
		switch (direction)
		{
		case Up:    return keysHeld[Change_keys_1[0]]; //lemonwater 5.13 키 설정
		case Down:  return keysHeld[Change_keys_1[1]];
		case Left:  return keysHeld[Change_keys_1[2]];
		case Right: return keysHeld[Change_keys_1[3]];
		}
	}
	else
	{
		switch (direction)
		{
		case Up:    return keysHeld[Change_keys_2[0]];
		case Down:  return keysHeld[Change_keys_2[1]];
		case Left:  return keysHeld[Change_keys_2[2]];
		case Right: return keysHeld[Change_keys_2[3]];
		}
	}

	printf("should never reach here\n");
	exit(1);
}

//#25 클라이언트 키 따로 받아서 하기위해 ..
//원래는 로컬에서 할 때는 같은 함수에서 if문으로 player num 떄려박아넣었는데.
//여기서 key를 따로 해줘야 server에서 wasd 로 조정했을때 2p가 움직여버리는 일이 안일어남
bool Client_dir_key_held(Direction direction)
{
	switch (direction)
	{
		case Up:    return Client_keysHeld[SDLK_UP];
		case Down:  return Client_keysHeld[SDLK_DOWN];
		case Left:  return Client_keysHeld[SDLK_LEFT];
		case Right: return Client_keysHeld[SDLK_RIGHT];
	}

	printf("should never reach here\n");
	exit(1);
}

bool dir_pressed_now(Direction *dir,int player_num)
{
	int highestPushed = 0;

	Direction dirs[4] = {Up, Left, Down, Right};

	for (int i = 3; i >= 0; i--)
	{
		if (!dir_key_held(dirs[i],player_num))continue;

		int x = frame_for_direction(dirs[i]);

		if (x > highestPushed)
		{
			*dir = dirs[i];
			highestPushed = x;
		}
	}

	return highestPushed != 0;
}

//#25 클라이언트 키 따로 받아서 하기위해 ..
//원래는 로컬에서 할 때는 같은 함수에서 if문으로 player num 떄려박아넣었는데.
//여기서 key를 따로 해줘야 server에서 wasd 로 조정했을때 2p가 움직여버리는 일이 안일어남
bool Client_dir_pressed_now(Direction *dir)
{
	int highestPushed = 0;
	Direction dirs[4] = {Up, Left, Down, Right};

	for (int i = 3; i >= 0; i--)
	{
		if (!Client_dir_key_held(dirs[i])) continue;

		int x = Client_frame_for_direction(dirs[i]);

		if (x > highestPushed)
		{
			*dir = dirs[i];
			highestPushed = x;
		}
	}

	return highestPushed != 0;
}



bool key_held(int keycode)
{
	check_keycode(keycode);

	return keysHeld[keycode];
}

bool key_pressed(int keycode)
{
	check_keycode(keycode);

	return keysPressedFrame[keycode] == (curKeyFrame - 1);
}

bool key_released(int keycode)
{
	check_keycode(keycode);//#19 : 1. 이 부분에서 키 값 계속 넘어가버려서 흠.. 체크 한뒤 false 바로만들기...
	//안그러면 true 상태라 menu 에서 online 체크 후 바로 make room 들어가져버림
	bool rt =keysReleasedFrame[keycode] == (curKeyFrame - 1);
	keysReleasedFrame[keycode]=false;

	return rt;
}

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) max((b), (a))

static int frame_for_direction(Direction dir) //lemonwater 5.13 키 설정
{
	switch (dir)
	{
	case Up:    return max(keysPressedFrame[Change_keys_1[0]], keysPressedFrame[Change_keys_2[0]]);
	case Down:  return max(keysPressedFrame[Change_keys_1[1]], keysPressedFrame[Change_keys_2[1]]);
	case Left:  return max(keysPressedFrame[Change_keys_1[2]], keysPressedFrame[Change_keys_2[2]]);
	case Right: return max(keysPressedFrame[Change_keys_1[3]], keysPressedFrame[Change_keys_2[3]]);
	}

	printf("should never reach here\n");
	exit(1);
}

static int Client_frame_for_direction(Direction dir)
{
	switch (dir)
	{
		case Up:    return Client_keysPressedFrame[SDLK_UP];
		case Down:  return Client_keysPressedFrame[SDLK_DOWN];
		case Left:  return Client_keysPressedFrame[SDLK_LEFT];
		case Right: return Client_keysPressedFrame[SDLK_RIGHT];
	}

	printf("should never reach here\n");
	exit(1);
}


static void check_keycode(int keycode)
{
	if (keycode >= MAX_KEYS)
	{
		printf("Keycode %d is out of range.\n", keycode);
		printf("Aborting\n");
		exit(1);
	}
}

void insert_key(client_key* key)
{
	key->keyHeld[0]=keysHeld[SDLK_UP];
	key->keyHeld[1]=keysHeld[SDLK_DOWN];
	key->keyHeld[2]=keysHeld[SDLK_LEFT];
	key->keyHeld[3]=keysHeld[SDLK_RIGHT];

	key->keyPressed[0] = keysPressedFrame[SDLK_UP];
	key->keyPressed[1] = keysPressedFrame[SDLK_DOWN];
	key->keyPressed[2] = keysPressedFrame[SDLK_LEFT];
	key->keyPressed[3] = keysPressedFrame[SDLK_RIGHT];
}

void get_key(client_key *key)
{
	Client_keysHeld[SDLK_UP]=key->keyHeld[0];
	Client_keysHeld[SDLK_DOWN]=key->keyHeld[1];
	Client_keysHeld[SDLK_LEFT]=key->keyHeld[2];
	Client_keysHeld[SDLK_RIGHT]=key->keyHeld[3];

	Client_keysPressedFrame[SDLK_UP]=key->keyPressed[0];
	Client_keysPressedFrame[SDLK_DOWN]=key->keyPressed[1];
	Client_keysPressedFrame[SDLK_LEFT]=key->keyPressed[2];
	Client_keysPressedFrame[SDLK_RIGHT]=key->keyPressed[3];
}
