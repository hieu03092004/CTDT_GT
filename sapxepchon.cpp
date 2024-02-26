#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> steps;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
        steps.push_back(arr);  // Luu tr?ng thái c?a m?ng sau m?i bu?c
    }

    // In k?t qu? ra standard output
    for (const auto& step : steps) {
        for (int i = 0; i < n; ++i) {
            if (i == step[i] || i == step[i] + 1) {
                cout << "[" << step[i] << "] ";
            } else {
                cout << step[i] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    selectionSort(arr);

    return 0;
}

