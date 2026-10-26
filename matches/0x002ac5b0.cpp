#include "compat/ptr.h"
#include "gen/pure3d.h"

class Chunk_2ac5b0 {
  public:
    int Type();
};
struct DefaultParticleGeneratorHandler_nv_2ac5b0 {
    int A(Chunk_2ac5b0*, int);
    int B(Chunk_2ac5b0*, int);
    int C(Chunk_2ac5b0*, int);
};

int pure3d::DefaultParticleGeneratorHandler::vfunc_4(hulk_intptr __p0, int arg) { Chunk_2ac5b0 * chunk = (Chunk_2ac5b0 *)__p0;

    int result = 0;
    switch (chunk->Type()) {
    case 0x15b00:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->A(chunk, arg);
        break;
    case 0x15b01:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->B(chunk, arg);
        break;
    case 0x15b02:
        result = ((DefaultParticleGeneratorHandler_nv_2ac5b0*)this)->C(chunk, arg);
        break;
    }
    return result;
}
