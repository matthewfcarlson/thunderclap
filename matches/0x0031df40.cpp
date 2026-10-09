typedef unsigned char u8;
struct pddiBaseContext {
    char pad[0x4c];
    struct Data {
        char pad2[0x18];
        u8 a, b, c, d;
    }* mData;
    void vfunc_57(u8*, u8*, u8*, u8*);
};
void pddiBaseContext::vfunc_57(u8* p1, u8* p2, u8* p3, u8* p4) {
    *p1 = mData->a;
    *p2 = mData->b;
    *p3 = mData->c;
    *p4 = mData->d;
}