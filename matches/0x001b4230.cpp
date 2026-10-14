typedef unsigned int u32_1b4230;
struct Obj_1b4230 {
    char pad[0x74];
    void* child;
};
struct Worker_1b4230 {
    void Finish(void*);
};
struct Ctx_1b4230 {
    char pad[8];
    Worker_1b4230* worker;
    bool Target(Obj_1b4230*);
};
extern u32_1b4230 g0_1b4230;
extern u32_1b4230 g8_1b4230;
extern u32_1b4230 g00;
extern u32_1b4230 g01;
bool Ctx_1b4230::Target(Obj_1b4230* p) {
    if (p == 0)
        return false;
    void* child = p->child;
    if (child == 0)
        return false;
    u32_1b4230* q = (u32_1b4230*)child;
    q[0x58 / 4] = g0_1b4230;
    q[0x5c / 4] = g8_1b4230;
    q[0x60 / 4] = g00;
    q[0x64 / 4] = g01;
    worker->Finish(q);
    return true;
}