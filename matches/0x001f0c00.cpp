#include "decls/address.h"
extern "C" char DAT_004246ec[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0049cad8[];
class Base_1f0c00 {
  public:
    Base_1f0c00(char*, int);
};
class CSoundSystem : public Base_1f0c00 {
  public:
    char pad0[0x10];
    unsigned char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    unsigned char b18;
    char pad19[3];
    void* p1c;
    CSoundSystem(char*, void*);
};
CSoundSystem::CSoundSystem(char* a, void* c) : Base_1f0c00(a, 6) {
    *(unsigned int*)this = ((int)DAT_004246ec);
    p1c = c;
    b18 = FUN_001d04d0((void*)((int)DAT_0048e100));
    b10 = FUN_001d04d0((void*)((int)DAT_0049cad8));
    b11 = FUN_001d04d0((void*)((int)DAT_0049cad8));
    b12 = FUN_001d04d0((void*)((int)DAT_0048e128));
    b13 = FUN_001d04d0((void*)((int)DAT_0048e128));
    b14 = FUN_001d04d0((void*)((int)DAT_0048e128));
    b15 = FUN_001d04d0((void*)((int)DAT_0048e128));
}