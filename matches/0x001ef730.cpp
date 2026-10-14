extern "C" char* strcpy(char*, const char*);
struct Base_1ef730 {
    virtual void v0() throw();
    virtual void v1() throw();
    int p4, p8, pc;
    Base_1ef730() throw() {
        p4 = 0;
        p8 = 0;
        pc = 0;
    }
};
struct Target_1ef730 : Base_1ef730 {
    char name[0x20];
    int p30;
    Target_1ef730(const char* s, int v, int unused) throw();
    virtual void v0() throw();
};
Target_1ef730::Target_1ef730(const char* s, int v, int unused) throw() {
    strcpy(name, s);
    p30 = v;
}
