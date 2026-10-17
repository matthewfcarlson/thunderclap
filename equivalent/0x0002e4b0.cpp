// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x0002e4b0
namespace math { struct Vector { float x,y,z; }; }
class CActorManager {};
struct Arguments { const char* text; math::Vector position; };
class Function { public: virtual void vfunc_0(); virtual void vfunc_1(); };
class Method2 : public Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* actor, const Arguments* args, bool* result);
    char pad[0x18];
    bool (CActorManager::*method)(const char*, math::Vector);
};
void Method2::vfunc_2(CActorManager* actor, const Arguments* args, bool* result) {
    bool value = (actor->*method)(args->text, args->position);
    if (result) *result = value;
}