class Obj {
  public:
    void Fn(int x);
};

extern Obj* g_obj;

void FUN_000fc3a0(int x) {
    g_obj->Fn(x);
}
