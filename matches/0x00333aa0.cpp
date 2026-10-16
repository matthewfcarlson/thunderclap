#include "gen/movie.h"

struct Thing_333aa0 {
    char pad[0xc];
    unsigned int value;
};

unsigned int movie::PlayerBink::vfunc_15() {
    if ((*(Thing_333aa0 * *)&this->f_1c))
        return (*(Thing_333aa0 * *)&this->f_1c)->value;
    return 0;
}
