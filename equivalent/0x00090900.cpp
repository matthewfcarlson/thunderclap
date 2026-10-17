// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00090900 @ 0x00090900
struct Callback { void invoke(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
void FUN_00090900(Callback *object, const unsigned *arguments, unsigned unused, void (Callback::*callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned))
{
    (object->*callback)(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}