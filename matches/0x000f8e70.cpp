class Mgr_f8e70 {
  public:
    int Check(int x);
};

class Inner_f8e70 {
  public:
    int pad;
    Mgr_f8e70* mMgr;
};

class Item_f8e70 {
  public:
    Item_f8e70* Init(Inner_f8e70* a, int b, int c, int d);
};

void* operator new(unsigned int n);

class Owner_f8e70 {
  public:
    Inner_f8e70* mInner;
    int Find(int a);
    void Add(Item_f8e70* it);
    Item_f8e70* Create(int a, int b, int c);
};

Item_f8e70* Owner_f8e70::Create(int a, int b, int c) {
    if (Find(a))
        return 0;
    Item_f8e70* r = 0;
    if (c && mInner->mMgr->Check(c)) {
        Item_f8e70* p = (Item_f8e70*)operator new(0x4c);
        if (p) {
            r = p->Init(mInner, a, b, c);
        } else {
            r = 0;
        }
        Add(r);
    }
    return r;
}
