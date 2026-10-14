// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_000a62c0 @ 0x000a62c0
struct V3_a62c0 { float x, y, z; };
struct Target_a62c0 { char pad[0x1a64]; float f1a64; };
struct Sub_a62c0 { void FUN_00059a50(V3_a62c0* p); };
struct Holder_a62c0 { char pad[0x10]; Sub_a62c0* sub; char pad2[0x1a64 - 0x14]; float f1a64; };

class Obj_a62c0 {
public:
    V3_a62c0* FUN_000a92c0(V3_a62c0* out, int a, Holder_a62c0* b);
    void FUN_000a2f30(int a);
    void FUN_000a1b30(int a, int b, int c);
    void run(int a, Holder_a62c0* b);
    char p0[0x1b8];
    V3_a62c0 v1b8;
    V3_a62c0 v1c4;
    V3_a62c0 v1d0;
    V3_a62c0 v1dc;
    V3_a62c0 v1e8;
    char p1[0x23c - 0x1f4];
    float f23c;
    char p2[0x29c - 0x240];
    V3_a62c0 v29c;
    V3_a62c0 v2a8;
    V3_a62c0 v2b4;
    char p3[0x314 - 0x2c0];
    float f314;
    char p4[0x344 - 0x318];
    char c344;
    char p5[0x350 - 0x345];
    Holder_a62c0* h350;
    char p6[0x4a0 - 0x354];
    V3_a62c0 v4a0;
};

void Obj_a62c0::run(int a, Holder_a62c0* b)
{
    if (h350 != 0 && b == h350) {
        h350->sub->FUN_00059a50(&v1b8);
        V3_a62c0 tmp; V3_a62c0* r = FUN_000a92c0(&tmp, a, h350);
        v1c4 = *r;
        v1e8 = v1c4;
        f314 = f23c = h350->f1a64;
        v1d0.x = 0; v1d0.y = 0; v1d0.z = 0;
        v1dc.x = 0; v1dc.y = 0; v1dc.z = 0;
        v29c = v1c4;
        v2a8.x = 0; v2a8.y = 0; v2a8.z = 0;
        v2b4.x = 0; v2b4.y = 0; v2b4.z = 0;
        v4a0.x = 0; v4a0.y = 0; v4a0.z = 0;
        FUN_000a2f30(0);
        FUN_000a1b30(a, 0, 1);
        c344 = 0;
    }
}
