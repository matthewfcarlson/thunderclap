// Same code shape as 0x00235300 (propagated; names are from that function)
class Part_235560 {
  public:
    void Init();
};
class ParamValueEnum_235560 {
  public:
    int vt;
    int pad;
    Part_235560 part;
    ParamValueEnum_235560* vfunc_0(int);
};
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(ParamValueEnum_235560*);
ParamValueEnum_235560* ParamValueEnum_235560::vfunc_0(int flag) {
    vt = (int)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}