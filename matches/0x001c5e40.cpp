struct Inner { void run(); };
Inner* __stdcall FUN_001c3d90(void*, unsigned int);
struct Obj { char pad[8]; void target(unsigned int); };
void Obj::target(unsigned int arg) {
    Inner* p = FUN_001c3d90((char*)this + 8, arg);
    p->run();
}