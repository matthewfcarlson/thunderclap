// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0035fb20 FUN_0035fb20 (22 B): matches/0x0035fb20.cpp [isolated: no out-of-line definition (target defined in a class body); lost its match in the tree (call sequence differs)]
// sym: _$E1
namespace fn_f92fe9df {} using namespace fn_f92fe9df;
namespace fn_f92fe9df {
class Thing {
  public:
    Thing() { FUN_0024dae0(); }
    void FUN_0024dae0();
    ~Thing();
};
#if !defined(HULK_PTR64)
Thing globalThing;
#else
extern "C" char DAT_004e65b8[];   // (unb4) the item (records.h types it; this TU includes no header)
// (x64t5) the object is the game's om type DAT_004e65b8 (records.h), which ListenerEffectWin32's allocation and type calls name.
// The Wine link binds this definition to the item by address (wine_link local_data_bindings); the native link has
// no such binding, so the 64-bit build constructs the item itself (the 32-bit code is the definition above)
struct Item_004e65b8 {
    Item_004e65b8() { ((Thing*)(void*)DAT_004e65b8)->FUN_0024dae0(); }   // (unb4) the constructor's body (no placement new without a header)
    ~Item_004e65b8() { ((Thing*)(void*)DAT_004e65b8)->~Thing(); }
} globalThing;
#endif
} // namespace fn_f92fe9df

