struct Item {
    char pad[0x38];
    volatile int a;
    int b;
};
void Func(int, int, int);
void Target(int unused, Item* p) {
    int a = p->a;
    Func(0, a, p->b);
}