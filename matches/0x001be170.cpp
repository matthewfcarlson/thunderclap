void* operator new(unsigned int) throw();
int Push(int) throw();

struct CDropShadowDisplayEffect_1be170 {
    void Init() throw();
};
struct Node2_1be170 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int, bool);
};
struct Shader_1be170 {
    int pad[3];
    Node2_1be170* c;
    int pad2[3];
    virtual void init();
    Shader_1be170() throw();
};
class Overlay_1be170 {
  public:
    virtual void f0();
    bool b4;
    Overlay_1be170() throw() { b4 = true; }
};
class CSubtitleOverlay : public Overlay_1be170 {
  public:
    int m8;
    char mc;
    int m10;
    int m14;
    Shader_1be170* m18;
    char pad[0x11c - 0x1c];
    char b11c;
    char b11d;
    char pad2[2];
    CDropShadowDisplayEffect_1be170 sub;
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
    m18 = new Shader_1be170;
    m18->init();
    Shader_1be170* q = m18;
    q->c->v6(0x444d4c42, true);
    Push(old);
}
