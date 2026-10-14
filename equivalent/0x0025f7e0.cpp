// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 30/34, incomplete)
// om::MetaType::vfunc_1 @ 0x0025f7e0
struct Output_25f7e0 { char pad[0x24]; unsigned depth; };
bool __cdecl FUN_00246f50(Output_25f7e0*, const char*, ...);
namespace om {
struct Link_25f7e0 { Link_25f7e0* left; Link_25f7e0* right; Link_25f7e0* parent; };
struct MetaType {
 virtual void vfunc_0();
 virtual bool vfunc_1(Output_25f7e0** out, void* context);
 virtual void vfunc_2();
 Link_25f7e0 links;
 char pad10[4];
 Link_25f7e0* root;
 Link_25f7e0 sentinel;
};
}
bool om::MetaType::vfunc_1(Output_25f7e0** out, void* context) {
 Link_25f7e0* end = &sentinel;
 Link_25f7e0* node = root;
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
  Link_25f7e0* current = &item->links;
  Link_25f7e0* next = current->right;
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