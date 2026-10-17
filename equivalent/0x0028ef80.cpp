// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ShaderTextureBroadcast::vfunc_3 @ 0x0028ef80
namespace pure3d {
struct Texture { char pad[16]; void* data; };
struct Shader {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5(int, void*);
};
struct Context { char pad[16]; Shader* shader; };
struct ShaderTextureBroadcast {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual Context* vfunc_3(Context*);
 virtual void vfunc_4();
 virtual void vfunc_5();
 char pad[4];
 int id;
 Texture* texture;
};
Context* ShaderTextureBroadcast::vfunc_3(Context* context) {
 if (context) context->shader->vfunc_5(id, texture ? texture->data : 0);
 return context;
}
}