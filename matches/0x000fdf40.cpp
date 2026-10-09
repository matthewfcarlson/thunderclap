class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Set(int);
    virtual int Get();
    char pad[0x58 - 4];
    struct Block {
        char p[8];
        int key;
        char q[6];
        unsigned char flag12;
        int value14;
        char r[0x1c];
        float value34;
        char s[0x38];
        unsigned char flag70;
        unsigned char flag71;
    } block;
    void Target(int);
};
void Obj::Target(int x) {
    Block* b = &block;
    if (x != 0 && b != 0 && b->key == x) {
        b->flag12 = 0;
        b->value14 = 0x40000000;
        b->value34 = 120.0f;
        b->flag70 = 0;
        b->flag71 = 1;
        int n = Get();
        if (n > 2)
            Set(2);
    }
}