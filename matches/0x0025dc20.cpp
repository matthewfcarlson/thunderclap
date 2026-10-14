struct Item_25dc20 {
    virtual void f0();
    virtual void f1();
    virtual void Run(void*, int);
};
struct Owner_25dc20 {
    char pad[0x40];
    Item_25dc20* first;
    Item_25dc20* last;
    int count;
    void Add(Item_25dc20*);
};
void Owner_25dc20::Add(Item_25dc20* item) {
    int* node = (int*)((char*)item + 4);
    *node = 0;
    if (last == 0)
        first = (Item_25dc20*)node;
    else
        *(int*)last = (int)node;
    last = (Item_25dc20*)node;
    ++count;
    item->Run(this, 1);
}