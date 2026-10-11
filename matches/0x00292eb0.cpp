extern "C" char DAT_0042cf7c[];
struct CameraAnimationController {
    unsigned int pad[0x44];
};
extern void __fastcall BaseInit(CameraAnimationController*, void*);
CameraAnimationController* __fastcall FUN_00292eb0(CameraAnimationController* self, void* edx) {
    BaseInit(self, edx);
    self->pad[0] = ((int)DAT_0042cf7c);
    self->pad[0x44] = 0xffffffff;
    self->pad[0x45] = 0;
    return self;
}