struct Result {
    char pad[0x1d05];
    unsigned char val;
};
class Obj {
  public:
    Result* lookup(int, int);
    unsigned char fn(int);
};
extern "C" unsigned __int64 __cdecl fetch(int, int, int);
unsigned char Obj::fn(int x) {
    unsigned __int64 v = fetch(x, 0, 0);
    Result* p = lookup((int)v, (int)(v >> 32));
    if (!p)
        return 1;
    return p->val;
}