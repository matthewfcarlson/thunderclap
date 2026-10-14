// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002ecb90 @ 0x002ecb90
extern float DAT_004d287c;
extern unsigned int DAT_004d2880;
extern unsigned char DAT_00554c0c;
void __cdecl FUN_002ecb90(unsigned int mode)
{
    if (mode == 8) return;
    switch (mode) {
    case 0: DAT_004d287c = 10.0f; break;
    case 1: DAT_004d287c = 1.0f; break;
    case 2: DAT_004d287c = 0.01f; break;
    case 3: DAT_004d287c = 0.00001f; break;
    case 4: DAT_004d287c = 0.3937f; break;
    case 5: DAT_004d287c = 0.03281f; break;
    case 6: DAT_004d287c = 0.01094f; break;
    case 7: DAT_004d287c = 0.0006214f; break;
    }
    DAT_00554c0c = 1;
    DAT_004d2880 = mode;
}
