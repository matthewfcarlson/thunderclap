struct Sub {
    char f[0xdc];
    char Check();
};
struct Obj {
    char pad[0x338];
    void* p;
};
extern "C" unsigned __int64 __cdecl Find(void*, int, int);
class Host {
  public:
    Obj* Get(unsigned __int64);
    char Test(void*);
};
char Host::Test(void* x) {
    unsigned __int64 n = Find(x, 0, 0);
    Obj* p = Get(n);
    if (!p)
        return 0;
    if (p->p)
        return 1;
    Sub* q = (Sub*)((char*)p + 0xdc);
    if (!q)
        return 0;
    return q->Check();
}