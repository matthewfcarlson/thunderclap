class Sub {
  public:
    void Run();
};
extern Sub* g_sub;
void __cdecl FUN_001e8a60() {
    g_sub->Run();
}
