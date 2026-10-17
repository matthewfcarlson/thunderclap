// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_2 @ 0x000d6370
struct Vector { float x, y, z; };
struct MessageOverlay {
    void invoke(int number, const char *text, int kind, Vector position, float duration);
};
struct Arguments {
    int number;
    const char *text;
    int kind;
    Vector position;
    float duration;
};
struct Closure5 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const Arguments *args, int unused2);
    char reserved[24];
    void (MessageOverlay::*method)(int, const char *, int, Vector, float);
    MessageOverlay *object;
};
void Closure5::vfunc_2(int unused, const Arguments *args, int unused2) {
    (object->*method)(args->number, args->text, args->kind, args->position, args->duration);
}