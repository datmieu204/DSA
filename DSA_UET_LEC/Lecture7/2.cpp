#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int a[1000][1000];

vector<int> findRectangle(int n, int m){
    vector<int> res;
    int r1, c1, r2, c2;
    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp = 0;
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                    temp += a[k][l];
                    
                    if(temp > sum){
                        sum = temp;
                        r1 = i;
                        c1 = j;
                        r2 = k;
                        c2 = l;
                    }
                }
            }
        }
    }
    
    res.push_back(r1);
    res.push_back(c1);
    res.push_back(r2);
    res.push_back(c2);
    res.push_back(sum);
    return res;
}

int main(){
    string file_in = "D://Meow//DSA_UET_LEC//Lecture7//Matrix.txt", file_out ="D://Meow//DSA_UET_LEC//Lecture7//Matrix.out";
    ifstream fileIn(file_in);
    ofstream fileOut(file_out);

    if(fileIn.is_open()){
        int n, m;
        fileIn >> n >> m;
        // int a[1000][1000];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                fileIn >> a[i][j];
        }
        
        int r1,c1, r2, c2;
        int sum = 0;
        vector<int> res = findRectangle( n, m);
        r1 = res[0];
        c1 = res[1];
        r2 = res[2];
        c2 = res[3];
        sum = res[4];

        fileOut << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1 << " " << sum << endl;
    }
    else cout << "Can't open file" << endl;

    fileIn.close();
    fileOut.close();
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

int kadane(int* arr, int* start, int* finish, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN, i;

	// Just some initial value to check
	// for all negative values case
	*finish = -1;

	// local variable
	int local_start = 0;

	for (i = 0; i < n; ++i) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(int M[][COL])
{
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop,
		finalBottom;

	int left, right, i;
	int temp[ROW], sum, start, finish;

	for (left = 0; left < COL; ++left) {
		memset(temp, 0, sizeof(temp));


		for (right = left; right < COL; ++right) {

			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			sum = kadane(temp, &start, &finish, ROW);

			if (sum > maxSum) {
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	cout << "(Top, Left) (" << finalTop << ", " << finalLeft
		<< ")" << endl;
	cout << "(Bottom, Right) (" << finalBottom << ", "
		<< finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
						{ -8, -3, 4, 2, 1 },
						{ 3, 8, 10, 1, 3 },
						{ -4, -1, 1, 7, -6 } };

	// Function call
	findMaxSum(M);

	return 0;
}

// This code is contributed by
// rathbhupendra
*/