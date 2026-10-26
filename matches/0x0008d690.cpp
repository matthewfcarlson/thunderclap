#include "decls/data/game/unknown.h"
// data: obj = DAT_004dd780, ready = DAT_004dd778

extern "C" void _ReadWriteBarrier();
class Obj {
  public:
    void Init();
};
void __cdecl prep();
void __cdecl stage(int);
int __cdecl first();
void* __cdecl second(int, int);
void* __cdecl FUN_0008d690(int x) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        prep();
        (*(Obj*)&DAT_004dd780).Init();
        stage(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return second(first(), x);
}