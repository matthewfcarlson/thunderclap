// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b050 @ 0x0024b050
struct Argument { char reserved[8]; void* value; };
struct Entry_24b050;
void __cdecl FUN_00258ba0(void* value, Entry_24b050* entries, unsigned count);
void __cdecl FUN_0024b050(Argument* argument, Entry_24b050* entries, unsigned count) {
    FUN_00258ba0(argument->value, entries, count);
}
