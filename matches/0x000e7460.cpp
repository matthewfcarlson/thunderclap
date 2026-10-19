struct TD {
    void* vf;
};
extern TD FEObject_Type, FEControl_Type, HSlider_Type;
struct ThisWrap_000e7460 {
    void* FUN_000e7260(void*);
    void* FUN_000e7460(void* p);
};
extern "C" void* __cdecl FUN_00344e74(void*, int, TD*, TD*, int);
void* ThisWrap_000e7460::FUN_000e7460(void* p) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(p), 0, &FEObject_Type, &FEControl_Type, 0), 0, &FEControl_Type,
                 &HSlider_Type, 0);
}