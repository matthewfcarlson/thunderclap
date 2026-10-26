#include "decls/data/platform/xbox/pure3d.h"
// data: gCount_31bcf0 = DAT_004d367c

#include "compat/ptr.h"
extern "C" char DAT_00432578[];
extern void __stdcall ReleaseResource(void*);
extern void __cdecl FreeArray(void*);

class d3dPrimStream {
  public:
    hulk_intptr vtable;
    char pad[0x128];
    void** resources;
};

void __fastcall FUN_0031bcf0(d3dPrimStream* self) {
    self->vtable = ((hulk_intptr)DAT_00432578);
    int i = 0;
    if (DAT_004d367c > 0) {
        do {
            ReleaseResource(self->resources[i]);
            ++i;
        } while (i < DAT_004d367c);
    }
    FreeArray(self->resources);
}
