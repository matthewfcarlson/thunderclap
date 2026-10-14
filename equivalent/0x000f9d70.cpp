// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 33/34, incomplete)
// FUN_000f9d70 @ 0x000f9d70
typedef unsigned __int64 TypeId;
extern unsigned long DAT_004e0a08, DAT_004e0a0c, DAT_004e0a10, DAT_004e0a14;
extern char DAT_004a1934, DAT_004a13e4;
struct Node {
 virtual void unused();
 virtual TypeId type();
 Node* next;
 int depth;
};
struct List_f9d70 { Node* first; };
extern void* __cdecl FUN_00344e74(Node*, int, const void*, const void*, int);
struct Cursor_f9d70 {
 char pad0[4];
 List_f9d70* list;
 Node* current;
 char pad1[9];
 unsigned char disabled;
 void* FUN_000f9d70();
};
void* Cursor_f9d70::FUN_000f9d70() {
 if (disabled == 1) return 0;
 Node* node = current ? current->next : list->first;
 int nesting = 0;
 if (node) {
  TypeId t = node->type();
  if ((unsigned long)t == DAT_004e0a08 && (unsigned long)(t >> 32) == DAT_004e0a0c) nesting = 1;
  else {
   t = node->type();
   if ((unsigned long)t == DAT_004e0a10 && (unsigned long)(t >> 32) == DAT_004e0a14) nesting = -1;
  }
  while (node->depth > 1 || nesting > 0) {
   node = node->next;
   if (!node) break;
   t = node->type();
   if ((unsigned long)t == DAT_004e0a08 && (unsigned long)(t >> 32) == DAT_004e0a0c) ++nesting;
   else {
    t = node->type();
    if ((unsigned long)t == DAT_004e0a10 && (unsigned long)(t >> 32) == DAT_004e0a14) --nesting;
   }
  }
  if (node) {
   t = node->type();
   if ((unsigned long)t == DAT_004e0a10 && (unsigned long)(t >> 32) == DAT_004e0a14 && nesting == 0) node = node->next;
  }
 }
 return FUN_00344e74(node, 0, &DAT_004a13e4, &DAT_004a1934, 0);
}