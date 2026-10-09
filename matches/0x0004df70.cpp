class ParamEnumConstList {
  public:
    char pad[0x18];
    bool (ParamEnumConstList::*fn)(int);
    bool vfunc_8(int a, int b);
};
bool ParamEnumConstList::vfunc_8(int a, int b) {
    if (!fn)
        return false;
    return (reinterpret_cast<ParamEnumConstList*>(a)->*fn)(b);
}