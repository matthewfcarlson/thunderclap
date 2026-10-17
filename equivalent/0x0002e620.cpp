// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 @ 0x0002e620
struct Vector { float x, y, z; };
struct Arguments { const char *name; Vector position; };
class CActorManager {};
class Closure2;
typedef void (__fastcall *ActorMethod)(CActorManager *, Closure2 *, const char *, Vector);
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Arguments *arguments, void *unused2);
    char reserved[0x18];
    ActorMethod method;
    CActorManager *actor;
};
void Closure2::vfunc_2(void *unused, const Arguments *arguments, void *unused2) {
    method(actor, this, arguments->name, arguments->position);
}