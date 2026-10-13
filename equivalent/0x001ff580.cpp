// STATUS: equivalent (tools/equiv.py level 3: 15 inputs, branch coverage 21/22, incomplete)
// FUN_001ff580 @ 0x001ff580
extern void* __cdecl FUN_00263ec0(unsigned);
extern void* __cdecl FUN_0008d6d0(unsigned);
extern unsigned DAT_00425168[6];
struct Volume { char data[64]; void FUN_001fbf40(); };
struct Group { char data[0xc70]; void FUN_001fa630(); };
struct Entry { unsigned count; Volume* volumes; };
struct CTriggerVolumeManager {
 virtual void slot0();
 unsigned untouched;
 unsigned count;
 unsigned table[128];
 unsigned active;
 Volume* volumes;
 Entry* entries[6];
 int* indices;
 int selected;
 Group* groups;
 unsigned groupCount;
 CTriggerVolumeManager();
};
CTriggerVolumeManager::CTriggerVolumeManager() {
 for(int i=0;i<128;++i) table[i]=0;
 count=0;
 unsigned* allocation=(unsigned*)FUN_00263ec0(0x4004);
 Volume* first=0;
 if(allocation) {
  first=(Volume*)(allocation+1); *allocation=256;
  for(int i=0;i<256;++i) first[i].FUN_001fbf40();
 }
 volumes=first;
 for(int type=0;type<6;++type) {
  entries[type]=(Entry*)FUN_0008d6d0(0xa0);
  for(int j=0;j<20;++j) {
   unsigned n=DAT_00425168[type];
   unsigned* block=(unsigned*)(n ? FUN_00263ec0((n<<6)+4) : FUN_0008d6d0(4));
   Volume* result=0;
   if(block) {
    result=(Volume*)(block+1); *block=n;
    if((int)(n-1)>=0) {
     Volume* p=result;
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
 Group* result=0;
 if(block) {
  result=(Group*)(block+1); *block=8;
  for(int k=0;k<8;++k) result[k].FUN_001fa630();
 }
 groups=result; groupCount=0;
}
