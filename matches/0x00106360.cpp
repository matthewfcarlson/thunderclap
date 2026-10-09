extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

class Item { public: virtual void f(); virtual void Release(); };
class Container {
public:
    char pad0[8];
    int count;
    Item** items;
    bool Remove(int index);
};

bool Container::Remove(int index) {
    if (index < 0 || index >= count) return false;
    items[index]->Release();
    --count;
    memmove(&items[index], &items[index + 1], (count - index) * 4);
    return true;
}