extern "C" char DAT_00421abc[];
struct Thing {
    virtual void Run();
    Thing* Init(unsigned p);
};
extern Thing* __cdecl Alloc(unsigned n);
class LevelLoader {
  public:
    unsigned vptr;
    int m4, m8, mc, m10;
    unsigned m14, m18;
    Thing* m1c;
    LevelLoader(unsigned a, unsigned b);
};
LevelLoader::LevelLoader(unsigned a, unsigned b) {
    m4 = 0;
    m8 = 0x60000700;
    mc = 0;
    m10 = 0;
    vptr = ((int)DAT_00421abc);
    m14 = a;
    m18 = b;
    Thing* t = Alloc(0x18);
    Thing* r;
    if (t)
        r = t->Init(m14);
    else
        r = 0;
    m1c = r;
    r->Run();
}
