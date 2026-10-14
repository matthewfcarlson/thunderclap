// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d5140 @ 0x001d5140
int __cdecl FUN_00096600(const char *a, const char *b);

int FUN_001d5140(const char *name)
{
    if (FUN_00096600(name, "steel_fists") == 0)
        return 1;
    if (FUN_00096600(name, "shield") == 0)
        return 2;
    if (FUN_00096600(name, "bowling_ball") == 0)
        return 3;
    if (FUN_00096600(name, "hammer_toss") == 0)
        return 4;
    if (FUN_00096600(name, "ball_and_chain") == 0)
        return 5;
    if (FUN_00096600(name, "missile_pack") == 0)
        return 6;
    return 0;
}
