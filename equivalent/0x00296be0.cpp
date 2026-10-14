// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// pure3d::scenegraph::Scenegraph::vfunc_13 @ 0x00296be0
class RefCounted_296be0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct Scene;

namespace pure3d {
namespace scenegraph {
class ShaderCallbackVisitor {
public:
    ShaderCallbackVisitor(RefCounted_296be0 *p) throw() : shader(p) {
        if (shader != 0)
            shader->AddRef();
    }
    virtual ~ShaderCallbackVisitor() throw() {
        if (shader != 0)
            shader->Release();
    }
    RefCounted_296be0 *shader;
};
}
}

void __cdecl FUN_00296220(Scene *scene, pure3d::scenegraph::ShaderCallbackVisitor *v) throw();

class Scenegraph {
public:
    virtual void v0();
    virtual void vfunc_13(RefCounted_296be0 *shader);
    char pad04[0x10 - 4];
    RefCounted_296be0 *shader;
    char pad14[0x40 - 0x14];
    Scene *scene;
};

void Scenegraph::vfunc_13(RefCounted_296be0 *newShader)
{
    if (newShader != 0)
        newShader->AddRef();
    if (shader != 0)
        shader->Release();
    shader = newShader;
    if (scene != 0) {
        pure3d::scenegraph::ShaderCallbackVisitor visitor(newShader);
        FUN_00296220(scene, &visitor);
    }
}
