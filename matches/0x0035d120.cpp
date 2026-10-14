extern "C" int __cdecl atexit(void (*f)());
extern char g3f3ea0[];
struct Reg {
    void Init(char*, int);
};
extern Reg g4dd818;
void InitSound() {
    g4dd818.Init(g3f3ea0, 0);
    atexit((void (*)())0x363cd0);
}
