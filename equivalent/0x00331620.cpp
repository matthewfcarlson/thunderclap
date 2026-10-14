// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00331620 @ 0x00331620
struct Color_331620 { float red, green, blue, alpha; };
// equiv-conv: FUN_00331620 ecx stack
void __cdecl FUN_00331620(Color_331620* color, unsigned int packed) {
    color->red = (int)((packed >> 16) & 255) * 0.003921568859368563f;
    color->green = (int)((packed >> 8) & 255) * 0.003921568859368563f;
    color->blue = (int)(packed & 255) * 0.003921568859368563f;
    color->alpha = (int)(packed >> 24) * 0.003921568859368563f;
}
