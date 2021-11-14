#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using yx = pair<int, int>;
using vi = vector<int>;
using Field = vector<vi>;

int solve(Field& f, int N, int M) {
    vi dx{ 0, -1, 0, 1 };
    vi dy{ -1, 0, 1, 0 };

    queue<pair<yx, int>> q{};

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (1 == f[i][j]) {
                q.push({ { i, j }, 0 });
            }
        }
    }

    int day{ 0 };
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (day < p.second)
            day = p.second;

        for (int i = 0; i < 4; ++i)
        {
            auto cx = p.first.second + dx[i];
            auto cy = p.first.first + dy[i];

            if (cx < 0 || M <= cx) continue;
            if (cy < 0 || N <= cy) continue;

            if (0 == f[cy][cx]) {
                f[cy][cx] = 1;
                q.push({ { cy, cx }, p.second + 1 });
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (0 == f[i][j]) {
                return -1;
            }
        }
    }

    return day;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    Field f(N, vi(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int t;
            cin >> t;

            f[i][j] = t;
        }
    }

    cout << solve(f, N, M);

    return 0;
}