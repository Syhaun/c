#include <stdio.h>

long long factorial(int n) {
if (n == 0) {
return 1;
}
long long res = 1;
for (int i = 1; i <= n; i++) {
res *= i;
}
return res;
}

long long doubleFactorial(int n) {
if (n <= 1) {
return 1;
}
long long res = 1;
for (int i = n; i >= 1; i -= 2) {
res *= i;
}
return res;
}

int main() {
int T;
scanf("%d", &T);
while (T--) {
int n;
scanf("%d", &n);
long long res = 2 * factorial(n) / doubleFactorial(n);
printf("%lld\n", res);
}
return 0;
}
