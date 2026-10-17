// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_001ba040 @ 0x001ba040
struct Caller { int FUN_001ba040_call(int a, int b, int c, int d); }; 
struct Args { int a; int b; int c; int d; };
typedef int (Caller::*Callback)(int,int,int,int);
void __cdecl FUN_001ba040(Caller* caller, Args* args, int* result, Callback callback) {
    int value = (caller->*callback)(args->a, args->b, args->c, args->d);
    if (result != 0) *result = value;
}
