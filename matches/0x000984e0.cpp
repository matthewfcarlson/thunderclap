class CGameCamera {
  public:
    void* vtable;
    void vfunc_29();
};
void __stdcall FUN_00098480(int);
void __fastcall FUN_000a9620(CGameCamera*);
void __fastcall FUN_000984e0(CGameCamera* p) {
    *(void**)p = (void*)0x404b3c;
    FUN_00098480(0);
    p->vfunc_29();
    FUN_000a9620(p);
}