#include <iostream>
#include <ctime>

using namespace std;

void Fisher(int arr[], int N);

void inclusion_sort(int arr[], int N);

int main() {
    srand(time(0));
    int N = 200;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }
    Fisher(arr, N);
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << ") " << arr[i] << endl;
    }
    inclusion_sort(arr, N);
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << ") " << arr[i] << endl;
    }
    return 0;
}

void Fisher(int arr[], int N) {
    int j, temp;
    for (int i = N - 1; i > 0; i--) {
        j = rand() % N;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

void inclusion_sort(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        int temp = arr[i];
        int j = i;
        while ((j > 0) && (arr[j - 1] % 10 > temp % 10 || (arr[j - 1] % 10 == temp % 10 && arr[j - 1] > temp))) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = temp;
    }
}