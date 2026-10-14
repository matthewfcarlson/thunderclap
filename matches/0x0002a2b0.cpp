struct Vec_2a2b0 {
    unsigned a, b;
};
struct Sub_2a2b0 {
    int Lookup(int);
};
struct Obj_2a2b0 {
    char pad[0x40];
    int id;
    char pad2[0xa8];
    Sub_2a2b0* ptr;
    Obj_2a2b0* Get(int);
};
extern "C" Vec_2a2b0 __cdecl Decode(int, int, int);
extern float* table_2a2b0[];
extern float zero_2a2b0;
class C_2a2b0 {
  public:
    Obj_2a2b0* Find(unsigned, unsigned);
    float* Fn(int);
};
float* C_2a2b0::Fn(int x) {
    Vec_2a2b0 v = Decode(x, 0, 0);
    Obj_2a2b0* o = Find(v.a, v.b);
    if (!o)
        return &zero_2a2b0;
    o = o->Get(0);
    if (!o)
        return &zero_2a2b0;
    Sub_2a2b0* p = o->ptr;
    if (!p)
        return &zero_2a2b0;
    int id = o->id;
    int n = p->Lookup(id);
    if (n < 1 || n >= 7)
        return &zero_2a2b0;
    return table_2a2b0[n];
}