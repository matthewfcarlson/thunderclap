#include "decls/data/game/unknown.h"
// data: obj = DAT_004dd780, ready = DAT_004dd778

extern "C" void _ReadWriteBarrier();
class Obj {
  public:
    void Init();
};
extern "C" void __cdecl FUN_00267a50();
extern "C" void __cdecl FUN_0026da80(int);
int __cdecl first();
void* __cdecl second(int, int);
extern "C" void* __cdecl FUN_0008d690(int x) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Obj*)&DAT_004dd780).Init();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return second(first(), x);
}