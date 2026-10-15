struct TD {
    void* vf;
};
extern TD FEObject_Type, FEControl_Type, HSlider_Type;
extern "C" void* __stdcall FUN_000e7260(void*);
extern "C" void* __cdecl FUN_00344e74(void*, int, TD*, TD*, int);
void __stdcall FUN_000e7460(void* p) {
    FUN_00344e74(FUN_00344e74(FUN_000e7260(p), 0, &FEObject_Type, &FEControl_Type, 0), 0, &FEControl_Type,
                 &HSlider_Type, 0);
}