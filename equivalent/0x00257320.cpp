// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 28/28)
// FUN_00257320 @ 0x00257320
struct Output_257320 { char pad[0x24]; volatile int depth; };
extern int __cdecl FUN_00246f50(Output_257320*, const char*, ...);
struct Text_257320 { const char* FUN_0023fb00(); };
struct Node { Node* volatile left; Node* volatile right; Node* volatile parent; Text_257320* FUN_0024c710(); };
struct Owner_257320 { char pad[0x44]; Node* volatile root; Node sentinel; bool FUN_00257320(Output_257320* volatile* output); };
bool Owner_257320::FUN_00257320(Output_257320* volatile* output) {
 if (!(unsigned char)FUN_00246f50(*output, "mBussList\n[\n")) return false;
 ++(*output)->depth;
 Node* end = &sentinel;
 Node* volatile node = root;
 if (node == end) node = 0;
 else { Node* left = node->left; while (left != end) { node = left; left = node->left; } }
 while (node) {
  Output_257320* stream = *output;
  Text_257320* text = node->FUN_0024c710();
  const char* name = text->FUN_0023fb00();
  if (!(unsigned char)FUN_00246f50(stream, "\"%s\"\n", name)) return false;
  Node* next = node->right;
  if (next != end) {
   Node* left = next->left;
   while (left != end) { next = left; left = next->left; }
  } else {
   Node* child = node;
   next = node->parent;
   while (next != end && child == next->right) {
    child = next;
    next = next->parent;
   }
  }
  node = next == end ? 0 : next;
 }
 --(*output)->depth;
 return (unsigned char)FUN_00246f50(*output, "]\n") != 0;
}