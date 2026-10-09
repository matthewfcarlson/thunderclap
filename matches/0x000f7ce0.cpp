class Item {
  public:
    virtual void a();
    virtual void Release();
};
class Obj {
  public:
    char pad[0x24];
    Item* items[25];
    int count;
    void Clear();
};
void Obj::Clear() {
    int i = 0;
    if (count > 0) {
        Item** p = items;
        do {
            if (*p) {
                (*p)->Release();
                *p = 0;
            }
            *p = 0;
            ++i;
            ++p;
        } while (i < count);
    }
    count = 0;
}