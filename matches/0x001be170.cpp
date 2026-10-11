void* operator new(unsigned int) throw();
int Push(int) throw();

struct Sub {
    void Init() throw();
};
struct Node2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int, bool);
};
struct Node {
    int pad[3];
    Node2* c;
    int pad2[3];
    virtual void init();
    Node() throw();
};
class Base {
  public:
    virtual void f0();
    bool b4;
    Base() throw() { b4 = true; }
};
class CSubtitleOverlay : public Base {
  public:
    int m8;
    char mc;
    int m10;
    int m14;
    Node* m18;
    char pad[0x11c - 0x1c];
    char b11c;
    char b11d;
    char pad2[2];
    Sub sub;
    virtual void f0();
    CSubtitleOverlay() throw();
};
CSubtitleOverlay::CSubtitleOverlay() throw() {
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    b11c = 0;
    b11d = 0;
    sub.Init();
    int old = Push(0xe);
    m18 = new Node;
    m18->init();
    Node* q = m18;
    q->c->v6(0x444d4c42, true);
    Push(old);
}
