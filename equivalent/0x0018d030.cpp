// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 22/22)
// hulkfight::motion::GrappleVarCompareCondition::vfunc_6 @ 0x0018d030
struct Key_18d030 {
    unsigned int lo;
    unsigned int hi;
};

struct Grappler {
    int FUN_00036e40(Key_18d030 *key);
};
Grappler *__cdecl FUN_00048260(void *owner);

namespace hulkfight {
namespace motion {

class GrappleVarCompareCondition {
public:
    virtual void vfunc_0();
    char pad04[0xc];
    Key_18d030 variable;
    int op;
    int value;
    bool vfunc_6(int a, void *owner, int c);
};

bool GrappleVarCompareCondition::vfunc_6(int a, void *owner, int c)
{
    Grappler *g = FUN_00048260(owner);
    if (g == 0)
        return false;
    int v = g->FUN_00036e40(&variable);
    int rhs = value;
    switch (op) {
    case 0: return v < rhs;
    case 1: return v <= rhs;
    case 2: return v == rhs;
    case 3: return v != rhs;
    case 4: return v >= rhs;
    case 5: return v > rhs;
    }
    return false;
}

}
}
