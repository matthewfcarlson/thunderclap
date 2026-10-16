struct Vec {
    int x, y, z;
};
class CScriptCamera {
  public:
    char pad[0x2a0];
    Vec pos;
    Vec vfunc_27();
};
Vec CScriptCamera::vfunc_27() {
    return pos;
}