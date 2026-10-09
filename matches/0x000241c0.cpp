struct Item {
    char pad[8];
    unsigned __int64 id;
};
struct Sub {
    Item* Get(int);
};
struct Mgr {
    char pad[0x44];
    Sub* sub;
};
unsigned __int64 Hash(int);
class List {
  public:
    Mgr* mMgr;
    char pad[8];
    int mCount;
    int mIds[1];
    int Find(int key);
};
int List::Find(int key) {
    unsigned __int64 h = Hash(key);
    int i = 0;
    if (0 < mCount) {
        int* p = mIds;
        do {
            Sub* s = mMgr->sub;
            Item* it = s->Get(*p);
            if (it && it->id == h)
                return i;
            i++;
            p++;
        } while (i < mCount);
    }
    return -1;
}
