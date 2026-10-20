#include "compat/ptr.h"
extern "C" int __cdecl _stricmp(const char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
namespace pure3d {
class ImageHandler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual const char* f6();
    virtual unsigned char vfunc_7(const char*);
};
unsigned char ImageHandler::vfunc_7(const char* name) {
    const char* ext = f6();
    hulk_intptr n = strlen(name);
    hulk_intptr m = strlen(ext);
    if (n < m)
        return 0;
    return _stricmp(ext, name + n - m) == 0;
}
} // namespace pure3d