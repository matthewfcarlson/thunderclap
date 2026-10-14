// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 51/52, incomplete)
// FUN_00093c40 @ 0x00093c40
extern "C" int __cdecl FUN_00345804(const char*, const char*, ...);
struct TypeInfo_93c40 { unsigned int data; };
extern TypeInfo_93c40 DAT_0049dab8, DAT_0049dafc, DAT_0049db1c;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo_93c40*, TypeInfo_93c40*, int);
struct State_93c40 { char pad[8]; unsigned char flag; };
struct CastState { char pad[32]; unsigned char flag; };
struct Entry_93c40 { unsigned int a,b; int chapter,mission; int ids[16]; };
struct Game_93c40 {
 char pad0[0x74]; State_93c40* state; char pad1[0xd90-0x78]; Entry_93c40 entries[32];
 void FUN_00093600(int,int);
 void target(const char* text);
};
void Game_93c40::target(const char* text) {
 int chapter, mission;
 if(FUN_00345804(text,"c%dm%d",&chapter,&mission)!=2) return;
 for(int i=0;i<32;++i) {
  Entry_93c40& e=entries[i];
  if(!(e.a|e.b)) break;
  bool restricted = chapter>7 ||
   (chapter==1 && mission==10) ||
   (chapter==4 && (mission==10 || mission==11)) ||
   (chapter==2 && mission==3 && e.chapter==2 && e.mission==2) ||
   e.chapter>chapter || (e.chapter==chapter && e.mission>mission);
  if(!restricted) {
   for(int j=0;j<16;++j) {
    int id=e.ids[j];
    if(id==-1) break;
    FUN_00093600(id,0);
   }
  } else {
   for(int j=0;j<16;++j) {
    if(e.ids[j]==-1) break;
    bool allow=false;
    if(!state->flag) {
     CastState* s=static_cast<CastState*>(FUN_00344e74(state,0,&DAT_0049dab8,&DAT_0049dafc,0));
     if(!s) s=static_cast<CastState*>(FUN_00344e74(state,0,&DAT_0049dab8,&DAT_0049db1c,0));
     if(s && s->flag) allow=true;
    }
    if(allow || (chapter==0 && mission==10)) {
     int id=e.ids[j];
     if(id>=0x266 && id<=0x2c9) FUN_00093600(id,0);
    }
   }
  }
 }
}