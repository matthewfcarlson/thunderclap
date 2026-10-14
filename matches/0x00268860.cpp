extern "C" int strcmp(const char*, const char*);
struct Elem_268860 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Name();
    int pad[3];
};
struct C_268860 {
    char pad[0x428];
    Elem_268860 e[2];
    int Count(const char* s);
};
int C_268860::Count(const char* s) {
    int n = 0;
    for (int i = 0; i < 2; i++) {
        if (strcmp(e[i].Name(), s) == 0)
            n++;
    }
    return n;
}
