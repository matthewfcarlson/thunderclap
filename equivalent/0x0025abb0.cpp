// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025abb0 @ 0x0025abb0
extern "C" int __cdecl FUN_00246f50(unsigned int, const char *, unsigned int);
int __cdecl FUN_0025abb0(const unsigned int *value, unsigned int arg)
{
    return FUN_00246f50(*value, "%u", arg);
}