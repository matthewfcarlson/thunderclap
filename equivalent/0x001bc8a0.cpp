// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 36/36)
// FUN_001bc8a0 @ 0x001bc8a0
struct V3_1bc8a0 {
    float x, y, z;
    void FUN_00011160(float s, V3_1bc8a0 *d);
    void FUN_00011090();
};

struct V4_1bc8a0 {
    float v[4];
};

struct Mat4_1bc8a0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(V3_1bc8a0 *in, V3_1bc8a0 *out);
};

struct Corners {
    V3_1bc8a0 pt[2];
};

struct Obj_1bc8a0;

struct List_1bc8a0 {
    Obj_1bc8a0 **begin;
    Obj_1bc8a0 **end;
};

struct Obj_1bc8a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_1bc8a0 *v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x10];
    List_1bc8a0 *children;     // 0x14
    char b18;
    char pad19[0x28 - 0x19];
    V3_1bc8a0 half;            // 0x28
    float f34;
    V3_1bc8a0 pos;             // 0x38
    float dx;           // 0x44
    float dy;           // 0x48
    union {
        Mat4_1bc8a0 mat;       // 0x4c
        struct {
            float dz;
            float f50;
            float f54;
            char b58;
        } c;
    };
    char pad8c[0xcc - 0x8c];
    char bcc;
    void FUN_002fb950(V3_1bc8a0 *out, int i);
    Corners *FUN_002f37c0();
};

extern "C" void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_1bc8a0::*ctor)());

// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(V4_1bc8a0 *q, V3_1bc8a0 *v);
// equiv-conv: FUN_001bc5b0 edi stack
void FUN_001bc5b0(V3_1bc8a0 *pos, float a);

void FUN_001bc8a0(Obj_1bc8a0 *obj, V4_1bc8a0 *q)
{
    if (obj == 0 || !obj->b18)
        return;
    switch (obj->v6()) {
    case 2: {
        V3_1bc8a0 p;
        float t = obj->c.f50;
        if (obj->c.b58)
            t = t - obj->c.f54;
        p = obj->pos;
        p.FUN_00011160(t, (V3_1bc8a0 *)&obj->dx);
        FUN_001bc5b0(&p, obj->c.f54);
        p = obj->pos;
        p.FUN_00011160(-t, (V3_1bc8a0 *)&obj->dx);
        FUN_001bc5b0(&p, obj->c.f54);
        break;
    }
    case 5: {
        V3_1bc8a0 out;
        for (int i = 0; i < 8; i++) {
            obj->FUN_002fb950(&out, i);
            FUN_001bc530(q, &out);
        }
        break;
    }
    case 7: {
        float a = obj->f34;
        V3_1bc8a0 *pos = obj->v4();
        FUN_001bc5b0(pos, a);
        break;
    }
    case 4: {
        struct Frame {
            V3_1bc8a0 pt[2];
            V3_1bc8a0 out;
            V3_1bc8a0 in;
            Mat4_1bc8a0 m;
        } f;
        Corners *src = obj->FUN_002f37c0();
        FUN_00011520(&f.pt[0], 12, 2, &V3_1bc8a0::FUN_00011090);
        f.pt[0] = src->pt[0];
        f.pt[1] = src->pt[1];
        f.m = obj->mat;
        if (!obj->bcc)
            f.m.FUN_0022b980();
        for (int a = 0; a < 2; a++) {
            f.in.x = f.pt[a].x;
            for (int b = 0; b < 2; b++) {
                f.in.y = f.pt[b].y;
                for (int c = 0; c < 2; c++) {
                    f.in.z = f.pt[c].z;
                    f.m.FUN_0022c2b0(&f.in, &f.out);
                    FUN_001bc530(q, &f.out);
                }
            }
        }
        break;
    }
    case 6: {
        V3_1bc8a0 lo = *obj->v4();
        V3_1bc8a0 h = obj->half;
        for (int i = 0; i < 4; i += 2) {
            V3_1bc8a0 p;
            p.x = (float)(((double)i - 1.0) * h.x + lo.x);
            double cy = lo.y;
            double cz = lo.z;
            for (int j = 0; j < 4; j += 2) {
                float ty = (float)(((double)j - 1.0) * h.y);
                p.y = (float)(cy + ty);
                for (int k = 0; k < 4; k += 2) {
                    float tz = (float)(((double)k - 1.0) * h.z);
                    p.z = (float)(cz + tz);
                    FUN_001bc530(q, &p);
                    cz = (double)p.z - tz;
                }
                cy = (double)p.y - ty;
            }
        }
        break;
    }
    default:
        break;
    }
    List_1bc8a0 *list = obj->children;
    if (list != 0) {
        for (Obj_1bc8a0 **it = list->begin; it != list->end; it++)
            FUN_001bc8a0(*it, q);
    }
}
