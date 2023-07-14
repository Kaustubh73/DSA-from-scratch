#include <bits/stdc++.h>
using namespace std;

void fft(vector<complex<double>>& a, bool invert)
{
    int n = a.size();
    if (n <= 1)
        return;
    
    vector<complex<double>> a0(n /2), a1(n/2);
    for (int i = 0, j =0 ; i < n; i+=2, ++j)
    {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double angle = 2 * M_PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));
    for (int i = 0 ; i < n /2 ; ++i)
    {
        complex<double> even = a0[i];
        complex<double> odd = w * a1[i];

        a[i] = even + odd;
        a[i + n /2] = even - odd;

        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }

        w *= wn;
    }
}

vector<int> multiplyPolynomials(const vector<int>& p1, const vector<int>& p2) {
    int n = 1;
    while (n < p1.size() + p2.size())
        n <<= 1;
    
    vector<complex<double>> a(n), b(n);
    for (int i = 0 ; i < p1.size() ; ++i)
        a[i] = p1[i];
    for (int i = 0 ; i < p2.size() ; ++i)
        b[i] = p2[i];
    
    fft(a, false);
    fft(b, false);

    for (int i = 0 ; i < n ; ++i)
        a[i] *= b[i];
    
    fft(a, true);

    vector<int> result(n);
    for (int i = 0 ; i < n ; ++i)
        result[i] = round(a[i].real());

    return result;
}

int main() 
{
    vector<int> p1 = {1, 2, 3};  // Polynomial: 1 + 2x + 3x^2
    vector<int> p2 = {4, 5};     // Polynomial: 4 + 5x

    vector<int> product = multiplyPolynomials(p1, p2);

    // Output the resulting polynomial
    for (int i = 0; i < product.size(); ++i) {
        if (product[i])
        {
            cout << product[i];
            if (i < product.size() - 1)
            {
                cout << "x^" << i;
                if (product[i+1])
                    cout << " + ";
            }
                
        }
    }
    cout << endl;

    return 0;
}