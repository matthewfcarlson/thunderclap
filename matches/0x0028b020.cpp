class Item_28b020 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Match(int);
};
class List_28b020 {
  public:
    char pad[8];
    int count;
    Item_28b020* items[1];
    Item_28b020* Find(int arg);
};
Item_28b020* List_28b020::Find(int arg) {
    int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Match(arg) == 1)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}