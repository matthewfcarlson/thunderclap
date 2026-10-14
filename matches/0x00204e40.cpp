extern unsigned char gEnabled, gMode;
extern int __cdecl switchState(int);
struct Item {
    char pad[0x3c];
    void init(const char*, int, int, int);
};
struct Obj {
    char pad[0x48];
    Item items[20];
    void run();
};
void Obj::run() {
    if (gEnabled) {
        int id = 0x13 + (gMode != 0 ? 2 : 0);
        int old = switchState(7);
        for (int i = 0; i < 20; i++)
            items[i].init("room data", id++, 0x25800, 7);
        switchState(old);
    }
}