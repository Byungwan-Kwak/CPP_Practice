#include<iostream>
#include<Windows.h>
using namespace std;

int main() {

	//MessageBoxA(NULL, "###", "후후", NULL);
	while (1) 
	{	
		// 키보드 입력 받기

		if (GetAsyncKeyState(VK_UP) & 0x8001) {
			cout << "↑";
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
			cout << "↓";
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
			cout << "←";
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			cout << "→";
		}


		Sleep(100);
	}
}