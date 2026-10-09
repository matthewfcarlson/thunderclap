struct Item {
    char pad[0x20];
    void A();
    Item* F(unsigned char);
};
void __cdecl FUN_00247550(void*, Item*);
extern char DAT_004e7b98;
Item* Item::F(unsigned char flags) {
    ((Item*)((char*)this + 0x10))->A();
    ((Item*)((char*)this + 4))->A();
    if (flags & 1)
        FUN_00247550(&DAT_004e7b98, this);
    return this;
}