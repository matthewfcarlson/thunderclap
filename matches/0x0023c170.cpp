namespace fight {
struct Reader {
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
};
struct BinReader : Reader {
    char pad[0x14];
    int x18;
    int x1c;
    int x20;
    char pad2[0x0c];
    unsigned char x30;
    void a17();
    void init();
};
void BinReader::a17() {
    init();
    x18 = 0;
    x1c = 0;
    x20 = 0;
    x30 = 1;
}
} // namespace fight