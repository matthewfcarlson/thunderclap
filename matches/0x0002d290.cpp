struct Vec { int x, y, z; };
class Actor { public: bool Invoke(Vec v); };
typedef bool (Actor::*ActorFn)(Vec);
class Method1 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* a, Vec* v, unsigned char* out);
    char pad[0x1c - 4];
    ActorFn fn;
};
void Method1::vfunc_2(void* a, Vec* v, unsigned char* out) {
    ActorFn f = fn;
    unsigned char r = (unsigned char)((((Actor*)a)->*f)(*v));
    if (out) *out = r;
}
