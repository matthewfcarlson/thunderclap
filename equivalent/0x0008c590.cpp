// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0008c590 @ 0x0008c590
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Record_8c590 { unsigned int words[66]; };
struct Source_8c590 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void first(const char*, Record_8c590*);
 virtual void next(Record_8c590*);
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22();
 virtual int error();
};
struct Entry_8c590 { Source_8c590* source; char padding[196]; };
struct Object { char padding[8]; Entry_8c590* entries; int target(int index, int selected, Record_8c590* output); };
int Object::target(int index,int selected,Record_8c590* output) {
 unsigned int cookie=DAT_004d9968;
 Record_8c590 records[5]; Source_8c590* source=entries[index].source;
 int result=0;
 for(unsigned int i=0;i<5;++i) {
  if(i==0) source->first(((const char*)&DAT_003f335c),&records[i]); else source->next(&records[i]);
  result=source->error();
  if(result) { output->words[0]=2; break; }
  if(i==(unsigned int)selected) { *output=records[i]; break; }
 }
 __security_check_cookie(cookie);
 return result;
}