class Obj {
  public:
    void Init();
};
extern "C" Obj* __stdcall Make(float, int, int, int, void*, int);
extern "C" void __stdcall FUN_001b9180(void* p) {
    Obj* o = Make(1.0f, 0, 0, 1, p, 1);
    o->Init();
}