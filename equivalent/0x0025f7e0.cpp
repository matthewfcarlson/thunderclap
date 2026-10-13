// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 30/34, incomplete)
// om::MetaType::vfunc_1 @ 0x0025f7e0
struct Output { char pad[0x24]; unsigned depth; };
bool __cdecl FUN_00246f50(Output*, const char*, ...);
namespace om {
struct Link { Link* left; Link* right; Link* parent; };
struct MetaType {
 virtual void vfunc_0();
 virtual bool vfunc_1(Output** out, void* context);
 virtual void vfunc_2();
 Link links;
 char pad10[4];
 Link* root;
 Link sentinel;
};
}
bool om::MetaType::vfunc_1(Output** out, void* context) {
 Link* end = &sentinel;
 Link* node = root;
 MetaType* item = 0;
 if (node != end) {
  while (node->left != end) node = node->left;
  item = reinterpret_cast<MetaType*>(reinterpret_cast<char*>(node)-4);
 }
 if (!FUN_00246f50(*out, "[\n")) return false;
 ++(*out)->depth;
 while (item) {
  if (!FUN_00246f50(*out, "%s ", item->sentinel.left)) return false;
  if (!item->vfunc_1(out, context)) return false;
  if (!FUN_00246f50(*out, "\n")) return false;
  Link* current = &item->links;
  Link* next = current->right;
  if (next != end) {
   while (next->left != end) next = next->left;
  } else {
   next = current->parent;
   while (next != end && current == next->right) {
    current = next;
    next = next->parent;
   }
  }
  item = next == end ? 0 : reinterpret_cast<MetaType*>(reinterpret_cast<char*>(next)-4);
 }
 --(*out)->depth;
 return FUN_00246f50(*out, "\n]\n") != 0;
}