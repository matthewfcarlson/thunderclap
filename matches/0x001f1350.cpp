struct Child_1f1350 {
    char pad[8];
    void Init(int);
};
struct Item_1f1350 {
    char pad0[8];
    int a;
    int b;
    int c;
    unsigned char flag;
    char pad15[3];
    Child_1f1350 child;
    float value;
    int pad24;
    void Process(int);
};
struct Owner_1f1350 {
    char pad0[12];
    Item_1f1350* items;
    void Run(int);
};
void Owner_1f1350::Run(int arg) {
    int i = 0;
    do {
        Item_1f1350* p = (Item_1f1350*)((char*)items + i);
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