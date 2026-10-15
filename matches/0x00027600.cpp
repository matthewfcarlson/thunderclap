struct Obj {
    char pad[0x1d28];
    unsigned char flag;
};
class C {
  public:
    Obj* Find(unsigned int a, unsigned int b);
    unsigned char Test(int x);
};
extern "C" unsigned __int64 __cdecl Lookup(int x, int a, int b);
unsigned char C::Test(int x) {
    unsigned __int64 v = Lookup(x, 0, 0);
    Obj* p = Find((unsigned int)v, (unsigned int)(v >> 32));
    if (!p)
        return 1;
    return p->flag;
}