// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009b140 @ 0x0009b140
struct Receiver {
    void callback(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
typedef void (Receiver::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0009b140(Receiver *receiver, unsigned *values, unsigned unused, Callback callback)
{
    (receiver->*callback)(values[0], values[1], values[2], values[3], values[4], values[5]);
}