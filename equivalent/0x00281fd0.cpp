// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_00281fd0 @ 0x00281fd0
struct V3 { float x, y, z; };
struct V2 { float x, y; };
struct Tri {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
};
struct Vtx {
    float x, y, z;
    unsigned int color;
    float u, v;
};
struct Palette {
    char pad0[0xc];
    unsigned int* colors;
    unsigned char* indices;
    int pad14;
    Tri* tris;
};
struct Xform {
    void FUN_0022c2b0(V3* in, V3* out);
};
struct Ctx {
    char pad0[0x44];
    Palette* pal;
    V3* FUN_002f3830(V3* out, Tri* item);
    void FUN_001af890(V3* out, unsigned int idx);
};

void FUN_00281fd0(Ctx* ctx, V2* scale, Xform* xf, int n, Tri** items, Vtx* out)
{
    for (; n > 0; n--, items++) {
        V3 tmp;
        V3* r = ctx->FUN_002f3830(&tmp, *items);
        V3 off;
        off.x = r->x * 0.1f;
        off.y = r->y * 0.1f;
        off.z = r->z * 0.1f;
        for (int j = 0; j < 3; j++) {
            V3 p;
            V3 q;
            ctx->FUN_001af890(&p, (*items)->idx[j]);
            xf->FUN_0022c2b0(&p, &q);
            out->x = p.x + off.x;
            out->y = p.y + off.y;
            out->z = p.z + off.z;
            Palette* pal = ctx->pal;
            unsigned int color;
            if (pal->indices != 0) {
                int tri = (int)(*items - pal->tris);
                color = pal->colors[pal->indices[(unsigned short)tri * 3 + j]];
            } else {
                color = 0xffff00ff;
            }
            out->color = color;
            out->u = q.x / scale->x + 0.5f;
            out->v = q.y / scale->y + 0.5f;
            out++;
        }
    }
}
