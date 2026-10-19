// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 32/32)
// FUN_001fdc90 @ 0x001fdc90
// cl-flags: /GS
struct Reader {
 bool FUN_001d2ba0(const char*,int,int);
 bool FUN_001d2c60(const char*,char*,int);
 bool FUN_001d2da0(const char*,int*);
 bool FUN_001d2d40(const char*,float*);
 bool FUN_001d2e10(const char*,int*);
 bool FUN_001d2de0(const char*,int*);
 void FUN_001d19d0(int);
 void FUN_001d1900(int);
};
Reader* __cdecl FUN_001d4c90();
struct Entry_1fdc90 {
 char pad[0x6e0]; int count; char tail[0xc70-0x6e4];
 int FUN_001f93e0(const char*,int,int,int,int,float,float,float,int,int);
};
struct Manager_1fdc90 {
 char pad[0x234]; Entry_1fdc90* entries;
 int FUN_001fcff0(int);
 bool FUN_001fdc90(int,const char*);
};
bool Manager_1fdc90::FUN_001fdc90(int id,const char* file) {
 struct Parameters {
 int script; float kill; int locator,total; float deactivate; int maximum; float radius; int minimum,reset; char name[256];
 } p;
 int index=FUN_001fcff0(id);
 if(index==-1) { return false; }
 if(entries[index].count>=16) { return false; }
 Reader* reader=FUN_001d4c90();
 if(!reader) { return false; }
 if(!reader->FUN_001d2ba0(file,1,0)) { return false; }
 p.script=-1;
 bool ok=false;
 if(reader->FUN_001d2c60("template",p.name,256) &&
 reader->FUN_001d2da0("min",&p.minimum) &&
 reader->FUN_001d2da0("max",&p.maximum) &&
 reader->FUN_001d2da0("total",&p.total) &&
 reader->FUN_001d2da0("locator_type",&p.locator) &&
 reader->FUN_001d2d40("kill_distance",&p.kill) &&
 reader->FUN_001d2d40("deactivate_distance",&p.deactivate) &&
 reader->FUN_001d2d40("trigger_radius",&p.radius) &&
 reader->FUN_001d2e10("script",&p.script) &&
 reader->FUN_001d2de0("reset_on_exit",&p.reset)) {
 ok=entries[index].FUN_001f93e0(p.name,p.minimum,p.maximum,p.total,p.locator,p.kill,p.deactivate,p.radius,p.script,p.reset)!=-1;
 }
 reader->FUN_001d19d0(1);
 if(!ok) reader->FUN_001d1900(p.script);
 return ok;
}