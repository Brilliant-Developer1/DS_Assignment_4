// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{

    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);

    queue<Node *> que;
    if (root)
        que.push(root);
    while (!que.empty())
    {

        Node *f = que.front();
        que.pop();

        int L, R;
        cin >> L >> R;
        Node *left;
        Node *right;

        if (L == -1)
            left = NULL;
        else
            left = new Node(L);

        if (R == -1)
            right = NULL;
        else
            right = new Node(R);

        f->left = left;
        f->right = right;

        if (f->left)
            que.push(f->left);
        if (f->right)
            que.push(f->right);
    }

    return root;
}

void preorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        ans.push_back(root->value);

    preorder(root->left, ans);
    preorder(root->right, ans);
}
int main()
{
    Node *root = input_tree();

    vector<int> ans;

    preorder(root, ans);
    // manual impliment
    int mx = ans[0];
    int mn = ans[0];
    int size = ans.size();

    for (int i = 1; i < size; i++)
    {
        if (ans[i] > mx)
            mx = ans[i];
        if (ans[i] < mn)
            mn = ans[i];
    }
    cout << mx << " " << mn;

    // Using Function
    // auto max = max_element(ans.begin(), ans.end());
    // auto min = min_element(ans.begin(), ans.end());
    // cout << *max << " " << *min;

    return 0;
}

/*
input
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

output
60 40
*/