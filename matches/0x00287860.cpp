class Base_287860 {
  public:
    Base_287860();
};
extern int vtable_287860;
class PoseAnimationController_287860 : public Base_287860 {
  public:
    char pad[0x10f];
    PoseAnimationController_287860();
};
PoseAnimationController_287860::PoseAnimationController_287860() {
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x118) = 0;
    *((char*)this + 0x131) = 0;
    *(int*)((char*)this + 0x14c) = 0;
    *(int*)((char*)this + 0x11c) = 0;
    *(int*)((char*)this + 0x134) = 0;
    *(int*)this = (int)&vtable_287860;
    *(int*)((char*)this + 0x114) = 0x3f800000;
    *(int*)((char*)this + 0x148) = 0xffff;
}