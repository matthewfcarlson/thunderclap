struct Obj {
    virtual void AddRef();
    virtual void Release();
    int p0, p1, p2;
    int h;
};
struct Mesh {
    void Set(void* c, int v);
};
int FUN_002ee6d0(Obj* o);
struct Ctx {
    void Reg(Obj* o);
};
void* Cast(int h, int a, const void* from, const void* to, int b);
extern char TFrom[], TTo[];
struct Holder {
    char pad[8];
    Ctx* ctx;
    char pad2[0x4fc - 0xc];
    Obj* slots[19];
    int vals[19];
    Mesh mesh;
    bool Add(Obj* o, int v);
};
bool Holder::Add(Obj* o, int v) {
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (o)
                o->AddRef();
            if (slots[i])
                slots[i]->Release();
            slots[i] = o;
            vals[i] = v;
            ctx->Reg(o);
            o = (Obj*)o->h;
            void* c = Cast((int)o, 0, TFrom, TTo, 0);
            if (c)
                mesh.Set(c, v);
            return true;
        }
        i++;
    } while (i < 19);
    return false;
}
