#include "decls/address.h"
extern "C" char DAT_00423398[];
class CSPManager {};
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
extern const char s0_1e0130[], s1[], s2[], s3[];
class Target_1e0130 : public Ctor_001d0480 {
  public:
    void* vf;
    char p4[12];
    unsigned char b10, b11, b12;
    char p13[5];
    unsigned char b18;
    char p19[3];
    CSPManager* mgr;
    Target_1e0130(const char*, CSPManager*);
};
Target_1e0130::Target_1e0130(const char* a, CSPManager* c) : Ctor_001d0480(a, 3) {
    vf = (void*)((int)DAT_00423398);
    mgr = c;
    b18 = FUN_001d04d0(s0_1e0130);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
}