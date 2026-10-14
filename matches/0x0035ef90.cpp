class Obj {
  public:
    void Fn(int x);
};
extern Obj g_obj;
void __stdcall Target() {
    g_obj.Fn(0);
}
