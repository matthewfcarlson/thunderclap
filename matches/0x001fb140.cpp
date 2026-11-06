extern char DAT_0048d5bc;
extern char DAT_004c84c0;
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
class CDataHandlerObject {
  public:
    virtual void* vfunc_0(void* p);
};
void* CDataHandlerObject::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (const void*)&DAT_0048d5bc, (const void*)&DAT_004c84c0, 0);
}
