#include <stdio.h> // 표준함수
#include <conio.h> // 비표준함수
#include <Windows.h> //
#include <mmsystem.h> // 소리 사용하려고 쓰는 함수
#include <Digitalv.h>
#include<stdlib.h>
#include <time.h>


#define NKEY 29
#define DKEY 10

#define UP 72//위
#define DOWN 80//아래
#define LEFT 75//왼쪽
#define RIGHT 77//오른쪽
#define ENTER 13//엔터의 아스키 코드값
#define ESC 27//ESC 버튼
#define ONE 4//1번 선택시
#define TWO 5//2번 선택시
#define THREE 6//3번 선택시
#define FOUR 7//4번 선택시
#define FIVE 8
#define SIX 9


#pragma comment(lib, "winmm.lib") //https://learn.microsoft.com/en-us/windows/win32/multimedia/midi-reference 여기에 관련자료들있음
#pragma warning(disable:4996)


/*키보드커서 움직임 함수*/
void gotoxy(int x, int y);
/*색깔 바꾸는 함수*/
void setcolor(int x);

/*메인 화면 키보드 커서*/
void main_key_cusor(int a, int b, int* suntaek);


void set_main();//움직이는 메인 출력
void removeCursor();//커서함수 없애는 함수



MCI_OPEN_PARMS openDo;		//도 구조체
MCI_PLAY_PARMS playDo;
MCI_OPEN_PARMS openDos;		//도샵구조체
MCI_PLAY_PARMS playDos;
MCI_OPEN_PARMS openLe;		//레 구조체
MCI_PLAY_PARMS playLe;
MCI_OPEN_PARMS openLes;		//레샵 구조체
MCI_PLAY_PARMS playLes;
MCI_OPEN_PARMS openMi;
MCI_PLAY_PARMS playMi;
MCI_OPEN_PARMS openpa;
MCI_PLAY_PARMS playpa;
MCI_OPEN_PARMS openpas;
MCI_PLAY_PARMS playpas;
MCI_OPEN_PARMS opensol;
MCI_PLAY_PARMS playsol;
MCI_OPEN_PARMS opensols;
MCI_PLAY_PARMS playsols;
MCI_OPEN_PARMS openla;
MCI_PLAY_PARMS playla;
MCI_OPEN_PARMS openlas;
MCI_PLAY_PARMS playlas;
MCI_OPEN_PARMS opensi;
MCI_PLAY_PARMS playsi;
MCI_OPEN_PARMS opendodo; MCI_PLAY_PARMS playdodo; MCI_OPEN_PARMS open5dos; MCI_PLAY_PARMS play5dos; MCI_OPEN_PARMS open5le; MCI_PLAY_PARMS play5le; 
MCI_OPEN_PARMS open5les; MCI_PLAY_PARMS play5les; MCI_PLAY_PARMS open5mi; MCI_PLAY_PARMS play5mi; MCI_PLAY_PARMS open5pa; MCI_PLAY_PARMS play5pa;
MCI_PLAY_PARMS open5pas; MCI_PLAY_PARMS play5pas; MCI_PLAY_PARMS open5sol; MCI_PLAY_PARMS play5sol; MCI_PLAY_PARMS open5sols; MCI_PLAY_PARMS play5sols;
MCI_PLAY_PARMS open5la; MCI_PLAY_PARMS play5la; MCI_PLAY_PARMS open5las; MCI_PLAY_PARMS play5las; MCI_PLAY_PARMS open5si; MCI_PLAY_PARMS play5si;



void drummute() {
	
	BYTE drumKey[DKEY] = { //S, E, D, F, G, U, J, V ,I, P
		 0x53, 0x45, 0x44, 0x46, 0x47, 0x55, 0x4A, 0x56, 0x49, 0x50
	};

	BYTE drumKeyOnOff[DKEY] = { 0 };

	system("cls");

	printf("\n\n");
	puts("                              .  =-:-==++-.                                       .           ");
	puts("                             .----      ---==:                               . .:==+==-.        ");
	puts("                             .-==+  (E)  ====.                           .:--::-=--:..:=.       ");
	puts("                              .-=-: .:-==-:                           :-==-:#=-=--==++-        ");
	puts("                        :           .:                               -=-:   (U) --==-.      ■■■■■■■■■■■■■■■■■■■■■");
	puts("                  _ --- -*.---:-.    ..    __---__      __---__    =-:::-=-:::......       |");
	puts("                  -:.___(S)___..-.   :   -|  (F)  |    |  (G)  |   .---=====--:..:         |  메인 메뉴 돌아가기");
	puts("                        +           =:   .|--___--|    |--___--|     .:::::.      :=:      |       - ESC - ");
	puts("                        :     ...:..+=    |-=@@@@+|----|@@@@@@%|                   =+.     |");
	puts("                        -  -__-:---___:. -|+*@@@@%| :: |@@#@@@%|#:                  : :    | 음소거 해제(OFF) : i");
	puts("                        =  *-          |  |_______| ++ |#*%@@%@|. . __------__     -:      | 현재 음소거 상태입니다");
	puts("                      .-+ .+-__  (D)  |#        __%@@#__          #*-_  (J)  _.-    :-      ■■■■■■■■■■■■■■■■■■■■■");
	puts("                        = :+*#%------%#@%   :*=----------=*.     .|%%  ---- @@%|.  .:          ");
	puts("                        -  =##@@@@@@@%@*.  .@+:..     ..::*@      |*#@@@@@*@@%#|    .-          ");
	puts("                        -    +@#*%#*=-.    +-..............==     |*#%@@@@@@%%*|   .:          ");
	puts("                        -     .  +-       :-................-.    |*#%@@@%@@@%*|   .-          ");
	puts("                        :         :  :   .=........   .......=    |##%%@@@@@%%*|   .:          ");
	puts("                       :*.        - =+:  +=....... (V) ......==   |@#%@@@%@@@+*|   .-          ");
	puts("                      .=-.:      :+ .. :.--....... -@- ......+.  :|#*%@@@@@@@+*|:  .:          ");
	puts("                     ::.-  :.   . : .: . ==......:::=.-.....:+-   |@*@@@@@*@@%@|.   :          ");
	puts("                    :- ..  :-:.. .=.:=  - :=.... #==-=%  ...+..-  :+=+*%%@#%%*+-   =+          ");
	puts("                   -: .-=.. :=. .+- -.  +  -+:.. +=+=-#  .-+:  *  .              .::-.:        ");
	puts("                  -:   =@:    =-:=:. .--    .+=- **==%@.-==.      ..*        . :-:  . .-.      ");
	puts("                .+:   .=+-   .- :-=  - .-%.   .::%@--@%::         : :       .-: +:.-+.. .:.    ");
	puts("                .=    :: +-      .= .+   :        +**+           :          +-     ..     .--  ");

	int key;
	int loop = 1;
	while (loop)
	{
		// esc누르면 종료
		if (GetKeyState(0x49) < 0) loop = 0;

		else
		{
			for (key = 0; key < DKEY; key++)
			{
				//szMuskey 배열에 i 번째 해당하는 키가 입력되면
				if (GetKeyState(drumKey[key]) < 0)
				{
					// 이전에 키를 누른적이 없으면 즉, 키가 눌렸을때
					if (drumKeyOnOff[key] == 0)
					{
						drumKeyOnOff[key] = 1; // 누른거로 on/off를 체크하고

						if (drumKeyOnOff[0] == 1) {
							gotoxy(25, 8); setcolor(10); printf("S"); setcolor(15);
						}
						if (drumKeyOnOff[1] == 1) {
							gotoxy(37, 4); setcolor(10); printf("E"); setcolor(15);
						}
						if (drumKeyOnOff[2] == 1) {
							gotoxy(34, 13); setcolor(10); printf("D"); setcolor(15);
						}
						if (drumKeyOnOff[3] == 1) {
							gotoxy(46, 8); setcolor(10); printf("F"); setcolor(15);
						}
						if (drumKeyOnOff[4] == 1) {
							gotoxy(59, 8); setcolor(10); printf("G"); setcolor(15);
						}
						if (drumKeyOnOff[5] == 1) {
							gotoxy(77, 6); setcolor(10); printf("U"); setcolor(15);
						}
						if (drumKeyOnOff[6] == 1) {
							gotoxy(73, 13); setcolor(10); printf("J"); setcolor(15);
						}
						if (drumKeyOnOff[7] == 1) {
							gotoxy(52, 19); setcolor(10); printf("V"); setcolor(15);
						}

					}
				}
			}
		}

		// 이번에는 키를 때었을때,
		for (key = 0; key < DKEY; key++)
		{
			//szMuskey 배열에 i 번째 해당하는 키가 입력된 것이 아니라면,
			if (!(GetKeyState(drumKey[key]) < 0))
			{
				// 이전에 키를 누른적이 있으면
				if (drumKeyOnOff[key] != 0)
				{
					drumKeyOnOff[key] = 0; // 누른거로 on/off를 체크하고 즉 다시 off로 바꿈


					if (drumKeyOnOff[0] == 0) {
						gotoxy(25, 8); setcolor(15); printf("S");
					}
					if (drumKeyOnOff[1] == 0) {
						gotoxy(37, 4); setcolor(15); printf("E");
					}
					if (drumKeyOnOff[2] == 0) {
						gotoxy(34, 13); setcolor(15); printf("D");
					}
					if (drumKeyOnOff[3] == 0) {
						gotoxy(46, 8); setcolor(15); printf("F");
					}
					if (drumKeyOnOff[4] == 0) {
						gotoxy(59, 8); setcolor(15); printf("G");
					}
					if (drumKeyOnOff[5] == 0) {
						gotoxy(77, 6); setcolor(15); printf("U");
					}
					if (drumKeyOnOff[6] == 0) {
						gotoxy(73, 13); setcolor(15); printf("J");
					}
					if (drumKeyOnOff[7] == 0) {
						gotoxy(52, 19); setcolor(15); printf("V");
					}

				}
			}
		}

	}

	system("cls");


	printf("\n\n");
	puts("                              .  =-:-==++-.                                       .           ");
	puts("                             .----      ---==:                               . .:==+==-.        ");
	puts("                             .-==+  (E)  ====.                           .:--::-=--:..:=.       ");
	puts("                              .-=-: .:-==-:                           :-==-:#=-=--==++-        ");
	puts("                        :           .:                               -=-:   (U) --==-.      ■■■■■■■■■■■■■■■■■■■■■");
	puts("                  _ --- -*.---:-.    ..    __---__      __---__    =-:::-=-:::......       |");
	puts("                  -:.___(S)___..-.   :   -|  (F)  |    |  (G)  |   .---=====--:..:         |  메인 메뉴 돌아가기");
	puts("                        +           =:   .|--___--|    |--___--|     .:::::.      :=:      |       - ESC - ");
	puts("                        :     ...:..+=    |-=@@@@+|----|@@@@@@%|                   =+.     |");
	puts("                        -  -__-:---___:. -|+*@@@@%| :: |@@#@@@%|#:                  : :    | 음소거 모드(ON) : P");
	puts("                        =  *-          |  |_______| ++ |#*%@@%@|. . __------__     -:      |");
	puts("                      .-+ .+-__  (D)  |#        __%@@#__          #*-_  (J)  _.-    :-      ■■■■■■■■■■■■■■■■■■■■■");
	puts("                        = :+*#%------%#@%   :*=----------=*.     .|%%  ---- @@%|.  .:          ");
	puts("                        -  =##@@@@@@@%@*.  .@+:..     ..::*@      |*#@@@@@*@@%#|    .-          ");
	puts("                        -    +@#*%#*=-.    +-..............==     |*#%@@@@@@%%*|   .:          ");
	puts("                        -     .  +-       :-................-.    |*#%@@@%@@@%*|   .-          ");
	puts("                        :         :  :   .=........   .......=    |##%%@@@@@%%*|   .:          ");
	puts("                       :*.        - =+:  +=....... (V) ......==   |@#%@@@%@@@+*|   .-          ");
	puts("                      .=-.:      :+ .. :.--....... -@- ......+.  :|#*%@@@@@@@+*|:  .:          ");
	puts("                     ::.-  :.   . : .: . ==......:::=.-.....:+-   |@*@@@@@*@@%@|.   :          ");
	puts("                    :- ..  :-:.. .=.:=  - :=.... #==-=%  ...+..-  :+=+*%%@#%%*+-   =+          ");
	puts("                   -: .-=.. :=. .+- -.  +  -+:.. +=+=-#  .-+:  *  .              .::-.:        ");
	puts("                  -:   =@:    =-:=:. .--    .+=- **==%@.-==.      ..*        . :-:  . .-.      ");
	puts("                .+:   .=+-   .- :-=  - .-%.   .::%@--@%::         : :       .-: +:.-+.. .:.    ");
	puts("                .=    :: +-      .= .+   :        +**+           :          +-     ..     .--  ");
}



