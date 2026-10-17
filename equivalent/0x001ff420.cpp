// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_001ff420 @ 0x001ff420
struct Triple { int a,b,c; };
struct Receiver { int invoke(Triple value, int x, int y, int z, int w); };
void __cdecl target(Receiver* receiver, const int* values, int* result, int (Receiver::*callback)(Triple,int,int,int,int)) {
    Triple v;
    v.a=values[0]; v.b=values[1]; v.c=values[2];
    int returned=(receiver->*callback)(v,values[3],values[4],values[5],values[6]);
    if (result) *result=returned;
}