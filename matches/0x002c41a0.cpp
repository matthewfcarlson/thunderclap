struct T {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int);
    char pad[0x64 - 4];
    int f1, f2, f3;
    void Set(int x, int y, int z);
};

void T::Set(int x, int y, int z) {
    f1 = x;
    f2 = y;
    f3 = z;
    v9(0);
}
