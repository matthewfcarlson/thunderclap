// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 18/18)
// pure3d::d3dContext::vfunc_89 @ 0x00321ea0
// Property getter: returns cached context values by property id; unknown ids fall through to the base default.
int __stdcall FUN_0031e2d0(int property);

namespace pure3d {
class d3dContext {
public:
    virtual void vfunc_0();
    char pad[0x424 - 4];
    int v424, v428, v42c, v430, v434, v438, v43c, v440, v444, v448;
    int vfunc_89(int property);
};

int d3dContext::vfunc_89(int property)
{
    switch (property) {
    case 0x101: return v424;
    case 0x102: return v434;
    case 0x103: return v440;
    case 0x104: return v444;
    case 0x105: return v448;
    case 0x106: return v43c;
    case 0x500001: return v428;
    case 0x500002: return v438;
    case 0x500004: return v42c;
    case 0x500005: return v430;
    default: return FUN_0031e2d0(property);
    }
}
}
