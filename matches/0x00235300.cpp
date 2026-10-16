class Part_235300 {
  public:
    void Init();
};
namespace fight { class ParamValueBool {
  public:
    int vt;
    int pad;
    Part_235300 part;
    ParamValueBool* vfunc_0(int);
}; }
extern int base_vtable;
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueBool*);
fight::ParamValueBool* fight::ParamValueBool::vfunc_0(int flag) {
    vt = (int)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}