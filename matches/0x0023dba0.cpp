// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<fight::CommentTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<fight::CommentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<fight::CommentTrack>*)a)->*(*(bool (fight::ParamString<fight::CommentTrack>::**)(int))&this->f_10))(b);
}
