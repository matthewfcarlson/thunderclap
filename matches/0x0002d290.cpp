struct Vec_2d290 {
    int x, y, z;
};
class Actor_2d290 {
  public:
    bool Invoke(Vec_2d290 v);
};
typedef bool (Actor_2d290::*ActorFn_2d290)(Vec_2d290);
class Method1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* a, Vec_2d290* v, unsigned char* out);
    char pad[0x1c - 4];
    ActorFn_2d290 fn;
};
void Method1::vfunc_2(void* a, Vec_2d290* v, unsigned char* out) {
    ActorFn_2d290 f = fn;
    unsigned char r = (unsigned char)((((Actor_2d290*)a)->*f)(*v));
    if (out)
        *out = r;
}
