// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00233460 @ 0x00233460
extern "C" int __cdecl FUN_00267760(char*, int, const char*, ...);
extern const char* DAT_004ca248;
extern unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Node {
 char pad[8]; unsigned low; unsigned high; char pad10[4]; Node* next;
 bool FUN_00233460(char* output, int capacity);
};
bool Node::FUN_00233460(char* output, int capacity) {
 unsigned cookie = DAT_004d9968;
 char temporary[1024];
 if ((low | high) == 0) { if (capacity > 0) output[0] = 0; }
 else FUN_00267760(output, capacity, "%08x%08x", high, low);
 Node* current = next;
 while (current) {
  if ((current->low | current->high) == 0)
   FUN_00267760(temporary, 1024, "%s%s", DAT_004ca248, output);
  else
   FUN_00267760(temporary, 1024, "%08x%08x%s%s", current->high, current->low, DAT_004ca248, output);
  FUN_00267760(output, capacity, "%s", temporary);
  current = current->next;
 }
 FUN_00267760(temporary, 1024, "%s%s", DAT_004ca248, output);
 FUN_00267760(output, capacity, "%s", temporary);
 __security_check_cookie(cookie);
 return true;
}