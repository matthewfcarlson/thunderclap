extern void* g_vftable_12bc30[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Str_12bc30 {
  public:
    void Init();
};
class Base_12bc30 {
  public:
    void* vptr;
    char pad[20];
    Str_12bc30 s;
    void Fin();
};
class Cond_12bc30 : public Base_12bc30 {
  public:
    void* Del(unsigned char flags);
};
void* Cond_12bc30::Del(unsigned char flags) {
    vptr = g_vftable_12bc30;
    s.Init();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
