#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //initialisation
    cout << "Input matrix size: ";
    int size = 0;
    cin >> size;
    cout << endl;
    int** matrixPointer = new int*[size];
    for(int i = 0; i < size; ++i){
        matrixPointer[i] = new int[size]();
    }
    int x = 0;
    int y = 0;
    int val = 1;
    matrixPointer[x][y] = val;
    int xStep = 1;
    int yStep = 0;

    //main idea
    while(true){
        x += xStep;
        y += yStep;
        if(x < 0 || x >= size || y < 0 || y >= size || matrixPointer[x][y] != 0){
            x -= xStep;
            y -= yStep;
            switch(xStep){
                case -1:
                    xStep = 0;
                    yStep = -1;
                    break;
                case 0:
                    if(yStep == 1){
                        xStep = -1;
                        yStep = 0;
                    }else{
                        xStep = 1;
                        yStep = 0;
                    }
                    break;
                default:
                    xStep = 0;
                    yStep = 1;
                    break;
            }
            x += xStep;
            y += yStep;
            if(x < 0 || x >= size || y < 0 || y >= size || matrixPointer[x][y] != 0){
                break;
            }
        }
        matrixPointer[x][y] = ++val;
    }

    //result
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cout << setw(4) << matrixPointer[i][j] << ' ';
            if(j == size - 1){
                delete[] matrixPointer[i];
            }
        }
        cout << endl;
    }
    delete[] matrixPointer;
    return 0;
}
