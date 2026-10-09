class Entry;
class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Count();
    virtual Entry* At(int);
};
class Entry {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char IsValid();
    virtual void d();
    virtual void e();
    virtual int Value();
};
class Owner {
  public:
    char pad[0x134];
    char flag;
    void Add(int);
    void Process();
};
Item* GetItems();
void Owner::Process() {
    flag = 0;
    int i = 0;
    int n = GetItems()->Count();
    if (n > 0) {
        do {
            Entry* e = GetItems()->At(i);
            if (e && e->IsValid())
                Add(e->Value());
            ++i;
            n = GetItems()->Count();
        } while (i < n);
    }
}