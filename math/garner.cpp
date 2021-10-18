#pragma once
#include <vector>
#include "extgcd.cpp"

long long garner(const std::vector<long long>& b, std::vector<long long> m, long long mod) {
    m.push_back(mod);
    int n = m.size();
    long long ans = 0;
    std::vector<long long> coeffs(n, 1);
    std::vector<long long> consts(n, 0);
    for (int k = 0; k < n; ++k) {
        long long t = (b[k] - consts[k]) * mod_inv(coeffs[k], m[k]) % m[k];
        if (t < 0) t += m[k];
        for (int i = k + 1; i < n; ++i) {
            consts[i] = (consts[i] + t * coeffs[i]) % m[i];
            coeffs[i] = coeffs[i] * m[k] % m[i];
        }
    }
    return consts.back();
}