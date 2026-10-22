extern void* g_vftable_10e8a0[];
void operator delete(void*);
void operator delete[](void*);
class Condition_10e8a0 {
  public:
    void* vptr;
    void Fin();
};
class KeyWordWaitCondition_10e8a0 : public Condition_10e8a0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    KeyWordWaitCondition_10e8a0* f5(unsigned char flags);
};
KeyWordWaitCondition_10e8a0* KeyWordWaitCondition_10e8a0::f5(unsigned char flags) {
    void* p = m10;
    vptr = g_vftable_10e8a0;
    operator delete[](p);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
