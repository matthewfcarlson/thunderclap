// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// pure3d::scenegraph::Scenegraph::vfunc_13 @ 0x00296be0
#include "gen/pure3d.h"

class RefCounted_296be0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};

struct Scene;

namespace pure3d {
namespace scenegraph {
class ShaderCallbackVisitor_296be0 {
public:
    ShaderCallbackVisitor_296be0(RefCounted_296be0 *p) throw() : shader(p) {
        if (shader != 0)
            shader->AddRef();
    }
    virtual ~ShaderCallbackVisitor_296be0() throw() {
        if (shader != 0)
            shader->Release();
    }
    RefCounted_296be0 *shader;
};
}
}

void __cdecl FUN_00296220(Scene *scene, pure3d::scenegraph::ShaderCallbackVisitor_296be0 *v) throw();

void pure3d::scenegraph::Scenegraph::vfunc_13(void* __p0) { RefCounted_296be0 * newShader = (RefCounted_296be0 *)__p0;

    if (newShader != 0)
        newShader->AddRef();
    if ((*(RefCounted_296be0 * *)&this->f_10) != 0)
        (*(RefCounted_296be0 * *)&this->f_10)->Release();
    (*(RefCounted_296be0 * *)&this->f_10) = newShader;
    if ((*(Scene * *)&this->f_40) != 0) {
        pure3d::scenegraph::ShaderCallbackVisitor_296be0 visitor(newShader);
        FUN_00296220((*(Scene * *)&this->f_40), &visitor);
    }
}
