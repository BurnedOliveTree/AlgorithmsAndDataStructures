#include "sort.cpp"

using namespace ads;

int main()
{
    const int n=10, p=90, q=10;
    int t[n];
    create(t, n, p, q);
    print(t, n);
    merge(t, 0, n-1);
    print(t, n);
    return 0;
}