typedef unsigned int U;
extern U __cdecl Query(U, U, const void*, const void*, U);
extern char CameraRTTI; extern char EntityRTTI;
class CameraAnimationController { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void vfunc_5(U); void Finish(U); };
void CameraAnimationController::vfunc_5(U arg) { U x=Query(arg,0,&EntityRTTI,&CameraRTTI,0); Finish(x); }