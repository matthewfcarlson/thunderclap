class Obj {
  public:
    void run(int, int, int, int);
};
Obj* __stdcall make();
void __stdcall FUN_001b91b0(int x) {
    make()->run(0, 0, 1, x);
}