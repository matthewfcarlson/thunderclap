extern "C" int __cdecl FUN_0008d690(int);
struct X_29f7c0 {
    int Init(int, int);
};
extern int g_29f7c0;
void FUN_0029f7c0() {
    if (g_29f7c0 == 0) {
        int x = FUN_0008d690(0x3c);
        if (x != 0)
            g_29f7c0 = ((X_29f7c0*)x)->Init(4, 0x100);
        else
            g_29f7c0 = 0;
    }
}