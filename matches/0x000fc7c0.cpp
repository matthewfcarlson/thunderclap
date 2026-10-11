extern void* g_vftable[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Agent {
  public:
    void* vptr;
    char pad[0x54];
    Ref* m58;
    void Fin();
    void* Del(unsigned char flags);
};
void* Agent::Del(unsigned char flags) {
    Ref* r = m58;
    vptr = g_vftable;
    r->Release();
    m58 = 0;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
