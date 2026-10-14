typedef unsigned char u8_23a470;
struct Source_23a470 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void read(u8_23a470*, int, int);
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
    virtual void finish();
};
struct IFileStringReader {
    char pad[8];
    Source_23a470* source;
    u8_23a470 value;
    u8_23a470 loaded;
    u8_23a470 vfunc_4();
};
u8_23a470 IFileStringReader::vfunc_4() {
    if (loaded)
        return value;
    value = 0;
    source->read(&value, 1, 1);
    source->finish();
    loaded = 1;
    return value;
}