// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e00f0 @ 0x001e00f0
struct CallbackTarget;
typedef void (CallbackTarget::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned);
struct CallbackTarget {};
void __cdecl FUN_001e00f0(CallbackTarget *target, const unsigned *values, unsigned unused, Callback callback)
{
    (target->*callback)(values[0], values[1], values[2], values[3], values[4]);
}