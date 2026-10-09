extern "C" unsigned char flag;
extern "C" void __cdecl init();
extern "C" void __cdecl delay(int);
struct Obj {
    char pad[0x20];
    void run();
};
extern Obj obj;
void FUN_0008d660() {
    if (!flag) {
        init();
        obj.run();
        delay(30);
        flag = 1;
    }
}