typedef unsigned int u32_13a280;
extern u32_13a280 vtable_13a280;
struct Sub_13a280 {
    void Init();
};
struct T_13a280 {
    char pad[0x28];
    void Run();
};
struct Base_13a280 {
    void Finish();
};
void T_13a280::Run() {
    *(u32_13a280*)this = (u32_13a280)&vtable_13a280;
    ((Sub_13a280*)((char*)this + 0x28))->Init();
    ((Sub_13a280*)((char*)this + 0x18))->Init();
    ((Base_13a280*)this)->Finish();
}