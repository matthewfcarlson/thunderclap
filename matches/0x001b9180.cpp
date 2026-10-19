class Obj {
  public:
    void Init(float, int, int, int, void*, int);
};
extern "C" Obj* __stdcall Make();
extern "C" void __stdcall FUN_001b9180(void* p) {
    Make()->Init(1.0f, 0, 0, 1, p, 1);
}