class Item_f7ce0 {
  public:
    virtual void a();
    virtual void Release();
};
class Obj_f7ce0 {
  public:
    char pad[0x24];
    Item_f7ce0* items[25];
    int count;
    void Clear();
};
void Obj_f7ce0::Clear() {
    int i = 0;
    if (count > 0) {
        Item_f7ce0** p = items;
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