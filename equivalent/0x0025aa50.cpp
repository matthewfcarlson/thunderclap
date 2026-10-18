// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_0025aa50 @ 0x0025aa50
// FUN_0025aa50 @ 0x0025aa50
extern int __cdecl FUN_00246f50(void *, const char *, const char *);
int __cdecl FUN_0025aa50(void **value, char flag)
{
    return FUN_00246f50(*value, "%s", flag ? "true" : "false");
}
