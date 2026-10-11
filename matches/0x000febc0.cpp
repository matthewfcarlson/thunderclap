class type_info;
class X {
  public:
    virtual void F();
    virtual void D();
};
class V : public X {};
class Owner {
  public:
    X* Find(const type_info&);
};
class Factory {
  public:
    V* Make(Owner*);
};
extern "C" void* __cdecl FUN_00266da0(int);
extern "C" void* __cdecl FUN_0008d690(int);
void __cdecl FUN_000febc0(Owner* owner, V** out) {
    X* p = owner->Find(typeid(V));
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
            q = ((Factory*)a)->Make(owner);
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
