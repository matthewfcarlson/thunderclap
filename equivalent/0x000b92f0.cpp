// STATUS: equivalent (tools/equiv.py level 3: 1169 inputs, branch coverage 11/12, incomplete)
// FUN_000b92f0 @ 0x000b92f0
struct Label_b92f0 { void FUN_000f8500(const char*, int, int); };
struct Item_b92f0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); char pad[20]; Label_b92f0 label; };
extern int DAT_0049dba4, DAT_0049f48c;
extern float DAT_004ddbd4;
void __cdecl FUN_000fc280(const char*);
void* __cdecl FUN_000fc260(const char*);
Item_b92f0* __cdecl FUN_00344e74(void*, int, void*, void*, int);
int __cdecl FUN_000fc1b0();
int __cdecl FUN_000fc320();
void __cdecl FUN_000fc2e0();
void __cdecl FUN_000fc1a0();
unsigned int __cdecl FUN_00267f80();
void __cdecl FUN_000fc300();
struct Renderer_b92f0 { char pad[0xd8]; int state; void FUN_0028f9a0(); void FUN_0028faf0(int); };
extern Renderer_b92f0* DAT_0052c2b4;
struct Scene_b92f0 { void FUN_00293ef0(); void FUN_00294080(); };
struct Owner_b92f0 { char pad[0x20]; Scene_b92f0* scene; void target(int,int,int); };
void Owner_b92f0::target(int a,int b,int flag) {
 FUN_000fc280("Loading");
 Item_b92f0* item=FUN_00344e74(FUN_000fc260("loading_loading_label"),0,&DAT_0049dba4,&DAT_0049f48c,0);
 if(item) {
  Label_b92f0* label=&item->label;
  if(label) { int token=FUN_000fc1b0(); label->FUN_000f8500((unsigned char)flag ? "TBS_MENU_ITEM_PRESS_START2" : "TBS_MENU_ITEM_MC_LOADING_1",token,1); }
  item->v3();
 }
 if(FUN_000fc320()) FUN_000fc2e0();
 for(int i=0;i<3;++i) {
  DAT_0052c2b4->state=-1;
  DAT_0052c2b4->FUN_0028f9a0();
  scene->FUN_00293ef0();
  FUN_000fc1a0();
  scene->FUN_00294080();
  DAT_0052c2b4->FUN_0028faf0(1);
 }
 DAT_004ddbd4=(float)FUN_00267f80()*0.001f;
 FUN_000fc300();
}