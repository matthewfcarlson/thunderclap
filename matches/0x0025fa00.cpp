// om::MetaType's constructor: the vftable, an empty tree of its own, the key (the name), then the insertion into the
// tree of meta types (0x004e79b8, set up on the first construction; 0x004cd360 points at it). records.h's OmMetaType.
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"

extern "C" char DAT_0042aa40[];
// the insertion (0x0025f170), declared at class scope: its definition merges into this TU (gen_tree)
struct MetaTypeTree_25fa00 {
    static bool FUN_0025f170(OmTree*, OmMetaType*, const char**);
};
struct MetaType : OmMetaType {
    MetaType* FUN_0025fa00(const char*, int);
};
MetaType* MetaType::FUN_0025fa00(const char* n, int f) {
    OmTreeNode* nil = &children.nil;
    vftable = DAT_0042aa40;
    nil->left = nil;
    children.nil.right = nil;
    children.nil.parent = nil;
    children.root = nil;
    children.nil.color = 0;
    const char** k = &name;
    *k = n;
    flags = f;
    if (DAT_004e79b8.count == 0) {
        DAT_004e79b8.nil.left = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.right = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.parent = &DAT_004e79b8.nil;
        DAT_004e79b8.nil.color = 0;
        DAT_004e79b8.root = &DAT_004e79b8.nil;
    }
    MetaTypeTree_25fa00::FUN_0025f170((OmTree*)DAT_004cd360, this, k);
    ++DAT_004e79b8.count;
    return this;
}
