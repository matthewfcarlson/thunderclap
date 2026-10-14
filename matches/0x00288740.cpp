namespace pure3d {
class PoseAnimationController {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual int vfunc_4();
};
class Helper_288740 {
  public:
    int run(PoseAnimationController*);
};
} // namespace pure3d
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
int pure3d::PoseAnimationController::vfunc_4() {
    pure3d::Helper_288740* p = (pure3d::Helper_288740*)thunk_FUN_0008d690(0x150);
    if (p)
        return p->run(this);
    return 0;
}