class Obj {
  public:
    void run();
};
Obj* __stdcall make(int, int, int, int);
void __stdcall FUN_001b91b0(int x) {
    Obj* p = make(0, 0, 1, x);
    p->run();
}