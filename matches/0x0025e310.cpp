typedef unsigned int uint;
struct Obj_25e310 {
    char pad0[4];
    uint m4;
    char pad8[8];
    unsigned char flag;
    char pad11[3];
    uint m14;
    uint m18;
    char pad1c[12];
    uint m28;
};
int __cdecl FUN_0025e310(Obj_25e310* p) {
    uint end, result;
    uint* q;
    if (p->m28 != 0) {
        q = (uint*)(p->m28 - 8);
        if (q != 0) {
            end = p->m18;
            if (end <= *q) {
                result = *q;
                return result - end;
            }
        }
    }
    end = p->m18;
    result = p->m14;
    if (end > result || p->flag != 0)
        result = p->m4;
    return result - end;
}
