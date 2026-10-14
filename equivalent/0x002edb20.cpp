// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 6/6)
// FUN_002edb20 @ 0x002edb20
class Handler_2edb20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual int GetKind();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15();
    virtual unsigned char Handle(int a, int b, int c);
};
struct Entry_2edb20 {
    char pad[0x10];
    Handler_2edb20* handler;
};
struct Sub_2edb20 {
    void FUN_003037e0();
};
class Mgr_2edb20 {
  public:
    char pad00[0x3c];
    Entry_2edb20** begin;
    Entry_2edb20** end;
    char pad44[0x1b0 - 0x44];
    Sub_2edb20 sub;
    unsigned char FUN_002edb20(int a, int b, int c);
};
unsigned char Mgr_2edb20::FUN_002edb20(int a, int b, int c) {
    unsigned char result = 0;
    sub.FUN_003037e0();
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Handler_2edb20* h = begin[i]->handler;
        if (h->GetKind() == 4)
            result |= h->Handle(a, b, c);
    }
    return result;
}
