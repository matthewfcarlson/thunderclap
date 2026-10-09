struct Child {
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
    virtual void Fn23();
};
struct Group {
    int pad;
    Child** begin;
    Child** end;
    int pad2;
};
struct DC {
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
    char p[0x44];
    Group* gb;
    Group* ge;
};
void DC::v9() {
    unsigned n = ge - gb;
    for (unsigned i = 0; i < n; i++) {
        Group* g = &gb[i];
        unsigned m = g->end - g->begin;
        for (unsigned j = 0; j < m; j++) {
            Child* c = g->begin[j];
            if (c)
                c->Fn23();
        }
    }
}
