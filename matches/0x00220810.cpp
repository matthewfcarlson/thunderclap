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
extern "C" void FUN_00220810(void * a, int n) {
    int x = ((A_220810 *)a)->m9 + n;
    if (x > (int)*(unsigned char*)((char*)((A_220810 *)a)->p0 + 0x47)) {
        if (x >= 250)
            err(((A_220810 *)a)->m3, DAT_004271d4);
        *(unsigned char*)((char*)((A_220810 *)a)->p0 + 0x47) = (unsigned char)x;
    }
}