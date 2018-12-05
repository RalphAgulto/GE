#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

void RREF1 (double matrix1[][2]);

int main() {
    int order=0;
    int x1, x2, x3=0;
    int y1, y2, y3=0;
    int z1, z2, z3=0;
    int t;

    double a=1;
    double b, b2,  c=0;
    double e1, e2=0;
    double E1, E2=0;
    double X1, X2, Y1, Y2=0;

    double matrix1[2][2];




    printf("Enter 2 or 3 for matrix: ");
    scanf("%d", &order);

    if(order==2){
        cout << "Enter 1st constant for 1st term for first equation: " << endl;
        cin >> x1;
        cout << "Enter 2nd constant for 2nd term for first equation: " << endl;
        cin >> x2;
        cout << "Enter 1st constant for 1st term for second equation: " << endl;
        cin >> y1;
        cout << "Enter 2nd constant for 2nd term for second equation: " << endl;
        cin >> y2;

        b = -(x1+y2);
        c = (x1*y2)-(x2*y1);
        b2= pow(b,2);

        if(b2-(4*c)<0){
            return 0;
        }

        e1=(-b+sqrt(b2-(4*c)));
        e1=e1/2;

        e2=(-b-sqrt(b2-(4*c)));
        e2=e2/2;

        E1=x1-e1;  //first eigen value
        E2=y2-e1;

        matrix1[0][0]=E1;
        matrix1[0][1]=x2;
        matrix1[1][0]=y1;
        matrix1[1][1]=E2;

        RREF1(matrix1);

        cout << "Enter value for t: " << endl;
        cin >> t;
        Y1=t;
        X1=((-matrix1[0][1])*t)/(matrix1[0][0]);

        cout << "V1= ( " << X1 << "," << Y1 << " )" << endl;

        E1=x1-e2;  //second eigen value
        E2=y2-e2;

        matrix1[0][0]=E1;
        matrix1[0][1]=x2;
        matrix1[1][0]=y1;
        matrix1[1][1]=E2;

        RREF1(matrix1);

        Y2=t;
        X2=((-matrix1[0][1])*t)/(matrix1[0][0]);

        cout << "V2= ( " << X2 << "," << Y2 << " )" << endl;

        cout << "x= c1( " << X1 << "," << Y1 << " )" << "e^(" << e1 << "t" << ") + c2( " << X2 << "," << Y2 << " )" << "e^(" << e2 << "t" << ")" << endl;
















    }

    if(order==3){

    }









    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void RREF1 (double matrix1[][2]) {

    const int numRows = 2;
    const int numCols = 2;

    int lead = 0;

    while(lead < numRows){
        double div, mul;

        for (int i = 0; i < numRows; i++){
            div = matrix1[lead][lead];
            mul = matrix1[i][lead] / matrix1[lead][lead];

            for (int j = 0; j < numCols;  j++){
                if (i == lead)
                    matrix1[i][j] = matrix1[i][j] / div;
                else
                    matrix1[i][j] = matrix1[i][j] - (matrix1[lead][j] * mul);
            }
        }
        lead++;
    }
}
