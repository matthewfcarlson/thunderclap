class Item {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Do(int, int);
};
class Owner {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Finish();
};
class Container {
  public:
    Owner* owner;
    Item** begin;
    Item** end;
    void Clear();
};
void Container::Clear() {
    int n = ((int)((char*)end - (char*)begin)) >> 2;
    for (unsigned int i = 0; i < (unsigned int)n; ++i) {
        Item* p = begin[i];
        if (p)
            p->Do(0, 1);
    }
    owner->Finish();
}
