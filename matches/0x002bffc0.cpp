struct Base_2bffc0 {
    char pad[0x10];
    void Init();
};
extern int Image32Vtable;
struct Image32 : Base_2bffc0 {
    int field10, field14, field18, field1c, field20, field24;
    unsigned char field28, field29;
    Image32* Init();
};
Image32* Image32::Init() {
    Base_2bffc0::Init();
    field24 = 0;
    field10 = 0;
    field14 = 0;
    field1c = 0;
    field29 = 0;
    field28 = 0;
    field20 = 8;
    *(int*)this = (int)&Image32Vtable;
    field18 = 0x20;
    return this;
}