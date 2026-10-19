// cl-flags: /O1
extern "C" char hulk_at_004e7b08[];
extern void* g_target_364740;
class Obj_364740 {
  public:
    void Run();
};
void __stdcall FUN_00364740() {
    ((Obj_364740*)((int)(hulk_at_004e7b08 + 0x48)))->Run();
}
