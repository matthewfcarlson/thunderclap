// Same code shape as 0x00235300 (propagated; names are from that function)
class Part_235590 {
  public:
    void Init();
};
class ParamValueVector_235590 {
  public:
    int vt;
    int pad;
    Part_235590 part;
    ParamValueVector_235590* vfunc_0(int);
};
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(ParamValueVector_235590*);
ParamValueVector_235590* ParamValueVector_235590::vfunc_0(int flag) {
    vt = (int)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}