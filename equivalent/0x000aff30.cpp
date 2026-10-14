// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 20/20)
// FUN_000aff30 @ 0x000aff30
struct Entry_aff30 { char pad[20]; char name[1]; };
struct Entries_aff30 { Entry_aff30* FUN_000ace20(int index); };
struct Group_aff30 {
 char pad[12]; Entries_aff30* entries; int count;
 void FUN_000af530(int index,int channel,float value);
 void FUN_000af650(int index,int channel,int value);
};
struct Owner_aff30 {
 char pad[8]; Group_aff30* groups[1];
 void update(int slot,float first,float second,int value,const char* name);
};
void Owner_aff30::update(int slot,float first,float second,int value,const char* name) {
 if(slot < 0 || slot >= 1) return;
 Group_aff30* group=groups[slot];
 if(!group) return;
 for(int i=0;i<group->count;++i) {
  Entry_aff30* entry=group->entries->FUN_000ace20(i);
  const char* a=name; const char* b=entry->name;
  while(*a==*b && *a) { ++a; ++b; }
  if(*a==*b) {
   group->FUN_000af530(i,0,first*0.01f);
   group->FUN_000af530(i,1,second*0.01f);
   group->FUN_000af650(i,0,value);
   group->FUN_000af650(i,1,value);
  }
 }
}