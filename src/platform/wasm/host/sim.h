/* The host's own state that the game observes, at a fixed address in linear memory (docs/wasm-port.md): with the
 * XBE image and the game arena it is the whole game state, so a snapshot or a state hash covers it. */
#ifndef HULK_WASM_SIM_H
#define HULK_WASM_SIM_H
#include <stdint.h>

#define SIM_ADDR 0x00F00000u          /* above the game stack (0xE00000..0xF00000), below the arena (16 MB) */

typedef struct {
    uint32_t magic, size;
    uint32_t arena_ready, arena_top;  /* arena.c */
    uint64_t clock;                   /* the virtual clock: ticks of the 733 MHz timestamp counter */
    uint32_t frame;                   /* Presents so far */
    uint32_t kernel_data[16];         /* kernel data exports the import table points at */
} hulk_sim;

#define SIM ((hulk_sim*)(uintptr_t)SIM_ADDR)
#endif
