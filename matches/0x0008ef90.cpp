typedef unsigned int u32;
struct Obj {
    char pad[8];
    u32* a;
    char pad2[4];
    u32* b;
    void CopyTail();
    void F(u32* src, u32 val);
};
void Obj::F(u32* src, u32 val) {
    u32* d = a;
    u32* s = src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    u32* q = b;
    *q = val;
    CopyTail();
}