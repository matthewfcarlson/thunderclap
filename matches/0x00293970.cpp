typedef unsigned int U_293970;
extern U_293970 __cdecl Query(U_293970, U_293970, const void*, const void*, U_293970);
extern char CameraRTTI;
extern char EntityRTTI_293970;
class CameraAnimationController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5(U_293970);
    void Finish(U_293970);
};
void CameraAnimationController::vfunc_5(U_293970 arg) {
    U_293970 x = Query(arg, 0, &EntityRTTI_293970, &CameraRTTI, 0);
    Finish(x);
}