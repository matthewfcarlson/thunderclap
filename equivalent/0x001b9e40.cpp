// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b9e40 @ 0x001b9e40
struct Values { int values[6]; };
typedef void (__cdecl *Callback)(int, int, int, int, int, int);
void __cdecl FUN_001b9e40(void *context, const Values *values, int unused, Callback callback)
{
    callback(values->values[0], values->values[1], values->values[2], values->values[3], values->values[4], values->values[5]);
}