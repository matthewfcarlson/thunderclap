class Obj;
struct LB {
    LB* next;
};
class Node : public LB {
  public:
};
struct NodeA {
    virtual void A();
    virtual void X();
    virtual void B(Obj*, int);
};
struct Node2 : NodeA, LB {};
class Inner {
  public:
    virtual void A();
    virtual void X();
    virtual void B(Obj*);
};
class Obj {
  public:
    char pad0[0x30];
    Inner* m30;
    void* m34;
    char pad38[8];
    LB* m40;
    void* m44;
    int m48;
    LB* m4c;
    char pad50[8];
    int m58;
    char m5c;
    void Fn(void*, char);
    void End(int);
    void Db30();
};
void FUN_0025dcb0(void*);
void FUN_0024bae0(void*, int);
void Obj::Fn(void* p, char mode) {
    m58 = 1;
    m5c = 0;
    if (mode == 1 || ((static_cast<Node2*>(m4c) == 0) && (static_cast<Node2*>(m40) == 0)) ||
        !(*(char*)((char*)m30 + 0x44) & 2)) {
        FUN_0025dcb0(&m40);
        m48 = 0;
        Db30();
        ((Inner*)((char*)m30 + 0x1c))->B(this);
    } else {
        for (Node2* n = static_cast<Node2*>(m40); n; n = static_cast<Node2*>(n->next))
            n->B(this, 0);
    }
    if (p) {
        m34 = p;
        FUN_0024bae0(p, 0);
    }
    End(0);
}
