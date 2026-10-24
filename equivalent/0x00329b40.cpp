// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0; --wine 600 inputs)
// FUN_00329b40 @ 0x00329b40
struct Color_329b40 { float r, g, b, a; };
// equiv-conv: FUN_00329b40 ecx stack
void __cdecl FUN_00329b40(Color_329b40* color, unsigned int packed)
{
    color->r = (int)((packed >> 16) & 255) * 0.0039215689f;
    color->g = (int)((packed >> 8) & 255) * 0.0039215689f;
    color->b = (int)(packed & 255) * 0.0039215689f;
    color->a = (int)(packed >> 24) * 0.0039215689f;
}
