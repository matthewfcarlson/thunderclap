struct Item {
    int a, b;
};
struct Buf {
    char pad[8];
    Item* cur;
    Item* start;
};
Buf* __cdecl FUN_00212d80(Buf* p, int n) {
    if (n >= 0) {
        n <<= 3;
        while ((unsigned)p->cur < (unsigned)((char*)p->start + n)) {
            p->cur->a = 0;
            p->cur = (Item*)((char*)p->cur + 8);
        }
        p->cur = (Item*)((char*)p->start + n);
        return p;
    }
    p->cur += n + 1;
    return p;
}