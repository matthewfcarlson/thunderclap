// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00019d30 @ 0x00019d30
struct Vec3_19d30 {
    float x, y, z;
    float FUN_0022d110();
};

struct RefObj_19d30 {
    virtual void AddRef();
    virtual void Release();
};

struct Request {
    int r00;
    int r04;
    Vec3_19d30 target;
    char pad14[4];
    Vec3_19d30 aim;
    unsigned char flag24;
    char pad25[0x4c - 0x25];
    RefObj_19d30* ref;
    char pad50[4];
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    char pad6c[0x78 - 0x6c];
    float r78;
    char pad7c[0x91 - 0x7c];
    unsigned char r91;
    char pad92[0xa0 - 0x92];
    Request* FUN_00059820();
    void FUN_000595f0(Vec3_19d30* v, float a, float b, float c);
    void FUN_00059300();
};

struct Fighter_19d30 {
    char pad00[0x12c];
    RefObj_19d30* ref12c;
    char pad130[0x328 - 0x130];
    int f328;
    void FUN_00035230(Vec3_19d30* out);
    void FUN_0003ffa0(void* obj, int zero);
    void FUN_00035c70(void* obj);
};

struct Anchor_19d30 {
    Fighter_19d30* FUN_00059a30();
    void FUN_00059a50(Vec3_19d30* out);
};

struct Owner_19d30 {
    Anchor_19d30* FUN_000592a0();
};

struct Params {
    char pad00[0x3b];
    unsigned char b3b;
    char pad3c[0x68 - 0x3c];
    int f68;
    int f6c;
    char pad70[0xd8 - 0x70];
    int mode;
    int fdc;
    char pad_e0[0xf0 - 0xe0];
    unsigned char bf0;
    char padf1[3];
    float ff4;
    float ff8;
    float ffc;
    float f100;
    float f104;
};

struct Target_19d30 {
    char pad00[0x64];
    float a;
    float b;
    float c;
    char pad70[0x100 - 0x70];
    void* obj;
    void FUN_00081420(Request* req);
};

// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Fighter_19d30* frame, void* obj, Vec3_19d30* out);
float __cdecl FUN_000964e0();

struct Frame_19d30 {
    Vec3_19d30 delta;
    float fa;
    float fb;
    float fc;
    Vec3_19d30 a;
    Vec3_19d30 b;
    Request req;
    float spill;
    Vec3_19d30 out;
};

class SpawnAction {
public:
    char pad00[0x1c];
    Owner_19d30* owner;
    Params* params;
    void FUN_00019d30(Target_19d30* t, Vec3_19d30* p1, Vec3_19d30* p2);
};

void SpawnAction::FUN_00019d30(Target_19d30* t, Vec3_19d30* p1, Vec3_19d30* p2)
{
    Anchor_19d30* anchor = owner->FUN_000592a0();
    Fighter_19d30* fighter = anchor->FUN_00059a30();
    if (t == 0)
        return;
    Frame_19d30 f;
    f.a.x = 0.0f;
    f.a.y = 0.0f;
    f.a.z = 0.0f;
    anchor->FUN_00059a50(&f.a);
    f.b.x = 0.0f;
    f.b.y = 0.0f;
    f.b.z = 0.0f;
    fighter->FUN_00035230(&f.b);
    f.req.FUN_00059820();

    Vec3_19d30 mid;
    mid.x = p1->x + t->a;
    mid.y = p1->y + t->b;
    mid.z = p1->z + t->c;
    mid.x = mid.x * 0.5f;
    mid.y = mid.y * 0.5f;
    mid.z = mid.z * 0.5f;
    f.req.target = mid;
    f.delta = mid;
    f.delta.x = f.delta.x - p1->x;
    f.delta.y = f.delta.y - p1->y;
    f.delta.z = f.delta.z - p1->z;
    if (f.delta.FUN_0022d110() > 1.0f) {
        f.req.target.x = f.delta.x + p1->x;
        f.req.target.y = f.delta.y + p1->y;
        f.req.target.z = f.delta.z + p1->z;
    }

    f.req.aim = *p2;
    Params* pr = params;
    f.req.r00 = pr->f68;
    f.req.r04 = pr->f6c;
    f.req.r91 = pr->b3b;
    f.req.r54 = pr->fdc;
    RefObj_19d30* nr = fighter->ref12c;
    if (nr)
        nr->AddRef();
    if (f.req.ref)
        f.req.ref->Release();
    pr = params;
    f.req.ref = nr;
    FUN_00014210(pr->mode, fighter, t->obj, &f.out);
    pr = params;
    f.req.flag24 = pr->bf0;
    f.req.r58 = pr->ff4;
    f.req.r68 = pr->f104;
    f.fa = pr->ffc;
    f.fc = pr->ff8;
    f.fb = pr->f100;
    if (f.req.r58 < 0.0f)
        f.req.r58 = -(FUN_000964e0() * f.req.r58);
    if (f.req.r68 < 0.0f)
        f.req.r68 = -(FUN_000964e0() * f.req.r68);
    f.req.r78 = 1.0f;
    if (f.fa <= 0.0f)
        f.fa = f.req.r58;
    f.req.FUN_000595f0(&f.out, f.fc, f.fa, f.fb);
    t->FUN_00081420(&f.req);
    if (fighter->f328 == 0)
        fighter->FUN_0003ffa0(t->obj, 0);
    fighter->FUN_00035c70(t->obj);
    f.req.FUN_00059300();
}
