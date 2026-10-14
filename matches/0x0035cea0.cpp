extern "C" void __cdecl FUN_00363c60();
extern "C" int __cdecl atexit(void (*f)());
extern "C" void __cdecl FUN_0023fc40(const char*, int);

struct G {
    void Init(const char*, int);
} g;

void __cdecl FUN_0035cea0() {
    g.Init("sound/rsd", 0);
    atexit((void (*)())FUN_00363c60);
}
