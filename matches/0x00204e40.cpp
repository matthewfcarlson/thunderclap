extern unsigned char gEnabled_204e40, gMode;
extern int __cdecl switchState(int);
struct Item_204e40 {
    char pad[0x3c];
    void init(const char*, int, int, int);
};
struct Obj_204e40 {
    char pad[0x48];
    Item_204e40 items[20];
    void run();
};
void Obj_204e40::run() {
    if (gEnabled_204e40) {
        int id = 0x13 + (gMode != 0 ? 2 : 0);
        int old = switchState(7);
        for (int i = 0; i < 20; i++)
            items[i].init("room data", id++, 0x25800, 7);
        switchState(old);
    }
}