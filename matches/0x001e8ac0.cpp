struct Item {
    char pad[12];
    int refs;
};
class Obj {
  public:
    char a[0x24];
    int count;
    char b[4];
    Item* items[64];
    void Release();
};
void Obj::Release() {
    for (int i = 0; i < *(int*)((char*)this + 0x12c); ++i) {
        if (items[i])
            --items[i]->refs;
    }
    --count;
}