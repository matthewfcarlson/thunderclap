// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 18/18)
// FUN_00336f30 @ 0x00336f30
struct Allocator { void FUN_00337d50(); void* FUN_00337d60(unsigned int size, int alignment); };
extern Allocator DAT_0055dbb0;
struct Entry_336f30 { int unknown; const char* name; int type; int FUN_00337f80(); };
struct Source_336f30 { char pad[0x44]; int count; Entry_336f30* FUN_00337090(int); };
struct Target_336f30 { int unknown; Source_336f30* source; void** items; int state; void FUN_003353e0(int, Entry_336f30*); void initialize(Source_336f30*, unsigned char); };
void Target_336f30::initialize(Source_336f30* input, unsigned char skip) {
 DAT_0055dbb0.FUN_00337d50();
 state=0; source=input;
 items=(void**)DAT_0055dbb0.FUN_00337d60((unsigned int)input->count*4,4);
 for(int i=0;i<input->count;++i) {
  Entry_336f30* entry=input->FUN_00337090(i);
  bool match=false;
  if(skip) {
   const char* a=entry->name; const char* b="MayaCreateFunction";
   int j=0; for(;j<19;++j) { if(a[j]!=b[j]) break; }
   match=(j==19);
  }
  items[i]=0;
  if(!match) {
   if(entry->type>=4 && entry->type<=8) {
    int bytes=entry->FUN_00337f80();
    items[i]=DAT_0055dbb0.FUN_00337d60(bytes,4);
   }
   FUN_003353e0(i,entry);
  }
 }
}