// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 20/20)
// FUN_00337210 @ 0x00337210
struct Parser_337210 { char pad[0x5108]; int error; const char* FUN_00337460(); void FUN_003374a0(); };
struct Entry_337210 { char pad[0x10]; unsigned char shape; char pad2[3]; int units; bool FUN_00338030(Parser_337210*); };
struct Manager_337210 { int FUN_003370b0(const char*); Entry_337210* FUN_00337190(); bool target(Parser_337210*); };
bool Manager_337210::target(Parser_337210* p) {
 const char* s=p->FUN_00337460();
 if (!s) return false;
 p->FUN_003374a0(); s=p->FUN_00337460();
 if (!s) return false;
 bool shape=false;
 const char* a="shape"; int i=0; while(i<6 && s[i]==a[i]) ++i;
 if(i==6) { shape=true; p->FUN_003374a0(); s=p->FUN_00337460(); if(!s) return false; }
 int units=-1;
 a="met"; i=0; while(i<4 && s[i]==a[i]) ++i;
 if(i==4) units=0;
 else { a="deg"; i=0; while(i<4 && s[i]==a[i]) ++i; if(i==4) units=1; }
 if(units!=-1) { p->FUN_003374a0(); s=p->FUN_00337460(); if(!s) return false; }
 if(FUN_003370b0(s)) { p->error=8; return false; }
 Entry_337210* e=FUN_00337190();
 if(!e) { p->error=6; return false; }
 if(shape) e->shape=1;
 e->units=units;
 return e->FUN_00338030(p);
}
