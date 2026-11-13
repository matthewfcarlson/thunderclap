// Class declarations from the game's RTTI. Source, edited by hand (tools/gen_headers.py generated them until
// gen1, 2026-11-13). vfunc_N = slot N of the class that introduced it; fields only where code proves the offset.
// tools/gen_headers.py --probe checks the layouts against RTTI and the XBE. See docs/headers.md.

#ifndef HULK_GEN_DATAHANDLER_H
#define HULK_GEN_DATAHANDLER_H

#include "_prelude.h"
// Forward declarations
namespace DataHandler {
class ObjectCreator;
} // namespace DataHandler

namespace DataHandler {
// .?AVObjectCreator@DataHandler@@  vftable 0x3feefc (2)
class ObjectCreator {
public:
    virtual ~ObjectCreator(); // slot 0
    virtual bool vfunc_1(void*) = 0; // slot 1
};

} // namespace DataHandler

#endif // HULK_GEN_DATAHANDLER_H
