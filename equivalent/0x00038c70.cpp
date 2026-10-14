// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 14/14)
// FUN_00038c70 @ 0x00038c70
struct V3_38c70 { float x, y, z; };

struct Target_38c70 {
    char pad00[0x3c];
};

struct Anchor_38c70 {
    int FUN_00059a40();
    void FUN_00059a50(V3_38c70* out);
};

struct Holder_38c70 {
    char pad00[0x34];
    float scale;
};

class Probe_38c70 {
public:
    char pad00[0x10];
    Anchor_38c70* anchor;
    char pad14[0x30];
    float min44;
    float min48;
    float min4c;
    char pad50[0xcc];
    Holder_38c70* holder;
    char pad120[0x20];
    int mode;
    char pad144[4];
    float margin;
    char pad14c[0x19ac];
    float offsetX;
    float offsetY;
    float offsetZ;

    char FUN_00038660(const V3_38c70* p, float h, int a0, int a1, int a2, int a3, int a4, int a5, const V3_38c70* q);
    bool FUN_00038c70(int a0, int a1, int a2, int a3, int a4, int a5);
};

bool Probe_38c70::FUN_00038c70(int a0, int a1, int a2, int a3, int a4, int a5)
{
    if (holder == 0)
        return false;

    float m = margin;
    if (!anchor->FUN_00059a40())
        return false;

    V3_38c70 base;
    base.x = 0.0f;
    base.y = 0.0f;
    base.z = 0.0f;
    anchor->FUN_00059a50(&base);

    V3_38c70 lo;
    lo.x = min44;
    lo.y = min48;
    lo.z = min4c;

    V3_38c70 p;
    p.x = base.x;
    p.y = base.y;
    p.z = base.z;
    if (lo.y > base.y)
        p.y = lo.y;

    if (mode == 1)
        p.y = p.y + m;
    else
        p.y = m * 0.25f + p.y;

    if (mode == 4) {
        float s = holder->scale;
        p.x = s * offsetX + p.x;
        p.y = s * offsetY + p.y;
        p.z = s * offsetZ + p.z;
    }

    float d = p.y - base.y;
    if (!(d >= 0.0f) && d == d)
        d = 0.0f;

    float h = (m + m + d) + 35.0f;
    return FUN_00038660(&p, h, a0, a1, a2, a3, a4, a5, &lo) != 0;
}
