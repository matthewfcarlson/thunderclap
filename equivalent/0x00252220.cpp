// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 13/14, incomplete)
// audio::SeqActionChannelVolumes::vfunc_1 @ 0x00252220
typedef unsigned int uint;
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct TreeNode { TreeNode* left; TreeNode* right; char pad[8]; uint key; };
struct Tree { TreeNode* root; TreeNode sentinel; };
namespace om { struct DynBehaviour { virtual void vfunc_0(); char pad[16]; }; }
namespace audio {
struct ChannelVolumeFadeBehaviour : om::DynBehaviour { virtual void vfunc_0(); uint key; uint volume; void* channels; void* owner; };
struct Data { char pad[8]; char channels[16]; uint volume; char search[4]; };
struct Context { char pad[60]; void* handle; };
struct Container { char pad[60]; void* owner; char pad2[36]; Tree tree; void* FUN_00251ad0(); };
struct SeqActionChannelVolumes { virtual void vfunc_0(); virtual void vfunc_1(Context*); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); uint unknown; Data* data; uint active; };
}
extern uint DAT_004e6d28;
extern char DAT_004e6d98;
audio::Container* __cdecl FUN_0024a940(void*,void*);
void* __cdecl FUN_00247530(void*);
void __cdecl FUN_0024f280(Tree*,void*,void*);
void audio::SeqActionChannelVolumes::vfunc_1(Context* context) {
 Container* container = FUN_0024a940(context->handle, data->search);
 Tree* tree = &container->tree;
 TreeNode* end = &tree->sentinel;
 TreeNode* node = tree->root;
 while(node != end) {
  uint key = DAT_004e6d28;
  if(key < node->key) node = node->left;
  else if(key > node->key) node = node->right;
  else {
   uint address = (uint)node - 4;
   if(address) {
    ChannelVolumeFadeBehaviour* found = (ChannelVolumeFadeBehaviour*)address;
    Data* source=data;
    uint volume=source->volume;
    void* channels=source->channels;
    found->volume = volume; found->channels = channels; active=0; return;
   }
   break;
  }
 }
 void* owner = container->owner;
 if(!owner) owner=container->FUN_00251ad0();
 void* mem=FUN_00247530(&DAT_004e6d98);
 ChannelVolumeFadeBehaviour* behavior=0;
 if(mem) {
  Data* source=data;
  uint volume=source->volume;
  void* channels=source->channels;
  behavior=new(mem) ChannelVolumeFadeBehaviour;
  behavior->key=DAT_004e6d28;
  behavior->volume=volume;
  behavior->channels=channels;
  behavior->owner=owner;
 }
 FUN_0024f280(tree,behavior,(char*)behavior+20);
 active=0;
}