#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

// 1. http://www.practice.geeksforgeeks.org/problem-page.php?pid=364
// 2. http://www.practice.geeksforgeeks.org/problem-page.php?pid=225
// 
// Given a value V, if we want to make change for V cents,
// and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?
//
// Input:
// The first line of input contains an integer T denoting the number of test cases.
// The first line of each test case is V and N,V is the value of cents and N is the number of coins.
// The second line of each test case contains N input C[i],value of available coins.
//
// Output:
// Print the minimum number of coins to make the change, if not possible print -1.

struct Problem
{
    int V;
    std::vector<int> C;

    void input()
    {
        int N = 0;
        int c = 0;
        std::cin >> V >> N;
        // std::cin >> N >> V; // 2nd problem

        ++N;
        while(--N && std::cin >> c)
        {
            C.push_back(c);
        }
    }

    void solve()
    {
        std::vector<int> m(V+1);
        std::fill(m.begin(), m.end(), 0);

        for(int j = 1; j <= V; ++j)
        {
            for(int i = 0; i < C.size(); ++i)
            {
                if(j - C[i] > 0 && m[j - C[i]] > 0)
                {
                    if(m[j] == 0)
                    {
                        m[j] = m[j - C[i] ] + 1;
                    }
                    else
                    {
                        m[j] = std::min(m[j], m[j - C[i] ] + 1);
                    }
                }
                else if(j - C[i] == 0)
                {
                    m[j] = m[j - C[i] ] + 1;
                }
            }
        }

        // std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));

        std::cout << (m[V] ? m[V] : -1) << std::endl;
    }
};


int main()
{
    int T = 0;
    std::cin >> T;
    std::vector<Problem> testCases(T);
    for(int i = 0; i < T; ++i)
    {
        testCases[i].input();
    }

    for(int i = 0; i < T; ++i)
    {
        testCases[i].solve();
    }

    return 0;
}
