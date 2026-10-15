class Item {
  public:
    void Apply(int);
};
class Obj {
  public:
    Item* Lookup(__int64);
    void Run(int key, int value);
};
extern "C" __int64 __cdecl GetPair(int, int, int);
void Obj::Run(int key, int value) {
    __int64 pair = GetPair(key, 0, 0);
    Item* item = Lookup(pair);
    if (item)
        item->Apply(value);
}