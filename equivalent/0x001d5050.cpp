// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001d5050 @ 0x001d5050
// Map a weapon name to its id (0 for an unknown name).
int __cdecl FUN_00096600(const char* a, const char* b);   // string compare, 0 when equal

int FUN_001d5050(const char* name)
{
    if (FUN_00096600(name, "small") == 0) {
        return 2;
    }
    if (FUN_00096600(name, "large") == 0) {
        return 3;
    }
    if (FUN_00096600(name, "club") == 0) {
        return 5;
    }
    if (FUN_00096600(name, "steel_fist") == 0) {
        return 6;
    }
    if (FUN_00096600(name, "shield") == 0) {
        return 7;
    }
    return 0;
}
