struct Info_214050 {
    char pad[6];
    char flag;
    char pad2[5];
    struct Rec_214050* rec;
};
struct Rec_214050 {
    char pad[0xc];
    int* arr;
};
struct Slot_214050 {
    int* base;
    int pad;
    int* end;
    int pad2;
};
struct A_214050 {
    char pad[0x28];
    Slot_214050* mSlots;
    Slot_214050* Get(int i) { return &mSlots[i]; }
};
struct B_214050 {
    char pad[0x5c];
    int mIdx;
};
int Lookup(Rec_214050* r, int x, int y);
void Apply(A_214050* a, int* p);
int Fn(A_214050* a, B_214050* b, int x) {
    int n = 0;
    Slot_214050* s = a->Get(b->mIdx);
    if (s->base[-2] == 6) {
        Info_214050* inf = ((Info_214050**)s->base)[-1];
        if (inf->flag == 0) {
            Rec_214050* r = inf->rec;
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
