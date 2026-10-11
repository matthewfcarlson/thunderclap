// STATUS: equivalent (tools/equiv.py level 3: 21 inputs, branch coverage 12/12)
// FUN_00225f30 @ 0x00225f30
struct Ref { virtual void FUN_ref0(); };
struct Inner { char pad[0x10]; unsigned count; };
struct Pair { unsigned a, b; };
struct Entry {
    Ref *obj;
    Pair pairs[64];
    unsigned tail;
};
struct Vec3 { unsigned x, y, z; };
struct Obj {
    char pad0[0x10];
    Inner *inner;
    char pad1[0x28 - 0x14];
    unsigned w, h, n;
    Entry entries[9];
    Pair grid[1];
    char pad3[0x12dc - 0x127c - 8];
    unsigned char b0, b1;
    char pad4[2];
    unsigned f12e0, f12e4, f12e8, f12ec;
    Vec3 v0, v1, v2, v3;
    unsigned f1320, f1324, f1328;
    void FUN_0022a9e0(Obj *src);
    Obj *FUN_00225f30(Obj *src);
};
Obj *Obj::FUN_00225f30(Obj *src)
{
    FUN_0022a9e0(src);
    w = src->w;
    h = src->h;
    n = src->n;
    unsigned cnt = inner->count;
    Entry *d = entries;
    Entry *s = src->entries;
    for (unsigned i = 0; i < n; i++) {
        d->obj = s->obj;
        d->obj->FUN_ref0();
        for (unsigned j = 0; j < cnt; j++)
            d->pairs[j] = s->pairs[j];
        d->tail = s->tail;
        d++;
        s++;
    }
    unsigned m = w * h;
    for (unsigned k = 0; k < m; k++)
        (&grid[0])[k] = (&src->grid[0])[k];
    b0 = src->b0;
    b1 = src->b1;
    f12e0 = src->f12e0;
    f12e4 = src->f12e4;
    f12e8 = src->f12e8;
    f12ec = src->f12ec;
    v0 = src->v0;
    v1 = src->v1;
    v2 = src->v2;
    v3 = src->v3;
    f1320 = src->f1320;
    f1324 = src->f1324;
    f1328 = src->f1328;
    return this;
}
