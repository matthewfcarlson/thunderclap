extern void* g_obj;
extern int atexit(void (*fn)());
extern void F2();
class G {
  public:
    void Reg(const char* name, int arg);
};
void __cdecl FUN_0035e6e0() {
    ((G*)0x4e2230)->Reg("sound/rsd", 0);
    atexit(F2);
}
