// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0025aa50 @ 0x0025aa50
extern void __cdecl FUN_00246f50(void *, const char *, const char *);
void __cdecl FUN_0025aa50(void **value, char flag)
{
    FUN_00246f50(*value, "%s", flag ? "true" : "false");
}
