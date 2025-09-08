#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int id;
    int deadline;
    int profit;
};

// Greedy job sequencing on a given set of events
vector<int> schedule(vector<Event> &events) {
    sort(events.begin(), events.end(), [](auto &a, auto &b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (auto &e : events)
        maxDeadline = max(maxDeadline, e.deadline);

    vector<int> slots(maxDeadline + 1, -1);

    for (auto &e : events) {
        for (int d = e.deadline; d >= 1; d--) {
            if (slots[d] == -1) {
                slots[d] = e.id;
                break;
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= maxDeadline; i++) {
        if (slots[i] != -1) result.push_back(slots[i]);
    }
    return result;
}

// Divide and Conquer function
vector<int> divideAndConquer(vector<Event> &arr, int low, int high) {
    if (low == high) {
        vector<Event> single = {arr[low]};
        return schedule(single);
    }

    int mid = (low + high) / 2;
    vector<int> left = divideAndConquer(arr, low, mid);
    vector<int> right = divideAndConquer(arr, mid + 1, high);

    // Combine step: merge both halves’ events and re-schedule
    vector<Event> merged;
    for (int i = low; i <= high; i++) merged.push_back(arr[i]);

    return schedule(merged);
}

int main() {
    int n;
    cin >> n;
    vector<Event> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;

    vector<int> result = divideAndConquer(arr, 0, n - 1);

    cout << "Event sequence in order: ";
    for (int id : result) cout << id << " ";
    cout << endl;

    return 0;
}
