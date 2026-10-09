class Sub { public: void Init(); char pad[8]; };
class AnimationGroup { public: AnimationGroup(); virtual ~AnimationGroup(); char pad[4]; Sub sub; int a,b,c,d; };
AnimationGroup::AnimationGroup() { sub.Init(); a=0; b=0; c=0; d=0; }
