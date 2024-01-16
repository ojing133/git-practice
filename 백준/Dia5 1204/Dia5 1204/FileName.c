#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_WNUM 16
#define MAX 100

int main(void) {
	int N, K; //단어의 개수, 단어의 길이
	char array[50][MAX_WNUM]; //사용자가 입력한 단어 저장 배열
	char tmparr[MAX][MAX];
	char resultarr[MAX][MAX];
	int count = 0;

	scanf("%d %d", &N, &K);

	// 단어 입력받아 배열에 저장하기
	for (int i = 0; i < N; i++) {
		scanf(" %s", array[i]);
	}

	// 가장 길이 짧은 단어 찾기
	int min = 0; //인덱스 저장
	for (int i = 1; i < N; i++) {
		if (strlen(array[i]) < strlen(array[min])) min = i;
	}

	//	문자열 생성, 팰린드롬 여부 검사 후 count++ 연산
	// 한 문자열에 들어가는 단어의 개수로 반복
	char tmp[MAX];
	char inchar[MAX];
	char curr_index, indexnum = -1;
	for (int i = 1; i < K / strlen(array[min]); i++) {
		// 문자열의 경우의 수로 반복
		for (int j = 0; j < pow(N, i); j++) {
			curr_index = j;
			strcpy(tmp, array[curr_index % N]);
			for (int k = 1; k < i; k++) {
				curr_index = curr_index / N;
				if ((strlen(tmp) + strlen(array[curr_index % N]) + 1) <= K) {
					strcat(tmp, " ");
					strcat(tmp, array[curr_index % N]);
				}
			}

			//생성된 문자열의 중복확인
			for (int k = 1; k < (indexnum + 1); k++) {
				if (strcmp(tmp, tmparr[k]) == 0) goto out;
			}

			//문자열 공백제거
			curr_index = 0;
			for (int k = 0; k < strlen(tmp); k++) {
				if (tmp[k] != ' ') inchar[curr_index++] = tmp[k];
			}
			inchar[curr_index] = '\0';
			strcpy(tmparr[++indexnum], tmp);
			strcpy(resultarr[indexnum], inchar);
		out:
			continue;
		}
	};

	//팰린드롬 검사 후 개수 카운트
	for (int i = 0; i <= indexnum; i++) {
		for (int j = 0; j < strlen(resultarr[i])/2; j++) {
			if (resultarr[i][j] != resultarr[i][strlen(resultarr[i]) - j-1]) goto a;
		}
		count++;
	a:
		continue;
	}

	printf("%d", count%835454957);
	return 0;
}