// STATUS: equivalent (tools/equiv.py level 3: 158 inputs, branch coverage 33/33)
// FUN_00325fd0 @ 0x00325fd0
// equiv-conv: FUN_00325fd0 ecx edx eax stack
class Device_325fd0 {
  public:
    bool Supports(int d3dFormat);
};
extern int g_formatTable[];      // 0x4d3e14
// equiv-map: ?g_formatTable@@3PAHA = 0x004d3e14
int FUN_00325fd0(int fmt, int depth, int bits, Device_325fd0* dev) {
    int idx = -1;
    switch (fmt) {
    case 0:
        if (depth == 0)
            idx = bits == 16 ? 0 : 3;
        else if (depth == 1)
            idx = bits != 16 ? 5 : 1;
        else
            idx = bits != 16 ? 4 : 2;
        break;
    case 1: idx = 6; break;
    case 2: idx = 7; break;
    case 3: idx = 8; break;
    case 4: return 12;
    case 5: case 6: return 14;
    case 7: case 8: return 15;
    case 9: case 10: break;
    case 11:
        if (depth == 0)
            idx = bits > 16 ? 12 : 9;
        else if (depth == 1)
            idx = bits > 16 ? 14 : 10;
        else
            idx = bits > 16 ? 13 : 11;
        break;
    }
    if (!dev->Supports(g_formatTable[idx]))
        return -1;
    return g_formatTable[idx];
}
