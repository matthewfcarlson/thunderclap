extern "C" char DAT_00411244[];
extern "C" void* __cdecl Alloc(unsigned int);
class Obj_1327f0 {
  public:
    void Init(int);
    char pad[12];
    int z;
    char c;
};
class Factory_1327f0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj_1327f0* Make();
};
Obj_1327f0* Factory_1327f0::Make() {
    Obj_1327f0* p = (Obj_1327f0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_00411244);
        p->z = 0;
        p->c = 0;
        return p;
    }
    return 0;
}