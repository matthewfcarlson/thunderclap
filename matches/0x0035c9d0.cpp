extern void Reg(const char* name, int a);
extern void Fn();
extern "C" int atexit(void (*)());
struct G {
    void Reg(const char* name, int a);
};
extern G g;
void FUN_0035c9d0() {
    g.Reg("sound/rsd", 0);
    atexit(Fn);
}