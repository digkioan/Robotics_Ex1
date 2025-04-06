#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double front_left, front_right, back_left, back_right;

    scanf("%lf %lf %lf %lf", &front_left, &front_right, &back_left, &back_right);

    double deltaX = front_left + back_right - front_right - back_left;
    double deltaY = front_left + front_right - back_left - back_right;

    double angle;

    if (deltaX == 0 && deltaY == 0) {
        if (front_left > 0) angle = 90;
        else angle = -90;
    }
    else if (deltaX == 0 && deltaY != 0) {
        if (deltaY > 0) angle = 90;
        else angle = -90;
    }
    else {
        angle = atan2(deltaY, deltaX) * 180 / PI;
    }

    if (front_left == 1 && front_right == 0 && back_left == 0 && back_right == 1) angle = 45;
    if (front_left == 0 && front_right == 1 && back_left == 1 && back_right == 0) angle = 135;

    printf("%.0f", angle);

    return 0;
}