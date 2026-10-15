struct Obj {
    char pad[0x1cf8];
    int value;
};
class C {
  public:
    Obj* Get(unsigned, unsigned);
    void Set(unsigned id, int v);
};
extern "C" unsigned __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
void C::Set(unsigned id, int v) {
    unsigned __int64 x = FUN_002672f0(id, 0, 0);
    Obj* p = Get((unsigned)x, (unsigned)(x >> 32));
    if (p)
        p->value = v;
}