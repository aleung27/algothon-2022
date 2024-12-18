#include "bounds.h"
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    string s1 = inf.readString();
    string s2 = inf.readString();

    ensuref(s1.length() == s2.length(), "Length of string unequal");
    for (int i = 0; i < s1.length(); i++) {
        ensuref(s1[i] == '+' || s1[i] == '-',
                "Incorrect symbol in original string");
        ensuref(s2[i] == s1[i] || s2[i] == '?',
                "Incorrect symbol in malformed string");
    }

    inf.readEof();
}