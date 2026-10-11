extern "C" char DAT_004144e0[];
extern "C" void* __cdecl Alloc(unsigned int);
class Obj {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    virtual void* E();
    virtual void* F();
    void Init();
    char pad[4];
    int x;
    int y;
    float z;
};
void* Obj::F() {
    Obj* p = (Obj*)Alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_004144e0);
        p->y = 0;
        p->z = -1.0f;
        p->x = 1;
        return p;
    }
    return 0;
}