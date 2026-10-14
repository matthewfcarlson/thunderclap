typedef unsigned int u32_2ed6e0;
struct Sub_2ed6e0 {
    void Call(void*, u32_2ed6e0, int);
};
struct Obj_2ed6e0 {
    char pad[0xb0];
    void Target(u32_2ed6e0 arg);
};
void Obj_2ed6e0::Target(u32_2ed6e0 arg) {
    ((Sub_2ed6e0*)((char*)this + 0xb0))->Call((char*)this + 0x2c, arg, 0);
}