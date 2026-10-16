// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00240eb0 @ 0x00240eb0
// FUN_00240eb0 @ 0x00240eb0
#include "decls/data/platform/xbox/unknown.h"

struct AudioState { char pad0[0x14]; int first; char pad1[4]; int second; char pad2[0x14]; void* sound; char pad3[0x74]; int handle; };
void __cdecl FUN_00257df0(int*);
void __cdecl FUN_0024c760();
namespace DSOUND { void __stdcall IDirectSound_Release(void*); }
struct Temp_240eb0 { char data[0x40]; int FUN_002584d0(int*, int*, int, int); void FUN_002580e0(); };
void __cdecl FUN_00247550(int, AudioState*);
void FUN_00240eb0() {
    FUN_00257df0(&(*(AudioState**)&DAT_004e5ce0)->first);
    FUN_00257df0(&(*(AudioState**)&DAT_004e5ce0)->second);
    FUN_0024c760();
    DSOUND::IDirectSound_Release((*(AudioState**)&DAT_004e5ce0)->sound);
    struct Frame { int pair0[2]; int pair1[2]; Temp_240eb0 temp; } fr;
    fr.pair0[0] = (*(int*)&DAT_004e5ce8); fr.pair0[1] = (*(int*)((char*)&DAT_004e5ce8 + 4));
    fr.pair1[0] = (*(int*)((char*)&DAT_004e5ce8 + 8)); fr.pair1[1] = (*(int*)((char*)&DAT_004e5ce8 + 12));
    AudioState* state = (*(AudioState**)&DAT_004e5ce0);
    int result = fr.temp.FUN_002584d0(fr.pair1, fr.pair0, state->handle, 4);
    FUN_00247550(result, state);
    fr.temp.FUN_002580e0();
    (*(AudioState**)&DAT_004e5ce0) = 0;
}
