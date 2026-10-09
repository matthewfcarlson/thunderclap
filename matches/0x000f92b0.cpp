typedef unsigned char u8; typedef unsigned int u32;
struct Inner { char pad[0x458]; int Find(u32, u32); };
struct Obj { char pad[0x458]; bool Get(u32, u32, u8*); };
bool Obj::Get(u32 a, u32 b, u8* out) {
    int i = ((Inner*)((char*)this + 0x458))->Find(a,b);
    if (i == -1) return false;
    *out = *((u8*)this + i + 0x864);
    return true;
}