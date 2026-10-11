extern "C" char DAT_0043397c[];
struct Ref {
    virtual void f0();
    virtual void f1();
};
struct Parent {
    void cleanup();
};
struct Obj : Parent {
    char pad[0x80];
    Ref* a;
    Ref* b;
    void run();
};
void Obj::run() {
    *(void**)this = (void*)((int)DAT_0043397c);
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
}