extern "C" char DAT_004cc084[];
extern "C" char DAT_004cc088[];
extern "C" char DAT_004e5f10[];
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
    FUN_00244610(*(void**)((int)DAT_004cc084), this);
    FUN_002446d0(*(void**)((int)DAT_004cc088), this);
    int x = *(volatile int*)((int)DAT_004e5f10);
    --x;
    *(volatile int*)((int)DAT_004e5f10) = x;
}