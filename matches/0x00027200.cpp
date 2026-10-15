typedef unsigned __int64 U64;
struct Item {
    char pad[0x2138];
    char flag;
};
extern "C" U64 __cdecl Lookup(int, int, int);
class Owner {
  public:
    Item* Find(U64);
    void Set(int, char);
};
void Owner::Set(int x, char v) {
    U64 key = Lookup(x, 0, 0);
    Item* p = Find(key);
    if (p)
        p->flag = v;
}