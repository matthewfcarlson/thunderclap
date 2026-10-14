// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00329430 @ 0x00329430
struct Element_329430 { char bytes[24]; };
extern void FUN_003290a0();
extern void __stdcall FUN_00011520(void*, unsigned, unsigned, void (*)());
extern unsigned __cdecl FUN_00329060(const char*);
extern char DAT_003f335c[];
extern char DAT_004d4f40[], DAT_004d5388[], DAT_004d5640[], DAT_004d5830[], DAT_004d56d8[], DAT_004d5d70[], DAT_004d5a08[], DAT_004d6048[], DAT_004d64d0[], DAT_004d6878[], DAT_004d6b80[], DAT_004d6ce8[], DAT_004d6f10[], DAT_004d70f8[], DAT_004d7320[], DAT_004d7508[], DAT_004d7730[];
struct Entry_329430 { unsigned name; char* data; unsigned count; Element_329430 elements[32]; };
struct Registry_329430 { unsigned owner; int count; Entry_329430 entries[20]; Registry_329430* init(unsigned); };
Registry_329430* Registry_329430::init(unsigned arg) {
 for(int i=0;i<20;++i) FUN_00011520(entries[i].elements,24,32,&FUN_003290a0);
 owner=arg; count=0;
 entries[0].name=FUN_00329060(DAT_003f335c);
 entries[count].data=0; entries[count].count=0;
 const char* names[17]={"skin","skin_onebone","point_sprite","toon2","toon","skin_toon","refract","skin_refract","spheremap","environmap","bumpmap","simple_multicbv","simple_proximity","layered_multicbv","layered_proximity","layered_lightmap_multicbv","layered_lightmap_proximity"};
 char* data[17]={DAT_004d4f40,DAT_004d5388,DAT_004d5640,DAT_004d5830,DAT_004d56d8,DAT_004d5d70,DAT_004d5a08,DAT_004d6048,DAT_004d64d0,DAT_004d6878,DAT_004d6b80,DAT_004d6ce8,DAT_004d6f10,DAT_004d70f8,DAT_004d7320,DAT_004d7508,DAT_004d7730};
 for(int j=0;j<17;++j) { int index=count+1; count=index; unsigned value=FUN_00329060(names[j]); entries[index].name=value; entries[count].data=data[j]; entries[count].count=0; }
 ++count; return this;
}