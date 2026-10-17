// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CSPManager,math::Vector,const_char_*>::vfunc_2 @ 0x001e0230
struct Vector { float x,y,z; };
struct CSPManager {};
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method1 : Function {
 char padding[0x18];
 Vector (CSPManager::*method)(const char*);
 virtual void vfunc_2(CSPManager* manager, const char** name, Vector* output);
};
void Method1::vfunc_2(CSPManager* manager, const char** name, Vector* output) {
 Vector value = (manager->*method)(*name);
 if (output) *output = value;
}