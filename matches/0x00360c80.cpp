extern "C" int atexit(void (*)());
struct G {
    void F();
};
extern G g;
extern void Cleanup();
void FUN_00360c80() {
    g.F();
    atexit((void (*)())Cleanup);
}
