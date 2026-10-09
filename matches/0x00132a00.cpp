extern void* __cdecl Alloc(unsigned int);
extern int LocationVtable;
struct LocationCondition { virtual void f0(); char pad[8]; int a,b,c,d; void Init(int); };
void* FactoryVfunc5() {
    LocationCondition* p = (LocationCondition*)Alloc(0x1c);
    if (p) {
        p->Init(0);
        p->a = 0; p->b = 0; p->c = 0; p->d = 0;
        *(int*)p = (int)&LocationVtable;
        return p;
    }
    return 0;
}