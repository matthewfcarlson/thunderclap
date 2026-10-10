// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00240eb0 @ 0x00240eb0
struct AudioState { char pad0[0x14]; int first; char pad1[4]; int second; char pad2[0x14]; void* sound; char pad3[0x74]; int handle; };
extern AudioState* DAT_004e5ce0;
extern int DAT_004e5ce8;
extern int DAT_004e5cec;
extern int DAT_004e5cf0;
extern int DAT_004e5cf4;
void __cdecl FUN_00257df0(int*);
void __cdecl FUN_0024c760();
namespace DSOUND { void __stdcall IDirectSound_Release(void*); }
struct Temp { int FUN_002584d0(int*, int*, int, int); void FUN_002580e0(); };
void __cdecl FUN_00247550(int, AudioState*);
void FUN_00240eb0() {
    FUN_00257df0(&DAT_004e5ce0->first);
    FUN_00257df0(&DAT_004e5ce0->second);
    FUN_0024c760();
    DSOUND::IDirectSound_Release(DAT_004e5ce0->sound);
    int pair0[2] = { DAT_004e5ce8, DAT_004e5cec };
    int pair1[2] = { DAT_004e5cf0, DAT_004e5cf4 };
    Temp temp;
    AudioState* state = DAT_004e5ce0;
    int result = temp.FUN_002584d0(pair1, pair0, state->handle, 4);
    FUN_00247550(result, state);
    temp.FUN_002580e0();
    DAT_004e5ce0 = 0;
}