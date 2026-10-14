class Item_8ca30 {
  public:
    virtual void A();
    virtual void B();
};
class BaseItem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
};
struct Record_8ca30 {
    BaseItem* first;
    Item_8ca30* second;
    char pad[192];
};
class Owner_8ca30 {
  public:
    char pad[8];
    Record_8ca30* items;
    void Run(int index);
};
void Owner_8ca30::Run(int index) {
    Item_8ca30** p = &items[index].second;
    Item_8ca30* item = *p;
    if (item) {
        item->B();
        *p = 0;
    }
    items[index].first->v22();
}