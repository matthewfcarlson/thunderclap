extern int gDummy;

void __cdecl FUN_00267090(void*);
void __cdecl FUN_00267091(void*);

struct Elem_1cc570 {
    char pad[0x28];
    void dtor();
};

class CEventManager {
  public:
    void* mVptr;
    int a[2];
    void* mPtr;
    void* mPtr2;
    char pad[0x10];
    Elem_1cc570 mArr[0x18];

    void* vfunc_0(unsigned char param_2);
};

void* CEventManager::vfunc_0(unsigned char param_2) {
    mVptr = &gDummy;
    Elem_1cc570* p = mArr + 0x18;
    for (int i = 0; i < 0x18; ++i) {
        --p;
        p->dtor();
    }
    void* t = mPtr;
    mPtr2 = t;
    if (t) {
        FUN_00267090(t);
    }
    if (param_2 & 1) {
        FUN_00267091(this);
    }
    return this;
}
