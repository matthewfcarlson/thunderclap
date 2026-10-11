extern "C" char DAT_00404b3c[];
class CGameCamera {
  public:
    void* vtable;
    void vfunc_29();
};
void __stdcall FUN_00098480(int);
void __fastcall FUN_000a9620(CGameCamera*);
void __fastcall FUN_000984e0(CGameCamera* p) {
    *(void**)p = (void*)((int)DAT_00404b3c);
    FUN_00098480(0);
    p->vfunc_29();
    FUN_000a9620(p);
}