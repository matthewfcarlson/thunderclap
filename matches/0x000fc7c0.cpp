extern void* g_vftable_fc7c0[];
void operator delete(void*);
class Ref_fc7c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Agent_fc7c0 {
  public:
    void* vptr;
    char pad[0x54];
    Ref_fc7c0* m58;
    void Fin();
    void* Del(unsigned char flags);
};
void* Agent_fc7c0::Del(unsigned char flags) {
    Ref_fc7c0* r = m58;
    vptr = g_vftable_fc7c0;
    r->Release();
    m58 = 0;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
