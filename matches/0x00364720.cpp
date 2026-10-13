class A {
  public:
    void Run();
};

extern A g_obj;
void __fastcall FUN_00364720() {
    g_obj.Run();
}
