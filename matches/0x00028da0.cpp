extern "C" __int64 __cdecl FindThing(void*, int, int);
struct Item {
    char pad[0x1ca0];
    struct Flag* flag;
};
struct Flag {
    char pad[0xe9];
    unsigned char value;
};
class Owner {
  public:
    Item* Get(__int64);
    void Act(void*);
};
void Owner::Act(void* p) {
    __int64 id = FindThing(p, 0, 0);
    Item* item = Get(id);
    if (item && item->flag)
        item->flag->value = 0;
}