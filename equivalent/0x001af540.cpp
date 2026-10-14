// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// FUN_001af540 @ 0x001af540
struct Point_1af540 { unsigned int x,y,z; };
struct Node { unsigned int x,y,z; void* group; unsigned int index; };
struct Collection_1af540 { unsigned int reserved; char* begin; char* end; };
extern bool __cdecl FUN_001ae3f0(Node*,Collection_1af540*);
struct Host_1af540 {
 float FUN_001af2b0(Node*,Node*,void*,void*,Collection_1af540*,void*,void*);
 bool FUN_001af540(Node*,Node*,void*,void*,Collection_1af540*,Point_1af540*,void*,void*,void*);
};
bool Host_1af540::FUN_001af540(Node* a, Node* b, void* c, void* d, Collection_1af540* list, Point_1af540* output, void* unused, void* h, void* i) {
 if (a->group && b->group) {
  if(a->group != b->group) { output->x=a->x; output->y=a->y; output->z=a->z; return false; }
  if(a->index != b->index) {
   float result=FUN_001af2b0(a,b,c,d,list,h,i);
   if(result==0.0f) {
    if(FUN_001ae3f0(a,list)) return true;
    output->x=a->x; output->y=a->y; output->z=a->z; return false;
   }
   if((unsigned int)((int)(list->end-list->begin)/20)>=2) return true;
   list->end=list->begin; return false;
  }
 } else { if(FUN_001ae3f0(a,list)) return true; }
 output->x=b->x; output->y=b->y; output->z=b->z; return false;
}
