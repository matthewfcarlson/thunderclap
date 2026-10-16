struct Data {
    int x;
};
extern Data a, b;
extern int __cdecl check(void*, int, Data*, Data*, int);
class Caster {
  public:
    virtual bool Match(void* p);
    virtual void Other();
};
bool Caster::Match(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}