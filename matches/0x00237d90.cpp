class ResultObj {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    void init(int a, int b, int c);
};

class Creator {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual ResultObj* create(int a, int b);
};

class Sub {
  public:
    char fn(int a, int b, int c);
};

class SequenceAction {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vfunc_4();
    virtual void vf5();

    char pad[0x18];
    int m1c;
    char pad2[4];
    Creator* mCreator;
    volatile int m28;
    Sub* m2c;
    volatile int m30;
    volatile int m34;
    ResultObj* volatile m38;
};

void SequenceAction::vfunc_4() {
    if (!mCreator)
        return;
    if (!m2c->fn(m1c, m34, 0))
        return;
    ResultObj* edi = mCreator->create(m34, 0);
    if (!edi)
        return;
    edi->vfunc_0();
    ResultObj* cur = m38;
    if (cur)
        cur->vfunc_1();
    m38 = edi;
    edi->init(m30, m34, m28);
}
