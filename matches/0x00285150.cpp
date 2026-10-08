extern const float gZero;
namespace pure3d {
class BlendFrameController {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual float vfunc_13();
    char pad[0x24];
    unsigned int count;
};
float BlendFrameController::vfunc_13() {
    if (count > 0) return *(float*)((char*)this + count * 0x2c);
    return gZero;
}
}