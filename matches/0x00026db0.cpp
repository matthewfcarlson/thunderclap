extern "C" __int64 __cdecl lookup(void*, int, int);
class Item {
  public:
    void Set(float);
};
class Owner {
  public:
    Item* Find(__int64);
    void Do(void*, float);
};
void Owner::Do(void* name, float angle) {
    __int64 id = lookup(name, 0, 0);
    Item* item = Find(id);
    if (item)
        item->Set(angle * 0.017453292519943295f);
}
