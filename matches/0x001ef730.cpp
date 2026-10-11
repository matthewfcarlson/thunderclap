extern "C" char* strcpy(char*, const char*);
struct Base {
    virtual void v0() throw();
    virtual void v1() throw();
    int p4, p8, pc;
    Base() throw() {
        p4 = 0;
        p8 = 0;
        pc = 0;
    }
};
struct Target : Base {
    char name[0x20];
    int p30;
    Target(const char* s, int v, int unused) throw();
    virtual void v0() throw();
};
Target::Target(const char* s, int v, int unused) throw() {
    strcpy(name, s);
    p30 = v;
}
