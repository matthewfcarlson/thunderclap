// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 21/22, incomplete)
// FUN_0021c790 @ 0x0021c790
struct Entry_21c790 { unsigned key; unsigned a,b; };
struct Table_21c790 { char pad[24]; Entry_21c790* entries; };
struct Node { Node* next; unsigned other; unsigned char limit, marked; };
struct Object { Table_21c790* table; unsigned pad4; Object* parent; char padc[8]; Node* nodes; char pad18[28]; unsigned char count; char pad35[65]; unsigned short indices[256]; };
struct Result_21c790 { int type; int index; unsigned extra; int a,b; };
int __cdecl FUN_002209b0(Object*,unsigned);
int __cdecl FUN_0021c5f0(unsigned,Result_21c790*);
void __cdecl target(Object* object,unsigned key,Result_21c790* result,int flag) {
 if (!object) { result->a=-1; result->b=-1; result->type=7; result->index=255; return; }
 int i=(int)object->count-1;
 for (;i>=0;--i) { if(object->table->entries[object->indices[i]].key==key) break; }
 if(i>=0) {
 result->a=-1; result->b=-1; result->type=5; result->index=i;
 if(!flag) { Node* node=object->nodes; while(node) { if((int)node->limit<=i) { node->marked=1; break; } node=node->next; } }
 return;
 }
 target(object->parent,key,result,0);
 if(result->type==7) { if(flag) result->index=FUN_002209b0(object,key); }
 else { int index=FUN_0021c5f0(key,result); result->type=6; result->index=index; }
}
