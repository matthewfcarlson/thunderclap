#include "gen/owners.h"
class Other_295250 {
  public:
    int g(int);
};
bool owners::C_295250::FUN_00295250(int x) {
    int r = ((Other_295250*)this)->g(x);
    if (r >= 0) {
        value = r;
        return true;
    }
    return false;
}