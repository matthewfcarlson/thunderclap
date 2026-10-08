class SimpleFrameController { public: char pad[0x2c]; int a; int b; void vfunc_15(int*, int*); };
void SimpleFrameController::vfunc_15(int* p, int* q) { *p = a; *q = b; }