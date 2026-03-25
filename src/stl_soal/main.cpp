#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> c(n);

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    map<long long, vector<long long>> paket;
    for (int i = 0; i < n; i++) {
        paket[x[i]].push_back(c[i]);
    }

    long long jawab = 0;
    map<long long, int> pernah;

    for (auto it = paket.begin(); it != paket.end(); ++it) {
        for (long long kategori : it->second) {
            if (pernah[kategori] == 0) {
                pernah[kategori] = 1;
                jawab++;
            }
        }
    }

    cout << jawab << '\n';
    return 0;
}
