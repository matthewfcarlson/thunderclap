extern "C" char g_target[];
struct Obj {
    void Run();
};
extern Obj g_obj;
void __fastcall FUN_00364360() {
    g_obj.Run();
}
