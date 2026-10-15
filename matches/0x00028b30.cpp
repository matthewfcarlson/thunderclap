struct Item {
    char pad[0x324];
    int value;
};
extern "C" unsigned __int64 __cdecl conv(int, int, int);
class Obj {
  public:
    Item* lookup(unsigned, unsigned);
    void fn(int, int);
};
void Obj::fn(int arg, int value) {
    unsigned __int64 key = conv(arg, 0, 0);
    Item* p = lookup((unsigned)key, (unsigned)(key >> 32));
    if (p)
        p->value = value;
}