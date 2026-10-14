// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_001d64c0 @ 0x001d64c0
typedef unsigned int uint;
extern uint DAT_004e25e8;
extern uint DAT_004e25e0, DAT_004e25e4, DAT_004e25d8, DAT_004e25dc, DAT_004e25d0, DAT_004e25d4;
extern unsigned __int64 __cdecl FUN_0027afb0(const char*);
struct Input_1d64c0 { bool FUN_00092940(int); };
struct Manager_1d64c0 { Input_1d64c0* FUN_00086340(); };
struct Root_1d64c0 { char pad[0x54]; Manager_1d64c0* manager; };
extern Root_1d64c0* DAT_004dd700;
struct Identity { char pad[8]; uint low, high; };
struct Object { char pad[0x9c]; Identity* identity; char pad2[0x14d-0xa0]; unsigned char flag; int FUN_001d64c0(); };
int Object::FUN_001d64c0() {
 unsigned __int64 value;
 if (!(DAT_004e25e8 & 1)) { DAT_004e25e8 |= 1; value=FUN_0027afb0("miss_soldier_miss_soldier_grp"); DAT_004e25e0=(uint)value; DAT_004e25e4=(uint)(value>>32); }
 if (!(DAT_004e25e8 & 2)) { DAT_004e25e8 |= 2; value=FUN_0027afb0("cow_male_cow_male"); DAT_004e25d8=(uint)value; DAT_004e25dc=(uint)(value>>32); }
 if (!(DAT_004e25e8 & 4)) { DAT_004e25e8 |= 4; value=FUN_0027afb0("mlrsMissileLarge_mlrsMissileLarge"); DAT_004e25d0=(uint)value; DAT_004e25d4=(uint)(value>>32); }
 bool active=DAT_004dd700->manager->FUN_00086340()->FUN_00092940(0x2f);
 uint low=identity->low, high=identity->high;
 if (low==DAT_004e25e0 && high==DAT_004e25e4) return 1;
 if (low==DAT_004e25d0 && high==DAT_004e25d4) return 1;
 if (active && !flag && low==DAT_004e25d8 && high==DAT_004e25dc) return 1;
 return 0;
}