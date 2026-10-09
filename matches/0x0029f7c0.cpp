extern "C" int __cdecl FUN_0008d690(int);
struct X {
    int Init(int, int);
};
extern int g;
void FUN_0029f7c0() {
    if (g == 0) {
        int x = FUN_0008d690(0x3c);
        if (x != 0)
            g = ((X*)x)->Init(4, 0x100);
        else
            g = 0;
    }
}