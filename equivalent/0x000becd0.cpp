// STATUS: equivalent (tools/equiv.py level 3: 3153 inputs, branch coverage 32/32)
// FUN_000becd0 @ 0x000becd0
struct Entry_becd0 { char pad[0x10]; int a,b; char tail[0x10]; };
struct Manager_becd0 { char pad[0x26c]; const char* names[128]; char gap[0x14]; Entry_becd0 entries[1]; bool FUN_000b4dc0(const char*); bool FUN_000b4c10(const char*); void FUN_000bc5c0(const char*,const char*,int,int); int FUN_000b4d70(int,int); void FUN_000bc6a0(); };
struct Record_becd0 { char pad[0x14]; int value; char tail[0x20]; };
struct Item_becd0 { char pad[0x154]; int index; Record_becd0 records[128]; int count; };
struct Service_becd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void* get(); };
extern "C" long __cdecl atol(const char*);
extern int DAT_0049dba4, DAT_0049dbbc;
extern unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned);
void* __cdecl FUN_000fc260(const char*);
Item_becd0* __cdecl FUN_00344e74(void*,int,int*,int*,int);
Service_becd0* __cdecl FUN_000fc3d0();
struct Object { __int64 FUN_000f72c0(int); };
void __cdecl FUN_000964a0(char*,int,const char*,int,int);
struct Target_becd0 { int unknown; Manager_becd0* manager; int run(int,const char**); };
int Target_becd0::run(int argc,const char** argv) {
 unsigned cookie=DAT_004d9968;
 int result=-1;
 do {
 if(!manager || argc!=4) break;
 const char* command=argv[0]; const char* name=argv[1];
 int mode=atol(argv[2]); if(mode<0 || mode>=3) break;
 int variant=atol(argv[3]); if(variant<1 || variant>2) break;
 Manager_becd0* m=manager;
 if(m->FUN_000b4dc0(command) && m->FUN_000b4c10(name)) { m->FUN_000bc5c0(command,name,mode,variant); result=0; break; }
 Item_becd0* primary=FUN_00344e74(FUN_000fc260("mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 FUN_00344e74(FUN_000fc260("story_mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 FUN_00344e74(FUN_000fc260("side_mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 Item_becd0* item=FUN_00344e74(FUN_000fc260(name),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 bool match=true; const char* s="oneshot";
 if(item && item->count>0) { for(int i=0;i<8;i++) if(command[i]!=s[i]) {match=false;break;} }
 else match=false;
 if(!match) { manager->FUN_000bc6a0(); result=0; break; }
 Record_becd0* record=item->records+item->index;
 Service_becd0* service=FUN_000fc3d0();
 int recvalue=record->value;   // MSVC pushes the argument before it calls get()
 __int64 key=((Object*)service->get())->FUN_000f72c0(recvalue);
 m=manager;
 int found=m->FUN_000b4d70((int)key,(int)(key>>32));
 if(found!=-1) {
 char buffer[128];
 FUN_000964a0(buffer,128,"c%02dm%02d",m->entries[found].a,m->entries[found].b);
 manager->FUN_000bc5c0(command,buffer,mode,variant); result=0; break;
 }
 if(item!=primary) break;
 int index=item->index;
 if(index<0 || index>=128 || !m->names[index]) break;
 manager->FUN_000bc5c0(command,manager->names[index],mode,variant); result=0;
 } while(false);
 __security_check_cookie(cookie);
 return result;
}