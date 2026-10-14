struct Obj_1b5ec0 {
    virtual void AddRef();
    virtual void Release();
    int p0, p1, p2;
    int h;
};
struct Mesh_1b5ec0 {
    void Set(void* c, int v);
};
int FUN_002ee6d0(Obj_1b5ec0* o);
struct Ctx_1b5ec0 {
    void Reg(Obj_1b5ec0* o);
};
void* Cast(int h, int a, const void* from, const void* to, int b);
extern char TFrom[], TTo[];
struct Holder_1b5ec0 {
    char pad[8];
    Ctx_1b5ec0* ctx;
    char pad2[0x4fc - 0xc];
    Obj_1b5ec0* slots[19];
    int vals[19];
    Mesh_1b5ec0 mesh;
    bool Add(Obj_1b5ec0* o, int v);
};
bool Holder_1b5ec0::Add(Obj_1b5ec0* o, int v) {
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
            o = (Obj_1b5ec0*)o->h;
            void* c = Cast((int)o, 0, TFrom, TTo, 0);
            if (c)
                mesh.Set(c, v);
            return true;
        }
        i++;
    } while (i < 19);
    return false;
}
