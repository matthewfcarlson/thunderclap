struct Item_44b30 {
    char pad[0x3b0];
    char a[0x40];
    char b[0x40];
};
long long GetId(void* p);
class Mgr_44b30 {
  public:
    char pad[0xc];
    int mCount;
    Item_44b30** mItems;
    Item_44b30* Find(long long id);
};
Item_44b30* Mgr_44b30::Find(long long id) {
    for (int i = 0; i < mCount; i++) {
        Item_44b30* it = mItems[i];
        if (it) {
            bool hit = GetId(it->b) == id;
            if (!hit) {
                Item_44b30* q = mItems[i];
                hit = GetId(q->a) == id;
            }
            if (hit)
                return mItems[i];
        }
    }
    return 0;
}
