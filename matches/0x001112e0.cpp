class Caster {
  public:
    virtual bool check(void*);
    virtual void other();
};
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;
bool Caster::check(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}