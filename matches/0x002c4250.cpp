struct Arg_2c4250 {
    int a;
    float b;
    float c;
};
struct Obj_2c4250 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void next(int);
    char pad[0x54];
    int x;
    float y;
    float z;
    void run(Arg_2c4250* p);
};
void Obj_2c4250::run(Arg_2c4250* p) {
    float c = p->c;
    float b = p->b;
    x = p->a;
    y = b;
    z = c;
    next(1);
}
