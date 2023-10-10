#include <stdio.h>
#include <map>

using namespace std;

int n, q;
map<pair<int, int>, int> m;

int main() {
    scanf("%d%d", &n, &q);
    while (q--) {
        int op, i, j, k;
        scanf("%d%d%d", &op, &i, &j);
        if (op == 1) {
            scanf("%d", &k);
            m[make_pair(i, j)] = k;
        } else {
            printf("%d\n", m[make_pair(i, j)]);
        }
    }
    return 0;
}

