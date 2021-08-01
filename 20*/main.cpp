/*
 * Return the nth fibonacci number.
 * F0 = 0 and F1 = 1
 * For the purpose of this question, the first Fibonacci number is F0; therefore, getNthFib(1) is equal to F0.
 */

using namespace std;

int getNthFib(int n) {
    int first = 0, second = 1;
    n--;
    if (n == 0 || n == 1)
        return n;

    while (--n) {
        int next = first + second;
        first = second;
        second = next;
    }

    return second;
}
