struct C_e37f0;
struct B_e37f0;
struct A_e37f0;

class C_e37f0 {
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
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int GetResult();
};

class B_e37f0 {
  public:
    char pad[4];
    C_e37f0* c;
};
class A_e37f0 {
  public:
    char pad[8];
    B_e37f0* b;
};

class Item_e37f0 {
  public:
    int M(int a, int b);
    char pad[0x38];
};

extern "C" void f7810(int a, int b, int c);

class Obj_e37f0 {
  public:
    char pad1[0x14];
    A_e37f0* a;
    char pad2[0x154 - 0x18];
    int idx;
    Item_e37f0 items[1];
    void target(int p2, int p3);
};

void Obj_e37f0::target(int p2, int p3) {
    C_e37f0* c = a->b->c;
    int r = c->GetResult();
    f7810(items[idx].M(r, 0), p2, p3);
}
