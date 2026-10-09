class Reader {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int*);
    virtual void v7(unsigned int*);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
};
class IFileStringReader {
  public:
    char pad0[8];
    Reader* reader;
    char padc[1];
    bool done;
    bool vfunc_6();
};
bool IFileStringReader::vfunc_6() {
    if (done)
        return false;
    reader->v21();
    unsigned int a;
    unsigned int b;
    reader->v6(&a);
    reader->v7(&b);
    reader->v21();
    return a >= b;
}
