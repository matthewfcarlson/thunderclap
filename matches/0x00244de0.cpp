namespace om {
class EntityType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
} // namespace om
extern void __cdecl FUN_00244610(void*, void*);
extern void __cdecl FUN_002446d0(void*, void*);
void om::EntityType::vfunc_1() {
    FUN_00244610(*(void**)0x4cc084, this);
    FUN_002446d0(*(void**)0x4cc088, this);
    int x = *(volatile int*)0x4e5f10;
    --x;
    *(volatile int*)0x4e5f10 = x;
}