// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 28/28)
// FUN_001c6950 @ 0x001c6950
extern unsigned int DAT_004e236c;
extern float DAT_004e2360, DAT_004e2364, DAT_004e2368;
extern float DAT_004e2354, DAT_004e2358, DAT_004e235c;
extern char DAT_004c5368, DAT_004c534c, DAT_004c532c;
struct Object {
 char padding[0x28]; unsigned char category;
 int FUN_002a0850();
 void FUN_002a0840(int);
 void FUN_002a0ba0(float*,float*);
};
extern Object* __cdecl FUN_00344e74(Object*,int,void*,void*,int);
struct List { char padding[0x10]; int capacity; int count; Object** objects; };
struct Group { void FUN_0029f800(Object*); };
struct Manager { char padding[0xc0]; Group* normal; Group* alternate; };
extern Manager** __cdecl FUN_001c3d90();
void __stdcall FUN_001c6950(List* list) {
 unsigned int flags=DAT_004e236c;
 if (!(flags&1)) { flags|=1; DAT_004e236c=flags; DAT_004e2360=0.0f; DAT_004e2364=0.0f; DAT_004e2368=0.0f; }
 if (!(flags&2)) { flags|=2; DAT_004e236c=flags; DAT_004e2354=25.0f; DAT_004e2358=0.0f; DAT_004e235c=0.0f; }
 if (!list) return;
 for(int i=0;i<list->count;++i) {
  if(i<list->capacity) {
   Object* object=list->objects[i];
   if(object && object->FUN_002a0850()==0) {
    Object* first=FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c5368,0);
    Object* second=FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c532c,0);
    Object* selected=first?first:second;
    if(selected) { selected->FUN_002a0840(1); selected->FUN_002a0ba0(&DAT_004e2360,&DAT_004e2354); }
   }
  }
 }
 for(int j=0;j<list->count;++j) {
  Object* object=j<list->capacity?list->objects[j]:0;
  Group* group;
  if(object->category) group=(*FUN_001c3d90())->alternate;
  else group=(*FUN_001c3d90())->normal;
  group->FUN_0029f800(object);
 }
}
