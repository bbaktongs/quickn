#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../data-structure/binary_trie.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BinaryTrie<int> bt;
    int Q;
    cin >> Q;
    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            if (!bt.count(x)) bt.insert(x);
        }
        if (t == 1) {
            bt.erase(x);
        }
        if (t == 2) {
            cout << bt.min_element(x) << "\n";
        }
    }
}