class Item {
  public:
    virtual void First();
    char pad[4];
    class Child* mChild;
    int mState;
};
class Child {
  public:
    void Run(int);
};
class Old {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
    char pad0[0xa0];
    void* mAtA0;
    char pad1[0x140];
    Item* mItem;

  public:
    void Prep();
    void Set(Item* p);
};
void Obj::Set(Item* p) {
    Prep();
    if (p != 0 && p->mState == 1 && p->mChild != 0) {
        void* q = mAtA0;
        p->mChild->Run(q ? *(int*)((char*)q + 0x10) : 0);
        p->First();
        Old* o = (Old*)mItem;
        if (o)
            o->B();
        mItem = p;
    }
}