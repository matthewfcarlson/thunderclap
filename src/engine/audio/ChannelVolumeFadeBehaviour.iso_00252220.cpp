// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00251850..0x00252350 (kind game, layer engine, confidence high), dominant class audio::ChannelVolumeFadeBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"


// 0x00252220 audio::SeqActionChannelVolumes::vfunc_1 (206 B): equivalent/0x00252220.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?vfunc_1@SeqActionChannelVolumes@audio@fn_f6824a53@@UAEXPAUContext@23@@Z @7f8beedfe095 @w0bd191c27414
#include "gen/owners.h"
#include "decls/data/engine/audio.h"
namespace fn_f6824a53 {} using namespace fn_f6824a53;
namespace fn_f6824a53 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 13/14, incomplete)
// audio::SeqActionChannelVolumes::vfunc_1 @ 0x00252220

typedef unsigned int uint;

} // namespace fn_f6824a53
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f6824a53 {

struct TreeNode_252220 { TreeNode_252220* left; TreeNode_252220* right; char pad[8]; uint key; };
struct Tree_252220 { TreeNode_252220* root; TreeNode_252220 sentinel; };
namespace om { struct DynBehaviour { virtual void vfunc_0(); char pad[16]; }; }
namespace audio {
struct ChannelVolumeFadeBehaviour : om::DynBehaviour { virtual void vfunc_0(); uint key; uint volume; void* channels; void* owner; };
struct Data_252220 { char pad[8]; char channels[16]; uint volume; char search[4]; };
struct Context { char pad[60]; void* handle; };
struct Container_252220 { char pad[60]; void* owner; char pad2[36]; Tree_252220 tree; void* FUN_00251ad0(); };
struct SeqActionChannelVolumes { virtual void vfunc_0(); virtual void vfunc_1(Context*); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); uint unknown; Data_252220* data; uint active; };
}
audio::Container_252220* __cdecl FUN_0024a940(void*,void*);
void* __cdecl FUN_00247530(void*);
void __cdecl FUN_0024f280(Tree_252220*,void*,void*);
void audio::SeqActionChannelVolumes::vfunc_1(Context* context) {
 Container_252220* container = FUN_0024a940(context->handle, data->search);
 Tree_252220* tree = &container->tree;
 TreeNode_252220* end = &tree->sentinel;
 TreeNode_252220* node = tree->root;
 while(node != end) {
  uint key = (*(uint*)&DAT_004e6d28);
  if(key < node->key) node = node->left;
  else if(key > node->key) node = node->right;
  else {
   hulk_uintptr address = (hulk_uintptr)node - 4;
   if(address) {
    ChannelVolumeFadeBehaviour* found = (ChannelVolumeFadeBehaviour*)address;
    Data_252220* source=data;
    uint volume=source->volume;
    void* channels=source->channels;
    found->volume = volume; found->channels = channels; active=0; return;
   }
   break;
  }
 }
 void* owner = container->owner;
 if(!owner) owner=container->FUN_00251ad0();
 void* mem=FUN_00247530(((char*)&DAT_004e6d98));
 ChannelVolumeFadeBehaviour* behavior=0;
 if(mem) {
  Data_252220* source=data;
  uint volume=source->volume;
  void* channels=source->channels;
  behavior=new(mem) ChannelVolumeFadeBehaviour;
  behavior->key=(*(uint*)&DAT_004e6d28);
  behavior->volume=volume;
  behavior->channels=channels;
  behavior->owner=owner;
 }
 FUN_0024f280(tree,behavior,(char*)&behavior->key);
 active=0;
}
} // namespace fn_f6824a53

