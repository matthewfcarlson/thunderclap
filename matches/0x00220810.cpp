#include "decls/data/engine/unknown.h"
// data: msg = DAT_004271d4

class A_220810 {
  public:
    void* p0;
    int pad[2];
    int m3;
    int pad2[5];
    int m9;
};
void err(int, const char*);
void f(A_220810* a, int n) {
    int x = a->m9 + n;
    if (x > (int)*(unsigned char*)((char*)a->p0 + 0x47)) {
        if (x >= 250)
            err(a->m3, DAT_004271d4);
        *(unsigned char*)((char*)a->p0 + 0x47) = (unsigned char)x;
    }
}