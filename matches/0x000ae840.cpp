extern "C" void __cdecl FUN_002684c0();
extern int gCount_ae840;
struct Helper_ae840 {
    void a();
    void d();
    void b(int);
    void c(int);
};
struct Obj_ae840 {
    char pad[4];
    Helper_ae840* p;
    char pad2[4];
    char flags[13];
    char flags2[2];
    void run();
    void finish();
};
void Obj_ae840::run() {
    p->a();
    FUN_002684c0();
    ++gCount_ae840;
    p->d();
    for (int i = 0; i < 13; ++i)
        if (flags[i])
            p->b(i);
    for (int i = 0; i < 2; ++i)
        if (flags2[i])
            p->c(i);
    finish();
}
