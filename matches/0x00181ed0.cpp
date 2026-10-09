class Model {
  public:
    char pad[0x128];
    void* field;
    void Update(unsigned char);
    void Apply(void*, void*);
};
class Actor {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    Actor* Get();
    Model* ModelFor();
};
struct Vec {
    int a, b, c;
};
class PropActorThinkingAction {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual bool vfunc_3(int, int);
    virtual void E();
    virtual void F();
    char pad[0x18];
    Actor* actor;
    Actor* context;
};
bool PropActorThinkingAction::vfunc_3(int a, int b) {
    Actor* x = context;
    Actor* y = x->Get();
    Model* m = y->ModelFor();
    unsigned char v = *((unsigned char*)actor + 0x10);
    m->Update(v);
    if (!v) {
        void* p = *((void**)((char*)m + 0x128));
        if (p) {
            void* q = context->D();
            if (q) {
                Vec t = *((Vec*)((char*)q + 0x38));
                ((Model*)p)->Apply(&t, (char*)q + 8);
            }
        }
    }
    return true;
}