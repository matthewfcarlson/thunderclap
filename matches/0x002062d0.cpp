extern "C" char DAT_00425c28[];
extern void* __cdecl Alloc(unsigned int);
struct Loader {
    unsigned int vptr;
    int a;
    int b;
    int c;
    int d;
    void* owner;
};
class Manager {
  public:
    void Register(Loader*, unsigned int);
};
extern Manager* gManager;
class Owner {
  public:
    char pad[0x588];
    int param;
    void Target(int);
};
void Owner::Target(int value) {
    param = value;
    Loader* r;
    Loader* p = (Loader*)Alloc(0x18);
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
    gManager->Register(r, 0x60000722);
}
