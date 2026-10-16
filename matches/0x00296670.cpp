#include "gen/pure3d.h"

void pure3d::scenegraph::BranchNode::vfunc_9() {
    (*(unsigned int *)&this->f_10) &= 0xfffffffe;
    for (unsigned int i = 0; i < this->f_18; ++i) {
        struct Child {
            virtual void a();
            virtual void b();
            virtual void c();
            virtual void d();
            virtual void e();
            virtual void f();
            virtual void g();
            virtual void h();
            virtual void i();
            virtual void call();
        };
        ((Child*)(*(void ** *)&this->f_1c)[i])->call();
    }
}
