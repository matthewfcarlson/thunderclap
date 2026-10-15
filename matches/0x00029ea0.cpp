typedef __int64 i64;
struct Item {
    char pad[0x32c];
    char flag;
};
extern "C" i64 __cdecl Fetch(void*, int, int);
class Obj {
  public:
    Item* Find(i64);
    unsigned char Check(void*);
};
unsigned char Obj::Check(void* p) {
    i64 value = Fetch(p, 0, 0);
    Item* item = Find(value);
    if (!item)
        return 0;
    return item->flag;
}
