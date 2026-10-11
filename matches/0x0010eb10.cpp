extern void* g_vftable[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Str {
  public:
    void Init();
};
class Base {
  public:
    void* vptr;
    char pad[20];
    Str s;
    void Fin();
};
class Cond : public Base {
  public:
    void* Del(unsigned char flags);
};
void* Cond::Del(unsigned char flags) {
    vptr = g_vftable;
    s.Init();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
