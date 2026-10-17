// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0002da20 @ 0x0002da20
struct Callback { void invoke(unsigned, unsigned, unsigned, unsigned, unsigned); };
typedef void (Callback::*Method)(unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0002da20(Callback* object, const unsigned* values, unsigned unused, Method callback)
{
    (object->*callback)(values[0], values[1], values[2], values[3], values[4]);
}