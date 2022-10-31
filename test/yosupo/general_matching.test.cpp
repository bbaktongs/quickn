#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include "../../graph/general_matching.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    GeneralMatching gm(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        gm.add_edge(u, v);
    }
    int ans = gm.maximum_cardinality_matching();
    cout << ans << "\n";
    for (auto [a, b] : gm.get_matches()) {
        cout << a << " " << b << "\n";
    }
}
