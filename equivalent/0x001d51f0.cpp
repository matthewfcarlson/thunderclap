// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_001d51f0 @ 0x001d51f0
extern int __cdecl FUN_00096600(const char*, const char*);
int __cdecl FUN_001d51f0(const char* material)
{
    if (FUN_00096600(material, "hardmetal") == 0) return 6;
    if (FUN_00096600(material, "softmetal") == 0) return 7;
    if (FUN_00096600(material, "hardwood") == 0) return 2;
    if (FUN_00096600(material, "softwood") == 0) return 3;
    if (FUN_00096600(material, "hardrubber") == 0) return 4;
    if (FUN_00096600(material, "softrubber") == 0) return 5;
    if (FUN_00096600(material, "concrete") == 0) return 8;
    if (FUN_00096600(material, "icy") == 0) return 10;
    if (FUN_00096600(material, "sticky") == 0) return 9;
    return 0;
}
