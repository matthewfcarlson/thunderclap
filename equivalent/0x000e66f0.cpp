// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000e66f0 @ 0x000e66f0
struct Entry {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual const char* name();
};
struct Manager {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
 virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
 virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
 virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
 virtual Entry* create(Manager*, const char*);
 char padding[0x108];
 Entry* entries[64];
 Entry* FUN_000e66f0(const char* key);
};
Entry* Manager::FUN_000e66f0(const char* key) {
 Entry* result = 0;
 for (int i=0;i<64;++i) {
  if (entries[i]) {
   const char* b=entries[i]->name();
   const char* a=key;
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) {
    result=entries[i];
    break;
   }
  }
 }
 if (result) return result;
 for (int j=0;j<64;++j) {
  if (!entries[j]) {
   result=create(this,key);
   entries[j]=result;
   break;
  }
 }
 return result;
}
