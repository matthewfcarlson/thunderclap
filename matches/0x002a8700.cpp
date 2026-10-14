extern "C" char DAT_0042dd24[];
class Ref_2a8700 {
  public:
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
};
class Shader : public Ref_2a8700 {
  public:
    char pad[0x40 - sizeof(Ref_2a8700)];
    Ref_2a8700* mRef;
    virtual Ref_2a8700* own4();
    void setup(Shader*);
};
extern void* __cdecl alloc(unsigned int);
Ref_2a8700* Shader::own4() {
    Shader* self = this;
    Shader* p = (Shader*)alloc(0x48);
    if (p) {
        p->setup(self);
        *(int*)p = ((int)DAT_0042dd24);
        p->mRef = 0;
        Ref_2a8700* q = self->mRef;
        if (q)
            q->v0();
        if (p->mRef)
            p->mRef->v1();
        p->mRef = q;
        return (Ref_2a8700*)p;
    }
    return 0;
}