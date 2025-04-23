#include <stdio.h>
#include <stdlib.h>  
#include "distance.h"

typedef struct {
    double x;
    double y;
} Point;

int main() {
    int N;
    printf("Enter the number of points: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("Need at least two points.\n");
        return 1;
    }

    Point* points = (Point*)malloc(N * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < N - 1; ++i) {
        double dist = calculate_distance(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
        printf("Distance between point %d and point %d: %.2lf\n", i + 1, i + 2, dist);
    }

    free(points); 

    return 0;
}
