#include <iostream>

#define INF_MIN -2147483648
#define INF_MAX 2147483647
#define PRECISION 0.00001

namespace ads {
    void swap(int &a, int &b)
    {
        int x = a;
        a = b;
        b = x;
    }

    int abs(int a)
    {
        if(a < 0)
            return -a;
        return a;
    }

    int pow(int a, int n)
    // exponentiating by squaring algorithm
    {
        if(n == 0)
            return 1;
        if(n%2 != 0)
            return a * pow(a, n-1);
        return pow(a, n/2) * pow(a, n/2);
    }

    double sqrt(int a)
    // findind square root with Newton–Raphson method
    {
        double x = a / 2;
        while(abs(x - a/x) > PRECISION)
        {
            x = (x - a/x) / 2;
            if(x * x == a)
                return x;
        }
        return x;
    }

    int max(int t[], int n)
    // n is the size of array t
    {
        int m=-256;
        for (int i=0; i<n; ++i)
            if (t[i] > m)
                m = t[i];
        return m;
    }

    int min(int t[], int n)
    // n is the size of array t
    {
        int m = INF_MIN;
        for (int i = 0; i < n; ++i)
            if (t[i] < m)
                m = t[i];
        return m;
    }

    int min_max(int t[], int n, int &M, int &m)
    // n is the size of array t
    {
        M = INF_MIN;
        m = INF_MAX;
        for (int i=0; i<n; i++)
        {
            if (t[i] > M)
                M = t[i];
            else
                if (t[i] < m)
                    m = t[i];
        }
        return M;
    }

    void factorization(int a, std::ostream& stream=std::cout)
    {
        while(a%2 == 0)
        {
            stream << 2 << " ";
            a /= 2;
        }
        int i = 3;
        while(a != 1)
        {
            while(a%i == 0)
            {
                stream << i << " ";
                a /= i;
            }
            i += 2;
        }
    }

    bool if_perfect_number(int a)
    {
        int b = 0;
        for (int i = 1; i < a; ++i)
        {
            if (a%i == 0)
                b += i;
        }
        return b == a;
    }

    void divisors(int a, std::ostream& stream=std::cout)
    {
        int half = a/2;
        stream << 1 << " ";
        for (int i = 2; i <= half; ++i)
            if (a%i == 0)
                stream << i << " ";
        stream << a;
    }

    int GCD_slow(int a, int b)
    // the Greatest Common Divisor by Euclidean subtraction algorithm
    {
        while (a != b)
        {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        return a;
    }

    int GCD(int a, int b)
    // the Greatest Common Divisor by Euclidean division algorithm
    {
        while (b != 0)
        {
            a = a%b;
            swap(a,b);
        }
        return a;
    }

    int LCM_slow(int a, int b)
    // the Least Common Multiciple
    {
        int n = 1, d = 2;
        while(d <= a && d <= b)
        {
            if (a%d == 0 && b%d == 0)
            {
                a /= d;
                b /= d;
                n *= d;
            }
            else
                d++;
        }
        return n;
    }

    int LCM(int a, int b)
    // the Least Common Multiciple by Euclidean algorithm
    {
        return a / GCD(a,b) * b;
    }


    void shorten_fractions(int& numerator, int& denominator)
    {
        int gcd = GCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    void add_fractions(int& num_a, int& den_a, int num_b, int den_b)
    {
        int n;
        n = GCD(num_a, den_a);
        num_a /= n;
        den_a /= n;
        n = GCD(num_b, den_b);
        num_b /= n;
        den_b /= n;
        n = GCD(den_a, den_b);
        num_a = (num_a * den_b + num_b * den_a) / n;
        den_a = den_a / n * den_b;
        shorten_fractions(num_a, den_a);
    }

    bool if_prime(int n)
    {
        int root = (int)sqrt(n);
        if(n == 1)
            return false;
        if(n == 2)
            return true;
        if(n%2 == 0)
            return false;
        for (int i = 3; i <= root; i += 2)
        {
            if (n%i == 0)
                return false;
        }
        return true;
    }

    void smaller_primes(int a, std::ostream& stream=std::cout)
    // prints all prime numbers smaller than a
    {
        int k;
        for (int j = 2; j <= a; ++j)
        {
            k = 0;
            for (int i = j; i > 0; --i)
            {
                if (j%i == 0)
                    k += i;
            }
            if(k == j+1)
                stream << j << " ";
        }
    }

    bool if_triangle(int a, int b, int c)
    // check if given three numbers can be the length of the side of the triangle
    {
        if (a+b > c)
            if (a+c > b)
                if (b+c > a)
                    return true;
        return false;
    }

    double f(int A, int B, int C, int D, double x)
    // value of polymonial by Horner's scheme; 3rd degree polymonial; Ax^3+Bx^2+Cx+D
    {
        return ((A*x+B)*x+C)*x+D;
    }

    double find_root(int a, int b, int A, int B, int C, int D)
    // find root by bisection method
    {
        if(f(A, B, C, D, a) == 0)
            return a;
        if(f(A, B, C, D, b) == 0)
            return b;
        double s;
        while(b-a > PRECISION)
        {
            s = (a+b) / 2;
            if(f(A, B, C, D, s) == 0)
                return s;
            if(f(A, B, C, D, a) * f(A, B, C, D, s) < 0)
                b = s;
            else
                a = s;
        }
        return (a+b) / 2;
    }

    int digits_amount(int a)
    {
        int n = 0;
        while(a > 0) {
            n++;
            a /= 10;
        }
        return n;
    }

    int digits_sum(int a)
    {
        int result = 0;
        while(a > 0)
        {
            result += (a%10);
            a /= 10;
        }
        return result;
    }

    int digits_sum(std::string a)
    {
        int n = a.size(), result = 0;
        for (int i = 0; i < n; ++i)
        {
            result += a[i] - 48;
        }
        return result;
    }

    std::string sum(std::string a, std::string b)
    {
        std::string c;
        int na = a.size(), nb = b.size();
        while (na > nb)
        {
            b = '0' + b;
            nb++;
        }
        while (nb > na)
        {
            a = '0' + a;
            na++;
        }
        c = a;
        for (int i = na-1; i >= 0; --i)
        {
            c[i] = a[i] + b[i] - 48;
            if (a[i] + b[i] - 48 > '9')
            {
                a[i-1] += 1;
                c[i] = c[i] - 10;
                if (i==0)
                {
                    c = '0' + c;
                    c[0] += 1;
                }
            }
        }
        return c;
    }

    long long any_to_dec(std::string a, int b)
    // b - base
    {
        int n = a.size();
        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result = (a[i]<'A')?a[i]-'0'+result:a[i]+10-'A'+result;
            result *= b;
        }
        return result / b;
    }

    std::string dec_to_any(int n, int b)
    // b - base
    {
        std::string result = "";
        int d;
        while (n > 0)
        {
            d = n%b;
            result = (d<10)?(char)(d+'0')+result:(char)(d+'A'-10)+result;
            n = n/b;
        }
        return result;
    }

    int U1_to_dec(std::string U1)
    {
        int n = 0;
        char z = U1[0];
        if(z == '1')
        {
            for (int i = 1; i < U1.length(); ++i)
            {
                if(U1[i] == '0')
                    U1[i] = '1';
                else
                    U1[i] = '0';
            }
        }
        for (int i = 1; i < U1.length(); ++i)
            n = n * 2 + U1[i] - 48;
        if(z == '1')
            return -n;
        return n;
    }
}


int main()
{
    int t[4] = {3, 45, 2, 4};
    std::cout << ads::max(t, 4) << std::endl;
    return 0;
}
