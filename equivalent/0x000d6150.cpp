// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<MessageOverlay,void,const_char_*,int,math::Vector>::vfunc_2 @ 0x000d6150
namespace math { struct Vector { float x,y,z; }; }
struct MessageOverlay { void FUN_000d6150(const char*, int, math::Vector); };
struct Arguments { const char *text; int count; math::Vector position; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *args, void *unused2);
    char padding[0x18];
    void (MessageOverlay::*method)(const char *, int, math::Vector);
    MessageOverlay *object;
};
void Closure3::vfunc_2(void *unused, Arguments *args, void *unused2) {
    (object->*method)(args->text, args->count, args->position);
}
