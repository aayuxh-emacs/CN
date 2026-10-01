#include <iostream>
using namespace std;

#define N 4
#define INF 999

int main() {
    int cost[N][N], dist[N][N], nextHop[N][N];

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = cost[i][j];

            if (i == j)
                nextHop[i][j] = i;
            else if (cost[i][j] != INF)
                nextHop[i][j] = j;
            else
                nextHop[i][j] = -1;
        }
    }

    int updated;

    do {
        updated = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (dist[i][k] != INF &&
                        dist[k][j] != INF &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {

                        dist[i][j] = dist[i][k] + dist[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    for (int i = 0; i < N; i++) {
        cout << "\nRouter " << i + 1 << ":\n";
        cout << "Destination\tCost\tNext Hop\n";

        for (int j = 0; j < N; j++) {
            cout << j + 1 << "\t\t";

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";

            if (nextHop[i][j] == -1)
                cout << "-\n";
            else
                cout << nextHop[i][j] + 1 << "\n";
        }
    }

    return 0;
}
