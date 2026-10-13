// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 15/16, incomplete)
// audio::SeqActionChannelSendVolumes::vfunc_1 @ 0x0024f6a0
typedef unsigned int uint;
void* __cdecl FUN_00247800();
void* __cdecl FUN_00247530(void*);
extern uint DAT_004e6748;
extern char DAT_004e67b8;
inline void* operator new(unsigned int, void* p) { return p; }
namespace om { struct DynBehaviour { virtual void v0(); }; }
namespace audio {
struct ChannelSendVolumeFadeBehaviour : om::DynBehaviour { virtual void v0(); char pad[16]; uint key; uint value; void* owner; float* volumes; };
struct TreeNode { TreeNode* left; TreeNode* right; char pad[8]; uint key; };
struct Tree { TreeNode* root; char sentinel[20]; };
struct Channel { char pad[0x40]; float* volumes; char pad2[0x20]; Tree tree; };
struct Context { char pad[0x3c]; void* value; };
struct Settings { char pad[8]; char owner[0x40]; uint value; char lookup[4]; };
struct SeqAction { virtual void vfunc_0(); virtual void vfunc_1(Context*); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); uint unknown; Settings* settings; uint active; };
struct SeqActionChannelSendVolumes : SeqAction { virtual void vfunc_1(Context*); };
}
audio::Channel* __cdecl FUN_0024a940(void*,void*);
void __cdecl FUN_0024f280(audio::Tree*,audio::ChannelSendVolumeFadeBehaviour*,uint*);
void audio::SeqActionChannelSendVolumes::vfunc_1(Context* ctx) {
 Channel* ch=FUN_0024a940(ctx->value,settings->lookup);
 Tree* tree=&ch->tree;
 TreeNode* node=tree->root;
 TreeNode* end=(TreeNode*)tree->sentinel;
 if(node!=end) {
 uint key=DAT_004e6748;
 while(node!=end) {
 if(key<node->key) node=node->left;
 else if(key>node->key) node=node->right;
 else {
 ChannelSendVolumeFadeBehaviour* obj=(ChannelSendVolumeFadeBehaviour*)((char*)node-4);
 if(obj) { obj->value=settings->value; obj->owner=settings->owner; active=0; return; }
 break;
 }
 }
 }
 float* volumes=ch->volumes;
 if(!volumes) {
 void* pool=FUN_00247800();
 volumes=(float*)FUN_00247530(pool);
 if(volumes) for(int i=0;i<64;++i) volumes[i]=1.0f;
 ch->volumes=volumes;
 }
 void* memory=FUN_00247530(&DAT_004e67b8);
 ChannelSendVolumeFadeBehaviour* b=0;
 if(memory) {
 new(memory) om::DynBehaviour;
 b=new(memory) ChannelSendVolumeFadeBehaviour;
 b->key=DAT_004e6748;
 b->value=settings->value;
 b->owner=settings->owner;
 b->volumes=volumes;
 }
 FUN_0024f280(tree,b,(uint*)((char*)b+0x14));
 active=0;
}