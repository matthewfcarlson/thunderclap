typedef unsigned int u32;
struct H {
    void call(int);
};
struct C {
    char pad[0xD88];
    H* member;
    void f(int, int);
};
extern char RTTI1;
extern char RTTI2;
extern void* Cast(void*, int, const void*, const void*, int);
void C::f(int index, int value) {
    void* p = Cast((void*)*(u32*)((char*)this + index * 4), 0, &RTTI1, &RTTI2, 0);
    if (p) {
        *(u32*)((char*)p + 0x28) = value;
        if (member)
            member->call(index);
    }
}