#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Box {
    int dollars;
    int size;
};

// 함수 프로토타입 선언
int* minCost(struct Box* box, int n);

int main() {
    int total;
    int result[100][2], time = 0;

    while (1) {
        struct Box box[2];
        scanf("%d", &total);
        if (total == 0)
            break;
        for (int i = 0; i < 2; i++) {
            scanf("%d %d", &box[i].dollars, &box[i].size);
        }
        int* val = minCost(box, total);

        result[time][0] = val[0];
        result[time][1] = val[1];

        time++;

        free(val);
    }

    for (int i = 0; i < time; i++) {
        if (result[i][0] < 0)
            printf("failed\n");
        else
            printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}

int* minCost(struct Box* box, int n) {
    int* val = (int*)malloc(sizeof(int) * 2);

    float cost1 = box[0].dollars / (float)box[0].size;
    float cost2 = box[1].dollars / (float)box[1].size;

    int value1 = -1, value2 = -1;

    if (cost1 < cost2) {
        int minCase = n / box[0].size;
        while (minCase >= 0) {
            if ((n - minCase * box[0].size) % box[1].size == 0) {
                value1 = minCase;
                value2 = (n - box[0].size * minCase) / box[1].size;
                break;
            }
            minCase--;
        }
    }
    else {
        int minCase = n / box[1].size;
        while (minCase >= 0) {
            if ((n - minCase * box[1].size) % box[0].size == 0) {
                value2 = minCase;
                value1 = (n - box[1].size * minCase) / box[0].size;
                break;
            }
            minCase--;
        }
    }

    val[0] = value1;
    val[1] = value2;

    return val;
}
