struct Item {
    void tick();
};
struct C {
    char pad[0x920];
    void run();
};
void C::run() {
    Item* p = (Item*)((char*)this + 0x920);
    int i = 0x40;
    do {
        p = (Item*)((char*)p - 0x20);
        p->tick();
        --i;
    } while (i != 0);
}