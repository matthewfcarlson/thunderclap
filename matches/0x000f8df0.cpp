class Mgr_f8df0 {
  public:
    int Check_000dfa60(int x);
};

class Inner_f8df0 {
  public:
    int pad;
    Mgr_f8df0* mMgr;
};

class Item_f8df0 {
  public:
    Item_f8df0* Init_000f8a90(Inner_f8df0* a, int b, int c, int d);
};

void* operator new(unsigned int n);

class Owner_f8df0 {
  public:
    Inner_f8df0* mInner;
    int Find(int a);
    void Add(Item_f8df0* it);
    Item_f8df0* Create(int a, int b, int c);
};

Item_f8df0* Owner_f8df0::Create(int a, int b, int c) {
    if (Find(a))
        return 0;
    Item_f8df0* r = 0;
    if (c && mInner->mMgr->Check_000dfa60(c)) {
        Item_f8df0* p = (Item_f8df0*)operator new(0x4c);
        if (p) {
            r = p->Init_000f8a90(mInner, a, b, c);
        } else {
            r = 0;
        }
        Add(r);
    }
    return r;
}
