class Entry_ae5a0;
class Item_ae5a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Count();
    virtual Entry_ae5a0* At(int);
};
class Entry_ae5a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char IsValid();
    virtual void d();
    virtual void e();
    virtual int Value();
};
class CController_ae5a0 {
  public:
    char pad[0x134];
    char flag;
    void Add(int);
    void Process();
};
Item_ae5a0* GetItems();
void CController_ae5a0::Process() {
    flag = 0;
    int i = 0;
    int n = GetItems()->Count();
    if (n > 0) {
        do {
            Entry_ae5a0* e = GetItems()->At(i);
            if (e && e->IsValid())
                Add(e->Value());
            ++i;
            n = GetItems()->Count();
        } while (i < n);
    }
}