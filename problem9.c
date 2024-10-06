#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void DescendingSort(int arr[], int index[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[maxIndex]) {
				maxIndex = j;
			}
		}
		int tempValue = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = tempValue;

		int tempIndex = index[i];
		index[i] = index[maxIndex];
		index[maxIndex] = tempIndex;
	}
}

int main() {
	int n; //test case
	int time[1000], penalty[1000];
	int job;

	scanf("%d", &n);
	printf("\n");

	for (int i = 0; i < n; i++) {
		scanf("%d", &job);
		for (int i = 0; i < job; i++) {
			scanf("%d %d", &time[i], &penalty[i]);
		}
		//High [penalty for time] must be performed first
		float* value = (float*)malloc(sizeof(float) * job);

		int index[1000] = { 0 };
		for (int i = 0; i < job; i++) {
			value[i] = penalty[i] / time[i];
			index[i] = i;
		}

		DescendingSort(value, index, job);

		for (int i = 0; i < job; i++) {
			printf("%d ", index[i] + 1);
		}
		printf("\n");
	}
}
	