extern "C" int atexit(void (*)());
struct G_360c80 {
    void F();
};
extern G_360c80 g_360c80;
extern void Cleanup();
void FUN_00360c80() {
    g_360c80.F();
    atexit((void (*)())Cleanup);
}
