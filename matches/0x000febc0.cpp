class type_info;
class X_febc0 {
  public:
    virtual void F();
    virtual void D();
};
class V : public X_febc0 {};
class Owner_febc0 {
  public:
    X_febc0* Find(const type_info&);
};
class Factory_febc0 {
  public:
    V* Make(Owner_febc0*);
};
extern "C" void* __cdecl FUN_00266da0(int);
extern "C" void* __cdecl FUN_0008d690(int);
void __cdecl FUN_000febc0(Owner_febc0* owner, V** out) {
    X_febc0* p = owner->Find(typeid(V));
    if (p) {
        V* q = dynamic_cast<V*>(p);
        if (q)
            q->F();
        if (*out)
            (*out)->D();
        *out = q;
    }
    if (!*out) {
        void* b = FUN_00266da0(0xc);
        void* a = FUN_0008d690(0xfc);
        V* q;
        if (a)
            q = ((Factory_febc0*)a)->Make(owner);
        else
            q = 0;
        if (q)
            q->F();
        if (*out)
            (*out)->D();
        *out = q;
        FUN_00266da0((int)b);
    }
}
