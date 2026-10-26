#include "decls/data/engine/core.h"
// data: g_last = DAT_004cdbb0

extern char vtA[], vtB[], vtC[], vtD[], vtE[], vtF[];
void A(void*);
void B(void*);
void C(void*);
void D(void*);
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
    B(&pad[0x18 - 0x10]);
    C(&pad[0x18 - 0x10]);
    D(&a);
    D(&b);
    int** q = &vc;
    *q = (int*)vtD;
    DAT_004cdbb0 = f8;
    int** q2 = &v4;
    *q2 = (int*)vtE;
    v0 = (int*)vtF;
}
