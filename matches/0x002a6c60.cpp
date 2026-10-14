// Same code shape as 0x00293970 (propagated; names are from that function)
typedef unsigned int U_2a6c60;
extern U_2a6c60 __cdecl Query(U_2a6c60, U_2a6c60, const void*, const void*, U_2a6c60);
extern char CameraRTTI;
extern char EntityRTTI_2a6c60;
class CameraAnimationController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5(U_2a6c60);
    void Finish(U_2a6c60);
};
void CameraAnimationController::vfunc_5(U_2a6c60 arg) {
    U_2a6c60 x = Query(arg, 0, &EntityRTTI_2a6c60, &CameraRTTI, 0);
    Finish(x);
}