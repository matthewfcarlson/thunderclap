extern "C" int atexit(void (*)(void));
void FUN_00363ca0(void);
class Obj {
  public:
    void Reg(const char*, int);
};
extern Obj g_4dd738;
void __stdcall FUN_0035cfd0(void) {
    g_4dd738.Reg("sound/rsd", 0);
    atexit((void (*)(void))FUN_00363ca0);
}
