class CStageAction {
  public:
    char pad[0x1c];
    void* a;
    void* b;
    bool vfunc_7(int);
};
class H {
  public:
    void* f();
    void* g();
};
bool CStageAction::vfunc_7(int) {
    H* x = (H*)a;
    void* t = x->f();
    H* y = (H*)t;
    void* z = y->g();
    *(void**)((char*)z + 0x1e44) = b;
    return false;
}