namespace pure3d {
struct Inner_31e0f0 {
    char pad[0x14];
    int value;
};
class pddiBaseContext {
  public:
    virtual void f();
    char pad[0x48];
    Inner_31e0f0* m;
    int vfunc_77();
};
int pddiBaseContext::vfunc_77() {
    return m->value;
}
} // namespace pure3d