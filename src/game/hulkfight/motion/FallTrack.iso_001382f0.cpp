// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"


// 0x001382f0 FUN_001382f0 (213 B): equivalent/0x001382f0.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_001382f0@fn_fd2a43d4@@YAXXZ @56b15dca0047 @wd9152599fe22
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_fd2a43d4 {} using namespace fn_fd2a43d4;
namespace fn_fd2a43d4 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_001382f0 @ 0x001382f0

/* size_t: tree_prelude.h */

} // namespace fn_fd2a43d4
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fd2a43d4 {

extern void* __cdecl FUN_0008d690(unsigned int);
extern char FUN_00133470(void*, int); /* (unb4) as defined; address taken only */
extern bool FUN_00133480(void*, int); /* (unb4) as defined; address taken only */
extern char FUN_001334a0(void*, int); /* (unb4) as defined; address taken only */
struct FloatBase_1382f0 {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 FloatBase_1382f0(const char*); // equiv-name: FUN_00234960
};
struct IntBase_1382f0 {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 IntBase_1382f0(const char*); // equiv-name: FUN_002348e0
};
namespace hulkfight { namespace motion { class HoverTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : FloatBase_1382f0 {
 ParamFloatConstRange(const char* s) : FloatBase_1382f0(s) {}
 virtual void slot0();
};
template<class T> struct ParamIntConstRange : IntBase_1382f0 {
 ParamIntConstRange(const char* s) : IntBase_1382f0(s) {}
 virtual void slot0();
};
}
extern void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl FUN_001382f0() {
 if (!DAT_004e0eec) {
  void* entries[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::HoverTrack> F;
  typedef fight::ParamIntConstRange<hulkfight::motion::HoverTrack> I;
  void* p=FUN_0008d690((int)sizeof(F));
  F* a = p ? new (p) F("timeBegin") : 0;
  if(a) a->callback=(void (*)())FUN_00133470;
  entries[0]=a;
  p=FUN_0008d690((int)sizeof(F));
  F* b = p ? new (p) F("timeEnd") : 0;
  if(b) b->callback=(void (*)())FUN_00133480;
  entries[1]=b;
  p=FUN_0008d690((int)sizeof(I));
  I* c = p ? new (p) I("groundFixup") : 0;
  if(c) c->callback=(void (*)())FUN_001334a0;
  entries[2]=c;
  FUN_002347b0(&DAT_004e0ee8,entries,3);
 }
 ++DAT_004e0eec;
}
} // namespace fn_fd2a43d4

