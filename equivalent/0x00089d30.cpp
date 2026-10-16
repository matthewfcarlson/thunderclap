// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 4/4)
// FUN_00089d30 @ 0x00089d30
#include "decls/address.h"
struct Control_89d30 { void FUN_00090130(int); };
struct Entries_89d30 { void FUN_00093600(int,int); void FUN_00092870(int,float); void FUN_000929a0(int,float); };
struct Final_89d30 { void FUN_000c3ea0(); };
struct Manager_89d30 { Control_89d30* FUN_00086370(); Entries_89d30* FUN_00086340(); Final_89d30* FUN_00086280(); };
struct World { char pad[0x54]; Manager_89d30* manager; };
extern "C" void __cdecl FUN_00267760(char*,int,const char*,int,int);
struct Item_89d30 { int first,second; char pad[16]; };
struct Target_89d30 {
 char p0[0x80]; int f80,f84; char p88[0x20]; int fa8,fac; char pb0[0x20]; int fd0,fd4; char name[0x20]; char pf8[0x60]; Item_89d30 items[100]; char pab8[7]; unsigned char flag;
 void FUN_00089d30();
};
void Target_89d30::FUN_00089d30() {
 Manager_89d30* manager=DAT_004dd700->manager;
 fd0=0; fd4=1;
 FUN_00267760(name,32,"c%02dm%02d",0,1);
 flag=0; f84=-1; f80=-1; fac=-1; fa8=-1;
 manager->FUN_00086370()->FUN_00090130(0);
 Entries_89d30* entries=manager->FUN_00086340();
 for(int i=0;i<0x2fe;++i) { entries->FUN_00093600(i,1); entries->FUN_00092870(i,0.0f); entries->FUN_000929a0(i,0.0f); }
 for(int j=0;j<100;++j) { items[j].first=0; items[j].second=0; }
 manager->FUN_00086280()->FUN_000c3ea0();
}
