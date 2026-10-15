struct Item {
    char pad[0x2140];
    char flag;
};
class Obj {
  public:
    Item* get(unsigned a, unsigned b);
    Item* lookup(unsigned lo, unsigned hi);
};
extern "C" unsigned __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
Item* Obj::get(unsigned a, unsigned b) {
    unsigned __int64 n = FUN_002672f0(a, 0, 0);
    Item* p = lookup((unsigned)n, (unsigned)(n >> 32));
    if (p)
        p->flag = (char)b;
    return p;
}