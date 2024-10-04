#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sweet Nap */

int main() {
	int n, day = 1; //appointments;
	char appointment[100];
	int start_hour[100], start_min[100], end_hour[100], end_min[100];
	int nap_min[100];
	int longest_nap = 0, index = -1, longest_nap_start_hour, longest_nap_start_min;

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%02d:%02d %02d:%02d %s", &start_hour[i], &start_min[i], &end_hour[i], &end_min[i], &appointment);
			if (start_hour[i] < 9 || end_hour[i]>18) {
				printf("There is no lecture in selected time!\n");
				continue;
			}
		}
		for (int i = 1; i < n; i++) {
			nap_min[i - 1] = (start_hour[i] * 60 + start_min[i]) - (end_hour[i - 1] * 60 + end_min[i - 1]);
		}
		for (int i = 0; i < n; i++) {
			if (longest_nap < nap_min[i]) {
				int temp = longest_nap;
				longest_nap = nap_min[i];
				nap_min[i] = temp;
				index = i;
			}
		}longest_nap_start_hour = end_hour[index], longest_nap_start_min = end_min[index];
		if (longest_nap / 60 != 0) {
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes\n",
				day, longest_nap_start_hour, longest_nap_start_min, longest_nap / 60, longest_nap % 60);
		}
		else {
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes\n",
				day, longest_nap_start_hour, longest_nap_start_min, longest_nap);
		}
		day++;
	}
}
