class Elem_1fc600 {
  public:
    void Destroy();
};
class CEncounterGenerator {
  public:
    virtual void A();
    virtual void B();
    virtual CEncounterGenerator* vfunc_2(unsigned char);
    virtual void D();
    virtual void E();
};
extern void BaseDestroy(void*);
extern void BaseDestroyVec(void*);
CEncounterGenerator* CEncounterGenerator::vfunc_2(unsigned char flags) {
    if (flags & 2) {
        char* base = (char*)this - 4;
        int n = *(int*)base;
        char* end = (char*)this + n * 0xc70;
        int test = n - 1;
        if (test >= 0) {
            int i = test + 1;
            do {
                end -= 0xc70;
                ((Elem_1fc600*)end)->Destroy();
                --i;
            } while (i != 0);
        }
        if (flags & 1)
            BaseDestroyVec(base);
        return (CEncounterGenerator*)base;
    }
    ((Elem_1fc600*)this)->Destroy();
    if (flags & 1)
        BaseDestroy(this);
    return this;
}