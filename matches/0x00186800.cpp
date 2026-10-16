class Caster {
  public:
    virtual int Check(void*);
    virtual void Other();
};
extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern int a, b;
int Caster::Check(void* p) {
    return Find(p, 0, &a, &b, 0) != 0;
}