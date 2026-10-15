class Obj {
  public:
    float Value();
};
class X {
  public:
    Obj* Find(unsigned __int64);
    float Fn(const char*);
};
extern "C" unsigned __int64 __cdecl Hash(const char*, int, int);
float X::Fn(const char* s) {
    unsigned __int64 h = Hash(s, 0, 0);
    Obj* p = Find(h);
    if (!p)
        return 0.0f;
    return p->Value();
}