#include <stdio.h>
#include <math.h>

float func1(int x);
float func2(int x);
float func3(int x, int y, int z);
float func4(int x);
int get_op();
void visual_result(int op, int x, int y, int z, float result);

int main(void) {
    int op = get_op();
    int x,y = 0,z = 0;
    float result;

    if ( op != 3) {
        printf("X? : ");
        scanf("%d", &x); 
    } else {
        printf("X?: ");
        scanf("%d", &x);

        printf("Y?: ");
        scanf("%d", &y);

        printf("Z?: ");
        scanf("%d", &z);
    }

    switch (op) {
        case 1 :
        result = func1(x);
            break;
        case 2 :
        result = func2(x);
            break;
        case 3 :
        result = func3(x, y, z);
            break;
        case 4 :
        result = func4(x);
            break;
    }

    visual_result(op, x, y, z, result);
}

// f1(x) = (x^3 - 9) + x^2
float func1(int x) {
    float result = (pow(x, 3) - 9 + pow(x, 2));
    return result;
}

// f2(x) = 4x^2 - 3x
float func2(int x) {
    float result = (4*pow(x, 2) - 3*x);
    return result;
}

// G(x,y,z) = z^3 - xy + yz + y^3 - 2
float func3(int x, int y, int z){
    float result = (pow(z, 3) - x*y + y*z + pow(y, 3) - 2);
    return result;
}

// f4(x) = 2/(x-2)^2
float func4(int x){
    float result = (2/pow((x-2), 2));
    return result;
}

int get_op() {
    int op;
    while (op != 1 && op != 2 && op != 3 && op != 4){
        printf("CHOOSE A FORMULA TO USE : \n");
        printf("1: f1(x) = (x^3 - 9) + x^2\n");
        printf("2: f2(x) = 4*x^2 - 3*x\n");
        printf("3: G(x,y,z) = z^3 - x*y + y*z + y^3 - 2\n");
        printf("4: f4(x) = 2/(x-2)^2\n");

        scanf("%d", &op); // madafaka ampersand ruined my 30min damn you c
    }
    return op;
}

void visual_result(int op, int x, int y, int z, float result){
    switch(op){
        case 1:
            printf("f1(%d) = %d^3 - 9 + %d^2 = %.2f", x, x, x, result);
            break;
        case 2:
            printf("f2(%d) = 4*%d^2 - 3*%d = %.2f", x, x, x, result);
            break;
        case 3:
            printf("G(%d, %d, %d) = %d^3 - %d*%d + %d*%d + %d^3 = %.2f", x, y, z, z, x, y, y, z, y, result);
            break;
        case 4:
            printf("f4(%d) = 2/[(%d - 2)^2] = %.2f", x, x, result);
            break;
    }
}



