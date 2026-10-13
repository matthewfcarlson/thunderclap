class Sub {
  public:
    void Fn();
};
extern Sub g_sub;
void __cdecl FUN_00364450() {
    g_sub.Fn();
}
