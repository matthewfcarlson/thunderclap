struct Info {
    char pad[6];
    char flag;
    char pad2[5];
    struct Rec* rec;
};
struct Rec {
    char pad[0xc];
    int* arr;
};
struct Slot {
    int* base;
    int pad;
    int* end;
    int pad2;
};
struct A {
    char pad[0x28];
    Slot* mSlots;
    Slot* Get(int i) { return &mSlots[i]; }
};
struct B {
    char pad[0x5c];
    int mIdx;
};
int Lookup(Rec* r, int x, int y);
void Apply(A* a, int* p);
int Fn(A* a, B* b, int x) {
    int n = 0;
    Slot* s = a->Get(b->mIdx);
    if (s->base[-2] == 6) {
        Info* inf = ((Info**)s->base)[-1];
        if (inf->flag == 0) {
            Rec* r = inf->rec;
            if (r) {
                int cnt = ((char*)s->end - (char*)r->arr >> 2) - 1;
                n = Lookup(r, x, cnt);
                if (n)
                    Apply(a, s->base + x * 2 - 2);
            }
        }
    }
    return n;
}
