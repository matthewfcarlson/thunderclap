// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 20/20)
// FUN_002168d0 @ 0x002168d0
struct Item_2168d0 { char pad[5]; unsigned char flags; };
struct Entry_2168d0 { int kind; Item_2168d0* item; };
struct Node { char pad[6]; unsigned char mode; unsigned char count; Item_2168d0* first; Item_2168d0* second; union { struct { int kind; Item_2168d0* item; } initial; Item_2168d0* children[1]; Entry_2168d0 entries[1]; } data; };
void __cdecl FUN_002164b0(void*, Item_2168d0*);
// equiv-conv: FUN_002168d0 esi stack
void __cdecl FUN_002168d0(Node* node, void* context) {
 if(node->mode) {
  for(int i=0;i<node->count;++i) {
   Entry_2168d0* entry=&node->data.entries[i];
   if(entry->kind>=4 && (entry->item->flags & 3)) FUN_002164b0(context,entry->item);
  }
 } else {
  Item_2168d0* item=node->data.initial.item;
  if(item->flags & 3) FUN_002164b0(context,item);
  item=node->second;
  if(item->flags & 3) FUN_002164b0(context,item);
  for(int i=0;i<node->count;++i) {
   item=node->data.children[i+2];
   if(item->flags & 3) FUN_002164b0(context,item);
  }
 }
}