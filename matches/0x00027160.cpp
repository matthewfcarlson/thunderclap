typedef __int64 I64;
extern "C" I64 __cdecl Parse(int, int, int);
class Obj {
  public:
    void* Lookup(I64);
    unsigned char Check(int);
};
unsigned char Obj::Check(int x) {
    I64 v = Parse(x, 0, 0);
    unsigned char* p = (unsigned char*)Lookup(v);
    if (!p)
        return 0;
    return p[0x1d4d];
}
