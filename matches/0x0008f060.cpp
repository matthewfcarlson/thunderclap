#include "compat/ptr.h"
extern "C" unsigned int strlen(const char*);
class Hash {
  public:
    int Calc(const char* s);
};
int Hash::Calc(const char* s) {
    hulk_intptr n = strlen(s);
    hulk_intptr sum = n;
    int product = 1;
    for (int i = 0; i < n; ++i) {
        int v = (signed char)s[i];
        sum += v;
        product *= v;
    }
    return sum + product;
}