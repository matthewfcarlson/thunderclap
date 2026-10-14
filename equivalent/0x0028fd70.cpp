// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 12/12)
// FUN_0028fd70 @ 0x0028fd70
struct Node { char pad[12]; void* source; };
struct Iterator_28fd70 {
 void* state; void* cursor; Node* node;
 void FUN_002314a0(void*);
 void* FUN_00231640();
 void* FUN_0028fcf0();
 void* FUN_002314c0();
};
extern char DAT_0048f610;
extern char DAT_0048d5bc;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void __cdecl FUN_0028fbc0(void*, void*, int);
void __cdecl FUN_0028fd70(Node* node) {
 struct Workspace { Iterator_28fd70 it; char buffer[256]; } work;
 work.it.FUN_002314a0(node->source);
 work.it.node = node;
 void* item = work.it.FUN_00231640();
 if (!FUN_00344e74(item, 0, &DAT_0048d5bc, &DAT_0048f610, 0)) item = work.it.FUN_0028fcf0();
 while (item) {
  FUN_0028fbc0(item, work.buffer, 255);
  item = work.it.FUN_002314c0();
  while (item && !FUN_00344e74(item, 0, &DAT_0048d5bc, &DAT_0048f610, 0)) item = work.it.FUN_002314c0();
 }
}
