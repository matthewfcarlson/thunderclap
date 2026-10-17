// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 6/6)
// FUN_00257730 @ 0x00257730
#include "decls/data/engine/audio.h"

struct Node { Node* next; }; struct List { Node* head; Node sentinel; }; void __cdecl FUN_00256da0(List*,Node*); void __cdecl FUN_00247550(void*,Node*);  void __cdecl FUN_00257730(List* list) { while (list->head != &list->sentinel) { Node* node = list->head; while (node->next != &list->sentinel) node = node->next; FUN_00256da0(list,node); FUN_00247550(((char*)&DAT_004e7690),node); } }