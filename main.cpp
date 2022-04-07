#include "PriorityQueue.h"

int main() {
    vector<int> finalResult;
    vector<int> result;
    MaxHeap mh;

    for (int i = 0; i < 100; ++i) {
        mh.insert(i+1);
        finalResult.push_back(100-i);
    }

    while (!mh.empty()) {
        result.push_back(mh.pop());
    }

    assert(result == finalResult);

    MinHeap minHeap;
    finalResult.clear();
    for (int i = 100; i > 0; --i) {
        minHeap.insert(i);
        finalResult.push_back(100-i+1);
    }
    minHeap.print();

    result.clear();
    while (!minHeap.empty()) {
        auto ret = minHeap.pop();
        cout << ret << ' ';
        result.push_back(ret);
    }
    cout << endl;
    assert(result == finalResult);

    return 0;
}
