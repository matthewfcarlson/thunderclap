// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c80a0 @ 0x000c80a0
struct Name_c80a0 {
    int lo, hi;
    Name_c80a0* FUN_0027af00();
    void FUN_0027af70(Name_c80a0* src);
    void FUN_0027af50();
};
struct Slot_c80a0 {
    int tag;            // -1 when free
    int a, b, c;
    unsigned __int64 id;
    int d, e, f;
    char pad[4];
    Name_c80a0 name;
    int g;
    char pad2[4];
    int h;
    char used;
    char pad3[3];
};
struct SlotTable_c80a0 {
    char pad[0x258];
    Slot_c80a0 slot[0x80];
    void Release(int tag);
};
// Frees every slot holding the given tag.
void SlotTable_c80a0::Release(int tag) {
    for (int i = 0; i < 0x80; i++) {
        Slot_c80a0* s = &slot[i];
        if (s->tag != tag) continue;
        s->tag = -1;
        Name_c80a0 tmp;
        s->name.FUN_0027af70(tmp.FUN_0027af00());
        tmp.FUN_0027af50();
        s->g = -1;
        s->a = 0; s->b = 0; s->c = 0;
        unsigned __int64 zero = 0;
        s->id = zero;
        s->d = 0; s->e = 0; s->f = 0;
        s->h = 0;
        s->used = 0;
    }
}
