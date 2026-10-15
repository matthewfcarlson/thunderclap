class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void Act(void*);
    char pad[0xc];
    char active;
};
class Holder {
  public:
    char pad[0xc];
    void* context;
    int count;
    char pad2[4];
    int* sizes;
    Item*** items;
    void Run(int index);
};
void Holder::Run(int index) {
    if (index >= 0 && index < count) {
        for (int i = 0; i < sizes[index]; ++i) {
            if (items[index][i]->active)
                items[index][i]->Act(context);
        }
    }
}