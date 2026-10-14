typedef unsigned int u32_928f0;
struct H {
    void call(int);
};
struct C_928f0 {
    char pad[0xD88];
    H* member;
    void f(int, int);
};
extern char RTTI1_928f0;
extern char RTTI2_928f0;
extern void* Cast(void*, int, const void*, const void*, int);
void C_928f0::f(int index, int value) {
    void* p = Cast((void*)*(u32_928f0*)((char*)this + index * 4), 0, &RTTI1_928f0, &RTTI2_928f0, 0);
    if (p) {
        *(u32_928f0*)((char*)p + 0x28) = value;
        if (member)
            member->call(index);
    }
}