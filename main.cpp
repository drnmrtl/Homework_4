#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buckets(vector<int> &vec)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i] < min)
        {
            min = vec[i];
        }
        if(vec[i] > max)
        {
            max = vec[i];
        }
    }
    return (int) sqrt(max - min) + 1;
}

void BucketSort( vector<int> &vec, int n)
{

    vector<vector<int>> buckets(n);
    int index;
    for (int i = 0; i<vec.size(); ++i)
    {
        index = (int)vec[i] / n;
        buckets[index].push_back(vec[i]);
    }
    for(int i = 0; i<buckets.size(); ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int k = 0;
    for(int i = 0; i < buckets.size(); ++i)
        for(int j = 0; j<buckets[i].size(); ++j)
        {
            vec[k] = buckets[i][j];
            ++k;
        }
}

int main()
{
    vector<int> vec = {50,45,29,38,13,17,6,3,78,99};
    cout << "Unsorted vector is ";
    for (int i=0; i<vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    unsigned int n = buckets(vec);
    BucketSort(vec,n);
    cout << "Sorted vector is ";
    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    return 0;
}
