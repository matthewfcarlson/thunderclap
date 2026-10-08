typedef unsigned char u8;
struct Obj { u8 run(); };
u8 __stdcall FUN_000242d0(Obj* p) {
    if (!p) return 0;
    return p->run();
}