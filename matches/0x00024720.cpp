extern "C" void* memmove(void*, const void*, unsigned int);
class ItemList_24720 {
  public:
    char pad0[0x228];
    char pad1[0x100];
    int count;
    int Find(int, int);
    bool Remove(int, int);
};
bool ItemList_24720::Remove(int a, int b) {
    int index = Find(a, b);
    if (index == -1)
        return false;
    int n = --count;
    memmove((char*)this + 0x228 + index * 8, (char*)this + 0x230 + index * 8, (n - index) * 8);
    return true;
}