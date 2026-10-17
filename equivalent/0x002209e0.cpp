// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002209e0 @ 0x002209e0
struct Args { int kind; int value; }; void __cdecl FUN_002208e0(Args *); void __cdecl FUN_002209e0(int unused, int value) { Args args; args.kind = 3; args.value = value; FUN_002208e0(&args); }