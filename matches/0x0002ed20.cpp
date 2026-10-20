#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_003f410c[];
extern "C" char DAT_003f442c[];
struct CActorManager {};
extern char GetName(const char*);
class Obj_2ed20 {
  public:
    int vt;
    char pad4[0x0c];
    char b10;
    char pad11[7];
    char b18;
    char pad19[3];
    CActorManager* p1c;
    void* p20;
    void Init(const char*, int);
    Obj_2ed20(const char*, void*, CActorManager*);
};
Obj_2ed20::Obj_2ed20(const char* arg, void* p, CActorManager* cm) {
    Init(arg, 1);
    vt = ((hulk_intptr)DAT_003f410c);
    p1c = cm;
    b18 = GetName((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = GetName((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    vt = ((hulk_intptr)DAT_003f442c);
    p20 = p;
}