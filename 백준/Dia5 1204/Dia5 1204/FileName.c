#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_WNUM 16
#define MAX 100

int main(void) {
	int N, K; //�ܾ��� ����, �ܾ��� ����
	char array[50][MAX_WNUM]; //����ڰ� �Է��� �ܾ� ���� �迭
	char tmparr[MAX][MAX];
	char resultarr[MAX][MAX];
	int count = 0;

	scanf("%d %d", &N, &K);

	// �ܾ� �Է¹޾� �迭�� �����ϱ�
	for (int i = 0; i < N; i++) {
		scanf(" %s", array[i]);
	}

	// ���� ���� ª�� �ܾ� ã��
	int min = 0; //�ε��� ����
	for (int i = 1; i < N; i++) {
		if (strlen(array[i]) < strlen(array[min])) min = i;
	}

	//	���ڿ� ����, �Ӹ���� ���� �˻� �� count++ ����
	// �� ���ڿ��� ���� �ܾ��� ������ �ݺ�
	char tmp[MAX];
	char inchar[MAX];
	char curr_index, indexnum = -1;
	for (int i = 1; i < K / strlen(array[min]); i++) {
		// ���ڿ��� ����� ���� �ݺ�
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

			//������ ���ڿ��� �ߺ�Ȯ��
			for (int k = 1; k < (indexnum + 1); k++) {
				if (strcmp(tmp, tmparr[k]) == 0) goto out;
			}

			//���ڿ� ��������
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

	//�Ӹ���� �˻� �� ���� ī��Ʈ
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