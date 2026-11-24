/* The module header the app's runner includes (wasm2c's game.h), cut down to the co-op imports: for
 * tests/net/coop_loop_test.cpp, which builds run/app/netplay.cpp without the game. */
#pragma once
#include <stdint.h>
typedef uint32_t u32;
typedef uint64_t u64;
struct w2c_hulk;
#ifdef __cplusplus
extern "C" {
#endif
u32 w2c_hulk_net_frame(struct w2c_hulk*, u32, u32);
u32 w2c_hulk_net_update(struct w2c_hulk*, u32, u32);
u32 w2c_hulk_net_host_snap(struct w2c_hulk*, u32, u32);
void w2c_hulk_net_host_ready(struct w2c_hulk*, u32, u32, u32, u32);
u32 w2c_hulk_net_guest_snap(struct w2c_hulk*, u32, u32, u32, u32, u32, u32);
void w2c_hulk_net_guest_ready(struct w2c_hulk*, u32, u32);
void w2c_hulk_net_hash(struct w2c_hulk*, u32, u64);
#ifdef __cplusplus
}
#endif
