class Obj { public: virtual void A(); virtual void B(); };
struct SubB { void Init(); void Fini(); char pad[0x24]; };
struct SubA { void Init(); void Fini(); char pad[0x20]; };
class Base { public: void Dtor(); };
class Context {
public:
    virtual ~Context();
    char pad4[0x0c];
    Obj* p10;
    SubB b14;
    SubA a38;
    char pad58[4];
    Obj* p5c;
};
Context::~Context() {
    p5c->B();
    if (p10) { p10->B(); p10 = 0; }
    a38.Init();
    a38.Fini();
    b14.Init();
    b14.Fini();
    Base* b = (Base*)this;
    b->Dtor();
}
