struct Item { int key; char pad[0x44]; int flag; char tail[0x14]; };
struct Caller { char pad[0x20]; void call(int); };
struct Obj { char pad[0x18]; Item items[100]; int run(int key, int arg); };
int Obj::run(int key, int arg) {
    int i=0;
    while (items[i].flag == 0 || items[i].key != key) {
        ++i;
        if (i >= 100) return 0;
    }
    ((Caller*)((char*)this + 0x20 + i*0x60))->call(arg);
    return key;
}
