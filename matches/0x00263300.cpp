struct Item_263300 {
    char pad[0x20];
    void A();
    Item_263300* F(unsigned char);
};
void __cdecl FUN_00247550(void*, Item_263300*);
extern char DAT_004e7b98;
Item_263300* Item_263300::F(unsigned char flags) {
    ((Item_263300*)((char*)this + 0x10))->A();
    ((Item_263300*)((char*)this + 4))->A();
    if (flags & 1)
        FUN_00247550(&DAT_004e7b98, this);
    return this;
}