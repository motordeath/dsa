#include <bits/stdc++.h>
using namespace std;

int indexSequentialSearch(vector<int>& arr, int x, int blockSize) {
    int n = arr.size();
    vector<pair<int,int>> indexTable;
    for (int i = 0; i < n; i += blockSize)
        indexTable.push_back({arr[i], i});
    int blockIndex = -1;
    for (auto& p : indexTable) {
        if (x < p.first) break;
        blockIndex = p.second;
    }
    if (blockIndex == -1) return -1;
    for (int i = blockIndex; i < min(blockIndex + blockSize, n); i++)
        if (arr[i] == x) return i;
    return -1;
}

int main() {
    vector<int> arr = {5,10,15,20,25,30,35,40,45,50};
    int x = 35, blockSize = 3;
    int pos = indexSequentialSearch(arr, x, blockSize);
    if (pos != -1) cout << "Element " << x << " found at index " << pos;

