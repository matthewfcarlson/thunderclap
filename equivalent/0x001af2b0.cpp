// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 25/26, incomplete)
// FUN_001af2b0 @ 0x001af2b0
struct Vec3 {
    float x, y, z;
};

struct Elem {
    int id;
    int idx;
    Vec3 pos;
};

struct ElemVec {
    Elem *begin;
    Elem *end;
    Elem *cap;
};

struct Rec {
    int ids[3];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
};

struct Reg {
    Rec *FUN_001b57a0(int id);
};

struct Info {
    Vec3 v;
    Reg *reg;
    int id;
};

struct Out {
    int first;
    ElemVec vec;
    int pad10;
    Reg *reg;
};

struct Query {
    Reg *reg;
    unsigned want;
    unsigned alpha;
    unsigned extra;
};

struct Target {
    Vec3 pos;
    char pad[4];
    int id;
};

struct Frame {
    Vec3 tmp;
    Query q;
    Elem x1;
    Elem x2;
};

struct Owner {
    int pad0;
    int f4;
    float FUN_001af2b0(Info *info, Target *pos, float scale, float alpha, Out *out, unsigned a6, unsigned a7);
};

Vec3 *__cdecl FUN_001acdd0(Vec3 *out, Reg *reg, int id);
float __cdecl FUN_001af150(ElemVec *vec, Elem *b, Elem *a, Query *q, unsigned a6);

float Owner::FUN_001af2b0(Info *info, Target *pos, float scale, float alpha, Out *out, unsigned a6, unsigned a7)
{
    Frame fr;
    unsigned want = (unsigned)(int)(scale * 0.7f * 32.0f);
    out->reg = info->reg;
    out->first = f4;

    Rec *rec = info->reg->FUN_001b57a0(info->id);
    if (!rec)
        return 1.0f;

    int best = 0;
    unsigned top = 0;
    if (rec->b0 > 0)
        top = rec->b0;
    if (rec->b1 > top) {
        best = 1;
        top = rec->b1;
    }
    if (rec->b2 > top) {
        best = 2;
        top = rec->b2;
    }

    if (top < want) {
        out->reg = info->reg;
        out->vec.end = out->vec.begin;
        int id = rec->ids[best];
        if (id != -1) {
            Vec3 *p = FUN_001acdd0(&fr.tmp, info->reg, id);
            Vec3 v = *p;
            if (out->vec.end < out->vec.cap) {
                Elem *e = out->vec.end;
                out->vec.end = e + 1;
                if (e) {
                    e->id = id;
                    e->idx = best;
                    e->pos = v;
                }
            }
            int id2 = info->id;
            Vec3 *p2 = FUN_001acdd0(&fr.tmp, info->reg, id2);
            Vec3 v2 = *p2;
            if (out->vec.end < out->vec.cap) {
                Elem *e = out->vec.end;
                out->vec.end = e + 1;
                if (e) {
                    e->id = id2;
                    e->idx = -1;
                    e->pos = v2;
                }
            }
        }
        return 1.0f;
    }

    fr.q.reg = info->reg;
    fr.q.want = want;
    fr.q.alpha = (unsigned)(int)(alpha * 255.0f);
    fr.q.extra = a7;
    fr.x1.id = pos->id;
    fr.x1.idx = -1;
    fr.x1.pos.x = pos->pos.x * 3.0f;
    fr.x1.pos.y = pos->pos.y * 3.0f;
    fr.x1.pos.z = pos->pos.z * 3.0f;
    fr.x2.id = info->id;
    fr.x2.idx = -1;
    fr.x2.pos.x = info->v.x * 3.0f;
    fr.x2.pos.y = info->v.y * 3.0f;
    fr.x2.pos.z = info->v.z * 3.0f;
    float r = FUN_001af150(&out->vec, &fr.x2, &fr.x1, &fr.q, a6);
    if (r == 0.0f)
        return r;
    Elem *e = out->vec.begin;
    if (e != out->vec.end) {
        do {
            e->pos.x = e->pos.x * 0.333333343f;
            e->pos.y = e->pos.y * 0.333333343f;
            e->pos.z = e->pos.z * 0.333333343f;
            e++;
        } while (e != out->vec.end);
    }
    Elem *b = out->vec.begin;
    b->pos = pos->pos;
    return r;
}