void mute() {
	BYTE pianoKey[NKEY] = {                                              //https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes 키 코드 분류표
		0x5A, 0x53, 0x58, 0x44, 0x43,              // Z S X D C
		0x56, 0x47, 0x42, 0x48, 0x4E, 0x4A, 0x4D,  // V G B H N J M
		0x51, 0x32, 0x57, 0x33, 0x45,              // Q 2 W 3 E
		0x52, 0x35, 0x54, 0x36, 0x59, 0x37, 0x55,  // R 5 T 6 Y 7 U
		0x49, 0x39, 0x4F, 0x30, 0x50               // I 9 O 0 P
	};

	BYTE pianoKeyOnOff[NKEY] = { 0 }; // 키보드 키 on/off 체크

	system("cls");


	printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("               피아노 연주\n");
	printf("                                                                        음소거 해제(OFF) : i    \n");
	printf("\n                                                                   !! 현재 음소거 상태입니다 !!                     \n");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("                             |\n                             |\n                             |\n");
	printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  | ■■  ");
	puts("                             ■■ |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  | ■■  ");
	puts("                             ■■ |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ■■  ");
	puts("                             ■■ | Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | ■■  ");
	puts("                             ■■ |___|___|___|___|___|___|___|___|___|___|___|___|___|___| ■■  ");

	int key;
	int loop = 1;
	while (loop)
	{
		if (GetKeyState(0x49) < 0) loop = 0;

		else {
			for (key = 0; key < NKEY; key++)
			{
				//szMuskey 배열에 i 번째 해당하는 키가 입력되면
				if (GetKeyState(pianoKey[key]) < 0)
				{
					// 이전에 키를 누른적이 없으면 즉, 키가 눌렸을때
					if (pianoKeyOnOff[key] == 0)
					{
						pianoKeyOnOff[key] = 1; // 누른거로 on/off를 체크하고
						// 현재 눌린 키의 음을 연주하고
						// 0x290 은 노트on 의미이다 즉, 음을 눌렸다는 의미


						if (pianoKeyOnOff[0] == 1) {
							gotoxy(36, 20); setcolor(10); printf("Z"); setcolor(15);
						}
						if (pianoKeyOnOff[1] == 1) {
							gotoxy(38, 17); setcolor(10); printf("S"); setcolor(15);
						}
						if (pianoKeyOnOff[2] == 1) {
							gotoxy(40, 20); setcolor(10); printf("X"); setcolor(15);
						}
						if (pianoKeyOnOff[3] == 1) {
							gotoxy(42, 17); setcolor(10); printf("D"); setcolor(15);
						}
						if (pianoKeyOnOff[4] == 1) {
							gotoxy(44, 20); setcolor(10); printf("C"); setcolor(15);
						}
						if (pianoKeyOnOff[5] == 1) {
							gotoxy(48, 20); setcolor(10); printf("V"); setcolor(15);
						}
						if (pianoKeyOnOff[6] == 1) {
							gotoxy(50, 17); setcolor(10); printf("G"); setcolor(15);
						}
						if (pianoKeyOnOff[7] == 1) {
							gotoxy(52, 20); setcolor(10); printf("B"); setcolor(15);
						}
						if (pianoKeyOnOff[8] == 1) {
							gotoxy(54, 17); setcolor(10); printf("H"); setcolor(15);
						}
						if (pianoKeyOnOff[9] == 1) {
							gotoxy(56, 20); setcolor(10); printf("N"); setcolor(15);
						}
						if (pianoKeyOnOff[10] == 1) {
							gotoxy(58, 17); setcolor(10); printf("J"); setcolor(15);
						}
						if (pianoKeyOnOff[11] == 1) {
							gotoxy(60, 20); setcolor(10); printf("M"); setcolor(15);
						}
						if (pianoKeyOnOff[12] == 1) {
							gotoxy(64, 20); setcolor(10); printf("Q"); setcolor(15);
						}
						if (pianoKeyOnOff[13] == 1) {
							gotoxy(66, 17); setcolor(10); printf("2"); setcolor(15);
						}
						if (pianoKeyOnOff[14] == 1) {
							gotoxy(68, 20); setcolor(10); printf("W"); setcolor(15);
						}
						if (pianoKeyOnOff[15] == 1) {
							gotoxy(70, 17); setcolor(10); printf("3"); setcolor(15);
						}
						if (pianoKeyOnOff[16] == 1) {
							gotoxy(72, 20); setcolor(10); printf("E"); setcolor(15);
						}
						if (pianoKeyOnOff[17] == 1) {
							gotoxy(76, 20); setcolor(10); printf("R"); setcolor(15);
						}
						if (pianoKeyOnOff[18] == 1) {
							gotoxy(78, 17); setcolor(10); printf("5"); setcolor(15);
						}
						if (pianoKeyOnOff[19] == 1) {
							gotoxy(80, 20); setcolor(10); printf("T"); setcolor(15);
						}
						if (pianoKeyOnOff[20] == 1) {
							gotoxy(82, 17); setcolor(10); printf("6"); setcolor(15);
						}
						if (pianoKeyOnOff[21] == 1) {
							gotoxy(84, 20); setcolor(10); printf("Y"); setcolor(15);
						}
						if (pianoKeyOnOff[22] == 1) {
							gotoxy(86, 17); setcolor(10); printf("7"); setcolor(15);
						}
						if (pianoKeyOnOff[23] == 1) {
							gotoxy(88, 20); setcolor(10); printf("U"); setcolor(15);
						}

					}
				}
			}
		}





		// 이번에는 키를 때었을때,
		for (key = 0; key < NKEY; key++)
		{
			//szMuskey 배열에 i 번째 해당하는 키가 입력된 것이 아니라면,
			if (!(GetKeyState(pianoKey[key]) < 0))
			{
				// 이전에 키를 누른적이 있으면
				if (pianoKeyOnOff[key] != 0)
				{
					pianoKeyOnOff[key] = 0; // 누른거로 on/off를 체크하고 즉 다시 off로 바꿈
					// 연주 중인 소리를 끔
					// 0x80 은 노트off의 의미 즉, 음을 때었다는것

					if (pianoKeyOnOff[0] == 0) {
						gotoxy(36, 20); setcolor(15); printf("Z");
					}
					if (pianoKeyOnOff[1] == 0) {
						gotoxy(38, 17); setcolor(15); printf("S");
					}
					if (pianoKeyOnOff[2] == 0) {
						gotoxy(40, 20); setcolor(15); printf("X");
					}
					if (pianoKeyOnOff[3] == 0) {
						gotoxy(42, 17); setcolor(15); printf("D");
					}
					if (pianoKeyOnOff[4] == 0) {
						gotoxy(44, 20); setcolor(15); printf("C");
					}
					if (pianoKeyOnOff[5] == 0) {
						gotoxy(48, 20); setcolor(15); printf("V");
					}
					if (pianoKeyOnOff[6] == 0) {
						gotoxy(50, 17); setcolor(15); printf("G");
					}
					if (pianoKeyOnOff[7] == 0) {
						gotoxy(52, 20); setcolor(15); printf("B");
					}
					if (pianoKeyOnOff[8] == 0) {
						gotoxy(54, 17); setcolor(15); printf("H");
					}
					if (pianoKeyOnOff[9] == 0) {
						gotoxy(56, 20); setcolor(15); printf("N");
					}
					if (pianoKeyOnOff[10] == 0) {
						gotoxy(58, 17); setcolor(15); printf("J");
					}
					if (pianoKeyOnOff[11] == 0) {
						gotoxy(60, 20); setcolor(15); printf("M");
					}
					if (pianoKeyOnOff[12] == 0) {
						gotoxy(64, 20); setcolor(15); printf("Q");
					}
					if (pianoKeyOnOff[13] == 0) {
						gotoxy(66, 17); setcolor(15); printf("2");
					}
					if (pianoKeyOnOff[14] == 0) {
						gotoxy(68, 20); setcolor(15); printf("W");
					}
					if (pianoKeyOnOff[15] == 0) {
						gotoxy(70, 17); setcolor(15); printf("3");
					}
					if (pianoKeyOnOff[16] == 0) {
						gotoxy(72, 20); setcolor(15); printf("E");
					}
					if (pianoKeyOnOff[17] == 0) {
						gotoxy(76, 20); setcolor(15); printf("R");
					}
					if (pianoKeyOnOff[18] == 0) {
						gotoxy(78, 17); setcolor(15); printf("5");
					}
					if (pianoKeyOnOff[19] == 0) {
						gotoxy(80, 20); setcolor(15); printf("T");
					}
					if (pianoKeyOnOff[20] == 0) {
						gotoxy(82, 17); setcolor(15); printf("6");
					}
					if (pianoKeyOnOff[21] == 0) {
						gotoxy(84, 20); setcolor(15); printf("Y");
					}
					if (pianoKeyOnOff[22] == 0) {
						gotoxy(86, 17); setcolor(15); printf("7");
					}
					if (pianoKeyOnOff[23] == 0) {
						gotoxy(88, 20); setcolor(15); printf("U");
					}

				}
			}
		}



	}

	// 메인함수로 돌아가기
	system("cls");

	printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("               피아노 연주\n");
	printf("                                                                         음소거 모드(ON) : P    메인화면 돌아가기 : ESC\n");
	printf("                                                                                                   \n");
	printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("                             |\n                             |\n                             |\n");
	printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
	puts("                             ■■ |  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  | ■■  ");
	puts("                             ■■ |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  | ■■  ");
	puts("                             ■■ |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ■■  ");
	puts("                             ■■ | Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | ■■  ");
	puts("                             ■■ |___|___|___|___|___|___|___|___|___|___|___|___|___|___| ■■  ");

}


