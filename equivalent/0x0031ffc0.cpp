// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0031ffc0 @ 0x0031ffc0
struct Color { float r, g, b, a; };
// equiv-conv: FUN_0031ffc0 ecx stack
void __cdecl FUN_0031ffc0(Color* color, unsigned int packed)
{
    color->r = (float)((packed >> 16) & 255) * 0.0039215688593685626983642578125f;
    color->g = (float)((packed >> 8) & 255) * 0.0039215688593685626983642578125f;
    color->b = (float)(packed & 255) * 0.0039215688593685626983642578125f;
    color->a = (float)(packed >> 24) * 0.0039215688593685626983642578125f;
}
