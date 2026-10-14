typedef unsigned int u32_901d0;
void __stdcall FUN_00090130(u32_901d0);
struct C_901d0 {
    char pad[0x38];
    void F(int index, u32_901d0 value);
};
void C_901d0::F(int index, u32_901d0 value) {
    if (index == 0) {
        FUN_00090130(value);
        return;
    }
    if (index >= 0 && index < 0x32)
        *(u32_901d0*)((char*)this + index * 0x40 + 0x38) = value;
}
