class pddiRenderContext {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    char pad[0x4c];
};
class pddiBaseContext : public pddiRenderContext {
  public:
    struct Entry {
        char b[0x68];
        int x, y, z;
        char rest[8];
    };
    Entry* entries;
    void vfunc_53(int, int*, int*, int*);
};
void pddiBaseContext::vfunc_53(int n, int* a, int* b, int* c) {
    if (n < 8) {
        *a = entries[n].x;
        *b = entries[n].y;
        *c = entries[n].z;
    } else {
        *c = 0;
        *b = 0;
        *a = 0;
    }
}