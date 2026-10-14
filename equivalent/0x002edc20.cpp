// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_002edc20 @ 0x002edc20
typedef unsigned int Word_2edc20;
struct Detail_2edc20 { char pad[0x10]; Word_2edc20 value; };
struct Entry_2edc20 { char pad0[0x20]; Detail_2edc20* detail; char pad1[0x2c]; unsigned char selected; char pad2[0x21]; unsigned char enabled; };
struct Work_2edc20 { Word_2edc20 first; Word_2edc20 second; Detail_2edc20* detail; };
extern char __cdecl FUN_002f1160(Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20,Work_2edc20*);
extern void __cdecl FUN_002f24f0(Word_2edc20,Work_2edc20*,Word_2edc20,Word_2edc20,Word_2edc20*);
struct Collection_2edc20 { Entry_2edc20** begin; Entry_2edc20** end; void FUN_002edc20(Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20,Word_2edc20*,char); };
void Collection_2edc20::FUN_002edc20(Word_2edc20 output,Word_2edc20 query,Word_2edc20 a,Word_2edc20 b,Word_2edc20* result,char onlySelected)
{
 Work_2edc20 work;
 work.first=0; work.second=0; work.detail=0;
 for(unsigned int i=0; i < (unsigned int)(end-begin); ++i) {
  Entry_2edc20* entry=begin[i];
  work.detail=entry->detail;
  if(entry->enabled && (!onlySelected || entry->selected)) {
   if(FUN_002f1160(query,a,b,*result,&work)) {
    work.second=work.detail->value;
    FUN_002f24f0(output,&work,a,b,result);
   }
  }
 }
}
