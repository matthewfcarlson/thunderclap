extern char g_data[];
struct Obj {
    void Run();
};
extern Obj g_obj;
void __cdecl FUN_00364240() {
    g_obj.Run();
}
