// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00025420 @ 0x00025420
struct Triple { unsigned int x, y, z; };
void __cdecl FUN_00095fa0(Triple *value, unsigned int arg);
void __stdcall FUN_00025420(Triple *result, unsigned int x, unsigned int y, unsigned int z, unsigned int arg)
{
    Triple value;
    value.x = x;
    value.y = y;
    value.z = z;
    FUN_00095fa0(&value, arg);
    *result = value;
}
