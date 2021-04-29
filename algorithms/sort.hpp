#ifndef ads_sort_hpp
#define ads_sort_hpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "math.hpp"

// sorting algorithms of integer arrays

namespace ads {
    void create(int t[], int n, int p, int q)
    {
        srand(time(NULL));
        for (int i = 0; i < n; ++i)
            t[i] = rand() % p + q;
    }

    bool if_sorted(int t[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if(t[j] < t[i]) // ascending
                    return false;
            }
        }
        return true;
    }

    void print(int t[], int n, std::ostream& stream=std::cout)
    {
        for (int i = 0; i < n; ++i)
            stream << t[i] << " ";
        stream << std::endl;
    }

    void bubble(int t[], int n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < n-i; ++j)
                if (t[j-1] > t[j]) // ascending
                    swap(t[j-1], t[j]);
    }

    void bubble_optimized(int t[], int n)
    {
        bool p;
        do
        {
            p = true;
            for (int i = 1; i < n; ++i)
            {
                if (t[i-1] > t[i]) // ascending
                {
                    swap(t[i-1], t[i]);
                    p = false;
                }
            }
        } while (!p);
    }

    void selection(int t[], int n)
    {
        int m;
        for (int j = 0; j < n-1; ++j)
        {
            m = j;
            for (int i = j+1; i < n; ++i)
                if (t[i] < t[m])
                    m = i;
            swap(t[j], t[m]);
        }
    }

    void insertion(int t[], int n)
    {
        int m, j;
        for (int i = 1; i < n; ++i)
        {
            m = t[i];
            for (j = i-1; j >= 0; --j)
            {
                if (m < t[j])
                    t[j+1] = t[j];
                else
                    break;
            }
            t[j+1] = m;
        }
    }

    void quick(int t[], int l, int p)
    // ascending, l - first index, p - last index
    {
        int v = t[(l+p)/2], i = l, j = p;
        do
        {
            while (t[i] < v)
                i++;
            while (t[j] > v)
                j--;
            if (i <= j)
            {
                swap(t[i], t[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (j > l)
            quick(t, l, j);
        if (i < p)
            quick(t, i, p);
    }

    void insertion_with_binary_search(int t[], int n, int l, int p)
    // ascending, l - first index, p - last index
    {
        int i, x;
        for (int j = n-2; j >= 0; --j)
        {
            x = t[j];
            l = j;
            p = n;
            while (p-l > 1)
            {
                i = (l+p) / 2;
                if (x <= t[i])
                    p = i;
                else
                    l = i;
            }
            for (i = j; i < l; ++i)
                t[i] = t[i+1];
            t[p] = x;
        }
    }

    void counting(int t[], int n, const int M)
    // M - max
    {
        int g[M];
        for (int i = 0; i < M; ++i)
            g[i] = 0;
        for (int i = 0; i < n; ++i)
            g[t[i]]++;
        int k = 0;
        for (int i = 1; i < M; ++i)
        {
            for (int j = 0; j < g[i]; ++j)
            {
                t[k] = i;
                k++;
            }
        }
    }

    void heap(int t[], int n)
    {
        int j;
        for (int k = n; k > 1; --k)
        {
            for (int i = 0; i < k; ++i)
            {
                j = 1;
                while ((i/pow(2, j)) > 0) {
                    if (t[i/pow(2, j)-1] < t[i/pow(2, j-1)-1]) // ascending
                        swap(t[i/pow(2, j)-1], t[i/pow(2, j-1)-1]);
                    ++j;
                }
            }
            swap(t[0], t[k-1]);
        }
        swap(t[1], t[2]);
    }

    void merge(int t[], int l, int p) {
    // l - first index, p - last index
        int q = 0;
        if (l < p) {
            q = (l+p) / 2;
            merge(t, l, q);
            merge(t, q+1, p);
            for (int i = l; i < p; ++i) {
                quick(t, l, p);
            }
        }
    }
}

#endif /* ads_sort_hpp */