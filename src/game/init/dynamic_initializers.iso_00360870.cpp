// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x00360870 FUN_00360870 (22 B): matches/0x00360870.cpp [isolated: no out-of-line definition (target defined in a class body); lost its match in the tree (call sequence differs)]
// sym: _$E1
namespace fn_fabc8fa7 {} using namespace fn_fabc8fa7;
namespace fn_fabc8fa7 {
class Thing {
  public:
    Thing() { FUN_00253120(); }
    void FUN_00253120();
    ~Thing();
};
#if !defined(HULK_PTR64)
Thing gThing;
#else
extern "C" char DAT_004e7038[];   // (unb4) the item (records.h types it; this TU includes no header)
// (x64t5) the object is the game's om type DAT_004e7038 (records.h), which SeqEventVarPosDist's allocation and type calls name.
// The Wine link binds this definition to the item by address (wine_link local_data_bindings); the native link has
// no such binding, so the 64-bit build constructs the item itself (the 32-bit code is the definition above)
struct Item_004e7038 {
    Item_004e7038() { ((Thing*)(void*)DAT_004e7038)->FUN_00253120(); }   // (unb4) the constructor's body (no placement new without a header)
    ~Item_004e7038() { ((Thing*)(void*)DAT_004e7038)->~Thing(); }
} gThing;
#endif
} // namespace fn_fabc8fa7

