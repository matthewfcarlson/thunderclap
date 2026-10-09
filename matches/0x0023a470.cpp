typedef unsigned char u8;
struct Source {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void read(u8*, int, int);
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
    Source* source;
    u8 value;
    u8 loaded;
    u8 vfunc_4();
};
u8 IFileStringReader::vfunc_4() {
    if (loaded)
        return value;
    value = 0;
    source->read(&value, 1, 1);
    source->finish();
    loaded = 1;
    return value;
}