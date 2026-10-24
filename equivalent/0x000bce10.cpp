// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 14/14)
// FUN_000bce10 @ 0x000bce10
struct Manager_bce10 { int FUN_000f7240(int,int); };
extern Manager_bce10* __cdecl FUN_000fc1b0();
extern void* __cdecl FUN_000fc260(const char*);
extern char DAT_0049dba4, DAT_0049dbbc;
struct Selector_bce10;
extern Selector_bce10* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Text_bce10 { char storage[36]; void FUN_000f7930(); void FUN_000f7960(); void FUN_000f8500(const char*,Manager_bce10*,int); void FUN_000f7a10(int,int); };
struct Item_bce10 { int first; int second; const char* FUN_0027b010(); };
struct List_bce10 { int FUN_00089950(); int FUN_00089960(int); };
struct Lookup_bce10 { Item_bce10* FUN_00092bb0(int); };
struct Selector_bce10 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(Text_bce10*,int,int); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(int);
 char pad[0x1d54]; int count;
 void FUN_000e36c0();
};
struct Target_bce10 { char pad[0x34]; List_bce10* list; char pad2[0x14]; Lookup_bce10* lookup; void FUN_000b8e70(int); void run(); };
void Target_bce10::run() {
 if (!list || !lookup) return;
 Selector_bce10* sel=FUN_00344e74(FUN_000fc260("jump_marker_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!sel) return;
 Text_bce10 text; text.FUN_000f7930();
 text.FUN_000f8500("", FUN_000fc1b0(), 1);
 sel->FUN_000e36c0();
 for(int i=0;i<list->FUN_00089950();++i) {
 int tmp1 = list->FUN_00089960(i);
 Item_bce10* item=lookup->FUN_00092bb0(tmp1);
 int second=item->second; int first=item->first;
 int index=FUN_000fc1b0()->FUN_000f7240(first,second);
 if(index!=-1) text.FUN_000f7a10(index,0);
 else text.FUN_000f8500(item->FUN_0027b010(), FUN_000fc1b0(), 1);
 sel->v19(&text,0,0);
 }
 if(sel->count>0) {sel->v25(0); FUN_000b8e70(0);}
 sel->v3();
 text.FUN_000f7960();
}
