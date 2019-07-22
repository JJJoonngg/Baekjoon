/*
https://www.acmicpc.net/problem/2819
문제
상근이는 새로운 로봇을 만들었다. 이 로봇의 성능을 시험하기 위해서 테스트 트랙 위에서 테스트하기로 했다. 테스트 트랙은 2차원 평면이다. 
가장 처음에 로봇은 (0,0)에서 시작한다. 상근이는 로봇에게 S, J, I, Z중 하나의 명령을 보낸다. 이 명령은 로봇이 움직여야 하는 방향을 나타낸다.
로봇이 현재 (x,y)에 있다고 하자. S(north)는 (x, y+1)로, J(south)는 (x,y-1)로, I(east)는 (x+1,y)로, Z(west)는 (x-1,y)로 이동하라는 의미이다.

상근이는 로봇이 올바르게 움직이는지 확인하기 위해서 테스트 트랙 위에 N개의 고정된 조사점을 설치했다. 
로봇은 명령을 수행할 때마다, 각 조사점과의 거리의 합을 상근이에게 전송한다. 이때, 거리는 맨해튼 거리이다.

로봇이 상근이에게 전송한 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 조사점의 수 N과 명령의 수 M이 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ M ≤ 300,000)
다음 N개 줄에는 조사점의 x좌표와 y좌표가 주어진다. 모든 좌표의 절댓값은 백만보다 작거나 같은 정수이다. 
같은 좌표를 가지는 조사점이 여러 개 있을 수도 있다. 이때는, 각각의 거리를 따로 계산해서 합해야 한다.
마지막 줄에는 상근이가 로봇에게 전송한 명령이 순서대로 주어진다.
3 5
0 0
1 1
1 -1
SIJJZ
출력
출력은 총 M줄이다. i번째 줄에는, i번째 명령을 수행하고 난 후에 상근이에게 전송한 값을 출력한다.
5
4
3
4
5
*/
#include <iostream>
#include <cmath>
#define MAXI 100000 + 1
using namespace std;
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int inputX[MAXI];
int inputY[MAXI];
char order[MAXI * 3];
int startX = 0;
int startY = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> inputX[i] >> inputY[i];
	while (m--) {
		char tmp; cin >> tmp;
		if (tmp == 'S') {
			startX += dx[0];
			startY += dy[0];
		}
		else if (tmp == 'J') {
			startX += dx[1];
			startY += dy[1];
		}
		else if (tmp == 'I') {
			startX += dx[2];
			startY += dy[2];
		}
		else if (tmp == 'Z') {
			startX += dx[3];
			startY += dy[3];
		}
		_calDistance();
	}
}