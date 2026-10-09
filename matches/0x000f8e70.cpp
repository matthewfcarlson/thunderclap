class Mgr {
  public:
    int Check(int x);
};

class Inner {
  public:
    int pad;
    Mgr* mMgr;
};

class Item {
  public:
    Item* Init(Inner* a, int b, int c, int d);
};

void* operator new(unsigned int n);

class Owner {
  public:
    Inner* mInner;
    int Find(int a);
    void Add(Item* it);
    Item* Create(int a, int b, int c);
};

Item* Owner::Create(int a, int b, int c) {
    if (Find(a))
        return 0;
    Item* r = 0;
    if (c && mInner->mMgr->Check(c)) {
        Item* p = (Item*)operator new(0x4c);
        if (p) {
            r = p->Init(mInner, a, b, c);
        } else {
            r = 0;
        }
        Add(r);
    }
    return r;
}
