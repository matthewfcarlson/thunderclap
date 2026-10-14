// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SceneGraphTransformAnimationController::vfunc_27 @ 0x002a77e0
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(int,int,int,int);
 char pad04[16]; Node* child; char pad18[16]; float rotation[12]; float translation[3];
};
struct Channel {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(float, float*); virtual void v5(); virtual void v6(float,float*);
};
struct Track { Channel* FUN_00288960(unsigned,unsigned); };
struct Animation { Track* FUN_00288a10(int); };
struct State { Animation* FUN_00284f50(); float FUN_00284f70(); };
namespace pure3d {
struct SceneGraphTransformAnimationController {
 char pad0[44]; State state; char pad2d[227]; Node* node;
 void vfunc_27();
};
}
void pure3d::SceneGraphTransformAnimationController::vfunc_27() {
 Track* track = state.FUN_00284f50()->FUN_00288a10(0);
 float time = state.FUN_00284f70();
 Channel* channel = track->FUN_00288960(0x544f52,0x544f52);
 if(channel) {
 Node* n=node;
 n->v10(1,6,2,1);
 if(n->child) n->child->v10(1,2,1,1);
 channel->v6(time,n->rotation);
 }
 channel=track->FUN_00288960(0x4e415254,0x54434556);
 if(channel) {
 Node* n=node;
 n->v10(1,6,2,1);
 if(n->child) n->child->v10(1,2,1,1);
 channel->v4(time,n->translation);
 }
}
