namespace pure3d {
struct State {
    int a;
    int value;
};
class pddiBaseContext {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual int* vfunc_7(int* out);
    char pad[0x44];
    State* state;
};
int* pddiBaseContext::vfunc_7(int* out) {
    *out = state->value;
    return out;
}
} // namespace pure3d