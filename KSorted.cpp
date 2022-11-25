
#include <queue>
#include <iostream>
using namespace std;

void kSortedArray(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j++] = pq.top();
        pq.pop();
        pq.push(input[i]);
    }

    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
    }
}

int main()
{
    int input[5] = {12, 15, 6, 7, 9};
    kSortedArray(input, 5, 3);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
}