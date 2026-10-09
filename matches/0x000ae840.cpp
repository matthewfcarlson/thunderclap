extern "C" void __cdecl FUN_002684c0();
extern int gCount;
struct Helper {
    void a();
    void d();
    void b(int);
    void c(int);
};
struct Obj {
    char pad[4];
    Helper* p;
    char pad2[4];
    char flags[13];
    char flags2[2];
    void run();
    void finish();
};
void Obj::run() {
    p->a();
    FUN_002684c0();
    ++gCount;
    p->d();
    for (int i = 0; i < 13; ++i)
        if (flags[i])
            p->b(i);
    for (int i = 0; i < 2; ++i)
        if (flags2[i])
            p->c(i);
    finish();
}
