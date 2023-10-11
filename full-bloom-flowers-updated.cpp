/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full
bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i]
is the time that the ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom
when the ith person arrives.

Example 1 :
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Example 2:
Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

*/

#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;

vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
{
    int count = 0;
    vector<int> start;
    vector<int> end;
    vector<int> answer;

    for (auto row : flowers)
    {
        start.push_back(row[0]);
        end.push_back(row[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for (int i = 0; i < people.size(); i++)
    {
        int p = start.size() - (upper_bound(start.begin(), start.end(), people[i]) - start.begin());

        int q = end.size() - (lower_bound(end.begin(), end.end(), people[i]) - end.begin());

        answer.push_back(q - p);
    }
    return answer;
}

int main()
{
    vector<vector<int>> flower =
        {
            {1, 6},
            {3, 7},
            {9, 12},
            {4,13}

        };

    // vector<vector<int>> flower =
    //     {
    //         {1, 10},
    //         {3, 3},

    //     };

    vector<int> people = { 2,3,7,11 } ;
    // vector<int> people = {3, 3, 2};

   vector<int> answer = fullBloomFlowers( flower , people ) ;

    cout << "Number of Blooming flowers: ";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}