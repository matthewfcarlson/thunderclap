class Obj_2368d0 {
  public:
    virtual void A();
    virtual void B();
};
struct SubB_2368d0 {
    void Init();
    void Fini();
    char pad[0x24];
};
struct SubA_2368d0 {
    void Init();
    void Fini();
    char pad[0x20];
};
class Context_2368d0 {
  public:
    void Dtor();
};
class Context {
  public:
    virtual ~Context();
    char pad4[0x0c];
    Obj_2368d0* p10;
    SubB_2368d0 b14;
    SubA_2368d0 a38;
    char pad58[4];
    Obj_2368d0* p5c;
};
Context::~Context() {
    p5c->B();
    if (p10) {
        p10->B();
        p10 = 0;
    }
    a38.Init();
    a38.Fini();
    b14.Init();
    b14.Fini();
    Context_2368d0* b = (Context_2368d0*)this;
    b->Dtor();
}
