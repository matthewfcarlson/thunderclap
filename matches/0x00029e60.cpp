extern "C" __int64 __cdecl Lookup(void*, int, int);
struct Item {
    char pad[0x1b20];
    int count;
};
class Obj {
  public:
    Item* Find(__int64);
    bool Check(void*);
};
bool Obj::Check(void* p) {
    __int64 id = Lookup(p, 0, 0);
    Item* item = Find(id);
    if (!item)
        return false;
    return item->count > 0;
}