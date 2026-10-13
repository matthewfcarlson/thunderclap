// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000bce10 @ 0x000bce10
struct Manager { int FUN_000f7240(int,int); };
extern Manager* __cdecl FUN_000fc1b0(int);
extern void* __cdecl FUN_000fc260(const char*);
extern char DAT_0049dba4, DAT_0049dbbc;
struct Selector;
extern Selector* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Text { char storage[36]; void FUN_000f7930(); void FUN_000f7960(); void FUN_000f8500(const char*,Manager*,int); void FUN_000f7a10(int,int); };
struct Item { int first; int second; const char* FUN_0027b010(); };
struct List { int FUN_00089950(); int FUN_00089960(int); };
struct Lookup { Item* FUN_00092bb0(int); };
struct Selector {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(Text*,int,int); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(int);
 char pad[0x1d54]; int count;
 void FUN_000e36c0();
};
struct Target { char pad[0x34]; List* list; char pad2[0x14]; Lookup* lookup; void FUN_000b8e70(int); void run(); };
void Target::run() {
 if (!list || !lookup) return;
 Selector* sel=FUN_00344e74(FUN_000fc260("jump_marker_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!sel) return;
 Text text; text.FUN_000f7930();
 text.FUN_000f8500("",FUN_000fc1b0(1),1);
 sel->FUN_000e36c0();
 for(int i=0;i<list->FUN_00089950();++i) {
 Item* item=lookup->FUN_00092bb0(list->FUN_00089960(i));
 int second=item->second; int first=item->first;
 Manager* manager=FUN_000fc1b0(first);
 int index=manager->FUN_000f7240(first,second);
 if(index!=-1) text.FUN_000f7a10(index,0);
 else { Manager* m=FUN_000fc1b0(1); const char* s=item->FUN_0027b010(); text.FUN_000f8500(s,m,1); }
 sel->v19(&text,0,0);
 }
 if(sel->count>0) {sel->v25(0); FUN_000b8e70(0);}
 sel->v3();
 text.FUN_000f7960();
}
