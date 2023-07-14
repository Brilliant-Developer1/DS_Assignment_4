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

int sum(Node *root)
{
    if (!root)
        return 0;
    int sm = root->value;

    sm = sm + sum(root->left);
    sm = sm + sum(root->right);
    return sm;
}
int main()
{
    Node *root = input_tree();
    int ans = sum(root);
    cout << ans;

    return 0;
}

/*
input
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1

output
20 30
*/