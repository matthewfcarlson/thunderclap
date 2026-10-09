struct Child {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetType();
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
    virtual bool Do(int a, int b);
};
struct Item {
    char pad[0x10];
    Child* c;
};
struct Sub {
    void Prep();
};
struct Vec {
    Item** b;
    Item** e;
    unsigned size() const { return e - b; }
    Item*& operator[](unsigned i) { return b[i]; }
};
struct T {
    char pad[0x3c];
    Vec v;
    char pad2[0x1b0 - 0x44];
    Sub sub;
    bool Run(int a, int b);
};
bool T::Run(int a, int p) {
    bool r = false;
    sub.Prep();
    for (unsigned i = 0; i < v.size(); i++) {
        Child* c = v[i]->c;
        if (c->GetType() == 4)
            r |= c->Do(a, p);
    }
    return r;
}
