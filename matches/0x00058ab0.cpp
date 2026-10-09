class Condition { public: void init(int); };
class CSmartPropWeaponizableTypeCondition { public: unsigned int vptr; unsigned int a; unsigned int b; unsigned int c; unsigned int d; };
class Factory { public: CSmartPropWeaponizableTypeCondition* vfunc_5(); };
extern void* __cdecl alloc(unsigned int);
CSmartPropWeaponizableTypeCondition* Factory::vfunc_5() {
    CSmartPropWeaponizableTypeCondition* p = (CSmartPropWeaponizableTypeCondition*)alloc(0x14);
    if (p) {
        ((Condition*)p)->init(0);
        p->vptr = 0x3f7130;
        p->c = 0;
        p->d = 0xffffffff;
        return p;
    }
    return 0;
}