int main(void)
{

	int dwID;		int dwID13;//음악 파일 불러오는 값
	int dwID1;      int dwID14;
	int dwID2;      int dwID15;
	int dwID3;      int dwID16;
	int dwID4;      int dwID17;
	int dwID5;      int dwID18;
	int dwID6;      int dwID19;
	int dwID7;      int dwID20;
	int dwID8;      int dwID21;
	int dwID9;      int dwID22;
	int dwID10;     int dwID23;
	int dwID11;
	int dwID12;

	int loop;
	BYTE key = 0;

	BYTE recode1[100];
	char recodename1[100];
	char recodename2[100];
	char recodename3[100];

	int recodetime1[100];
	int readtime1[100];
	int readtime2[100];
	int readtime3[100];
	clock_t start_time, end_time;

	int v;
	int recodecount = 0;
	int recodecount2 = 0;
	int recodecount3 = 0;

	// 피아노 건반으로 매칭할 키보드 키 설정
	BYTE pianoKey[NKEY] = {                                              //https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes 키 코드 분류표
		0x5A, 0x53, 0x58, 0x44, 0x43,              // Z S X D C
		0x56, 0x47, 0x42, 0x48, 0x4E, 0x4A, 0x4D,  // V G B H N J M
		0x51, 0x32, 0x57, 0x33, 0x45,              // Q 2 W 3 E
		0x52, 0x35, 0x54, 0x36, 0x59, 0x37, 0x55,  // R 5 T 6 Y 7 U
		0x49, 0x39, 0x4F, 0x30, 0x50               // I 9 O 0 P
	};

	BYTE drumKey[DKEY] = { //S, E, D, F, G, U, J, V ,I, P
		 0x53, 0x45, 0x44, 0x46, 0x47, 0x55, 0x4A, 0x56, 0x49, 0x50
	};


	BYTE pianoKeyOnOff[NKEY] = { 0 }; // 키보드 키 on/off 체크

	BYTE drumKeyOnOff[DKEY] = { 0 };

	int suntaek;//선택변수 1
	int a, b;       // a좌표, b좌표 

	removeCursor();

	//첫번째 인수 : text 매크로는 받은 문자열이 유니코드면 좌측에 대문자 아니면 그대로
	//2번째 인수
	//3번째 인수 or 연산자 | 을 통해 snd_filename 첫번째 매개변수를 파일명으로 인식 , snd_async 비동기 전송 snd_loop 무한재생등

	set_main();//움직이는 화면 출력



	while (1)//화일문으로 묶어 3x3 밒 5x5 문을 끝내어도 메인 첫번째 화면으로 돌아가기 
	{
		/*메인화면*/

		system("cls");//게임이 끝난후 돌아올때 화면초기화
		setcolor(15);//15번 색상의 출력문 색깔 바꾸는 명렁어
		printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
		setcolor(13);//13번 색상의 출력문 색깔 바꾸는 명렁어
		printf("   ■■■ ■     ■■■ ■■■       ■■■ ■    ■   ■■■  ■■■ ■■■ ■  ■ ■      ■ ■■■  ■    ■ ■■■ \n");
		setcolor(12);		  
		printf("   ■     ■     ■     ■             ■   ■■  ■  ■         ■   ■  ■ ■  ■ ■■  ■■ ■      ■■  ■   ■ \n");
		setcolor(14);		 			    
		printf("   ■■■ ■     ■■■ ■             ■   ■ ■ ■   ■■■    ■   ■■■ ■  ■ ■  ■  ■ ■■■  ■ ■ ■   ■ \n");
		setcolor(10);		 			    
		printf("   ■     ■     ■     ■             ■   ■  ■■        ■   ■   ■■   ■  ■ ■      ■ ■      ■  ■■   ■ \n");
		setcolor(11);		 				
		printf("   ■■■ ■■■ ■■■ ■■■       ■■■ ■    ■   ■■■    ■   ■  ■ ■■■ ■      ■ ■■■  ■    ■   ■ \n\n\n");
		setcolor(15);//다시 원래 색상 15번 색상의 뒤로 전부 다 출력문이 15번색상으로 나옴
		printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

		printf("\n\n                                                                                              ↑Up   :   위로 이동\n");
		printf("                                                                                              ↓Down : 아래로 이동\n");
		printf("                                                                                               Enter :        선택\n");
		printf("                                                                                               Esc   : 연주중 종료\n\n");
		printf("                                                       전자피아노\n");//24,12 의 위치에 설명 하기 위해
		printf("                                                       전자 드럼\n");//24, 13
		printf("                                                       음악 듣기\n");//24 , 14
		printf("                                                       녹음 하기\n");//24,15
		printf("                                                       녹음 듣기\n");//24,16
		printf("                                                       종료");//24,17
		printf("\n\n\n\n\n\n");
		a = 51, b = 18;//24,12 의 위치에
		gotoxy(a, b); puts(">");//화살표 보여주기


		main_key_cusor(a, b, &suntaek);//메인 키보드 이동 함수
		system("cls");//메인 1~4 를 지우고 다음 메뉴선택 

		if (suntaek == ONE)// 전자피아노
		{

			printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
			printf("               피아노 연주\n");
			printf("                                                                         음소거 모드(ON) : P    메인화면 돌아가기 : ESC\n");
			printf("                                                                                                   \n");
			printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
			printf("                             |\n                             |\n                             |\n");
			printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  | ■■  ");
			puts("                             ■■ |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  | ■■  ");
			puts("                             ■■ |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ■■  ");
			puts("                             ■■ | Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | ■■  ");
			puts("                             ■■ |___|___|___|___|___|___|___|___|___|___|___|___|___|___| ■■  ");



			loop = 1;
			while (loop)
			{
				// esc누르면 종료
				if (GetKeyState(VK_ESCAPE) < 0) loop = 0;

				else
				{
					for (key = 0; key < NKEY; key++)
					{
						//szMuskey 배열에 i 번째 해당하는 키가 입력되면
						if (GetKeyState(pianoKey[key]) < 0)
						{
							// 이전에 키를 누른적이 없으면 즉, 키가 눌렸을때
							if (pianoKeyOnOff[key] == 0)
							{
								pianoKeyOnOff[key] = 1; // 누른거로 on/off를 체크하고
								// 현재 눌린 키의 음을 연주하고
								// 0x90 은 노트on 의미이다 즉, 음을 눌렸다는 의미

								if (key == 0) {
									openDo.lpstrElementName = TEXT("do.wav"); //파일 오픈
									openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
									dwID = openDo.wDeviceID;

									mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								}

								if (key == 1) {
									openDos.lpstrElementName = TEXT("dos.wav"); //파일 오픈
									openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
									dwID1 = openDos.wDeviceID;

									mciSendCommand(dwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								}
								
								if (key == 2) {
									openLe.lpstrElementName = TEXT("le.wav"); //파일 오픈
									openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
									dwID2 = openLe.wDeviceID;

									mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								}

								if (key == 3) {
									openLes.lpstrElementName = TEXT("les.wav"); //파일 오픈
									openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
									dwID3 = openLes.wDeviceID;

									mciSendCommand(dwID3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								}
								if (key == 4) {
									openMi.lpstrElementName = TEXT("mi.wav"); //파일 오픈
									openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
									dwID4 = openMi.wDeviceID;

									mciSendCommand(dwID4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								}
								if (key == 5) {
									openpa.lpstrElementName = TEXT("pa.wav"); //파일 오픈
									openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
									dwID5 = openpa.wDeviceID;

									mciSendCommand(dwID5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
								}
								if (key == 6) {
									openpas.lpstrElementName = TEXT("pas.wav"); //파일 오픈
									openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
									dwID6 = openpas.wDeviceID;

									mciSendCommand(dwID6, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
								}

								if (key == 7) {
									opensol.lpstrElementName = TEXT("sol.wav"); //파일 오픈
									opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
									dwID7 = opensol.wDeviceID;

									mciSendCommand(dwID7, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
								}

								if (key == 8) {
									opensols.lpstrElementName = TEXT("sols.wav"); //파일 오픈
									opensols.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensols);
									dwID8 = opensols.wDeviceID;

									mciSendCommand(dwID8, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensols); //음악을 한 번 재생
								}

								if (key == 9) {
									openla.lpstrElementName = TEXT("la.wav"); //파일 오픈
									openla.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openla);
									dwID9 = openla.wDeviceID;

									mciSendCommand(dwID9, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openla); //음악을 한 번 재생
								}

								if (key == 10) {
									openlas.lpstrElementName = TEXT("las.wav"); //파일 오픈
									openlas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openlas);
									dwID10 = openlas.wDeviceID;

									mciSendCommand(dwID10, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openlas); //음악을 한 번 재생
								}
								if (key == 11) {
									opensi.lpstrElementName = TEXT("si.wav"); //파일 오픈
									opensi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensi);
									dwID11 = opensi.wDeviceID;

									mciSendCommand(dwID11, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensi); //음악을 한 번 재생
								}
								if (key == 12) {
									opendodo.lpstrElementName = TEXT("dodo.wav"); //파일 오픈
									opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
									dwID12 = opendodo.wDeviceID;

									mciSendCommand(dwID12, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
								}
								if (key == 13) {
									openpas.lpstrElementName = TEXT("5dos.wav"); //파일 오픈
									openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
									dwID13 = openpas.wDeviceID;

									mciSendCommand(dwID13, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
								}
								if (key == 14) {
									opensol.lpstrElementName = TEXT("5le.wav"); //파일 오픈
									opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
									dwID14 = opensol.wDeviceID;

									mciSendCommand(dwID14, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
								}
								if (key == 15) {
									open5les.lpstrElementName = TEXT("5les.wav"); //파일 오픈
									open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
									dwID15 = open5les.wDeviceID;

									mciSendCommand(dwID15, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
								}
								if (key == 16) {
									open5les.lpstrElementName = TEXT("5mi.wav"); //파일 오픈
									open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
									dwID16 = open5les.wDeviceID;

									mciSendCommand(dwID16, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
								}
								if (key == 17) {
									opendodo.lpstrElementName = TEXT("5pa.wav"); //파일 오픈
									opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
									dwID17 = opendodo.wDeviceID;

									mciSendCommand(dwID17, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
								}
								if (key == 18) {
									openDo.lpstrElementName = TEXT("5pas.wav"); //파일 오픈
									openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
									dwID18 = openDo.wDeviceID;

									mciSendCommand(dwID18, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								}
								if (key ==19) {
									openDos.lpstrElementName = TEXT("5sol.wav"); //파일 오픈
									openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
									dwID19 = openDos.wDeviceID;

									mciSendCommand(dwID19, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								}
								if (key == 20) {
									openLe.lpstrElementName = TEXT("5sols.wav"); //파일 오픈
									openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
									dwID20 = openLe.wDeviceID;

									mciSendCommand(dwID20, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								}
								if (key == 21) {
									openLes.lpstrElementName = TEXT("5la.wav"); //파일 오픈
									openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
									dwID21 = openLes.wDeviceID;

									mciSendCommand(dwID21, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								}
								if (key == 22) {
									openMi.lpstrElementName = TEXT("5las.wav"); //파일 오픈
									openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
									dwID22 = openMi.wDeviceID;

									mciSendCommand(dwID22, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								}
								if (key == 23) {
									openpa.lpstrElementName = TEXT("5si.wav"); //파일 오픈
									openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
									dwID23 = openpa.wDeviceID;

									mciSendCommand(dwID23, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
								}

								if (key == 28) {
									mute();
								}
								if (pianoKeyOnOff[0] == 1) {
									gotoxy(36, 20); setcolor(10); printf("Z"); setcolor(15);
								}
								if (pianoKeyOnOff[1] == 1) {
									gotoxy(38, 17); setcolor(10); printf("S"); setcolor(15);
								}
								if (pianoKeyOnOff[2] == 1) {
									gotoxy(40, 20); setcolor(10); printf("X"); setcolor(15);
								}
								if (pianoKeyOnOff[3] == 1) {
									gotoxy(42, 17); setcolor(10); printf("D"); setcolor(15);
								}
								if (pianoKeyOnOff[4] == 1) {
									gotoxy(44, 20); setcolor(10); printf("C"); setcolor(15);
								}
								if (pianoKeyOnOff[5] == 1) {
									gotoxy(48, 20); setcolor(10); printf("V"); setcolor(15);
								}
								if (pianoKeyOnOff[6] == 1) {
									gotoxy(50, 17); setcolor(10); printf("G"); setcolor(15);
								}
								if (pianoKeyOnOff[7] == 1) {
									gotoxy(52, 20); setcolor(10); printf("B"); setcolor(15);
								}
								if (pianoKeyOnOff[8] == 1) {
									gotoxy(54, 17); setcolor(10); printf("H"); setcolor(15);
								}
								if (pianoKeyOnOff[9] == 1) {
									gotoxy(56, 20); setcolor(10); printf("N"); setcolor(15);
								}
								if (pianoKeyOnOff[10] == 1) {
									gotoxy(58, 17); setcolor(10); printf("J"); setcolor(15);
								}
								if (pianoKeyOnOff[11] == 1) {
									gotoxy(60, 20); setcolor(10); printf("M"); setcolor(15);
								}
								if (pianoKeyOnOff[12] == 1) {
									gotoxy(64, 20); setcolor(10); printf("Q"); setcolor(15);
								}
								if (pianoKeyOnOff[13] == 1) {
									gotoxy(66, 17); setcolor(10); printf("2"); setcolor(15);
								}
								if (pianoKeyOnOff[14] == 1) {
									gotoxy(68, 20); setcolor(10); printf("W"); setcolor(15);
								}
								if (pianoKeyOnOff[15] == 1) {
									gotoxy(70, 17); setcolor(10); printf("3"); setcolor(15);
								}
								if (pianoKeyOnOff[16] == 1) {
									gotoxy(72, 20); setcolor(10); printf("E"); setcolor(15);
								}
								if (pianoKeyOnOff[17] == 1) {
									gotoxy(76, 20); setcolor(10); printf("R"); setcolor(15);
								}
								if (pianoKeyOnOff[18] == 1) {
									gotoxy(78, 17); setcolor(10); printf("5"); setcolor(15);
								}
								if (pianoKeyOnOff[19] == 1) {
									gotoxy(80, 20); setcolor(10); printf("T"); setcolor(15);
								}
								if (pianoKeyOnOff[20] == 1) {
									gotoxy(82, 17); setcolor(10); printf("6"); setcolor(15);
								}
								if (pianoKeyOnOff[21] == 1) {
									gotoxy(84, 20); setcolor(10); printf("Y"); setcolor(15);
								}
								if (pianoKeyOnOff[22] == 1) {
									gotoxy(86, 17); setcolor(10); printf("7"); setcolor(15);
								}
								if (pianoKeyOnOff[23] == 1) {
									gotoxy(88, 20); setcolor(10); printf("U"); setcolor(15);
								}
							}
						}
					}
				}

				// 이번에는 키를 때었을때,
				for (key = 0; key < NKEY; key++)
				{
					//szMuskey 배열에 i 번째 해당하는 키가 입력된 것이 아니라면,
					if (!(GetKeyState(pianoKey[key]) < 0))
					{
						// 이전에 키를 누른적이 있으면
						if (pianoKeyOnOff[key] != 0)
						{
							pianoKeyOnOff[key] = 0; // 누른거로 on/off를 체크하고 즉 다시 off로 바꿈
							// 연주 중인 소리를 끔
							// 0x80 은 노트off의 의미 즉, 음을 때었다는것


							if (key == 0) {
								mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 1) {
								mciSendCommand(dwID1, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 2) {
								mciSendCommand(dwID2, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 3) {
								mciSendCommand(dwID3, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 4) {
								mciSendCommand(dwID4, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 5) {
								mciSendCommand(dwID5, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID5, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 6) {
								mciSendCommand(dwID6, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID6, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 7) {
								mciSendCommand(dwID7, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID7, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 8) {
								mciSendCommand(dwID8, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID8, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 9) {
								mciSendCommand(dwID9, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID9, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 10) {
								mciSendCommand(dwID10, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID10, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 11) {
								mciSendCommand(dwID11, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID11, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 12) {
								mciSendCommand(dwID12, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID12, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}
							if (key == 13) {
								mciSendCommand(dwID13, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID13, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 14) {
								mciSendCommand(dwID14, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID14, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 15) {
								mciSendCommand(dwID15, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID15, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 16) {
								mciSendCommand(dwID16, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID16, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 17) {
								mciSendCommand(dwID17, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID17, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 18) {
								mciSendCommand(dwID18, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID18, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 19) {
								mciSendCommand(dwID19, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID19, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 20) {
								mciSendCommand(dwID20, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID20, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 21) {
								mciSendCommand(dwID21, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID21, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 22) {
								mciSendCommand(dwID22, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID22, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 23) {
								mciSendCommand(dwID23, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID23, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							
							if (pianoKeyOnOff[0] == 0) {
								gotoxy(36, 20); setcolor(15); printf("Z");
							}
							if (pianoKeyOnOff[1] == 0) {
								gotoxy(38, 17); setcolor(15); printf("S");
							}
							if (pianoKeyOnOff[2] == 0) {
								gotoxy(40, 20); setcolor(15); printf("X");
							}
							if (pianoKeyOnOff[3] == 0) {
								gotoxy(42, 17); setcolor(15); printf("D");
							}
							if (pianoKeyOnOff[4] == 0) {
								gotoxy(44, 20); setcolor(15); printf("C");
							}
							if (pianoKeyOnOff[5] == 0) {
								gotoxy(48, 20); setcolor(15); printf("V");
							}
							if (pianoKeyOnOff[6] == 0) {
								gotoxy(50, 17); setcolor(15); printf("G");
							}
							if (pianoKeyOnOff[7] == 0) {
								gotoxy(52, 20); setcolor(15); printf("B");
							}
							if (pianoKeyOnOff[8] == 0) {
								gotoxy(54, 17); setcolor(15); printf("H");
							}
							if (pianoKeyOnOff[9] == 0) {
								gotoxy(56, 20); setcolor(15); printf("N");
							}
							if (pianoKeyOnOff[10] == 0) {
								gotoxy(58, 17); setcolor(15); printf("J");
							}
							if (pianoKeyOnOff[11] == 0) {
								gotoxy(60, 20); setcolor(15); printf("M");
							}
							if (pianoKeyOnOff[12] == 0) {
								gotoxy(64, 20); setcolor(15); printf("Q");
							}
							if (pianoKeyOnOff[13] == 0) {
								gotoxy(66, 17); setcolor(15); printf("2");
							}
							if (pianoKeyOnOff[14] == 0) {
								gotoxy(68, 20); setcolor(15); printf("W");
							}
							if (pianoKeyOnOff[15] == 0) {
								gotoxy(70, 17); setcolor(15); printf("3");
							}
							if (pianoKeyOnOff[16] == 0) {
								gotoxy(72, 20); setcolor(15); printf("E");
							}
							if (pianoKeyOnOff[17] == 0) {
								gotoxy(76, 20); setcolor(15); printf("R");
							}
							if (pianoKeyOnOff[18] == 0) {
								gotoxy(78, 17); setcolor(15); printf("5");
							}
							if (pianoKeyOnOff[19] == 0) {
								gotoxy(80, 20); setcolor(15); printf("T");
							}
							if (pianoKeyOnOff[20] == 0) {
								gotoxy(82, 17); setcolor(15); printf("6");
							}
							if (pianoKeyOnOff[21] == 0) {
								gotoxy(84, 20); setcolor(15); printf("Y");
							}
							if (pianoKeyOnOff[22] == 0) {
								gotoxy(86, 17); setcolor(15); printf("7");
							}
							if (pianoKeyOnOff[23] == 0) {
								gotoxy(88, 20); setcolor(15); printf("U");
							}
						}
					}
				}

			}
			system("cls");
		}
		else if (suntaek == TWO)// 전자드럼
		{
			printf("\n\n");
			puts("                              .  =-:-==++-.                                       .           ");
			puts("                             .----      ---==:                               . .:==+==-.        ");
			puts("                             .-==+  (E)  ====.                           .:--::-=--:..:=.       ");
			puts("                              .-=-: .:-==-:                           :-==-:#=-=--==++-        ");
			puts("                        :           .:                               -=-:   (U) --==-.      ■■■■■■■■■■■■■■■■■■■■■");
			puts("                  _ --- -*.---:-.    ..    __---__      __---__    =-:::-=-:::......       |");
			puts("                  -:.___(S)___..-.   :   -|  (F)  |    |  (G)  |   .---=====--:..:         |  메인 메뉴 돌아가기");
			puts("                        +           =:   .|--___--|    |--___--|     .:::::.      :=:      |       - ESC - ");
			puts("                        :     ...:..+=    |-=@@@@+|----|@@@@@@%|                   =+.     |");
			puts("                        -  -__-:---___:. -|+*@@@@%| :: |@@#@@@%|#:                  : :    | 음소거 모드(ON) : P");
			puts("                        =  *-          |  |_______| ++ |#*%@@%@|. . __------__     -:      |");
			puts("                      .-+ .+-__  (D)  |#        __%@@#__          #*-_  (J)  _.-    :-      ■■■■■■■■■■■■■■■■■■■■■");
			puts("                        = :+*#%------%#@%   :*=----------=*.     .|%%  ---- @@%|.  .:          ");
			puts("                        -  =##@@@@@@@%@*.  .@+:..     ..::*@      |*#@@@@@*@@%#|    .-          ");
			puts("                        -    +@#*%#*=-.    +-..............==     |*#%@@@@@@%%*|   .:          ");
			puts("                        -     .  +-       :-................-.    |*#%@@@%@@@%*|   .-          ");
			puts("                        :         :  :   .=........   .......=    |##%%@@@@@%%*|   .:          ");
			puts("                       :*.        - =+:  +=....... (V) ......==   |@#%@@@%@@@+*|   .-          ");
			puts("                      .=-.:      :+ .. :.--....... -@- ......+.  :|#*%@@@@@@@+*|:  .:          ");
			puts("                     ::.-  :.   . : .: . ==......:::=.-.....:+-   |@*@@@@@*@@%@|.   :          ");
			puts("                    :- ..  :-:.. .=.:=  - :=.... #==-=%  ...+..-  :+=+*%%@#%%*+-   =+          ");
			puts("                   -: .-=.. :=. .+- -.  +  -+:.. +=+=-#  .-+:  *  .              .::-.:        ");
			puts("                  -:   =@:    =-:=:. .--    .+=- **==%@.-==.      ..*        . :-:  . .-.      ");
			puts("                .+:   .=+-   .- :-=  - .-%.   .::%@--@%::         : :       .-: +:.-+.. .:.    ");
			puts("                .=    :: +-      .= .+   :        +**+           :          +-     ..     .--  ");

			loop = 1;
			while (loop)
			{
				// esc누르면 종료
				if (GetKeyState(VK_ESCAPE) < 0) loop = 0;

				else
				{
					for (key = 0; key < DKEY; key++)
					{
						//szMuskey 배열에 i 번째 해당하는 키가 입력되면
						if (GetKeyState(drumKey[key]) < 0)
						{
							// 이전에 키를 누른적이 없으면 즉, 키가 눌렸을때
							if (drumKeyOnOff[key] == 0)
							{
								drumKeyOnOff[key] = 1; // 누른거로 on/off를 체크하고
								

								if (key == 0) {
									openDo.lpstrElementName = TEXT("1심벌즈.wav"); //파일 오픈
									openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
									dwID = openDo.wDeviceID;

									mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								}

								if (key == 1) {
									openDos.lpstrElementName = TEXT("2심벌즈.wav"); //파일 오픈
									openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
									dwID1 = openDos.wDeviceID;

									mciSendCommand(dwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								}

								if (key == 2) {
									openLe.lpstrElementName = TEXT("1드럼.wav"); //파일 오픈
									openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
									dwID2 = openLe.wDeviceID;

									mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								}

								if (key == 3) {
									openLes.lpstrElementName = TEXT("2드럼.wav"); //파일 오픈
									openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
									dwID3 = openLes.wDeviceID;

									mciSendCommand(dwID3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								}
								if (key == 4) {
									openMi.lpstrElementName = TEXT("3드럼.wav"); //파일 오픈
									openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
									dwID4 = openMi.wDeviceID;

									mciSendCommand(dwID4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								}
								if (key == 5) {
									openpa.lpstrElementName = TEXT("3심벌즈.wav"); //파일 오픈
									openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
									dwID5 = openpa.wDeviceID;

									mciSendCommand(dwID5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
								}
								if (key == 6) {
									openpas.lpstrElementName = TEXT("4드럼.wav"); //파일 오픈
									openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
									dwID6 = openpas.wDeviceID;

									mciSendCommand(dwID6, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
								}

								if (key == 7) {
									opensol.lpstrElementName = TEXT("북.wav"); //파일 오픈
									opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
									dwID7 = opensol.wDeviceID;

									mciSendCommand(dwID7, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
								}

								if (key == 9) {
									drummute();
								}

								if (drumKeyOnOff[0] == 1) {
									gotoxy(25, 8); setcolor(10); printf("S"); setcolor(15);
								}
								if (drumKeyOnOff[1] == 1) {
									gotoxy(37, 4); setcolor(10); printf("E"); setcolor(15);
								}
								if (drumKeyOnOff[2] == 1) {
									gotoxy(34, 13); setcolor(10); printf("D"); setcolor(15);
								}
								if (drumKeyOnOff[3] == 1) {
									gotoxy(46, 8); setcolor(10); printf("F"); setcolor(15);
								}
								if (drumKeyOnOff[4] == 1) {
									gotoxy(59, 8); setcolor(10); printf("G"); setcolor(15);
								}
								if (drumKeyOnOff[5] == 1) {
									gotoxy(77, 6); setcolor(10); printf("U"); setcolor(15);
								}
								if (drumKeyOnOff[6] == 1) {
									gotoxy(73, 13); setcolor(10); printf("J"); setcolor(15);
								}
								if (drumKeyOnOff[7] == 1) {
									gotoxy(52, 19); setcolor(10); printf("V"); setcolor(15);
								}
								
							}
						}
					}
				}

				// 이번에는 키를 때었을때,
				for (key = 0; key < DKEY; key++)
				{
					//szMuskey 배열에 i 번째 해당하는 키가 입력된 것이 아니라면,
					if (!(GetKeyState(drumKey[key]) < 0))
					{
						// 이전에 키를 누른적이 있으면
						if (drumKeyOnOff[key] != 0)
						{
							drumKeyOnOff[key] = 0; // 누른거로 on/off를 체크하고 즉 다시 off로 바꿈
							


							if (key == 0) {
								mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 1) {
								mciSendCommand(dwID1, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 2) {
								mciSendCommand(dwID2, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 3) {
								mciSendCommand(dwID3, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 4) {
								mciSendCommand(dwID4, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 5) {
								mciSendCommand(dwID5, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID5, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 6) {
								mciSendCommand(dwID6, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID6, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 7) {
								mciSendCommand(dwID7, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID7, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							


							if (drumKeyOnOff[0] == 0) {
								gotoxy(25, 8); setcolor(15); printf("S");
							}
							if (drumKeyOnOff[1] == 0) {
								gotoxy(37, 4); setcolor(15); printf("E");
							}
							if (drumKeyOnOff[2] == 0) {
								gotoxy(34, 13); setcolor(15); printf("D");
							}
							if (drumKeyOnOff[3] == 0) {
								gotoxy(46, 8); setcolor(15); printf("F");
							}
							if (drumKeyOnOff[4] == 0) {
								gotoxy(59, 8); setcolor(15); printf("G");
							}
							if (drumKeyOnOff[5] == 0) {
								gotoxy(77, 6); setcolor(15); printf("U");
							}
							if (drumKeyOnOff[6] == 0) {
								gotoxy(73, 13); setcolor(15); printf("J");
							}
							if (drumKeyOnOff[7] == 0) {
								gotoxy(52, 19); setcolor(15); printf("V");
							}
							
						}
					}
				}

			}
			system("cls");
		}
		else if (suntaek == THREE)//mp3
		{
			


			printf("\n\n         음악 파일\n\n\n\n\n");
			printf("                    음악파일 번호 클릭  :   재생\n");
			printf("                           Q/q          :   노래 종료\n");
			printf("                           ESC          :   메인화면 돌아가기\n\n\n\n");
			printf("           ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("           ■                                                                ■\n");
			printf("           ■   1. [Jazz Piano] White Christmas - Beegie Adair               ■\n");
			printf("           ■                                                                ■                    *       \n");
			printf("           ■   2. [Jazz Piano] Jingle-Bell - Ramong                         ■                   @@@          \n");
			printf("           ■                                                                ■                  *****               \n");
			printf("           ■   3. [Jazz Piano] Let it snow - Sweet Dreams                   ■                 @@@@@@@            \n");
			printf("           ■                                                                ■                *********             \n");
			printf("           ■   4. [Electronic Piano] We Wish You a Merry Christmas - Lami   ■               @@@@@@@@@@@             \n");
			printf("           ■                                                                ■              *************           \n");
			printf("           ■   5. [Jazz Piano] Santa Claus is coming to town - Ramong       ■                    ■        \n");
			printf("           ■                                                                ■                    ■     \n");
			printf("           ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

			
			BYTE Mp3[6] = {                                              //https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes 키 코드 분류표
				0x31, 0x32, 0x33, 0x34, 0x35, 0x51            // 1  2  3  4  5  Q

			};

			loop = 1;
			while (loop)
			{
				
				// esc누르면 종료
				if (GetKeyState(VK_ESCAPE) < 0) {
					

					mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
					mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

					mciSendCommand(dwID1, MCI_CLOSE, 0, 0);		//재생 정지
					mciSendCommand(dwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

					mciSendCommand(dwID2, MCI_CLOSE, 0, 0);		//재생 정지
					mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

					mciSendCommand(dwID3, MCI_CLOSE, 0, 0);		//재생 정지
					mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

					mciSendCommand(dwID4, MCI_CLOSE, 0, 0);		//재생 정지
					mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					Sleep(500);
					loop = 0;

				}
				
				else
				{
					for (key = 0; key < 6; key++)
					{
						//szMuskey 배열에 i 번째 해당하는 키가 입력되면
						if (GetKeyState(Mp3[key]) < 0)
						{

							if (key == 0) {
								

								openDo.lpstrElementName = TEXT("White Christmas.wav"); //파일 오픈
								openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
								mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
								dwID = openDo.wDeviceID;

								mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								Sleep(500);
								setcolor(10); gotoxy(16, 15); printf("1. [Jazz Piano] White Christmas - Beegie Adair"); setcolor(15);
								gotoxy(0, 2); printf("         "); printf("음악 파일");
							}

							if (key == 1) {
								openDos.lpstrElementName = TEXT("Jingle-Bell.wav"); //파일 오픈
								openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
								mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
								dwID1 = openDos.wDeviceID;

								mciSendCommand(dwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								Sleep(500);
								setcolor(10); gotoxy(16, 17); printf("2. [Jazz Piano] Jingle-Bell - Ramong"); setcolor(15);
								gotoxy(49, 8); printf("     "); gotoxy(49, 8); printf("종료");
							}

							if (key == 2) {
								openLe.lpstrElementName = TEXT("Let it snow.wav"); //파일 오픈
								openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
								mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
								dwID2 = openLe.wDeviceID;

								mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								Sleep(500);
								setcolor(10); gotoxy(16, 19); printf("3. [Jazz Piano] Let it snow - Sweet Dreams"); setcolor(15);
								gotoxy(57, 9); printf("    "); gotoxy(57, 9); printf("가기");
							}

							if (key == 3) {
								openLes.lpstrElementName = TEXT("We-Wish-You-a-Merry-Christmas.wav"); //파일 오픈
								openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
								mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
								dwID3 = openLes.wDeviceID;

								mciSendCommand(dwID3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								Sleep(500);
								setcolor(10); gotoxy(16, 21); printf("4. [Electronic Piano] We Wish You a Merry Christmas - Lami"); setcolor(15);
							}

							if (key == 4) {
								openMi.lpstrElementName = TEXT("Santa Claus is coming to town.wav"); //파일 오픈
								openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
								mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
								dwID4 = openMi.wDeviceID;

								mciSendCommand(dwID4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								Sleep(500);
								setcolor(10); gotoxy(16, 23); printf("5. [Jazz Piano] Santa Claus is coming to town - Ramong"); setcolor(15);
							}

							if (key == 5) {
								mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

								mciSendCommand(dwID1, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

								mciSendCommand(dwID2, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

								mciSendCommand(dwID3, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

								mciSendCommand(dwID4, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화

								Sleep(500);
								setcolor(15); gotoxy(16, 15); printf("1. [Jazz Piano] White Christmas - Beegie Adair");
								setcolor(15); gotoxy(16, 17); printf("2. [Jazz Piano] Jingle-Bell - Ramong");
								setcolor(15); gotoxy(16, 19); printf("3. [Jazz Piano] Let it snow - Sweet Dreams");
								setcolor(15); gotoxy(16, 21); printf("4. [Electronic Piano] We Wish You a Merry Christmas - Lami");
								setcolor(15); gotoxy(16, 23); printf("5. [Jazz Piano] Santa Claus is coming to town - Ramong");
								
								Sleep(500);
							}
							

						}
					}
				}
				
				
			}

			system("cls");

			
		}
		else if (suntaek == FOUR) { // 녹음하기
			for (int i = 0; i < 100; ++i) {
				recode1[i] = 50;
			}

			int input;
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■            사용할 파일 선택(1,2,3 중에서 입력) :               ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			gotoxy(80, 12);
			scanf_s("%d", &input);
			while (1) {

				if (input == 1) {
					Sleep(300); 
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                   1번 파일이 선택되었습니다.                   ■\n");
					printf("                             ■               파일 이름 입력(띄어쓰기 없이) :                  ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					gotoxy(77, 13);
					scanf_s("%s", recodename1,sizeof(recodename1)); while (getchar() != '\n');
					// 파일 열기
					FILE* file = fopen("text_file1.txt", "w");

					// 파일에 문자열 쓰기
					if (file != NULL) {
						fprintf(file, "%s", recodename1);
						fclose(file);
					}
					v = 1; break;
				}
				if (input == 2) {
					Sleep(300); 
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                   2번 파일이 선택되었습니다.                   ■\n");
					printf("                             ■               파일 이름 입력(띄어쓰기 없이) :                  ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					gotoxy(77, 13);
					scanf_s("%s", recodename2,sizeof(recodename2)); while (getchar() != '\n');
					// 파일 열기
					FILE* file5 = fopen("text_file2.txt", "w");

					// 파일에 문자열 쓰기
					if (file5 != NULL) {
						fprintf(file5, "%s", recodename2);
						fclose(file5);
					}
					v = 2; break;
				}
				if (input == 3) {
					Sleep(300);  ;
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                   3번 파일이 선택되었습니다.                   ■\n");
					printf("                             ■               파일 이름 입력(띄어쓰기 없이) :                  ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■                                                                ■\n");
					printf("                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
					gotoxy(77, 13);
					scanf_s("%s", recodename3,sizeof(recodename3)); while (getchar() != '\n');
					// 파일 열기
					FILE* file7 = fopen("text_file3.txt", "w");

					// 파일에 문자열 쓰기
					if (file7 != NULL) {
						fprintf(file7, "%s", recodename3);
						fclose(file7);
					}
					v = 3; break;
				}

			}
			Sleep(500);
			system("cls");



			printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
			printf("               피아노 녹음 중입니다...\n");
			printf("                                                                                                  녹음 끝내기 : ESC\n");
			printf("                                                                                                   \n");
			printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
			printf("                             |\n                             |\n                             |\n");
			printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                             |■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  | ■■  ");
			puts("                             ■■ |  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  | ■■  ");
			puts("                             ■■ |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  | ■■  ");
			puts("                             ■■ |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ■■  ");
			puts("                             ■■ | Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | ■■  ");
			puts("                             ■■ |___|___|___|___|___|___|___|___|___|___|___|___|___|___| ■■  ");

			loop = 1;
			recodecount = 0;
			recodecount2 = 0;
			recodecount3 = 0;
			while (loop)
			{
				// esc누르면 종료
				if (GetKeyState(VK_ESCAPE) < 0) loop = 0;

				else
				{
					for (key = 0; key < NKEY; key++)
					{
						//szMuskey 배열에 i 번째 해당하는 키가 입력되면
						if (GetKeyState(pianoKey[key]) < 0)
						{
							// 이전에 키를 누른적이 없으면 즉, 키가 눌렸을때
							if (pianoKeyOnOff[key] == 0)
							{
								pianoKeyOnOff[key] = 1; // 누른거로 on/off를 체크하고
								// 현재 눌린 키의 음을 연주하고
								// 0x90 은 노트on 의미이다 즉, 음을 눌렸다는 의미

								if (key == 0) {
									openDo.lpstrElementName = TEXT("do.wav"); //파일 오픈
									openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
									dwID = openDo.wDeviceID;

									mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								}

								if (key == 1) {
									openDos.lpstrElementName = TEXT("dos.wav"); //파일 오픈
									openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
									dwID1 = openDos.wDeviceID;

									mciSendCommand(dwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								}

								if (key == 2) {
									openLe.lpstrElementName = TEXT("le.wav"); //파일 오픈
									openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
									dwID2 = openLe.wDeviceID;

									mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								}

								if (key == 3) {
									openLes.lpstrElementName = TEXT("les.wav"); //파일 오픈
									openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
									dwID3 = openLes.wDeviceID;

									mciSendCommand(dwID3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								}
								if (key == 4) {
									openMi.lpstrElementName = TEXT("mi.wav"); //파일 오픈
									openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
									dwID4 = openMi.wDeviceID;

									mciSendCommand(dwID4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								}
								if (key == 5) {
									openpa.lpstrElementName = TEXT("pa.wav"); //파일 오픈
									openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
									dwID5 = openpa.wDeviceID;

									mciSendCommand(dwID5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
								}
								if (key == 6) {
									openpas.lpstrElementName = TEXT("pas.wav"); //파일 오픈
									openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
									dwID6 = openpas.wDeviceID;

									mciSendCommand(dwID6, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
								}

								if (key == 7) {
									opensol.lpstrElementName = TEXT("sol.wav"); //파일 오픈
									opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
									dwID7 = opensol.wDeviceID;

									mciSendCommand(dwID7, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
								}

								if (key == 8) {
									opensols.lpstrElementName = TEXT("sols.wav"); //파일 오픈
									opensols.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensols);
									dwID8 = opensols.wDeviceID;

									mciSendCommand(dwID8, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensols); //음악을 한 번 재생
								}

								if (key == 9) {
									openla.lpstrElementName = TEXT("la.wav"); //파일 오픈
									openla.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openla);
									dwID9 = openla.wDeviceID;

									mciSendCommand(dwID9, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openla); //음악을 한 번 재생
								}

								if (key == 10) {
									openlas.lpstrElementName = TEXT("las.wav"); //파일 오픈
									openlas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openlas);
									dwID10 = openlas.wDeviceID;

									mciSendCommand(dwID10, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openlas); //음악을 한 번 재생
								}
								if (key == 11) {
									opensi.lpstrElementName = TEXT("si.wav"); //파일 오픈
									opensi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensi);
									dwID11 = opensi.wDeviceID;

									mciSendCommand(dwID11, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensi); //음악을 한 번 재생
								}
								if (key == 12) {
									opendodo.lpstrElementName = TEXT("dodo.wav"); //파일 오픈
									opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
									dwID12 = opendodo.wDeviceID;

									mciSendCommand(dwID12, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
								}
								if (key == 13) {
									openpas.lpstrElementName = TEXT("5dos.wav"); //파일 오픈
									openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
									dwID13 = openpas.wDeviceID;

									mciSendCommand(dwID13, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
								}
								if (key == 14) {
									opensol.lpstrElementName = TEXT("5le.wav"); //파일 오픈
									opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
									dwID14 = opensol.wDeviceID;

									mciSendCommand(dwID14, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
								}
								if (key == 15) {
									open5les.lpstrElementName = TEXT("5les.wav"); //파일 오픈
									open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
									dwID15 = open5les.wDeviceID;

									mciSendCommand(dwID15, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
								}
								if (key == 16) {
									open5les.lpstrElementName = TEXT("5mi.wav"); //파일 오픈
									open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
									dwID16 = open5les.wDeviceID;

									mciSendCommand(dwID16, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
								}
								if (key == 17) {
									opendodo.lpstrElementName = TEXT("5pa.wav"); //파일 오픈
									opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
									dwID17 = opendodo.wDeviceID;

									mciSendCommand(dwID17, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
								}
								if (key == 18) {
									openDo.lpstrElementName = TEXT("5pas.wav"); //파일 오픈
									openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
									dwID18 = openDo.wDeviceID;

									mciSendCommand(dwID18, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
								}
								if (key == 19) {
									openDos.lpstrElementName = TEXT("5sol.wav"); //파일 오픈
									openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
									dwID19 = openDos.wDeviceID;

									mciSendCommand(dwID19, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
								}
								if (key == 20) {
									openLe.lpstrElementName = TEXT("5sols.wav"); //파일 오픈
									openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
									dwID20 = openLe.wDeviceID;

									mciSendCommand(dwID20, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
								}
								if (key == 21) {
									openLes.lpstrElementName = TEXT("5la.wav"); //파일 오픈
									openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
									dwID21 = openLes.wDeviceID;

									mciSendCommand(dwID21, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
								}
								if (key == 22) {
									openMi.lpstrElementName = TEXT("5las.wav"); //파일 오픈
									openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
									dwID22 = openMi.wDeviceID;

									mciSendCommand(dwID22, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
								}
								if (key == 23) {
									openpa.lpstrElementName = TEXT("5si.wav"); //파일 오픈
									openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
									mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
									dwID23 = openpa.wDeviceID;

									mciSendCommand(dwID23, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
								}


								if (pianoKeyOnOff[0] == 1) {
									gotoxy(36, 20); setcolor(10); printf("Z"); setcolor(15);
								}
								if (pianoKeyOnOff[1] == 1) {
									gotoxy(38, 17); setcolor(10); printf("S"); setcolor(15);
								}
								if (pianoKeyOnOff[2] == 1) {
									gotoxy(40, 20); setcolor(10); printf("X"); setcolor(15);
								}
								if (pianoKeyOnOff[3] == 1) {
									gotoxy(42, 17); setcolor(10); printf("D"); setcolor(15);
								}
								if (pianoKeyOnOff[4] == 1) {
									gotoxy(44, 20); setcolor(10); printf("C"); setcolor(15);
								}
								if (pianoKeyOnOff[5] == 1) {
									gotoxy(48, 20); setcolor(10); printf("V"); setcolor(15);
								}
								if (pianoKeyOnOff[6] == 1) {
									gotoxy(50, 17); setcolor(10); printf("G"); setcolor(15);
								}
								if (pianoKeyOnOff[7] == 1) {
									gotoxy(52, 20); setcolor(10); printf("B"); setcolor(15);
								}
								if (pianoKeyOnOff[8] == 1) {
									gotoxy(54, 17); setcolor(10); printf("H"); setcolor(15);
								}
								if (pianoKeyOnOff[9] == 1) {
									gotoxy(56, 20); setcolor(10); printf("N"); setcolor(15);
								}
								if (pianoKeyOnOff[10] == 1) {
									gotoxy(58, 17); setcolor(10); printf("J"); setcolor(15);
								}
								if (pianoKeyOnOff[11] == 1) {
									gotoxy(60, 20); setcolor(10); printf("M"); setcolor(15);
								}
								if (pianoKeyOnOff[12] == 1) {
									gotoxy(64, 20); setcolor(10); printf("Q"); setcolor(15);
								}
								if (pianoKeyOnOff[13] == 1) {
									gotoxy(66, 17); setcolor(10); printf("2"); setcolor(15);
								}
								if (pianoKeyOnOff[14] == 1) {
									gotoxy(68, 20); setcolor(10); printf("W"); setcolor(15);
								}
								if (pianoKeyOnOff[15] == 1) {
									gotoxy(70, 17); setcolor(10); printf("3"); setcolor(15);
								}
								if (pianoKeyOnOff[16] == 1) {
									gotoxy(72, 20); setcolor(10); printf("E"); setcolor(15);
								}
								if (pianoKeyOnOff[17] == 1) {
									gotoxy(76, 20); setcolor(10); printf("R"); setcolor(15);
								}
								if (pianoKeyOnOff[18] == 1) {
									gotoxy(78, 17); setcolor(10); printf("5"); setcolor(15);
								}
								if (pianoKeyOnOff[19] == 1) {
									gotoxy(80, 20); setcolor(10); printf("T"); setcolor(15);
								}
								if (pianoKeyOnOff[20] == 1) {
									gotoxy(82, 17); setcolor(10); printf("6"); setcolor(15);
								}
								if (pianoKeyOnOff[21] == 1) {
									gotoxy(84, 20); setcolor(10); printf("Y"); setcolor(15);
								}
								if (pianoKeyOnOff[22] == 1) {
									gotoxy(86, 17); setcolor(10); printf("7"); setcolor(15);
								}
								if (pianoKeyOnOff[23] == 1) {
									gotoxy(88, 20); setcolor(10); printf("U"); setcolor(15);
								}
								recode1[recodecount] = key;

								start_time = clock(); // 스톱워치 시작 시간 기록
							}
						}
					}
				}

				// 이번에는 키를 때었을때,
				for (key = 0; key < NKEY; key++)
				{
					//szMuskey 배열에 i 번째 해당하는 키가 입력된 것이 아니라면,
					if (!(GetKeyState(pianoKey[key]) < 0))
					{
						// 이전에 키를 누른적이 있으면
						if (pianoKeyOnOff[key] != 0)
						{
							pianoKeyOnOff[key] = 0; // 누른거로 on/off를 체크하고 즉 다시 off로 바꿈
							// 연주 중인 소리를 끔
							// 0x80 은 노트off의 의미 즉, 음을 때었다는것


							if (key == 0) {
								mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 1) {
								mciSendCommand(dwID1, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 2) {
								mciSendCommand(dwID2, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 3) {
								mciSendCommand(dwID3, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 4) {
								mciSendCommand(dwID4, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 5) {
								mciSendCommand(dwID5, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID5, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 6) {
								mciSendCommand(dwID6, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID6, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 7) {
								mciSendCommand(dwID7, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID7, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 8) {
								mciSendCommand(dwID8, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID8, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 9) {
								mciSendCommand(dwID9, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID9, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 10) {
								mciSendCommand(dwID10, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID10, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 11) {
								mciSendCommand(dwID11, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID11, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 12) {
								mciSendCommand(dwID12, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID12, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}
							if (key == 13) {
								mciSendCommand(dwID13, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID13, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 14) {
								mciSendCommand(dwID14, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID14, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 15) {
								mciSendCommand(dwID15, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID15, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 16) {
								mciSendCommand(dwID16, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID16, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 17) {
								mciSendCommand(dwID17, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID17, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 18) {
								mciSendCommand(dwID18, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID18, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 19) {
								mciSendCommand(dwID19, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID19, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 20) {
								mciSendCommand(dwID20, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID20, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 21) {
								mciSendCommand(dwID21, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID21, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 22) {
								mciSendCommand(dwID22, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID22, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}

							if (key == 23) {
								mciSendCommand(dwID23, MCI_CLOSE, 0, 0);		//재생 정지
								mciSendCommand(dwID23, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
							}


							if (pianoKeyOnOff[0] == 0) {
								gotoxy(36, 20); setcolor(15); printf("Z");
							}
							if (pianoKeyOnOff[1] == 0) {
								gotoxy(38, 17); setcolor(15); printf("S");
							}
							if (pianoKeyOnOff[2] == 0) {
								gotoxy(40, 20); setcolor(15); printf("X");
							}
							if (pianoKeyOnOff[3] == 0) {
								gotoxy(42, 17); setcolor(15); printf("D");
							}
							if (pianoKeyOnOff[4] == 0) {
								gotoxy(44, 20); setcolor(15); printf("C");
							}
							if (pianoKeyOnOff[5] == 0) {
								gotoxy(48, 20); setcolor(15); printf("V");
							}
							if (pianoKeyOnOff[6] == 0) {
								gotoxy(50, 17); setcolor(15); printf("G");
							}
							if (pianoKeyOnOff[7] == 0) {
								gotoxy(52, 20); setcolor(15); printf("B");
							}
							if (pianoKeyOnOff[8] == 0) {
								gotoxy(54, 17); setcolor(15); printf("H");
							}
							if (pianoKeyOnOff[9] == 0) {
								gotoxy(56, 20); setcolor(15); printf("N");
							}
							if (pianoKeyOnOff[10] == 0) {
								gotoxy(58, 17); setcolor(15); printf("J");
							}
							if (pianoKeyOnOff[11] == 0) {
								gotoxy(60, 20); setcolor(15); printf("M");
							}
							if (pianoKeyOnOff[12] == 0) {
								gotoxy(64, 20); setcolor(15); printf("Q");
							}
							if (pianoKeyOnOff[13] == 0) {
								gotoxy(66, 17); setcolor(15); printf("2");
							}
							if (pianoKeyOnOff[14] == 0) {
								gotoxy(68, 20); setcolor(15); printf("W");
							}
							if (pianoKeyOnOff[15] == 0) {
								gotoxy(70, 17); setcolor(15); printf("3");
							}
							if (pianoKeyOnOff[16] == 0) {
								gotoxy(72, 20); setcolor(15); printf("E");
							}
							if (pianoKeyOnOff[17] == 0) {
								gotoxy(76, 20); setcolor(15); printf("R");
							}
							if (pianoKeyOnOff[18] == 0) {
								gotoxy(78, 17); setcolor(15); printf("5");
							}
							if (pianoKeyOnOff[19] == 0) {
								gotoxy(80, 20); setcolor(15); printf("T");
							}
							if (pianoKeyOnOff[20] == 0) {
								gotoxy(82, 17); setcolor(15); printf("6");
							}
							if (pianoKeyOnOff[21] == 0) {
								gotoxy(84, 20); setcolor(15); printf("Y");
							}
							if (pianoKeyOnOff[22] == 0) {
								gotoxy(86, 17); setcolor(15); printf("7");
							}
							if (pianoKeyOnOff[23] == 0) {
								gotoxy(88, 20); setcolor(15); printf("U");
							}
							end_time = clock(); // 스톱워치 종료 시간 기록
							double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
							recodetime1[recodecount] = (int)elapsed_time;
							recodecount++;
							recodecount2++;
							recodecount3++;
						}
					}
				}

			}
			if (v == 1) {
				FILE* file = fopen("recodetime1.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file, "%d\n", recodetime1[i]);
				}

				// 파일 닫기
				fclose(file);
			}
			if (v == 2) {
				FILE* file = fopen("recodetime2.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file, "%d\n", recodetime1[i]);
				}

				// 파일 닫기
				fclose(file);
			}
			if (v == 3) {
				FILE* file = fopen("recodetime3.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file, "%d\n", recodetime1[i]);
				}

				// 파일 닫기
				fclose(file);
			}

			if (v == 1) {
				FILE* file = fopen("array_data1.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file, "%d\n", recode1[i]);
				}

				// 파일 닫기
				fclose(file);
			}
			if (v == 2) {
				FILE* file2 = fopen("array_data2.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file2, "%d\n", recode1[i]);
				}

				// 파일 닫기
				fclose(file2);
			}
			if (v == 3) {
				FILE* file3 = fopen("array_data3.txt", "w");

				// 배열 값 파일에 쓰기
				for (int i = 0; i < recodecount; ++i) {
					fprintf(file3, "%d\n", recode1[i]);
				}

				// 파일 닫기
				fclose(file3);
			}
			if (v == 1) {
				FILE* file = fopen("recodecount1.txt", "w");

				// 배열 값 파일에 쓰기

				fprintf(file, "%d\n", recodecount);


				// 파일 닫기
				fclose(file);
			}
			if (v == 2) {
				FILE* file2 = fopen("recodecount2.txt", "w");

				// 배열 값 파일에 쓰기

				fprintf(file2, "%d\n", recodecount2);


				// 파일 닫기
				fclose(file2);
			}
			if (v == 3) {
				FILE* file3 = fopen("recodecount3.txt", "w");

				// 배열 값 파일에 쓰기

				fprintf(file3, "%d\n", recodecount3);


				// 파일 닫기
				fclose(file3);
			}
			for (int i = 0; i < 100; ++i) {
				recode1[i] = 50;
			}
			system("cls");
		}


		else if (suntaek == FIVE) {
			FILE* file = fopen("text_file1.txt", "r");
			if (file != NULL) {
				fgets(recodename1, sizeof(recodename1), file);
				fclose(file);

			}

			FILE* file1 = fopen("text_file2.txt", "r");
			if (file1 != NULL) {
				fgets(recodename2, sizeof(recodename2), file1);
				fclose(file1);

			}

			FILE* file2 = fopen("text_file3.txt", "r");
			if (file2 != NULL) {
				fgets(recodename3, sizeof(recodename3), file2);
				fclose(file2);

			}
			printf("\n\n\n\n\n\n\n\n\n                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■            녹음한 파일 중 재생할 파일번호를 누르시오.          ■\n");
			printf("                             ■        (1. %s)\n", recodename1);  
			printf("                             ■        (2. %s)\n", recodename2);
			printf("                             ■        (3. %s)\n", recodename3);
			printf("                             ■                                                                ■\n");
			printf("                             ■                                       메인메뉴 돌아가기 : ESC  ■\n");
			printf("                             ■                                                                ■\n");
			printf("                             ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			gotoxy(95, 13); printf("■"); gotoxy(95, 14); printf("■"); gotoxy(95, 15); printf("■");
			
			int read1[100];
			
			int readcount1;
			int readcount2;
			int readcount3;
			int countt;

			int o;
			int loop3 = 1;
			while (loop3) {
				for (int i = 0; i < 100; ++i) {
					read1[i] = 50;
				}

				while (1) {
					gotoxy(39, 13); setcolor(15); printf("(1. %s)\n", recodename1);
					gotoxy(39, 14); setcolor(15); printf("(2. %s)\n", recodename2);
					gotoxy(39, 15); setcolor(15); printf("(3. %s)\n", recodename3);
					if (GetKeyState(VK_ESCAPE) < 0) {
						loop3 = 0; break;
					}

					if (GetKeyState(0x31) < 0) {
						o = 1;
						gotoxy(39, 13); setcolor(10); printf("(1. %s)\n", recodename1); setcolor(15);
						FILE* file = fopen("array_data1.txt", "r");
						if (file != NULL) {
							// 파일에서 배열 값 읽기

							for (int i = 0; i < 100; ++i) {
								fscanf_s(file, "%d", &read1[i]);
							}

							// 파일 닫기
							fclose(file);

						}
						else {
							printf("파일을 열 수 없습니다.\n");
						}
						break;
					}
					if (GetKeyState(0x32) < 0) {
						o = 2;
						gotoxy(39, 14); setcolor(10); printf("(2. %s)\n", recodename2); setcolor(15);
						FILE* file2 = fopen("array_data2.txt", "r");
						if (file2 != NULL) {
							// 파일에서 배열 값 읽기

							for (int i = 0; i < 100; ++i) {
								fscanf_s(file2, "%d", &read1[i]);
							}

							// 파일 닫기
							fclose(file2);

						}
						else {
							printf("파일을 열 수 없습니다.\n");
						}
						break;
					}
					if (GetKeyState(0x33) < 0) {
						o = 3;
						gotoxy(39, 15); setcolor(10); printf("(3. %s)\n", recodename3); setcolor(15);
						FILE* file3 = fopen("array_data3.txt", "r");
						if (file3 != NULL) {
							// 파일에서 배열 값 읽기

							for (int i = 0; i < 100; ++i) {
								fscanf_s(file3, "%d", &read1[i]);
							}

							// 파일 닫기
							fclose(file3);

						}
						else {
							printf("파일을 열 수 없습니다.\n");
						}
						break;
					}
				}
				FILE* file4 = fopen("recodecount1.txt", "r");
				if (file4 != NULL) {
					// 파일에서 배열 값 읽기


					fscanf_s(file4, "%d", &readcount1);


					// 파일 닫기
					fclose(file4);

				}
				FILE* file5 = fopen("recodecount2.txt", "r");
				if (file5 != NULL) {
					// 파일에서 배열 값 읽기


					fscanf_s(file5, "%d", &readcount2);


					// 파일 닫기
					fclose(file5);

				}
				FILE* file6 = fopen("recodecount3.txt", "r");
				if (file6 != NULL) {
					// 파일에서 배열 값 읽기


					fscanf_s(file6, "%d", &readcount3);


					// 파일 닫기
					fclose(file6);

				}
				FILE* file9 = fopen("recodetime1.txt", "r");
				if (file9 != NULL) {
					// 파일에서 배열 값 읽기

					for (int i = 0; i < 100; ++i) {
						fscanf_s(file9, "%d", &readtime1[i]);
					}

					// 파일 닫기
					fclose(file9);

				}
				FILE* file8 = fopen("recodetime2.txt", "r");
				if (file8 != NULL) {
					// 파일에서 배열 값 읽기

					for (int i = 0; i < 100; ++i) {
						fscanf_s(file8, "%d", &readtime2[i]);
					}

					// 파일 닫기
					fclose(file8);

				}
				FILE* file7 = fopen("recodetime3.txt", "r");
				if (file7 != NULL) {
					// 파일에서 배열 값 읽기

					for (int i = 0; i < 100; ++i) {
						fscanf_s(file7, "%d", &readtime3[i]);
					}

					// 파일 닫기
					fclose(file7);

				}
				if (o == 1) {
					countt = readcount1;

				}
				if (o == 2) {
					countt = readcount2;
				}
				if (o == 3) {
					countt = readcount3;
				}

				for (int i = 0; i < countt; i++) {
					int t = read1[i];
					int g;
					if (o == 1) {
						g = readtime1[i];
					}
					if (o == 2) {
						g = readtime2[i];
					}
					if (o == 3) {
						g = readtime3[i];
					}


					if (t == 0) {
						openDo.lpstrElementName = TEXT("do.wav"); //파일 오픈
						openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
						dwID = openDo.wDeviceID;

						mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 1) {
						openDos.lpstrElementName = TEXT("dos.wav"); //파일 오픈
						openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
						dwID1 = openDos.wDeviceID;

						mciSendCommand(dwID1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 2) {
						openLe.lpstrElementName = TEXT("le.wav"); //파일 오픈
						openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
						dwID2 = openLe.wDeviceID;

						mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 3) {
						openLes.lpstrElementName = TEXT("les.wav"); //파일 오픈
						openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
						dwID3 = openLes.wDeviceID;

						mciSendCommand(dwID3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 4) {
						openMi.lpstrElementName = TEXT("mi.wav"); //파일 오픈
						openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
						dwID4 = openMi.wDeviceID;

						mciSendCommand(dwID4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 5) {
						openpa.lpstrElementName = TEXT("pa.wav"); //파일 오픈
						openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
						dwID5 = openpa.wDeviceID;

						mciSendCommand(dwID5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 6) {
						openpas.lpstrElementName = TEXT("pas.wav"); //파일 오픈
						openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
						dwID6 = openpas.wDeviceID;

						mciSendCommand(dwID6, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 7) {
						opensol.lpstrElementName = TEXT("sol.wav"); //파일 오픈
						opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
						dwID7 = opensol.wDeviceID;

						mciSendCommand(dwID7, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 8) {
						opensols.lpstrElementName = TEXT("sols.wav"); //파일 오픈
						opensols.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensols);
						dwID8 = opensols.wDeviceID;

						mciSendCommand(dwID8, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensols); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 9) {
						openla.lpstrElementName = TEXT("la.wav"); //파일 오픈
						openla.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openla);
						dwID9 = openla.wDeviceID;

						mciSendCommand(dwID9, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openla); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}

					if (t == 10) {
						openlas.lpstrElementName = TEXT("las.wav"); //파일 오픈
						openlas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openlas);
						dwID10 = openlas.wDeviceID;

						mciSendCommand(dwID10, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openlas); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 11) {
						opensi.lpstrElementName = TEXT("si.wav"); //파일 오픈
						opensi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensi);
						dwID11 = opensi.wDeviceID;

						mciSendCommand(dwID11, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensi); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 12) {
						opendodo.lpstrElementName = TEXT("dodo.wav"); //파일 오픈
						opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
						dwID12 = opendodo.wDeviceID;

						mciSendCommand(dwID12, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 13) {
						openpas.lpstrElementName = TEXT("5dos.wav"); //파일 오픈
						openpas.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpas);
						dwID13 = openpas.wDeviceID;

						mciSendCommand(dwID13, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpas); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 14) {
						opensol.lpstrElementName = TEXT("5le.wav"); //파일 오픈
						opensol.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensol);
						dwID14 = opensol.wDeviceID;

						mciSendCommand(dwID14, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensol); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 15) {
						open5les.lpstrElementName = TEXT("5les.wav"); //파일 오픈
						open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
						dwID15 = open5les.wDeviceID;

						mciSendCommand(dwID15, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 16) {
						open5les.lpstrElementName = TEXT("5mi.wav"); //파일 오픈
						open5les.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&open5les);
						dwID16 = open5les.wDeviceID;

						mciSendCommand(dwID16, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&open5les); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 17) {
						opendodo.lpstrElementName = TEXT("5pa.wav"); //파일 오픈
						opendodo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opendodo);
						dwID17 = opendodo.wDeviceID;

						mciSendCommand(dwID17, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opendodo); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 18) {
						openDo.lpstrElementName = TEXT("5pas.wav"); //파일 오픈
						openDo.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDo);
						dwID18 = openDo.wDeviceID;

						mciSendCommand(dwID18, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDo); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 19) {
						openDos.lpstrElementName = TEXT("5sol.wav"); //파일 오픈
						openDos.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openDos);
						dwID19 = openDos.wDeviceID;

						mciSendCommand(dwID19, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openDos); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 20) {
						openLe.lpstrElementName = TEXT("5sols.wav"); //파일 오픈
						openLe.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLe);
						dwID20 = openLe.wDeviceID;

						mciSendCommand(dwID20, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLe); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 21) {
						openLes.lpstrElementName = TEXT("5la.wav"); //파일 오픈
						openLes.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openLes);
						dwID21 = openLes.wDeviceID;

						mciSendCommand(dwID21, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openLes); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 22) {
						openMi.lpstrElementName = TEXT("5las.wav"); //파일 오픈
						openMi.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openMi);
						dwID22 = openMi.wDeviceID;

						mciSendCommand(dwID22, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openMi); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
					if (t == 23) {
						openpa.lpstrElementName = TEXT("5si.wav"); //파일 오픈
						openpa.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
						mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openpa);
						dwID23 = openpa.wDeviceID;

						mciSendCommand(dwID23, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openpa); //음악을 한 번 재생
						Sleep(g);
						mciSendCommand(dwID, MCI_CLOSE, 0, 0);		//재생 정지
						mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
					}
				}
			}
			

			Sleep(500);
			system("cls");
		}
		else if (suntaek == SIX)//종료
			break;

	}
	return 0;
}

/*키보드 커서 옮기는 함수*/
void gotoxy(int a, int b)
{
	COORD CursorPosition = { a,b };// CursorPosition  이라는 이름의 구조체 정의하여 키보드 커서 옮기는 함수 만듦
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);//키보드 커서 포지션 함수 정의
}

/*출력문 색깔 바꾸는 함수*/
void setcolor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);//x가 색깔의 수
}

/*메인 화면 키보드 커서*/
void main_key_cusor(int a, int b, int* suntaek)//인수 a,b 선택 
{
	int key;

	while (1)
	{
		key = getch();//key에 한개의 키보드 입력을 받음


		// 자동입력 
		switch (key)   // key변수 - 스위치 
		{


		case UP:     // #define UP 에 대한 것 (위로 움직일 때) 
			if (a > 0 && b > 18)//1번 위로 올라가지 않게
			{
				gotoxy(a, b--); puts(" "); //위로 움직일 때마다 * 감소 
				gotoxy(a, b); puts(">");//x,y좌표에 대한 값 * 출력
				setcolor(15);
			}

			break;
		case DOWN:  // #define DOWN 에 대한 것 (아래로 움직일 때)
			if (b < 23)//3.번 아래로 내려가지 않게
			{
				gotoxy(a, b++); puts(" "); // 아래로 움직일 때마다 * 증가 
				gotoxy(a, b); puts(">"); //x,y좌표에 대한 값 * 출력
				setcolor(15);
			}
			break;

		}
		if (key == ENTER && a == 51 && b == 18)//엔터가 입력되고 그 위치가 24,12일때 의 뜻
		{
			*suntaek = ONE;//suntaek의 변수에 one 이라는 값을 입력
			break;
		}
		else if (key == ENTER && a == 51 && b == 19)
		{
			*suntaek = TWO;
			break;

		}
		else if (key == ENTER && a == 51 && b == 20)
		{
			*suntaek = THREE;
			break;
		}
		else if (key == ENTER && a == 51 && b == 21)
		{
			*suntaek = FOUR;
			break;

		}
		else if (key == ENTER && a == 51 && b == 22)
		{
			*suntaek = FIVE;
			break;

		}
		else if (key == ENTER && a == 51 && b == 23)
		{
			*suntaek = SIX;
			break;

		}
	}
}

void removeCursor()//커서 함수 없애는것
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/*움직이는 메인 화면*/
void set_main()
{
	int i;

	setcolor(5);//15번 색상의 출력문 색깔 바꾸는 명렁어
	gotoxy(0, 16); printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"); Sleep(110);
	gotoxy(0, 0); printf("\n"); Sleep(150);//슬립100이면 0.1초를 뜻한다 0.1초동안 보여주어서 순식간에 빠르게 지나가는걸 막기 위해
	setcolor(15);//15번 색상의 출력문 색깔 바꾸는 명렁어
	gotoxy(0, 10); printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");  Sleep(110);
	for (i = 5; i >= 0; i--)
	{
		setcolor(i + 4);
		gotoxy(i, 11); printf("   ■■■ ■     ■■■ ■■■       ■■■ ■    ■  ■■■  ■■■ ■■■ ■  ■ ■      ■ ■■■  ■    ■ ■■■ \n");  Sleep(150);
	}
	for (i = 5; i >= 0; i--)
	{
		setcolor(i + 2);//13번 색상의 출력문 색깔 바꾸는 명렁어
		gotoxy(i, 12); printf("   ■     ■     ■     ■             ■   ■■  ■ ■         ■   ■  ■ ■  ■ ■■  ■■ ■      ■■  ■   ■ \n"); Sleep(150);
	}
	for (i = 5; i >= 0; i--)
	{
		setcolor(i + 3);//13번 색상의 출력문 색깔 바꾸는 명렁어
		gotoxy(i, 13); printf("   ■■■ ■     ■■■ ■             ■   ■ ■ ■  ■■■    ■   ■■■ ■  ■ ■  ■  ■ ■■■  ■ ■ ■   ■ \n"); Sleep(150);
	}
	for (i = 5; i >= 0; i--)
	{
		setcolor(i + 5);//13번 색상의 출력문 색깔 바꾸는 명렁어
		gotoxy(i, 14); printf("   ■     ■     ■     ■             ■   ■  ■■       ■   ■   ■■   ■  ■ ■      ■ ■      ■  ■■   ■ \n"); Sleep(150);
	}
	for (i = 5; i >= 0; i--)
	{
		setcolor(i + 6);//13번 색상의 출력문 색깔 바꾸는 명렁어
		gotoxy(i, 15); printf("   ■■■ ■■■ ■■■ ■■■       ■■■ ■    ■  ■■■    ■   ■  ■ ■■■ ■      ■ ■■■  ■    ■   ■ \n"); Sleep(150);
	}

	setcolor(15);//다시 원래 색상 15번 색상의 뒤로 전부 다 출력문이 15번색상으로 나옴
	gotoxy(0, 16); printf(" ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"); Sleep(1000);
}
