// cl-flags: /O1
extern void* g_target;
class Obj {
  public:
    void Run();
};
void __stdcall FUN_00364740() {
    ((Obj*)0x4e7b50)->Run();
}
