extern "C" int __cdecl check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
class Caster {
  public:
    virtual int Test(void*);
    virtual void Other();
};
int Caster::Test(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}