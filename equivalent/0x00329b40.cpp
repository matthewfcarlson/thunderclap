// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0; --wine 600 inputs)
// FUN_00329b40 @ 0x00329b40
struct Color_329b40 { float r, g, b, a; };
// equiv-conv: FUN_00329b40 ecx stack
extern "C" void __cdecl FUN_00329b40(void * color, unsigned int packed)
{
    ((Color_329b40 *)color)->r = (int)((packed >> 16) & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->g = (int)((packed >> 8) & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->b = (int)(packed & 255) * 0.0039215689f;
    ((Color_329b40 *)color)->a = (int)(packed >> 24) * 0.0039215689f;
}
