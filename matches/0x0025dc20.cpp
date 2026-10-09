struct Item {
    virtual void f0();
    virtual void f1();
    virtual void Run(void*, int);
};
struct Owner {
    char pad[0x40];
    Item* first;
    Item* last;
    int count;
    void Add(Item*);
};
void Owner::Add(Item* item) {
    int* node = (int*)((char*)item + 4);
    *node = 0;
    if (last == 0)
        first = (Item*)node;
    else
        *(int*)last = (int)node;
    last = (Item*)node;
    ++count;
    item->Run(this, 1);
}