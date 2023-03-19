#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11; // size of array
int n = MAXN-1; // size of array for Fenwick Tree
int BIT1[MAXN], BIT2[MAXN];

void update(int *BIT, int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

void range_update(int l, int r, int val) {
    update(BIT1, l, val);
    update(BIT1, r+1, -val);
    update(BIT2, l, val*(l-1));
    update(BIT2, r+1, -val*r);
}

void build(int *arr) {
    for (int i = 1; i <= n; i++) {
        range_update(i, i, arr[i]);
    }
}

int query(int *BIT, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int prefix_sum(int idx) {
    return query(BIT1, idx)*idx - query(BIT2, idx);
}

int range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l-1);
}

int main() {
    // Initialize the array and build the Fenwick Tree with point updates
    int arr[MAXN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    build(arr);

    cout << prefix_sum(2) << endl; // expected output: 40
    range_update(1, 2, 2);
    cout << prefix_sum(10) << endl; // expected output: 25
    return 0;
}
