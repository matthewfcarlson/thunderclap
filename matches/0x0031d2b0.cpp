#include "gen/pure3d.h"

namespace pure3d {

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_102(unsigned char flags) {
    if (flags & 2) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_48))->call(this);
    }
    if (flags & 1) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_4c))->call(this);
    }
    if (flags & 4) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_50))->call(this);
    }
    if (flags & 8) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_54))->call(this);
    }
    if (flags & 16) {
        struct V {
            virtual void call(pure3d::pddiBaseContext*);
        };
        ((V*)(*(void * *)&this->f_58))->call(this);
    }
}
