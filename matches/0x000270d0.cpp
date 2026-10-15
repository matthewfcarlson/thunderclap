struct Item {
    char pad[0x39c];
    int value;
};
extern "C" __int64 __cdecl lookup(int, int, int);
class Obj {
  public:
    Item* get(__int64);
    void fn(int id, int value);
};
void Obj::fn(int id, int value) {
    __int64 key = lookup(id, 0, 0);
    Item* p = get(key);
    if (p)
        p->value = value;
}