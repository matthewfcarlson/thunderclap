extern "C" int strcmp(const char*, const char*);
class Elem_2687e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Name();
    char pad[0x30];
};
class C_2687e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Count(const char* name);
    char pad[0x10];
    unsigned int mCount;
    Elem_2687e0 mElems[1];
};
int C_2687e0::Count(const char* name) {
    int n = 0;
    for (unsigned int i = 0; i < mCount; i++) {
        if (strcmp(mElems[i].Name(), name) == 0)
            n++;
    }
    return n;
}
