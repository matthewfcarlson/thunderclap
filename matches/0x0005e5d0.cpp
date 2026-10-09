// Same code shape as 0x0004dfd0 (propagated; names are from that function)
class ParamIntConstRange {
public:
    char pad[0x10];
    bool (ParamIntConstRange::*fn)(int);
    bool vfunc_6(int a, int b);
};
bool ParamIntConstRange::vfunc_6(int a, int b) {
    if (!fn) return false;
    return (((ParamIntConstRange*)a)->*fn)(b);
}
