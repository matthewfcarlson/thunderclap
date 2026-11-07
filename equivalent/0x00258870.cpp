// STATUS: equivalent (tools/equiv.py level 3: 641 inputs, branch coverage 15/16, incomplete)
// FUN_00258870 @ 0x00258870
// The tree of om types by key: the type with this key, or 0 (records.h OmType: the type's node, keyed by its own key).
#include "compat/ptr.h"
#include "decls/data/records.h"
static inline OmType* entry_of(OmTreeNode* n) {
    return (OmType*)((char*)n - (hulk_intptr) & ((OmType*)0)->body.node);
}
extern "C" OmType* __cdecl FUN_00258870(OmTree* tree, const OmKey* key) {
    OmTreeNode* node = tree->root;
    OmTreeNode* end = &tree->nil;
    while (node != end) {
        const OmKey* k = &entry_of(node)->body.key;
        if (key->hi < k->hi || (key->hi == k->hi && key->lo < k->lo)) {
            node = node->left;
        } else if (key->hi == k->hi && key->lo == k->lo) {
            return entry_of(node);
        } else {
            node = node->right;
        }
    }
    return 0;
}
