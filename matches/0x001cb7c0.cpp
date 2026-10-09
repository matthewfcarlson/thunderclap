struct Slot {
    bool InUse();
    char pad[0x28];
};
struct Obj {
    void Set(Slot* s, int v, int z);
};
extern char gFlag;
class T {
  public:
    char pad[0x24];
    Slot mSlots[0x18];
    unsigned Find() {
        for (unsigned i = 0; i < 0x18; i++)
            if (!mSlots[i].InUse())
                return i;
        return 0xffffffff;
    }
    unsigned Alloc(Obj* o, int v);
};
unsigned T::Alloc(Obj* o, int v) {
    if (!o)
        return 0xffffffff;
    unsigned i = Find();
    if (i == 0xffffffff)
        return i;
    gFlag = 1;
    o->Set(&mSlots[i], v, 0);
    return i;
}
