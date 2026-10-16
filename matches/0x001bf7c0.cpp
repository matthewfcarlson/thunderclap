#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00421520[];
class CSubtitleManager {
  public:
    int vptr;
    char pad04[0x0c];
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int m1c;
    void Init(const char*, int);
    CSubtitleManager* Setup(const char*, const char*);
};
CSubtitleManager* CSubtitleManager::Setup(const char* a, const char* b) {
    Init(a, 3);
    vptr = ((int)DAT_00421520);
    m1c = (int)b;
    b18 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((const char*)((int)((char*)&DAT_0048e128)));
    return this;
}