extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
class Item_30fea0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_30fea0 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    int* counts;
    Item_30fea0*** items;
    bool Remove(int i, int j);
};
bool Container_30fea0::Remove(int i, int j) {
    if (i < 0 || i >= count)
        return false;
    if (j < 0 || j >= counts[i])
        return false;
    items[i][j]->B();
    --counts[i];
    memmove(&items[i][j], &items[i][j + 1], (counts[i] - j) * 4);
    return true;
}