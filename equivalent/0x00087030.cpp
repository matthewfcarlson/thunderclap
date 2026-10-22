// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x00087030
namespace math { struct Vector { float x,y,z; }; }
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
template<class R,class A,class B,class C,class D> struct Function4 : Function {
 virtual void vfunc_2(unsigned unused, const math::Vector* args, bool* result);
 char padding[24];
 R (__cdecl *callback)(A,B,C,D);
};
template<> void Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2(unsigned unused, const math::Vector* args, bool* result) {
 unsigned char value = ((unsigned char (__cdecl*)(math::Vector,math::Vector,math::Vector,math::Vector))callback)(args[0],args[1],args[2],args[3]);
 if(result) *(unsigned char*)result = value;
}
