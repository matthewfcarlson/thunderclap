struct CasterA {
    CasterA() {}
    virtual void Cast();
};
struct CasterB {
    CasterB() {}
    virtual void Cast();
};
extern const char DAT_0041c1b0[];
extern const char DAT_0041c1a0[];
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
class Registry {
  public:
    void Add(void*);
};
void __cdecl Register(Registry* reg) {
    int slot;
    CasterA* a = reinterpret_cast<CasterA*>(&slot);
    a->CasterA::CasterA();
    reg->Add(FUN_002343e0(DAT_0041c1b0, a));
    CasterB* b = reinterpret_cast<CasterB*>(&slot);
    b->CasterB::CasterB();
    reg->Add(FUN_002343e0(DAT_0041c1a0, b));
}