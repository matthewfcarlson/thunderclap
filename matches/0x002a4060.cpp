class Item_2a4060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Do(int, int);
};
class Owner_2a4060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Finish();
};
class Container_2a4060 {
  public:
    Owner_2a4060* owner;
    Item_2a4060** begin;
    Item_2a4060** end;
    void Clear();
};
void Container_2a4060::Clear() {
    int n = ((int)((char*)end - (char*)begin)) >> 2;
    for (unsigned int i = 0; i < (unsigned int)n; ++i) {
        Item_2a4060* p = begin[i];
        if (p)
            p->Do(0, 1);
    }
    owner->Finish();
}
