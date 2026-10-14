extern "C" char DAT_00425c28[];
extern void* __cdecl Alloc(unsigned int);
struct Loader_2062d0 {
    unsigned int vptr;
    int a;
    int b;
    int c;
    int d;
    void* owner;
};
class Manager_2062d0 {
  public:
    void Register(Loader_2062d0*, unsigned int);
};
extern Manager_2062d0* gManager_2062d0;
class Owner_2062d0 {
  public:
    char pad[0x588];
    int param;
    void Target(int);
};
void Owner_2062d0::Target(int value) {
    param = value;
    Loader_2062d0* r;
    Loader_2062d0* p = (Loader_2062d0*)Alloc(0x18);
    if (p != 0) {
        p->a = 0;
        p->b = 0x60000722;
        p->c = 0;
        p->d = 0;
        p->vptr = ((int)DAT_00425c28);
        p->owner = this;
        r = p;
    } else {
        r = 0;
    }
    gManager_2062d0->Register(r, 0x60000722);
}
