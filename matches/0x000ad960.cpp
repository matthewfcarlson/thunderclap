// Same code shape as 0x000ad930 (propagated; names are from that function)
class Item { public: void Release(); };
class Owner {
public:
    char pad0[0x10];
    int count;
    Item** items;
    void Clear();
};
void Owner::Clear() {
    for (int i = 0; i < count; ++i) {
        Item* p = items[i];
        if (p) p->Release();
    }
}