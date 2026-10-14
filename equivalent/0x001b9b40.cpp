// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_001b9b40 @ 0x001b9b40
struct Sink_1b9b40 { int FUN_001c17c0(unsigned argb); };
struct Holder_1b9b40 { Sink_1b9b40* sink; };
Holder_1b9b40* FUN_001c3d90();
static int Clamp255(int v) { return v < 0 ? 0 : (v > 255 ? 255 : v); }
int __stdcall SetColor(int r, int g, int b) {
    int cr = Clamp255(r);
    int cg = Clamp255(g);
    int cb = Clamp255(b);
    unsigned argb = (((0xffu << 8 | cr) << 8 | cg) << 8) | cb;
    return FUN_001c3d90()->sink->FUN_001c17c0(argb);
}
