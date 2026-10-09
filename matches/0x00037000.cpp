struct Entry { unsigned char a; unsigned char flag; unsigned char rest[14]; };
struct Obj { unsigned char pad[0x2260]; Entry entries[4]; };
class Helper { public: void Do(int, int); };
void __fastcall target(Obj* self) {
    Entry* p = self->entries;
    int n = 4;
    do {
        if (p->flag) {
            p->a = 0;
            Helper* h = (Helper*)((char*)p - 8);
            h->Do(0, 0);
        }
        ++p;
        --n;
    } while (n != 0);
    *(int*)((char*)self + 0x2298) = 0;
}
