typedef unsigned char u8_f92b0;
typedef unsigned int u32_f92b0;
struct Inner_f92b0 {
    char pad[0x458];
    int Find(u32_f92b0, u32_f92b0);
};
struct Obj_f92b0 {
    char pad[0x458];
    bool Get(u32_f92b0, u32_f92b0, u8_f92b0*);
};
bool Obj_f92b0::Get(u32_f92b0 a, u32_f92b0 b, u8_f92b0* out) {
    int i = ((Inner_f92b0*)((char*)this + 0x458))->Find(a, b);
    if (i == -1)
        return false;
    *out = *((u8_f92b0*)this + i + 0x864);
    return true;
}