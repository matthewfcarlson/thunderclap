class Item {
  public:
    void Act(int);
};
extern "C" __int64 __cdecl Lookup(int, int, int);
class Owner {
  public:
    Item* Get(__int64);
    char Run(int, int);
};
char Owner::Run(int key, int value) {
    __int64 id = Lookup(key, 0, 0);
    Item* item = Get(id);
    if (!item)
        return 0;
    item->Act(value);
    return 1;
}