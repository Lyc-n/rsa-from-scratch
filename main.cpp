#include <iostream>
#include <vector>
#include <string>
using namespace std;

// fungsi gcd / fpb
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// mencari modular inverse
int modInverse(int e, int phi){
    for(int d = 1; d < phi; d++){
        if((d * e) % phi == 1){
            return d;
        }
    }
    return 1;
}

// fungsi perpangkatan modulo
long long rsa(long long base, long long exp, long long mod){
    long long result = 1;

    for(int i = 0; i < exp; i++){
        result = (result * base) % mod;
    }

    return result;
}

int main(){

    // bilangan prima
    int p = 17;
    int q = 11;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // mencari e
    int e = 2;
    while(e < phi){
        if(gcd(e, phi) == 1)
            break;
        e++;
    }

    // mencari d
    int d = modInverse(e, phi);

    cout << "Public Key (e,n): (" << e << "," << n << ")" << endl;
    cout << "Private Key (d,n): (" << d << "," << n << ")" << endl;

    string message;
    cout << "\nMasukkan plaintext: ";
    getline(cin, message);

    vector<long long> encrypted;

    cout << "\nASCII tiap karakter:\n";

    // ENKRIPSI
    for(char c : message){
        int m = (int)c;
        cout << c << " -> " << m << endl;

        long long cipher = rsa(m, e, n);
        encrypted.push_back(cipher);
    }

    // CHIPER TEXT
    cout << "\nCiphertext:\n";
    for(long long c : encrypted){
        cout << c;
    }

    cout << endl;

    // DEKRIPSI
    cout << "\nHasil Dekripsi:\n";

    string decrypted = "";

    for(long long c : encrypted){
        long long m = rsa(c, d, n);
        decrypted += (char)m;
    }

    cout << decrypted << endl;

    return 0;
}