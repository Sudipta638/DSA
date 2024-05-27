// 126. Word Ladder II
// Solved
// Hard
// Topics
// Companies
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 5
// endWord.length == beginWord.length
// 1 <= wordList.length <= 500
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
// The sum of all shortest transformation sequences does not exceed 105.

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        auto it = q.front();
        string startword = it.first;
        int dist = it.second;
        q.pop();
        for (int i = 0; i < startword.length(); i++)
        {
            char wch = startword[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (wch != ch)
                {
                    startword[i] = ch;
                    if (st.find(startword) != st.end())
                    {
                        if (startword == endWord)
                        {
                            return dist + 1;
                        }
                        st.erase(startword);
                        q.push({startword, dist + 1});
                    }
                    startword[i] = wch;
                }
            }
        }
    }
    return 0;
}

vector<vector<string>>
findLaddersfromExtansionofSetpsLadder(string beginWord, string endWord,
                                      vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    vector<string> start;
    start.push_back(beginWord);
    q.push(start);
    vector<vector<string>> ans;
    int level = 0;
    while (!q.empty())
    {
        auto it = q.front();
        vector<string> wordList = it;
        string startword = it.back();
        if (wordList.size() > level)
        {
            level++;
            st.erase(startword);
        }
        q.pop();
        for (int i = 0; i < startword.length(); i++)
        {
            char wch = startword[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (wch != ch)
                {
                    startword[i] = ch;
                    if (st.find(startword) != st.end())
                    {

                        wordList.push_back(startword);

                        if (startword == endWord)
                        {
                            {
                                if (ans.size())
                                {
                                    if (ans[0].size() == wordList.size())
                                        ans.push_back(wordList);
                                }
                                else
                                {
                                    ans.push_back(wordList);
                                }
                            }
                        }
                        else
                        {
                            // st.erase(startword);
                            q.push(wordList);
                        }
                        wordList.pop_back();
                    }
                    startword[i] = wch;
                }
            }
        }
    }
    return ans;
}

vector<vector<string>> optimisedsolution(string beginWord, string endWord,
                                         vector<string> &wordList)
{
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    unordered_set<string> st(wordList.begin(), wordList.end());

    if (st.find(endWord) == st.end())
        return ans;

    queue<pair<string, int>> q;
    q.push({beginWord, 0});
    mp[beginWord] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        string currentword = it.first;
        int steps = it.second;
        if (currentword == endWord)
            break;
        for (int i = 0; i < currentword.size(); i++)
        {
            char original = currentword[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != original)
                {
                    currentword[i] = ch;
                    if (st.find(currentword) != st.end())
                    {
                        q.push({currentword, steps + 1});
                        mp[currentword] == 0 && currentword != beginWord ? mp[currentword] = steps + 1 : mp[currentword] = min(steps + 1, mp[currentword]);
                        st.erase(currentword);
                    }
                }
                currentword[i] = original;
            }
        }
    }
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    vector<string> wordlist;
    wordlist.push_back(endWord);
    dfs(beginWord, mp, ans, wordlist, endWord);
    return ans;
}

void dfs(string beginWord, unordered_map<string, int> mp,
         vector<vector<string>> &ans, vector<string> wordList,
         string currentword)
{
    if (currentword == beginWord)
    {
        reverse(wordList.begin(), wordList.end());
        ans.push_back(wordList);
        reverse(wordList.begin(), wordList.end());
        return;
    }
    int steps = mp[currentword];
    for (int i = 0; i < currentword.size(); i++)
    {
        char org = currentword[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (ch != org)
            {
                currentword[i] = ch;
                if (mp.find(currentword) != mp.end())
                {
                    if (mp[currentword] < steps)
                    {
                        wordList.push_back(currentword);
                        dfs(beginWord, mp, ans, wordList, currentword);
                        wordList.pop_back();
                    }
                }
                currentword[i] = org;
            }
        }
    }
    return;
}
vector<vector<string>> findLadders(string beginWord, string endWord,
                                   vector<string> &wordList)
{

    return optimisedsolution(beginWord, endWord, wordList);
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);

    cout << "Shortest transformation sequences:" << endl;
    for (const auto &sequence : result)
    {
        for (const auto &word : sequence)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
