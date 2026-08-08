// Problem: https://spinner-number-game.vercel.app/

#include<iostream>
using namespace std;

const int MAX_MATRIX = 20;
const int MAX_STEP = 20;

int n = 4;

// int a[MAX_MATRIX][MAX_MATRIX];
// int a[MAX_MATRIX][MAX_MATRIX] = {
//     {2, 3, 5, 6}
//     {16, 4, 8, 15}
//     {14, 11, 12, 10}
//     {7, 13, 3, 9}
// };
int a[MAX_MATRIX][MAX_MATRIX] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 15, 11},
    {13, 14, 16, 12},
};

int best=99999;
int n_step = 0;
int steps[MAX_STEP][2];
int status[MAX_MATRIX][MAX_MATRIX];

void read() {
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
}

void show_array(int a[][MAX_MATRIX]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "==============================" << endl;
}

bool check() {
    int sum = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (status[i][j]==false)
                return false;
                
    return true;
}

void update_status(int x, int y) {
    
    if (a[x][y]==x*n+y+1) 
        status[x][y] = 1;
    else
        status[x][y] = 0;
        
    if (a[x+1][y]==(x+1)*n+y+1) 
        status[x+1][y] = 1;
    else
        status[x+1][y] = 0;
        
    if (a[x][y+1]==x*n+y+1+1) 
        status[x][y+1] = 1;
    else
        status[x][y+1] = 0;
        
    if (a[x+1][y+1]==(x+1)*n+y+1+1) 
        status[x+1][y+1] = 1;
    else
        status[x+1][y+1] = 0;
}

void press(int x, int y) {
    steps[n_step][0] = x;
    steps[n_step][1] = y;
    n_step++;
    
    // Update values
    int tmp = a[x][y];
    a[x][y] = a[x+1][y];
    a[x+1][y] = a[x+1][y+1];
    a[x+1][y+1] = a[x][y+1];
    a[x][y+1] = tmp;
    
    update_status(x, y);
    
    cout << "Step: " << n_step << " - Press" << x << " " << y << endl;
}

void unpress(int x, int y) {
    n_step--;
    
    // Update values
    int tmp = a[x][y];
    a[x][y] = a[x][y+1];
    a[x][y+1] = a[x+1][y+1];
    a[x+1][y+1] = a[x+1][y];
    a[x+1][y] = tmp;
    
    update_status(x, y);
}

int backtrack(int x, int y) {
    press(x, y);
    if (check()==true) {
        return 1;
    }
    
    if (n_step == 10) {
        cout << "Unsolve" << endl << endl;
        return 1;
    }
    
    for (int i=0; i<=n-1; i++)
        for (int j=0; j<=n-1; j++) {
            int code = backtrack(i, j);
            if (code==1)
                return 1;
        }
            
    unpress(x, y);
    return 0;
}

int main() {
    // // Read input
    // read_input()
    
    // Show
    cout << n << endl;
    show_array(a);
    
    // Create status
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++)
            if (a[i][j]==i*n+j+1) 
                status[i][j] = 1;
            else
                status[i][j] = 0;
                
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << status[i][j] << " ";
        cout << endl;
    }
    cout << "==============================" << endl;
    
    // Solve
    int code = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            code = backtrack(i, j);
            // if (code==1) {
            //     cout << code << " ";
            //     // break;
            // }
            // else
            //     cout << code << " ";
            n_step--;
        }
        cout << endl;
    }
    
        
    // Show result
    
    return 0;
}
