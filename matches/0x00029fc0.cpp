typedef unsigned __int64 U64;
extern U64 __cdecl lookup(void*, int, int);
struct Item {
    char pad[0x1b28];
    void* value;
};
class Obj {
  public:
    Item* fetch(U64);
    char check(void*);
};
char Obj::check(void* p) {
    U64 id = lookup(p, 0, 0);
    Item* item = fetch(id);
    if (!item)
        return 0;
    return item->value != 0;
}