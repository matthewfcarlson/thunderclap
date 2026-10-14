// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 24/24)
// FUN_000e7d90 @ 0x000e7d90
struct LanguageInfo { char pad[0x10c]; unsigned language; };
struct Reader {
 bool FUN_000f9e90();
 const char* FUN_000fad90();
 bool FUN_000f9ef0();
 void FUN_000f9f30();
 bool FUN_000f9e50();
 int FUN_000fb110();
 void FUN_000fa0a0();
 void FUN_000f9fb0();
};
struct Handler_e7d90 { virtual void process(Reader*, int); };
extern "C" int __cdecl strncmp(const char*, const char*, unsigned);
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual LanguageInfo* info();
 void target(Reader* reader, Handler_e7d90* handler);
};
void Object::target(Reader* reader, Handler_e7d90* handler) {
 bool match=false;
 const char* language;
 switch(info()->language) {
 case 1: language="fr"; break;
 case 2: language="it"; break;
 case 3: language="jp"; break;
 case 4: language="es"; break;
 case 5: language="uk"; break;
 default: language="en"; break;
 }
 while(reader->FUN_000f9e90()) {
 if(strncmp(reader->FUN_000fad90(),language,2)==0) match=true;
 }
 if(reader->FUN_000f9ef0()) {
 reader->FUN_000f9f30();
 while(reader->FUN_000f9e50()) {
 int value=reader->FUN_000fb110();
 if(match) {
 if(!handler) { reader->FUN_000fa0a0(); break; }
 handler->process(reader,value);
 }
 }
 reader->FUN_000f9fb0();
 }
}
