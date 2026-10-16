#include "gen/physics.h"

struct Elem_30e250 {
    void process();
};
struct CollisionAnalyser_nv_30e250 {
    void init();
};

void physics::CollisionAnalyser::vfunc_2(int , int ) {
    ((CollisionAnalyser_nv_30e250*)this)->init();
    unsigned char* p = (*(unsigned char * *)&this->f_04);
    this->f_10 = 0;
    if (p <= (*(unsigned char * *)&this->f_08)) {
        do {
            ((Elem_30e250*)*(void**)(p + 0x10))->process();
            unsigned char* old = p;
            p += 0x14;
            if (old == (*(unsigned char * *)&this->f_08))
                break;
        } while (1);
    }
}
