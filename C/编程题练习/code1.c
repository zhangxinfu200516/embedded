#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    // 素数筛，isPrime[i] = 1 表示 i 是素数
    int *isPrime = (int*)malloc((N + 1) * sizeof(int));
    for (int i = 0; i <= N; ++i) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // 收集所有不超过 N 的素数
    int *primes = (int*)malloc((N + 1) * sizeof(int));
    int primeCnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) primes[primeCnt++] = i;
    }

    long long ans = 0;
    int limit = (int)sqrt(2.0 * N);   // 满足 C^2 ≤ 2N 的最大 C
    for (int i = 0; i < primeCnt; ++i) {
        int c = primes[i];
        if (c > limit) break;          // 更大的 C 使得 C^2 > 2N，不可能有解
        long long S = (long long)c * c;
        // 枚举所有素数 A，寻找 B = S - A 也是素数且不超过 N
        for (int j = 0; j < primeCnt; ++j) {
            int a = primes[j];
            if (a > S) break;          // a 继续增大会导致 b < 2，跳过
            int b = S - a;
            if (b >= 2 && b <= N && isPrime[b]) {
                ++ans;
            }
        }
    }

    printf("%lld\n", ans);

    free(isPrime);
    free(primes);
    return 0;
}