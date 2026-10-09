class Obj {
  public:
    virtual void f0();
    Obj* operator=(const Obj& o);
    int a4, a8, ac, a10, a14, a18, a1c, a20, a24, a28;
    int a2c;
    int a30, a34, a38, a3c, a40, a44, a48, a4c, a50, a54, a58;
    char b5c, b5d;
    int a60;
};

Obj* Obj::operator=(const Obj& o) {
    a4 = o.a4;
    a8 = o.a8;
    ac = o.ac;
    a10 = o.a10;
    a14 = o.a14;
    a18 = o.a18;
    a1c = o.a1c;
    a20 = o.a20;
    a24 = o.a24;
    a28 = o.a28;
    a30 = o.a30;
    a34 = o.a34;
    a38 = o.a38;
    a3c = o.a3c;
    a40 = o.a40;
    a44 = o.a44;
    a48 = o.a48;
    a4c = o.a4c;
    a50 = o.a50;
    a54 = o.a54;
    a58 = o.a58;
    b5c = o.b5c;
    b5d = o.b5d;
    a60 = o.a60;
    return this;
}
