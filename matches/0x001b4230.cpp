typedef unsigned int u32;
struct Obj {
    char pad[0x74];
    void* child;
};
struct Worker {
    void Finish(void*);
};
struct Ctx {
    char pad[8];
    Worker* worker;
    bool Target(Obj*);
};
extern u32 g0;
extern u32 g8;
extern u32 g00;
extern u32 g01;
bool Ctx::Target(Obj* p) {
    if (p == 0)
        return false;
    void* child = p->child;
    if (child == 0)
        return false;
    u32* q = (u32*)child;
    q[0x58 / 4] = g0;
    q[0x5c / 4] = g8;
    q[0x60 / 4] = g00;
    q[0x64 / 4] = g01;
    worker->Finish(q);
    return true;
}