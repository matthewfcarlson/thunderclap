extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004c26a4[];
class Obj {
  public:
    Obj* Get();
    Obj* Target();
};
extern int __cdecl Find(Obj*, int, const char*, const char*, int);
Obj* Obj::Target() {
    Obj* p = Get();
    while (p && Find(p, 0, (const char*)((int)DAT_0048d5bc), (const char*)((int)DAT_004c26a4), 0) == 0)
        p = Get();
    return p;
}