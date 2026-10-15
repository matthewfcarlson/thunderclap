class Thing {
  public:
    char pad[0x1ac];
    float value;
};
class Mgr {
  public:
    Thing* get(unsigned a, unsigned b);
};
class Obj {
  public:
    char pad[4];
    Mgr* mgr;
    float fn(const char* s);
};
extern "C" unsigned __int64 __cdecl parse(const char* s);
extern const float zero;
float Obj::fn(const char* s) {
    Mgr* m = mgr;
    unsigned __int64 id = parse(s);
    Thing* t = m->get((unsigned)id, (unsigned)(id >> 32));
    if (!t)
        return zero;
    return t->value;
}