#include "gen/om.h"

extern const char TypeName[];
void __cdecl RegisterType(const char*, void*, void*);

void om::Type::vfunc_0() {
    RegisterType(TypeName, this, (char*)this + 0x30);
}
