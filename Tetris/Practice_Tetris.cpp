#include <iostream>
#include <Windows.h>
using namespace std;

char map[10][10] = {
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#       #",
	"#########",
};

int nowY = 0;
int nowX = 2;

char block[4][5] =
{
	"#   ",
	"### ",
	"    ",
	"    ",
};

void print()
{
	system("cls");

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 9; x++) {

			//4 x 4 블럭 외 있으면
			if (!(nowY <= y && y <= nowY + 4 && nowX <= x && x <= nowX + 4))
			{
				cout << map[y][x];
			}
			else {
				//블럭 안에 있지만
				int by = y - nowY;
				int bx = x - nowX;
				//# 위치라면 # 출력, 그 외는 맵출력
				if (block[by][bx] == '#') cout << "#";
				else cout << map[y][x];
			}
		}
		cout << endl;
	}
}

void spin()
{
	char temp[4][4];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			temp[x][3 - y] = block[y][x];
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			block[y][x] = temp[y][x];
		}
	}

	char tt2[4][4] = { 0 };
	int miny = 99;
	int minx = 99;
	int maxy = -99;
	int maxx = -99;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (block[y][x] == '#') {

				if (miny > y) miny = y;
				if (minx > x) minx = x;
				if (maxy < y) maxy = y;
				if (maxx < x) maxx = x;

			}
		}
	}

	for (int y = miny; y <= maxy; y++) {
		for (int x = minx; x <= maxx; x++) {
			tt2[y - miny][x - minx] = block[y][x];
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			block[y][x] = tt2[y][x];
		}
	}
}

int isStack(int dy, int dx)
{
	//Map을 dy, dx 쪽에 Block 가져다 놓았을 때
	//겹치는지 안겹치는지

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {

			if (block[y][x] == '#')
				if (map[dy + y][dx + x] == '#') {
					return 1;
				}
		}
	}
	return 0;
}

void down()
{
	if (isStack(nowY + 1, nowX) == 0) {
		nowY++;
		return;
	}


	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (block[y][x] == '#') {
				map[nowY + y][nowX + x] = '#';
			}
		}
	}

	// 새로운 블럭 준비
	nowY = 0;
	nowX = 2;
}

int main()
{
	while (1)
	{
		print();

		if (GetAsyncKeyState(VK_UP) & 0x8001) {
			spin();
			if (isStack(nowY, nowX) == 1) {
				spin(); spin(); spin();
			}
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
			if (isStack(nowY, nowX - 1) == 0) {
				nowX--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			if (isStack(nowY, nowX + 1) == 0) {
				nowX++;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
			down();
		}

		Sleep(100);
	}

	return 0;
}