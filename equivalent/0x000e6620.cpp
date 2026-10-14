// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 22/22)
// FUN_000e6620 @ 0x000e6620
struct Entry_e6620 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual const char* name();
};
extern "C" void __cdecl FUN_000dfcc0(char*, int, const char*, const char*);
struct Manager_e6620 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual Entry_e6620* create(Manager_e6620*, const char*);
 char pad[8]; Entry_e6620* entries[64]; char gap[0x170c-0x10c]; char label[40];
 Entry_e6620* FUN_000e6620(const char*);
};
Entry_e6620* Manager_e6620::FUN_000e6620(const char* text) {
 Entry_e6620* result = 0;
 for(int i=0;i<64;++i) {
  if(entries[i]) {
   const char* b=entries[i]->name();
   const char* a=text;
   while(*a == *b) { if(*a == 0) break; ++a; ++b; }
   if(*a == *b) { result=entries[i]; break; }
  }
 }
 if(result) return result;
 for(int j=0;j<64;++j) {
  if(!entries[j]) {
   result=create(this,text);
   entries[j]=result;
   if(!label[0]) FUN_000dfcc0(label,40,"%s",text);
   break;
  }
 }
 return result;
}
