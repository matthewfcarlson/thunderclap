extern "C" int atexit(void (*)(void));
extern char g_s3f3ea0[];
class Obj {
  public:
    void F(const char* s, int a);
};
void FUN_0035d4c0() {
    ((Obj*)0x4dde6c)->F(g_s3f3ea0, 0);
    atexit((void (*)(void))((int)0x363e10));
}
