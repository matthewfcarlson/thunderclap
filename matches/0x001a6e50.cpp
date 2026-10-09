class Obj {
  public:
    Obj* Get();
    Obj* Target();
};
extern int __cdecl Find(Obj*, int, const char*, const char*, int);
Obj* Obj::Target() {
    Obj* p = Get();
    while (p && Find(p, 0, (const char*)0x48d5bc, (const char*)0x4c26a4, 0) == 0)
        p = Get();
    return p;
}