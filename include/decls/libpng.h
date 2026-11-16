// (x64t16, D72) The game's statically linked libpng 1.0.3 and zlib 1.1.3: the records their functions share. Only the
// libpng / zlib TUs and PNGHandler_2 include it (not records.h: a header every TU reaches perturbs MSVC 7.1's
// instruction scheduling in unrelated functions, e.g. 0x002ea3c0, when it grows). Declare no namespaces here.
#ifndef HULK_DECLS_LIBPNG_H
#define HULK_DECLS_LIBPNG_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

// The functions are 0x002d6bb0-0x002dd760 and 0x002e6780-0x002ecd50; PNGHandler_2 drives them. The layouts are the
// game's own, read off its call sites (offsets are the 32-bit ones: 0x002e6a50 allocates sizeof(PngStruct) = 0x21c and sizeof(PngInfo) =
// 0xb8, 0x002e6e50 the inflate state's 0x18 bytes, 0x002ea320 the blocks state's 0x40, 0x002eb780 the codes
// state's 0x1c, 0x002d6f10 passes sizeof(ZStream) = 0x38 to inflateInit's check); natively every pointer is 8 bytes
// and the records are larger. Fields no game function touches keep a role name or stay padding words.
struct PngStruct;
struct PngInfo;
struct PngRowInfo;

// zlib's stream (z_stream): 0x002e6f70 inflates through it, 0x002d6f10 / 0x002e6e50 set it up
struct ZStream {
    unsigned char* next_in;                 // +0x00
    unsigned int avail_in;                  // +0x04
    unsigned int total_in;                  // +0x08
    unsigned char* next_out;                // +0x0c
    unsigned int avail_out;                 // +0x10
    unsigned int total_out;                 // +0x14
    char* msg;                              // +0x18 the last error's text
    struct ZInflateState* state;            // +0x1c
    void* (__cdecl* zalloc)(void* opaque, unsigned int items, unsigned int size);  // +0x20
    void (__cdecl* zfree)(void* opaque, void* address);                            // +0x24
    void* opaque;                           // +0x28 (libpng: its PngStruct)
    int data_type;                          // +0x2c
    unsigned int adler;                     // +0x30
    unsigned int reserved;                  // +0x34
};

// inflate's own state (0x002e6e50 allocates it, 0x002e6f70 runs it, 0x002e6db0 resets it, 0x002e6e00 frees it)
struct ZInflateState {
    int mode;                               // +0x00
    union {
        unsigned int method;                // +0x04
        struct { unsigned int was, need; } check;
        unsigned int marker;
    } sub;
    int nowrap;                             // +0x0c
    unsigned int wbits;                     // +0x10
    struct ZInflateBlocks* blocks;          // +0x14
};

// one Huffman table entry (no pointers: its layout is the same everywhere)
struct ZInflateHuft {
    unsigned char exop;                     // +0x0
    unsigned char bits;                     // +0x1
    unsigned short pad;                     // +0x2
    unsigned int base;                      // +0x4
};

// the codes state (0x002eb780 allocates it, 0x002eb7c0 decodes with it, 0x002ebed0 frees it)
struct ZInflateCodes {
    int mode;                               // +0x00
    unsigned int len;                       // +0x04
    union {
        struct { ZInflateHuft* tree; unsigned int need; } code;   // +0x08
        unsigned int lit;
        struct { unsigned int get; unsigned int dist; } copy;
    } sub;
    unsigned char lbits;                    // +0x10
    unsigned char dbits;                    // +0x11
    ZInflateHuft* ltree;                    // +0x14
    ZInflateHuft* dtree;                    // +0x18
};

// the blocks state (0x002ea320 allocates it, 0x002ea3c0 decodes, 0x002ea2a0 resets, 0x002ec650 flushes its window)
struct ZInflateBlocks {
    int mode;                               // +0x00
    union {
        unsigned int left;                  // +0x04 stored block: bytes left
        struct {
            unsigned int table;             // +0x04
            unsigned int index;             // +0x08
            unsigned int* blens;            // +0x0c
            unsigned int bb;                // +0x10
            ZInflateHuft* tb;               // +0x14
        } trees;
        struct { ZInflateCodes* codes; } decode;   // +0x04
    } sub;
    unsigned int last;                      // +0x18
    unsigned int bitk;                      // +0x1c
    unsigned int bitb;                      // +0x20
    ZInflateHuft* hufts;                    // +0x24 (0x5a0 entries)
    unsigned char* window;                  // +0x28
    unsigned char* end;                     // +0x2c
    unsigned char* read;                    // +0x30
    unsigned char* write;                   // +0x34
    unsigned int (__cdecl* checkfn)(unsigned int check, const unsigned char* buf, unsigned int len);  // +0x38
    unsigned int check;                     // +0x3c
};

