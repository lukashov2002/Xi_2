#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cassert>
#include <map>
#include <ctime>

using namespace std;


int _RANGE_ = 51;

long double get_V(int const &n, int const &RANGE) {
    vector<long long> count(RANGE, 0);

    for (long long i = 0; i < n; i = i + 1) {
        int t = rand() % RANGE;
        count[t] += 1;
    }
    /*for (int i = 0; i < RANGE; ++i) {
        cout << i << ": " << count[i] << endl;
    }*/
    long double V = 0;
    for (auto &x:count) {
        V += ((long double) x - n / RANGE) * ((long double) x - n / RANGE) / (n / RANGE);
    }
    return V;
}

int main() {
    srand(time(0));
    long long n;
    cout << "Enter n:";
    cin >> n;
    cout << "-----------------------------------------------------";
    long double mid_V = 0;
    cout << "\n0 - 97:\n";
    for (int i = 0; i < 10; ++i) {
        auto t = get_V(n, 97);
        mid_V += t / 10.0;
        cout << t << "  ";
    }
    cout << "\n0 - 50:\n";
    mid_V = 0;
    for (int i = 0; i < 10; ++i) {
        auto t = get_V(n, 51);
        mid_V += t / 10.0;
        cout << t << "  ";
    }
    cout << "\n0 - 100:\n";
    mid_V = 0;
    for (int i = 0; i < 10; ++i) {
        auto t = get_V(n, 101);
        mid_V += t / 10.0;
        cout << t << "  ";
    }

    cout << "\n-----------------------------------------------------\n";

    mid_V = 0;
    for (int i = 0; i < 100; ++i) {
        auto t = get_V(n, 31);
        mid_V += t;
    }
    cout << "mid for [0; 30]: " << mid_V / 100.0 << endl;

    mid_V = 0;
    for (int i = 0; i < 100; ++i) {
        auto t = get_V(n, 51);
        mid_V += t;
    }
    cout << "mid for [0; 50]: " << mid_V / 100.0 << endl;

    mid_V = 0;
    for (int i = 0; i < 100; ++i) {
        auto t = get_V(n, 101);
        mid_V += t;
    }
    cout << "mid for [0; 100]: " << mid_V / 100.0;
    return 0;
}
