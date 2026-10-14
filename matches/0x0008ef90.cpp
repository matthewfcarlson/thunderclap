typedef unsigned int u32_8ef90;
struct Obj_8ef90 {
    char pad[8];
    u32_8ef90* a;
    char pad2[4];
    u32_8ef90* b;
    void CopyTail();
    void F(u32_8ef90* src, u32_8ef90 val);
};
void Obj_8ef90::F(u32_8ef90* src, u32_8ef90 val) {
    u32_8ef90* d = a;
    u32_8ef90* s = src;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    u32_8ef90* q = b;
    *q = val;
    CopyTail();
}