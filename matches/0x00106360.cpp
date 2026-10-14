extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

class Item_106360 {
  public:
    virtual void f();
    virtual void Release();
};
class Container_106360 {
  public:
    char pad0[8];
    int count;
    Item_106360** items;
    bool Remove(int index);
};

bool Container_106360::Remove(int index) {
    if (index < 0 || index >= count)
        return false;
    items[index]->Release();
    --count;
    memmove(&items[index], &items[index + 1], (count - index) * 4);
    return true;
}