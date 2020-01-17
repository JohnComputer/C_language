#include <stdlib.h>

void slot_input_value(int(*slot)[10]) {
	// A = 1  0.064%  / K = 2 0.027% / S = 3 0.008% / 7 = 4 0.001%   0~3/4~6/7~8/9
	int i, j, k, value = 1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++) {		
			// j �� 10�� ���ư��� ���� 0~3/4~6/7~8/9 ������ ���� �־��ش�. �������� �־�� �ϱ⶧���� ����� 2�����迭�� �ּҸ� ���Ѵ�.
			k = rand() % 10;
			if (slot[i][k] == 0) {
				if (j < 4) {
					slot[i][k] = value;
				}
				else if (j < 7) {
					slot[i][k] = value + 1;
				}
				else if (j < 9) {
					slot[i][k] = value + 2;
				}
				else {
					slot[i][k] = value + 3;
				}
			}
			else {
				j--;
			}
		}
	}
}