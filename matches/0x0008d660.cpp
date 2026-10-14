extern "C" unsigned char flag_8d660;
extern "C" void __cdecl init();
extern "C" void __cdecl delay(int);
struct Obj_8d660 {
    char pad[0x20];
    void run();
};
extern Obj_8d660 obj_8d660;
void FUN_0008d660() {
    if (!flag_8d660) {
        init();
        obj_8d660.run();
        delay(30);
        flag_8d660 = 1;
    }
}