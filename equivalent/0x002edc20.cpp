// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_002edc20 @ 0x002edc20
typedef unsigned int Word;
struct Detail { char pad[0x10]; Word value; };
struct Entry { char pad0[0x20]; Detail* detail; char pad1[0x2c]; unsigned char selected; char pad2[0x21]; unsigned char enabled; };
struct Work { Word first; Word second; Detail* detail; };
extern char __cdecl FUN_002f1160(Word,Word,Word,Word,Work*);
extern void __cdecl FUN_002f24f0(Word,Work*,Word,Word,Word*);
struct Collection { Entry** begin; Entry** end; void FUN_002edc20(Word,Word,Word,Word,Word*,char); };
void Collection::FUN_002edc20(Word output,Word query,Word a,Word b,Word* result,char onlySelected)
{
 Work work;
 work.first=0; work.second=0; work.detail=0;
 for(unsigned int i=0; i < (unsigned int)(end-begin); ++i) {
  Entry* entry=begin[i];
  work.detail=entry->detail;
  if(entry->enabled && (!onlySelected || entry->selected)) {
   if(FUN_002f1160(query,a,b,*result,&work)) {
    work.second=work.detail->value;
    FUN_002f24f0(output,&work,a,b,result);
   }
  }
 }
}
