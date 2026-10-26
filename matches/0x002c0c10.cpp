#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
struct ImageData {
    char pad[8];
    unsigned int width;
    unsigned int height;
};
struct ImageLoader_nv_2c0c10 {
    ImageData* FUN_002c0590(unsigned int data, unsigned int format);
};
} // namespace pure3d
void pure3d::ImageLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { ImageData ** image = (ImageData **)__p0; unsigned int * size = (unsigned int *)__p1; hulk_uintptr data = (hulk_uintptr)__p2; unsigned int unused = (unsigned int)__p3;

    ImageData* loaded = ((ImageLoader_nv_2c0c10*)this)->FUN_002c0590(data, (*(unsigned int *)&this->f_18));
    if (loaded) {
        *image = loaded;
        size[0] = loaded->width;
        size[1] = loaded->height;
    }
}
