struct CasterA {
    CasterA() {}
    virtual void Cast();
};
struct CasterB {
    CasterB() {}
    virtual void Cast();
};
extern const char nameA[];
extern const char nameB[];
extern "C" void* __cdecl Find(const char*, void*);
class Registry {
  public:
    void Add(void*);
};
void __cdecl Register(Registry* reg) {
    int slot;
    CasterA* a = reinterpret_cast<CasterA*>(&slot);
    a->CasterA::CasterA();
    reg->Add(Find(nameA, a));
    CasterB* b = reinterpret_cast<CasterB*>(&slot);
    b->CasterB::CasterB();
    reg->Add(Find(nameB, b));
}