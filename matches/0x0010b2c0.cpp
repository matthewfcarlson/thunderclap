// cl-flags: /O2
#include "decls/data/game/hulkfight/ai.h"

#include "compat/ptr.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_0010b2a0();
extern "C" void __cdecl FUN_0010b2b0();
class List_10b2c0;

class ColorHolder {
  public:
};

struct Context_10b2c0 {
    char pad0[8];
    ColorHolder ch;
    char pad1[0x60 - 8 - 1];
    Context_10b2c0() throw();
};

class List_10b2c0 {
  public:
    void Add(Context_10b2c0* it);
};

class This_10b2c0 {
  public:
    List_10b2c0* GetList();
    This_10b2c0* Build();
};

void* operator new(unsigned int) throw();


extern "C" void __cdecl FUN_00238b60(hulk_intptr a, int b);
extern "C" void __cdecl FUN_00238330(hulk_intptr a, int b);

This_10b2c0* This_10b2c0::Build() {
    List_10b2c0* list = GetList();
    Context_10b2c0* a = new Context_10b2c0();
    ((owners::Target_27b040 *)&(a->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[0]));
    list->Add(a);
    Context_10b2c0* b = new Context_10b2c0();
    ((owners::Target_27b040 *)&(b->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[1]));
    list->Add(b);
    Context_10b2c0* c = new Context_10b2c0();
    ((owners::Target_27b040 *)&(c->ch))->FUN_0027b040((hulk_uintptr)(((float**)&DAT_004a1f60)[2]));
    list->Add(c);
    FUN_00238b60(((hulk_intptr)(void (__cdecl*)())&FUN_0010b2a0), 0);
    FUN_00238330(((hulk_intptr)(void (__cdecl*)())&FUN_0010b2b0), 0);
    return this;
}
