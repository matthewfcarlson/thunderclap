class Obj_25dfc0;
struct LB_25dfc0 {
    LB_25dfc0* next;
};
class Node : public LB_25dfc0 {
  public:
};
struct NodeA_25dfc0 {
    virtual void A();
    virtual void X();
    virtual void B(Obj_25dfc0*, int);
};
struct Node2_25dfc0 : NodeA_25dfc0, LB_25dfc0 {};
class Inner_25dfc0 {
  public:
    virtual void A();
    virtual void X();
    virtual void B(Obj_25dfc0*);
};
class Obj_25dfc0 {
  public:
    char pad0[0x30];
    Inner_25dfc0* m30;
    void* m34;
    char pad38[8];
    LB_25dfc0* m40;
    void* m44;
    int m48;
    LB_25dfc0* m4c;
    char pad50[8];
    int m58;
    char m5c;
    void Fn(void*, char);
    void End(int);
    void Db30();
};
void FUN_0025dcb0(void*);
void FUN_0024bae0(void*, int);
void Obj_25dfc0::Fn(void* p, char mode) {
    m58 = 1;
    m5c = 0;
    if (mode == 1 || ((static_cast<Node2_25dfc0*>(m4c) == 0) && (static_cast<Node2_25dfc0*>(m40) == 0)) ||
        !(*(char*)((char*)m30 + 0x44) & 2)) {
        FUN_0025dcb0(&m40);
        m48 = 0;
        Db30();
        ((Inner_25dfc0*)((char*)m30 + 0x1c))->B(this);
    } else {
        for (Node2_25dfc0* n = static_cast<Node2_25dfc0*>(m40); n; n = static_cast<Node2_25dfc0*>(n->next))
            n->B(this, 0);
    }
    if (p) {
        m34 = p;
        FUN_0024bae0(p, 0);
    }
    End(0);
}
