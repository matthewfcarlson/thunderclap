struct Obj_189140 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10(int, int, int);
};
struct Allocated_189140 {
    int run(Obj_189140*, int);
};
extern int check(void*, int, int*, int*, int);
extern Allocated_189140* alloc(int);
extern int typeA_189140, typeB;
int Obj_189140::v10(int a, int b, int c) {
    if (check((void*)c, 0, &typeA_189140, &typeB, 0)) {
        Allocated_189140* q = alloc(0x54);
        if (q)
            return q->run(this, c);
    }
    return 0;
}