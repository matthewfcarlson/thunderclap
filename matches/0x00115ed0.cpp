class A_115ed0 {
  public:
    void* f();
};
class B_115ed0 {
  public:
    void* g();
    void h(void*);
};
class MotionBoostAction {
  public:
    char pad[0x20];
    void* member;
    char rest[0x20];
    bool vfunc_3(int, int);
};
bool MotionBoostAction::vfunc_3(int, int) {
    if (!member)
        return false;
    void* x = ((A_115ed0*)member)->f();
    x = ((B_115ed0*)x)->g();
    ((B_115ed0*)x)->h((char*)this + 0x28);
    return true;
}