#include "decls/address.h"
extern "C" char DAT_00424b0c[];
extern "C" char DAT_0048e0e4[];
extern "C" char DAT_0048e100[];
class CSoundVoiceManager {
  public:
    void Init(void*, int);
    int vf;
    char pad4[0x0c];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int a;
    CSoundVoiceManager* Fn(void*, int);
};
CSoundVoiceManager* CSoundVoiceManager::Fn(void* p, int v) {
    Init(p, 3);
    vf = ((int)DAT_00424b0c);
    a = v;
    b18 = FUN_001d04d0((void*)((int)DAT_0048e100));
    b10 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b11 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b12 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    return this;
}