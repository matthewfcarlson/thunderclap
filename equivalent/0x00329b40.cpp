// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00329b40 @ 0x00329b40
struct Color_329b40 { float r, g, b, a; };
// equiv-conv: FUN_00329b40 ecx stack
void __cdecl FUN_00329b40(Color_329b40* color, unsigned int packed)
{
    color->r = (int)((packed >> 16) & 255) * (1.0f / 255.0f);
    color->g = (int)((packed >> 8) & 255) * (1.0f / 255.0f);
    color->b = (int)(packed & 255) * (1.0f / 255.0f);
    color->a = (int)(packed >> 24) * (1.0f / 255.0f);
}
