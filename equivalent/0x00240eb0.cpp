// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00240eb0 @ 0x00240eb0
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
struct Temp { char data[0x40]; int FUN_002584d0(int*, int*, int, int); void FUN_002580e0(); };
void __cdecl FUN_00247550(int, AudioState*);
void FUN_00240eb0() {
    FUN_00257df0(&DAT_004e5ce0->first);
    FUN_00257df0(&DAT_004e5ce0->second);
    FUN_0024c760();
    DSOUND::IDirectSound_Release(DAT_004e5ce0->sound);
    struct Frame { int pair0[2]; int pair1[2]; Temp temp; } fr;
    fr.pair0[0] = DAT_004e5ce8; fr.pair0[1] = DAT_004e5cec;
    fr.pair1[0] = DAT_004e5cf0; fr.pair1[1] = DAT_004e5cf4;
    AudioState* state = DAT_004e5ce0;
    int result = fr.temp.FUN_002584d0(fr.pair1, fr.pair0, state->handle, 4);
    FUN_00247550(result, state);
    fr.temp.FUN_002580e0();
    DAT_004e5ce0 = 0;
}
