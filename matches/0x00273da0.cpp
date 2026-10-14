struct Sink_273da0 {
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
    virtual void Do(int a, char* b);
};
struct Sub_273da0 {
    virtual void Fin();
    virtual void Rel();
};
struct Ev_273da0 {
    char pad[0x12c];
};
struct Inner_273da0 {
    char pad0[4];
    Sub_273da0 sub;
    char pad1[4];
    Sink_273da0* sink;
    char pad2[4];
    int f14;
    char pad3[4];
    char f1c;
    char pad4;
    char name[0x10e];
    char ev[0x30];
    int h;
};
struct Ev2 {
    bool Test();
    void Run();
};
struct FileCloseRequest {
    virtual int vfunc_0();
    virtual int vfunc_1();
    int pad;
    Inner_273da0* in;
};
int FileCloseRequest::vfunc_1() {
    Sink_273da0* s = in->sink;
    if (!((Ev2*)((char*)in + 0x12c))->Test())
        s->Do(*(int*)((char*)in + 0x15c), (char*)in + 0x1e);
    else
        ((Ev2*)((char*)in + 0x12c))->Run();
    in->f1c = 0;
    in->sub.Fin();
    in->f14 = 0;
    in->sub.Rel();
    return 1;
}
