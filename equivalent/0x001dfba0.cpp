// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001dfba0 @ 0x001dfba0
struct Triple_1dfba0 {
    int a, b, c;
};

class Target_1dfba0 {
public:
    virtual void v0();
};

typedef void (Target_1dfba0::*Callback_1dfba0)(int, int, int, int, Triple_1dfba0, Triple_1dfba0);

// Calls `callback` on `self` with the ten words of `args`
// (four scalars, then two 3-word records).
void FUN_001dfba0(Target_1dfba0 *self, int *args, int unused, Callback_1dfba0 callback) {
    Triple_1dfba0 first = { args[4], args[5], args[6] };
    Triple_1dfba0 second = { args[7], args[8], args[9] };
    (self->*callback)(args[0], args[1], args[2], args[3], first, second);
}
