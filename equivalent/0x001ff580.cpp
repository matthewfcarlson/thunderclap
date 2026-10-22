// STATUS: equivalent (tools/equiv.py level 3: 15 inputs, branch coverage 21/22, incomplete)
// FUN_001ff580 @ 0x001ff580
#include "decls/data/game/global.h"

extern void* __cdecl FUN_00263ec0(unsigned);
extern void* __cdecl FUN_0008d6d0(unsigned);
struct CLocator_1ff580 { char data[64]; void FUN_001fbf40(); };
struct CEncounterGenerator_1ff580 { char data[0xc70]; void FUN_001fa630(); };
struct Entry_1ff580 { unsigned count; CLocator_1ff580* volumes; };
struct CTriggerVolumeManager {
 virtual void slot0();
 unsigned untouched;
 unsigned count;
 unsigned table[128];
 unsigned active;
 CLocator_1ff580* volumes;
 Entry_1ff580* entries[6];
 int* indices;
 int selected;
 CEncounterGenerator_1ff580* groups;
 unsigned groupCount;
 CTriggerVolumeManager();
};
CTriggerVolumeManager::CTriggerVolumeManager() {
 for(int i=0;i<128;++i) table[i]=0;
 count=0;
 unsigned* allocation=(unsigned*)FUN_00263ec0(0x4004);
 CLocator_1ff580* first=0;
 if(allocation) {
  first=(CLocator_1ff580*)(allocation+1); *allocation=256;
  for(int i=0;i<256;++i) first[i].FUN_001fbf40();
 }
 volumes=first;
 for(int type=0;type<6;++type) {
  entries[type]=(Entry_1ff580*)FUN_0008d6d0(0xa0);
  for(int j=0;j<20;++j) {
   unsigned n=((unsigned*)&DAT_00425168)[type];
   unsigned* block=(unsigned*)(n ? FUN_00263ec0((n<<6)+4) : FUN_0008d6d0(4));
   CLocator_1ff580* result=0;
   if(block) {
    result=(CLocator_1ff580*)(block+1); *block=n;
    if((int)(n-1)>=0) {
     CLocator_1ff580* p=result;
     do { p->FUN_001fbf40(); ++p; } while(--n);
    }
   }
   entries[type][j].volumes=result;
   entries[type][j].count=0;
  }
 }
 indices=(int*)FUN_0008d6d0(0x50);
 for(int k=0;k<20;++k) indices[k]=-1;
 selected=-1; active=0;
 unsigned* block=(unsigned*)FUN_00263ec0(0x6384);
 CEncounterGenerator_1ff580* result=0;
 if(block) {
  result=(CEncounterGenerator_1ff580*)(block+1); *block=8;
  for(int k=0;k<8;++k) result[k].FUN_001fa630();
 }
 groups=result; groupCount=0;
}
