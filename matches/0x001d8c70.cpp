class Item_1d8c70 {
  public:
    virtual void First();
    char pad[4];
    class Child_1d8c70* mChild;
    int mState;
};
class Child_1d8c70 {
  public:
    void Run(int);
};
class Old_1d8c70 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d8c70 {
    char pad0[0xa0];
    void* mAtA0;
    char pad1[0x140];
    Item_1d8c70* mItem;

  public:
    void Prep();
    void Set(Item_1d8c70* p);
};
void Obj_1d8c70::Set(Item_1d8c70* p) {
    Prep();
    if (p != 0 && p->mState == 1 && p->mChild != 0) {
        void* q = mAtA0;
        p->mChild->Run(q ? *(int*)((char*)q + 0x10) : 0);
        p->First();
        Old_1d8c70* o = (Old_1d8c70*)mItem;
        if (o)
            o->B();
        mItem = p;
    }
}