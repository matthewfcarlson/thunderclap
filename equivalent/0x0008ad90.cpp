// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 16/18, incomplete)
// FUN_0008ad90 @ 0x0008ad90
typedef unsigned __int64 U64_8ad90;
extern unsigned DAT_004dd730;
extern U64_8ad90 DAT_004dd728;
extern const char* DAT_003ffde0[35];
U64_8ad90 __cdecl FUN_0027b020(const char*);
int __cdecl FUN_00345804(const char*,const char*,int*,int*);
struct Entry_8ad90 { char text[24]; };
struct Obj_8ad90 { char pad[0x160]; Entry_8ad90 entries[1]; int FUN_00089400(const char*); void target(int*,int*); };
void Obj_8ad90::target(int* a,int* b) {
 if (!(DAT_004dd730 & 1)) { DAT_004dd730 |= 1; DAT_004dd728=FUN_0027b020("complete"); }
 *a=0; *b=0;
 int index=FUN_00089400("c00m01");
 const char* s=index==-1 ? "" : entries[index].text;
 if (*s==0) { FUN_00345804("c00m01","c%dm%d",a,b); return; }
 for(int i=0;i<35;++i) {
 const char* name=DAT_003ffde0[i];
 index=FUN_00089400(name);
 s=index==-1 ? "" : entries[index].text;
 if(s) { U64_8ad90 v=FUN_0027b020(s); if(v && v!=DAT_004dd728) {FUN_00345804(name,"c%dm%d",a,b);return;} }
 }
}