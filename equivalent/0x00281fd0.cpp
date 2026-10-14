// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_00281fd0 @ 0x00281fd0
struct V3_281fd0 { float x, y, z; };
struct V2_281fd0 { float x, y; };
struct Tri_281fd0 {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
};
struct Vtx_281fd0 {
    float x, y, z;
    unsigned int color;
    float u, v;
};
struct Palette_281fd0 {
    char pad0[0xc];
    unsigned int* colors;
    unsigned char* indices;
    int pad14;
    Tri_281fd0* tris;
};
struct Xform_281fd0 {
    void FUN_0022c2b0(V3_281fd0* in, V3_281fd0* out);
};
struct Ctx_281fd0 {
    char pad0[0x44];
    Palette_281fd0* pal;
    V3_281fd0* FUN_002f3830(V3_281fd0* out, Tri_281fd0* item);
    void FUN_001af890(V3_281fd0* out, unsigned int idx);
};

void FUN_00281fd0(Ctx_281fd0* ctx, V2_281fd0* scale, Xform_281fd0* xf, int n, Tri_281fd0** items, Vtx_281fd0* out)
{
    for (; n > 0; n--, items++) {
        V3_281fd0 tmp;
        V3_281fd0* r = ctx->FUN_002f3830(&tmp, *items);
        V3_281fd0 off;
        off.x = r->x * 0.1f;
        off.y = r->y * 0.1f;
        off.z = r->z * 0.1f;
        for (int j = 0; j < 3; j++) {
            V3_281fd0 p;
            V3_281fd0 q;
            ctx->FUN_001af890(&p, (*items)->idx[j]);
            xf->FUN_0022c2b0(&p, &q);
            out->x = p.x + off.x;
            out->y = p.y + off.y;
            out->z = p.z + off.z;
            Palette_281fd0* pal = ctx->pal;
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
