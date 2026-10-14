typedef unsigned char u8_31df40;
struct pddiBaseContext {
    char pad[0x4c];
    struct Data {
        char pad2[0x18];
        u8_31df40 a, b, c, d;
    }* mData;
    void vfunc_57(u8_31df40*, u8_31df40*, u8_31df40*, u8_31df40*);
};
void pddiBaseContext::vfunc_57(u8_31df40* p1, u8_31df40* p2, u8_31df40* p3, u8_31df40* p4) {
    *p1 = mData->a;
    *p2 = mData->b;
    *p3 = mData->c;
    *p4 = mData->d;
}