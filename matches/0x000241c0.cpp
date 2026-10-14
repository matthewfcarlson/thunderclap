struct Item_241c0 {
    char pad[8];
    unsigned __int64 id;
};
struct Sub_241c0 {
    Item_241c0* Get(int);
};
struct Mgr_241c0 {
    char pad[0x44];
    Sub_241c0* sub;
};
unsigned __int64 Hash(int);
class List_241c0 {
  public:
    Mgr_241c0* mMgr;
    char pad[8];
    int mCount;
    int mIds[1];
    int Find(int key);
};
int List_241c0::Find(int key) {
    unsigned __int64 h = Hash(key);
    int i = 0;
    if (0 < mCount) {
        int* p = mIds;
        do {
            Sub_241c0* s = mMgr->sub;
            Item_241c0* it = s->Get(*p);
            if (it && it->id == h)
                return i;
            i++;
            p++;
        } while (i < mCount);
    }
    return -1;
}
