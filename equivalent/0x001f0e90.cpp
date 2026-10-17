// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f0e90 @ 0x001f0e90
struct Receiver { void invoke(int a, int b, int c, int d, int e); };
struct Values { int a,b,c,d,e; };
typedef void (Receiver::*Callback)(int,int,int,int,int);
void __cdecl FUN_001f0e90(Receiver *receiver, Values *values, int unused, Callback callback)
{
    (receiver->*callback)(values->a, values->b, values->c, values->d, values->e);
}
