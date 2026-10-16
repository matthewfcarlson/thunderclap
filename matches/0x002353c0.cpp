// Same code shape as 0x00235300 (propagated; names are from that function)
class Part_2353c0 {
  public:
    void Init();
};
namespace fight { class ParamValueName {
  public:
    int vt;
    int pad;
    Part_2353c0 part;
    ParamValueName* vfunc_0(int);
}; }
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueName*);
fight::ParamValueName* fight::ParamValueName::vfunc_0(int flag) {
    vt = (int)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}