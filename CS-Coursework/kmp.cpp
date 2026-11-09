#include <iostream>
#include <string>
using namespace std;

// LPS (Longest Prefix Suffix) array banane wali function
// pat = pattern, lps[] = array jisme har index ka LPS store hoga
void computeLPS(string pat, int lps[]) {
    int m = pat.length();

    lps[0] = 0;          // pehle character ka LPS hamesha 0 hota hai
    int len = 0;         // current longest prefix-suffix length
    int i = 1;           // pattern ke 2nd character se start

    while (i < m) {
        if (pat[i] == pat[len]) {
            // agar match ho gaya, LPS increase karo
            len++;
            lps[i] = len;
            i++;
        } else {
            // mismatch
            if (len != 0) {
                // peeche wale LPS par jump karo, dobara compare karo
                len = lps[len - 1];
            } else {
                // koi prefix-suffix match nahi
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMP(string text, string pat) {
    int n = text.length();
    int m = pat.length();

    // LPS array dynamic allocate (pattern ki length ke hisaab se)
    int *lps = new int[m];

    // pehle LPS array bana lo
    computeLPS(pat, lps);

    int i = 0;  // index in text
    int j = 0;  // index in pattern

    while (i < n) {

        if (text[i] == pat[j]) {
            // characters match ? dono aage badhao
            i++;
            j++;
        }

        if (j == m) {
            // pattern ka saara match ho gaya
            cout << "Pattern found at index " << (i - j) << endl;
            delete[] lps;
            return;
        }

        // mismatch case
        if (i < n && text[i] != pat[j]) {
            if (j != 0) {
                // pattern ko shift karo using LPS (dobara compare nahi)
                j = lps[j - 1];
            } else {
                // agar j == 0 hai to sirf text aage badhao
                i++;
            }
        }
    }

    cout << "Pattern not found." << endl;
    delete[] lps;
}

int main() {
    string text = "ABABABABCABABABA";
    string pat  = "ABABA";

    KMP(text, pat);

    return 0;
}
