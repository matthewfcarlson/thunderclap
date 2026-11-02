#include "decls/data/engine/core.h"
// data: g_last = DAT_004cdbb0

extern char vtA[], vtB[], vtC[], vtD[], vtE[], vtF[];
void A(void*);
extern "C" void FUN_0026d780(void*);
extern "C" void FUN_0026dad0(void*);
extern "C" void FUN_0026d880(void*);
struct DriveThread_272f00 {
    int* v0;
    int* v4;
    int f8;
    int* vc;
    char pad[0x64 - 0x10];
    char flag;
    char pad2[3];
    int a[1];
    char pad3[0x84 - 0x6c];
    int b[1];
    void Fn();
};
void DriveThread_272f00::Fn() {
    v0 = (int*)vtA;
    v4 = (int*)vtB;
    vc = (int*)vtC;
    flag = 1;
    A(&a);
    FUN_0026d780(&pad[0x18 - 0x10]);
    FUN_0026dad0(&pad[0x18 - 0x10]);
    FUN_0026d880(&a);
    FUN_0026d880(&b);
    int** q = &vc;
    *q = (int*)vtD;
    DAT_004cdbb0 = f8;
    int** q2 = &v4;
    *q2 = (int*)vtE;
    v0 = (int*)vtF;
}
