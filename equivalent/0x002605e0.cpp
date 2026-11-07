// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_002605e0 @ 0x002605e0
// audio::SeqEventType constructor: base type registration, own vtable, then insertion into the global type tree.
// equiv-map: ??0FUN_002584d0@@QAE@PAUKey_2605e0@@PAXHH@Z = 0x002584d0
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
inline void *operator new(unsigned int, void *p) { return p; }

struct Key_2605e0 {
    unsigned int lo, hi;
};

struct String {
    void FUN_00240170(const char *s);
};

extern "C" char __cdecl FUN_002601d0(void *, void *, void *);


namespace om {
class Type {
public:
    virtual void v0();
    char data[0x44];
    Type() throw() {}
};
}
// om::Type's constructor (0x002584d0), on a stand-in class named by its address for the native links.
class FUN_002584d0 {
public:
    FUN_002584d0(Key_2605e0 *key, void *b, int c, int d) throw();
};

namespace audio {
class SeqEventType : public om::Type {
public:
    virtual void v0();
    OmTreeNode node;   // records.h SeqEventTypeHead: the node, then the name
    OmString name;
    SeqEventType() throw() {}
    SeqEventType *FUN_002605e0(const char *name, void *b, int c, int d);
};

SeqEventType *SeqEventType::FUN_002605e0(const char *name, void *b, int c, int d)
{
    Key_2605e0 key;
    unsigned __int64 k = FUN_002672f0("Data_Sequence", 0, 0);
    key.lo = (unsigned int)k;
    key.hi = (unsigned int)(k >> 32);
    new (this) FUN_002584d0(&key, b, c, d);
    new (this) SeqEventType;
    ((String *)&this->name)->FUN_00240170(name);
    OmTree *tree = (*(OmTree**)&DAT_004cd380);
    if (DAT_004e7a18.count == 0 && tree) {
        OmTreeNode *nil = &tree->nil;
        nil->left = nil;
        tree->nil.right = nil;
        tree->nil.parent = nil;
        tree->nil.color = 0;
        tree->root = nil;
    }
    FUN_002601d0(tree, this, &this->name);
    DAT_004e7a18.count++;
    return this;
}
}
