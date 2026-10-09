struct Item {
    char pad[0x3b0];
    char a[0x40];
    char b[0x40];
};
long long GetId(void* p);
class Mgr {
  public:
    char pad[0xc];
    int mCount;
    Item** mItems;
    Item* Find(long long id);
};
Item* Mgr::Find(long long id) {
    for (int i = 0; i < mCount; i++) {
        Item* it = mItems[i];
        if (it) {
            bool hit = GetId(it->b) == id;
            if (!hit) {
                Item* q = mItems[i];
                hit = GetId(q->a) == id;
            }
            if (hit)
                return mItems[i];
        }
    }
    return 0;
}
