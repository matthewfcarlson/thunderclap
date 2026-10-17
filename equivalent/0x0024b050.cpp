// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024b050 @ 0x0024b050
struct Argument { char reserved[8]; void* value; };
void __cdecl FUN_00258ba0(void* value);
void __cdecl FUN_0024b050(Argument* argument) {
    FUN_00258ba0(argument->value);
}