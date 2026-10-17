// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e0d60 @ 0x001e0d60
struct Arguments { unsigned int first; unsigned int second; unsigned int third; unsigned int fourth; };
typedef unsigned char (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0d60(void* object, const Arguments* args, unsigned char* result, Callback method)
{
    unsigned char value = method(args->first, args->second, args->third, args->fourth);
    if (result) *result = value;
}
