class Item {
  public:
    virtual void A();
    virtual void B();
    virtual void Set(int);
    virtual int Get();
};
extern Item* items[9];
extern int count;
extern int current;
void FUN_0035a6c0(int v) {
    current = v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count; j++) {
            if (items[j]->Get() == i)
                items[j]->Set(current);
        }
    }
}