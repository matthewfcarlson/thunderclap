// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0026da20 @ 0x0026da20
#include "decls/data/platform/xbox/core.h"

struct Node { char pad0[12]; Node* next; Node* prev; }; struct Head_26da20 { char pad[48]; Node* first; Node* last; };     void __cdecl FUN_0026d940(void*); void FUN_0026da20() { Head_26da20* head = (*(Head_26da20**)&DAT_0052a140); if ((*(Node**)&DAT_0052a148) == 0) head->first = (*(Node**)&DAT_0052a144); else (*(Node**)&DAT_0052a148)->next = (*(Node**)&DAT_0052a144); if ((*(Node**)&DAT_0052a144) == 0) head->last = (*(Node**)&DAT_0052a148); else (*(Node**)&DAT_0052a144)->prev = (*(Node**)&DAT_0052a148); FUN_0026d940(((char*)&DAT_0052a130)); }