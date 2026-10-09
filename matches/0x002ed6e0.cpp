typedef unsigned int u32;
struct Sub {
    void Call(void*, u32, int);
};
struct Obj {
    char pad[0xb0];
    void Target(u32 arg);
};
void Obj::Target(u32 arg) {
    ((Sub*)((char*)this + 0xb0))->Call((char*)this + 0x2c, arg, 0);
}