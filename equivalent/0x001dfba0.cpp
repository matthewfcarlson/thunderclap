// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001dfba0 @ 0x001dfba0
struct Triple {
    int a, b, c;
};

class Target {
public:
    virtual void v0();
};

typedef void (Target::*Callback)(int, int, int, int, Triple, Triple);

// Calls `callback` on `self` with the ten words of `args`
// (four scalars, then two 3-word records).
void FUN_001dfba0(Target *self, int *args, int unused, Callback callback) {
    Triple first = { args[4], args[5], args[6] };
    Triple second = { args[7], args[8], args[9] };
    (self->*callback)(args[0], args[1], args[2], args[3], first, second);
}
