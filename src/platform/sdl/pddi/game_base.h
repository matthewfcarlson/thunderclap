// The portable pddi bases' own functions, for the native image only (HULK_PDDI_GAME).
//
// The game's d3d classes inherit these slots from pddiBaseContext, pddiBaseShader, pddiTexture, pddiPrimBuffer and
// pddiDevice, whose code is engine code in the tree (src/engine/pure3d/...). Our classes forward those slots to it:
// each member is named FUN_<XBE address> with the slot's signature, called thiscall on our object, and the native
// link binds the name to the tree's definition at that address (build/g0/LINK.md), as it does for the tree's own
// address-named references. Never defined here.
#pragma once

#if HULK_PDDI_GAME
namespace hulk {
namespace pddi {

struct GameBase {
    void FUN_0031cb60();
    void FUN_0031d2b0(unsigned char);
    void FUN_0031d300();
    void FUN_0031d380();
    void FUN_0031d3f0();
    void FUN_0031d4f0(unsigned int);
    int* FUN_0031d500(int*);
    void FUN_0031d510(void*);
    float FUN_0031d520();
    void FUN_0031d530(void*);
    int FUN_0031d540();
    void FUN_0031d560(int);
    void FUN_0031d590(int, void*);
    void FUN_0031d5d0(int, int);
    void FUN_0031d630(int, int, int, int);
    void FUN_0031d6c0(void*);
    void* FUN_0031d6e0();
    void FUN_0031d6f0(int);
    unsigned int FUN_0031d710();
    void FUN_0031d720(unsigned int, unsigned int, unsigned int, unsigned int);
    void FUN_0031d750(void*, void*, void*, void*);
    void FUN_0031d790(unsigned int, unsigned int, unsigned int, unsigned int);
    void FUN_0031d7c0(void*, void*, void*, void*);
    void FUN_0031d830(int, int, int, int);
    int FUN_0031d900();
    int* FUN_0031d920(int*);
    void FUN_0031d940(int, int, int);
    void FUN_0031da40(int, int);
    unsigned char FUN_0031da80(unsigned int);
    void FUN_0031daa0(int, int);
    int FUN_0031dae0(int);
    void FUN_0031db00(int, int);
    void FUN_0031dba0(int, int);
    void FUN_0031dbd0(int, int);
    void FUN_0031dc50(int, void*);
    void FUN_0031dc90(int, int);
    void FUN_0031dd10(int, void*);
    void FUN_0031dd50(int, float);
    float FUN_0031dd90(int);
    void FUN_0031ddb0(int, float, float, float);
    void FUN_0031ddf0(int, void*, void*, void*);
    void FUN_0031de50(int, float, float, float);
    void FUN_0031de90(int, void*, void*, void*);
    unsigned int FUN_0031df00();
    void FUN_0031df40(void*, void*, void*, void*);
    unsigned char FUN_0031df90();
    unsigned int FUN_0031dfb0();
    unsigned char FUN_0031dfd0();
    unsigned char FUN_0031dff0();
    int FUN_0031e010();
    int FUN_0031e030();
    int FUN_0031e050();
    int FUN_0031e070();
    void FUN_0031e0b0(void*, void*, void*);
    int FUN_0031e0f0();
    bool FUN_0031e110();
    void FUN_0031e150(void*, void*, void*);
    int FUN_0031e180(int);
    float FUN_0031e1a0(int);
    void FUN_0031e1b0(unsigned char);
    unsigned char FUN_0031e1c0();
    void FUN_0031e230(int);
    void FUN_0031e5a0(int);
    void FUN_0031e5b0(int);
    void FUN_0031e5d0(int, int);
    int FUN_0031e600(void*, int);
    void FUN_0031e610();
    void FUN_0031e810(int);
    void FUN_0031e840(int);
    int FUN_0031e860(int);
    void FUN_0031e880(int);
    void FUN_0031e8d0(int, int);
    void FUN_0031e930(int, void*);
    void FUN_0031e9b0(unsigned char);
    void FUN_0031f190();
    void FUN_0031f290(int);
    void FUN_00325ee0(int, int, int);
    void FUN_00325ef0(int, int, int, int, int, int, int);
    void FUN_00326d60();
    void FUN_00327980();
    void FUN_00327990();
    void FUN_003279a0();
    void FUN_003279b0();
    void FUN_003279c0();
    void FUN_003279d0();
    bool FUN_003279e0(int, int);
    bool FUN_00327a40(int, int);
    unsigned char FUN_00327aa0(int, int);
    bool FUN_00327b00(int, int);
    bool FUN_00327b60(int, int);
    bool FUN_00327bc0(int, int);
    // base implementations our overrides call first, as the game's do
    void FUN_0031d4c0();                             // pddiBaseContext slot 5
    void FUN_0031def0(int);                          // pddiBaseContext slot 54
    // constructors and destructors of the portable bases
    void FUN_0031f410(void* display, void* device);  // pddiBaseContext::pddiBaseContext (equivalent/0x0031f410.cpp)
    void* FUN_0031ece0(unsigned int flags);          // pddiBaseContext's scalar deleting destructor (flags 0: no free)
};

} // namespace pddi
} // namespace hulk
#endif
