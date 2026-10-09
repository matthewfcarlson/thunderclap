struct Child {
    char pad[8];
    void Init(int);
};
struct Item {
    char pad0[8];
    int a;
    int b;
    int c;
    unsigned char flag;
    char pad15[3];
    Child child;
    float value;
    int pad24;
    void Process(int);
};
struct Owner {
    char pad0[12];
    Item* items;
    void Run(int);
};
void Owner::Run(int arg) {
    int i = 0;
    do {
        Item* p = (Item*)((char*)items + i);
        p->Process(arg);
        if (p->flag == 0) {
            p->a = 0;
            p->b = 0;
            p->c = 0;
            p->flag = 0;
            p->value = 100.0f;
            p->pad24 = 0;
            p->child.Init(0);
        }
        i += 0x28;
    } while (i < 4000);
}