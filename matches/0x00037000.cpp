struct Entry_37000 {
    unsigned char a;
    unsigned char flag;
    unsigned char rest[14];
};
struct Obj_37000 {
    unsigned char pad[0x2260];
    Entry_37000 entries[4];
};
class Helper_37000 {
  public:
    void Do(int, int);
};
void __fastcall target(Obj_37000* self) {
    Entry_37000* p = self->entries;
    int n = 4;
    do {
        if (p->flag) {
            p->a = 0;
            Helper_37000* h = (Helper_37000*)((char*)p - 8);
            h->Do(0, 0);
        }
        ++p;
        --n;
    } while (n != 0);
    *(int*)((char*)self + 0x2298) = 0;
}
