#include "gen/fight.h"

class StringReader_23a3f0 {
  public:
    char pad0[8];
    unsigned char* mBuffer;
    char padc[4];
    unsigned int mLength;
    unsigned int mPosition;
};
namespace fight {

} // namespace fight
unsigned char fight::BufferStringReader::vfunc_4() {
    if (this->f_14 >= this->f_10)
        return 0;
    return (*(unsigned char * *)&this->f_08)[this->f_14];
}
