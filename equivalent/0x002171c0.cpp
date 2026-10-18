// STATUS: equivalent (tools/equiv.py level 3: 19712 inputs, branch coverage 18/18)
// FUN_002171c0 @ 0x002171c0
// FUN_002171c0 @ 0x002171c0
struct Node { Node* next; unsigned char type; unsigned char flags; char pad[0x42]; Node* child; };
struct Context { char pad[0x14]; unsigned int flags; Node* tail; };
struct Owner_2171c0 { char pad[0x10]; Context* context; };
// equiv-conv: FUN_00216d30 ecx eax
void FUN_00216d30(Owner_2171c0* owner, Node* node);
Node** __cdecl FUN_002171c0(Owner_2171c0* owner, Node** link, int mode, int* budget, int* count) {
 Context* context=owner->context;
 unsigned int mask=context->flags ^ 3;
 int remaining=*budget;
 if(mode) mask |= 0x20;
 Node* node=*link;
 if(node) {
  do {
   if((((unsigned int)node->flags ^ 0x20) & mask)!=mask) {
    node->flags=(unsigned char)((node->flags & 0xf8) | (unsigned char)context->flags);
    if(node->type==8) {
     int nested=0x7fffffff;
     if(node->child) FUN_002171c0(owner,&node->child,mode,&nested,count);
     remaining += nested-0x7fffffff;
    }
    link=&node->next;
    remaining-=8;
   } else {
    *link=node->next;
    if(node==context->tail) context->tail=node->next;
    FUN_00216d30(owner, node);
    remaining-=4;
    if(count) --*count;
   }
   if(remaining<=0) break;
   node=*link;
  } while(node);
 }
 *budget=remaining;
 return link;
}
