extern "C" char DAT_003f6f34[];
void* __cdecl Alloc(unsigned int);
struct CAxisDirectionCondition {
    int vt;
    void Init(int);
    char pad[8];
    int a;
    int b;
    int c;
};
class Factory {
  public:
    CAxisDirectionCondition* vfunc_5();
};
CAxisDirectionCondition* Factory::vfunc_5() {
    CAxisDirectionCondition* p = (CAxisDirectionCondition*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_003f6f34);
        p->a = 0;
        p->b = 0;
        p->c = 0x3fc90fdb;
        return p;
    }
    return 0;
}
