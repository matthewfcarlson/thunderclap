// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d50e0 @ 0x001d50e0
int __cdecl FUN_00096600(const char *, const char *);
int __cdecl FUN_001d50e0(const char *name) {
    if (FUN_00096600(name, "static") == 0) return 0;
    if (FUN_00096600(name, "rigidbody") == 0) return 1;
    if (FUN_00096600(name, "articulated") == 0) return 2;
    return 0;
}