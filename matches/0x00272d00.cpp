#include "decls/data/engine/core.h"

extern "C" void _ReadWriteBarrier();
extern void* vt0_272d00[];
extern void* vt4[];
extern void* vtc[];
extern void* vtD_272d00[];
extern void* vtD4[];
extern void* vtDc[];
void Hook();
class Sub_272d00 {
  public:
    void Init();
};
class Drive {
  public:
    void* vptr;
    void* v4;
    int m8;
    void* vc;
    int m10;
    Sub_272d00 s14;
    char pad[0x23];
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    char m54;
    int m58;
    char m5c;
    char m5d;
    char pad2[0x56];
    int mb4;
    int mb8;
    Drive();
};
Drive::Drive() {
    vptr = vt0_272d00;
    v4 = vt4;
    m8 = DAT_004cdbb0;
    Hook();
    vc = vtc;
    _ReadWriteBarrier();
    m10 = 1;
    _ReadWriteBarrier();
    vptr = vtD_272d00;
    v4 = vtD4;
    vc = vtDc;
    s14.Init();
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
    m5c = 1;
    m5d = 0;
    mb4 = 3;
    mb8 = 0;
    Hook();
}
