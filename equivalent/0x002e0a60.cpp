// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 16/16)
// pure3d::VertexAnimPrimGroup::vfunc_6 @ 0x002e0a60
struct Ref_2e0a60 {
 virtual void vfunc_0();
 virtual void vfunc_1();
};
struct State_2e0a60 { char pad[0x58]; Ref_2e0a60* current; };
struct Renderer_2e0a60 {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual Ref_2e0a60* vfunc_7();
 virtual void vfunc_8(Ref_2e0a60*);
 char pad[0x58];
 State_2e0a60* state;
};
namespace pure3d {
struct VertexAnimPrimGroup {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 char pad0[0x3c];
 Ref_2e0a60* material;
 char pad1[0x14];
 Renderer_2e0a60* renderer;
 Ref_2e0a60* animation;
};
void VertexAnimPrimGroup::vfunc_6() {
 Renderer_2e0a60* r = renderer;
 State_2e0a60* state = r->state;
 Ref_2e0a60* previous = state->current;
 Ref_2e0a60* saved = r->vfunc_7();
 if (previous) previous->vfunc_0();
 Ref_2e0a60* replacement = animation;
 if (replacement) replacement->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = replacement;
 if (saved) saved->vfunc_0();
 renderer->vfunc_8(material);
 renderer->vfunc_6();
 renderer->vfunc_8(saved);
 if (saved) saved->vfunc_1();
 if (previous) previous->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = previous;
 if (previous) previous->vfunc_1();
}
}
