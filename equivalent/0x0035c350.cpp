// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035c350 @ 0x0035c350
struct Context { char padding[0x14]; int value; };
int __cdecl FUN_003abdde(int value);
// equiv-conv: FUN_0035c350 ebp
int FUN_0035c350(Context* context) {
    return FUN_003abdde(context->value);
}