// libpng's colours: a palette entry, the 16-bit colour (tRNS / bKGD values), the significant bits / shifts
struct PngColor { unsigned char red, green, blue; };
struct PngColor16 { unsigned char index; unsigned short red, green, blue, gray; };   // 10 bytes
struct PngColor8 { unsigned char red, green, blue, gray, alpha; };
struct PngTime { unsigned short year; unsigned char month, day, hour, minute, second; };
struct PngText {                            // tEXt / zTXt
    int compression;                        // +0x0
    char* key;                              // +0x4
    char* text;                             // +0x8
    unsigned int text_length;               // +0xc
};

// the row being transformed (png_row_info; no pointers)
struct PngRowInfo {
    unsigned int width;                     // +0x0
    unsigned int rowbytes;                  // +0x4
    unsigned char color_type;               // +0x8
    unsigned char bit_depth;                // +0x9
    unsigned char channels;                 // +0xa
    unsigned char pixel_depth;              // +0xb
};

typedef void (__cdecl* PngErrorFn)(PngStruct* png, const char* message);
typedef void (__cdecl* PngRwFn)(PngStruct* png, unsigned char* data, unsigned int length);
typedef void (__cdecl* PngUserTransformFn)(PngStruct* png, PngRowInfo* row_info, unsigned char* row);
typedef void* (__cdecl* PngMallocFn)(PngStruct* png, unsigned int size);
typedef void (__cdecl* PngFreeFn)(PngStruct* png, void* block);

// png_struct (0x21c bytes): 0x002d6f10 creates it, 0x002d7b60 clears it but for the jump buffer, the error callbacks
// and the free callback
struct PngStruct {
    int jmpbuf[16];                         // +0x000 the error handler's _setjmp3 buffer (64 bytes on every target)
    PngErrorFn error_fn;                    // +0x040
    PngErrorFn warning_fn;                  // +0x044
    void* error_ptr;                        // +0x048
    PngRwFn write_data_fn;                  // +0x04c
    PngRwFn read_data_fn;                   // +0x050
    PngUserTransformFn read_user_transform_fn;   // +0x054
    PngUserTransformFn write_user_transform_fn;  // +0x058
    void* io_ptr;                           // +0x05c the read callback's stream
    unsigned int mode;                      // +0x060
    unsigned int flags;                     // +0x064
    unsigned int transformations;           // +0x068
    ZStream zstream;                        // +0x06c
    unsigned char* zbuf;                    // +0x0a4
    unsigned int zbuf_size;                 // +0x0a8
    int zlib_level;                         // +0x0ac
    int zlib_method;                        // +0x0b0
    int zlib_window_bits;                   // +0x0b4
    int zlib_mem_level;                     // +0x0b8
    int zlib_strategy;                      // +0x0bc
    unsigned int width;                     // +0x0c0
    unsigned int height;                    // +0x0c4
    unsigned int num_rows;                  // +0x0c8
    unsigned int usr_width;                 // +0x0cc
    unsigned int rowbytes;                  // +0x0d0
    unsigned int irowbytes;                 // +0x0d4
    unsigned int iwidth;                    // +0x0d8
    unsigned int row_number;                // +0x0dc
    unsigned char* prev_row;                // +0x0e0
    unsigned char* row_buf;                 // +0x0e4
    unsigned char* sub_row;                 // +0x0e8
    unsigned char* up_row;                  // +0x0ec
    unsigned char* avg_row;                 // +0x0f0
    unsigned char* paeth_row;               // +0x0f4
    PngRowInfo row_info;                    // +0x0f8
    unsigned int idat_size;                 // +0x104
    unsigned int crc;                       // +0x108
    PngColor* palette;                      // +0x10c
    unsigned short num_palette;             // +0x110
    unsigned short num_trans;               // +0x112
    unsigned char chunk_name[5];            // +0x114
    unsigned char compression_type;         // +0x119
    unsigned char filter_type;              // +0x11a
    unsigned char interlaced;               // +0x11b
    unsigned char pass;                     // +0x11c
    unsigned char do_filter;                // +0x11d
    unsigned char color_type;               // +0x11e
    unsigned char bit_depth;                // +0x11f
    unsigned char usr_bit_depth;            // +0x120
    unsigned char pixel_depth;              // +0x121
    unsigned char channels;                 // +0x122
    unsigned char usr_channels;             // +0x123
    unsigned char sig_bytes;                // +0x124
    unsigned short filler;                  // +0x126
    unsigned char background_gamma_type;    // +0x128
    float background_gamma;                 // +0x12c
    PngColor16 background;                  // +0x130
    PngColor16 background_1;                // +0x13a
    void (__cdecl* output_flush_fn)(PngStruct* png);   // +0x144
    unsigned int flush_dist;                // +0x148
    unsigned int flush_rows;                // +0x14c
    int gamma_shift;                        // +0x150
    float gamma;                            // +0x154
    float screen_gamma;                     // +0x158
    unsigned char* gamma_table;             // +0x15c
    unsigned char* gamma_from_1;            // +0x160
    unsigned char* gamma_to_1;              // +0x164
    unsigned short** gamma_16_table;        // +0x168
    unsigned short** gamma_16_from_1;       // +0x16c
    unsigned short** gamma_16_to_1;         // +0x170
    PngColor8 sig_bit;                      // +0x174
    PngColor8 shift;                        // +0x179
    unsigned char* trans;                   // +0x180
    PngColor16 trans_values;                // +0x184
    void (__cdecl* read_row_fn)(PngStruct* png, unsigned int row, int pass);   // +0x190
    void* write_row_fn;                     // +0x194
    void* info_fn;                          // +0x198 (the progressive reader's callbacks: no game function)
    void* row_fn;                           // +0x19c
    void* end_fn;                           // +0x1a0
    unsigned char* save_buffer_ptr;         // +0x1a4
    unsigned char* save_buffer;             // +0x1a8
    unsigned char* current_buffer_ptr;      // +0x1ac
    unsigned char* current_buffer;          // +0x1b0
    unsigned int push_words[10];            // +0x1b4 the progressive reader's counts
    char* current_text;                     // +0x1dc
    char* current_text_ptr;                 // +0x1e0
    unsigned char* palette_lookup;          // +0x1e4
    unsigned char* dither_index;            // +0x1e8
    unsigned short* hist;                   // +0x1ec
    unsigned char heuristic_method;         // +0x1f0
    unsigned char num_prev_filters;         // +0x1f1
    unsigned char* prev_filters;            // +0x1f4
    unsigned short* filter_weights;         // +0x1f8
    unsigned short* inv_filter_weights;     // +0x1fc
    unsigned short* filter_costs;           // +0x200
    unsigned short* inv_filter_costs;       // +0x204
    char* time_buffer;                      // +0x208
    void* mem_ptr;                          // +0x20c
    PngMallocFn malloc_fn;                  // +0x210
    PngFreeFn free_fn;                      // +0x214
    unsigned char rgb_to_gray_status;       // +0x218
    unsigned char rgb_to_gray_red_coeff;    // +0x219
    unsigned char rgb_to_gray_green_coeff;  // +0x21a
    unsigned char rgb_to_gray_blue_coeff;   // +0x21b
};

