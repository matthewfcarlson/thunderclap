// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 18/18)
// hulkfight::motion::VarAssignAction::vfunc_3 @ 0x0018d1c0
struct Name {
    int lo, hi;
};

struct VarAssign {
    char pad0[0x10];
    Name name;              // 0x10
    unsigned int op;        // 0x18
    int operand;            // 0x1c
    char pad20[4];
    char result;            // 0x24
};

struct Character {
    int FUN_00036e40(const Name *name);
    void FUN_00036e70(const Name *name, int value);
};

struct Slot {
    Character *FUN_00059a30();
};

struct Owner {
    Slot *FUN_000592a0();
};

namespace hulkfight { namespace motion {
class VarAssignAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);

    char pad4[0x1c - 4];
    VarAssign *assign;      // 0x1c
    Owner *owner;           // 0x20
};

char VarAssignAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return 0;

    Character *c = owner->FUN_000592a0()->FUN_00059a30();
    int value = c->FUN_00036e40(&assign->name);
    VarAssign *va = assign;
    int operand = va->operand;
    switch (va->op) {
    case 0:
        value = operand;
        break;
    case 1:
        value = value + operand;
        break;
    case 2:
        value = value - operand;
        break;
    case 3:
        value = value * operand;
        break;
    case 4:
        value = (operand != 0) ? value / operand : 0;
        break;
    case 5:
        value = (operand != 0) ? value % operand : 0;
        break;
    case 6:
        value = value + 1;
        if (operand != 0)
            value = value % operand;
        break;
    case 7:
        value = value + operand - 1;
        if (operand != 0)
            value = value % operand;
        break;
    default:
        return 0;
    }
    c->FUN_00036e70(&va->name, value);
    return assign->result;
}
}}
