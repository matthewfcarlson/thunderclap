// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 26/28, incomplete)
// FUN_000366f0 @ 0x000366f0
struct V3_366f0 { float x, y, z; };
struct Matrix { float m[12]; V3_366f0 pos; float w; };
struct Sub2324b0 { void FUN_002324b0(int a); };
struct Attach_366f0 {
    char pad[0x10];
    Attach_366f0* inner;
    void FUN_001c5e40(Matrix* m);
    void FUN_001c5e80(V3_366f0* p);
    void FUN_001c5ed0(V3_366f0* p);
    void FUN_001c5ef0(bool b);
};
struct Obj000366f0 {
    char pad0[0x10];
    void* owner;
    char pad1[0xdc - 0x14];
    Sub2324b0 sub;
    char pad2[0x118 - 0xdc - 1];
    char skip;
    char pad3[0x124 - 0x119];
    Attach_366f0* attach;
    char pad4[0x140 - 0x128];
    int mode;
    char pad5[0x308 - 0x144];
    float f308;
    float f30c;
    float f310;
    float f314;
    char pad6[0x1a84 - 0x318];
    V3_366f0 vec1a84;
    char pad7[0x20b0 - 0x1a90];
    int flag20b0;
    void FUN_000366f0(int unused, float dt);
};
extern float DAT_00421894;
extern void __fastcall FUN_0022b980(Matrix* m);
extern void* __fastcall FUN_00059a40(void* o);
extern Matrix* __fastcall FUN_00221c40(void* p);
// equiv-conv: FUN_001c5080 ecx stack stack
extern void __stdcall FUN_001c5080(Attach_366f0* inner, float a, float b);

void Obj000366f0::FUN_000366f0(int unused, float dt)
{
    if (skip != 0) return;
    if (f310 > 0.0f && f30c <= 0.0f) {
        float v = dt / f310 * (1.0f - f314) + f314;
        f314 = v;
        if (v > 1.0f) f314 = 1.0f;
        f310 = f310 - dt;
    }
    if (f308 > 0.0f) {
        f308 = f308 - dt;
    }
    if (f308 <= 0.0f && f30c > 0.0f) {
        f314 = 0.01f;
        f30c = f30c - dt;
    }
    if (f310 <= 0.0f && f30c <= 0.0f) {
        f314 = 1.0f;
    }
    sub.FUN_002324b0(1);
    if (attach != 0) {
        Matrix m;
        FUN_0022b980(&m);
        void* o = FUN_00059a40(owner);
        if (o != 0) {
            Matrix* src = FUN_00221c40((char*)o + 0x10);
            m = *src;
        }
        attach->FUN_001c5e40(&m);
        attach->FUN_001c5e80(&m.pos);
        attach->FUN_001c5ed0(&vec1a84);
        attach->FUN_001c5ef0(mode == 3);
        if (flag20b0 == 1) {
            if (attach->inner != 0) {
                FUN_001c5080(attach->inner, DAT_00421894, 1.5f);
            }
        }
    }
}
