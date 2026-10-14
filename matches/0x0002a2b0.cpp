struct Vec {
    unsigned a, b;
};
struct Sub {
    int Lookup(int);
};
struct Obj {
    char pad[0x40];
    int id;
    char pad2[0xa8];
    Sub* ptr;
    Obj* Get(int);
};
extern "C" Vec __cdecl Decode(int, int, int);
extern float* table[];
extern float zero;
class C {
  public:
    Obj* Find(unsigned, unsigned);
    float* Fn(int);
};
float* C::Fn(int x) {
    Vec v = Decode(x, 0, 0);
    Obj* o = Find(v.a, v.b);
    if (!o)
        return &zero;
    o = o->Get(0);
    if (!o)
        return &zero;
    Sub* p = o->ptr;
    if (!p)
        return &zero;
    int id = o->id;
    int n = p->Lookup(id);
    if (n < 1 || n >= 7)
        return &zero;
    return table[n];
}