// Texture override packs (wpack1; docs/texture-packs.md "Override packs in the app"): run/app/texpack.cpp, called from
// app.cpp's texture imports. Runner-side only: the module never sees a replacement, so game state is unaffected.
#pragma once
#include <stddef.h>
#include <stdint.h>
#include "pddi/draw_sink.h"

// a texture vid made (its sink id in *slot; the slot is the vid's entry in app.cpp's table and stays put)
void texpack_created(uint32_t vid, uint32_t* slot, const hulk::pddi::SinkTextureDesc& desc);
// a level written: returns the sink's answer (false: no memory now); may change *slot (a replacement made or dropped)
bool texpack_update(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t pitch,
                    uint32_t size);
void texpack_dropped(uint32_t vid);
void texpack_frame();                            // between frames: finished decodes are swapped in
// the Texture Pack setting (port_settings.c texture_pack): the installed packs' names, newline-separated
uint32_t texpack_list(char* out, uint32_t cap);
void texpack_select(uint32_t value);             // 0: off, else the pack whose name hash is `value`
uint32_t texpack_name_hash(const char* name);    // (the setting's value for a pack: FNV-1a, 31 bits, never 0)
bool texpack_tracks(uint32_t vid);               // texpack_update uploads this vid's levels (else app.cpp does)
// a draw that counts for an occlusion query samples the original (the game reads the pixel count): the sink id to use
uint32_t texpack_query_texture(uint32_t vid, uint32_t id);

// ---- shared with meshpack.cpp (model overrides)
uint64_t texpack_xxh64(const void* p, size_t n);
bool texpack_models_wanted();                    // a pack has models, or HULK_PACK_DUMP is on
const char* texpack_model_path(uint64_t key);    // the selected pack's mdl-<key>.obj, or null
bool texpack_dumping();                          // HULK_PACK_DUMP is on
const char* texpack_dump_dir();                  // HULK_PACK_DUMP's folder (null: off, or a keys list only)
void texpack_dump_line(const char* line);        // a line of the dump's keys list
uint32_t texpack_generation();                   // changes when another pack is chosen

// ---- model overrides (meshpack.cpp): a prim buffer's vertices / indices written, a vid dropped, a buffer draw (its
// buffers swapped for the replacement's when the selected pack has one; `counted`: an occlusion query's draw, kept)
void meshpack_vertices(uint32_t vid, const hulk::pddi::SinkVertexData& d);
void meshpack_indices(uint32_t vid, const uint16_t* idx, uint32_t n);
void meshpack_dropped(uint32_t vid);
void meshpack_draw(uint32_t vbVid, uint32_t ibVid, bool counted, hulk::pddi::DrawPacket* p);
