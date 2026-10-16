struct Base {
    virtual bool Check(void*);
    virtual void other();
};
struct Caster : Base {
    virtual bool Check(void*);
    virtual void other();
};
extern "C" int __cdecl Lookup(void*, int, void*, void*, int);
extern void* a;
extern void* b;
bool Caster::Check(void* p) {
    return Lookup(p, 0, &a, &b, 0) != 0;
}