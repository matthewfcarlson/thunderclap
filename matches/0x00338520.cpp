#include "decls/data/engine/movie.h"

void __cdecl thunk_FUN_00267090(void*);
class Obj_338520 {
  public:
    int* vptr;
    char pad[0x10];
    void* m;
    void Fn();
};
void Obj_338520::Fn() {
    vptr = ((int*)&DAT_00434630);
    thunk_FUN_00267090(m);
}
