// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0032ee30 @ 0x0032ee30
struct Color { float red, green, blue, alpha; };
// equiv-conv: FUN_0032ee30 ecx stack
void __cdecl FUN_0032ee30(Color* color, unsigned int packed) {
    color->red = (float)(int)((packed >> 16) & 255) * 0.003921568859368563f;
    color->green = (float)(int)((packed >> 8) & 255) * 0.003921568859368563f;
    color->blue = (float)(int)(packed & 255) * 0.003921568859368563f;
    color->alpha = (float)(int)(packed >> 24) * 0.003921568859368563f;
}
