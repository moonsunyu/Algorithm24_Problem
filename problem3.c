#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int students;
	int spent[100];
	int time = 0, result[100] = { 0 };
	while (1) {
		int total = 0;

		scanf("%d", &students);
		if (students == 0) break;
		for (int i = 0; i < students; i++) {
			scanf("%d", &spent[i]);
			total += spent[i];
		}
		int average = total / students;
		for (int i = 0; i < students; i++) {
			if (spent[i] > average) {
				result[time] += spent[i] - average;
			}
		}
		time++;
	}
	for (int i = 0; i < time; i++) {
		printf("%d won\n", result[i]);
	}
}