// png_info (0xb8 bytes): 0x002d6ea0 creates it, 0x002d6d10 frees what it owns, the chunk handlers fill it
struct PngInfo {
    unsigned int width;                     // +0x00
    unsigned int height;                    // +0x04
    unsigned int valid;                     // +0x08 which chunks were read
    unsigned int rowbytes;                  // +0x0c
    PngColor* palette;                      // +0x10
    unsigned short num_palette;             // +0x14
    unsigned short num_trans;               // +0x16
    unsigned char bit_depth;                // +0x18
    unsigned char color_type;               // +0x19
    unsigned char compression_type;         // +0x1a
    unsigned char filter_type;              // +0x1b
    unsigned char interlace_type;           // +0x1c
    unsigned char channels;                 // +0x1d
    unsigned char pixel_depth;              // +0x1e
    unsigned char spare_byte;               // +0x1f
    unsigned char signature[8];             // +0x20
    float gamma;                            // +0x28
    unsigned char srgb_intent;              // +0x2c
    int num_text;                           // +0x30
    int max_text;                           // +0x34
    PngText* text;                          // +0x38
    PngTime mod_time;                       // +0x3c
    PngColor8 sig_bit;                      // +0x44
    unsigned char* trans;                   // +0x4c
    PngColor16 trans_values;                // +0x50
    PngColor16 background;                  // +0x5a
    int x_offset;                           // +0x64
    int y_offset;                           // +0x68
    unsigned char offset_unit_type;         // +0x6c
    unsigned int x_pixels_per_unit;         // +0x70
    unsigned int y_pixels_per_unit;         // +0x74
    unsigned char phys_unit_type;           // +0x78
    unsigned short* hist;                   // +0x7c
    float x_white, y_white, x_red, y_red, x_green, y_green, x_blue, y_blue;   // +0x80
    char* pcal_purpose;                     // +0xa0
    int pcal_X0;                            // +0xa4
    int pcal_X1;                            // +0xa8
    char* pcal_units;                       // +0xac
    char** pcal_params;                     // +0xb0
    unsigned char pcal_type;                // +0xb4
    unsigned char pcal_nparams;             // +0xb5
};

#endif
