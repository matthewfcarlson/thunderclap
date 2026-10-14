struct Item_67a20 {
    void tick();
};
struct C_67a20 {
    char pad[0x920];
    void run();
};
void C_67a20::run() {
    Item_67a20* p = (Item_67a20*)((char*)this + 0x920);
    int i = 0x40;
    do {
        p = (Item_67a20*)((char*)p - 0x20);
        p->tick();
        --i;
    } while (i != 0);
}