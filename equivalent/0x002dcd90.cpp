// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 70/70)
// FUN_002dcd90 @ 0x002dcd90
extern "C" int sprintf(char *, const char *, ...);

struct png_struct;
typedef unsigned char png_byte;

struct png_row_info {
    unsigned int width;
    unsigned int rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
};

struct png_color_16 {
    unsigned short v[5];
};

struct png_struct {
    char pad000[0x54];
    void (__cdecl *read_user_transform_fn)(png_struct *, png_row_info *, png_byte *);
    char pad058[0x64 - 0x58];
    unsigned int flags;
    unsigned int transformations;
    char pad06c[0xdc - 0x6c];
    unsigned long row_number;
    char pade0[4];
    png_byte *row_buf;
    char pade8[0xf8 - 0xe8];
    png_row_info row_info;
    char pad104[0x10c - 0x104];
    void *palette;
    char pad110[2];
    unsigned short num_trans;
    char pad114[0x11c - 0x114];
    png_byte pass;
    png_byte pad11d;
    png_byte color_type;
    char pad11f[0x126 - 0x11f];
    unsigned short filler;
    char pad128[0x130 - 0x128];
    png_color_16 background;
    png_color_16 background_1;
    char pad144[0x150 - 0x144];
    int gamma_shift;
    char pad154[0x15c - 0x154];
    void *gamma_table;
    void *gamma_from_1;
    void *gamma_to_1;
    void *gamma_16_table;
    void *gamma_16_from_1;
    void *gamma_16_to_1;
    char pad174[0x179 - 0x174];
    png_byte shift[5];
    char pad17e[0x180 - 0x17e];
    void *trans;
    png_color_16 trans_values;
    char pad18e[0x1e4 - 0x18e];
    void *palette_lookup;
    void *dither_index;
    char pad1ec[0x218 - 0x1ec];
    png_byte rgb_to_gray_status;
};

void __cdecl FUN_002e69a0(png_struct *p, const char *msg);
void __cdecl FUN_002e69d0(png_struct *p, const char *msg);
void __cdecl FUN_002db6b0(png_row_info *ri, png_byte *row, void *palette, void *trans, int num_trans);
void __cdecl FUN_002db8d0(png_row_info *ri, png_byte *row, png_color_16 *trans_values);
void __cdecl FUN_002dd3a0(png_row_info *ri, png_byte *row, int flags);
int __cdecl FUN_002d9c30(png_struct *p, png_row_info *ri, png_byte *row);
void __cdecl FUN_002d9ae0(png_row_info *ri, png_byte *row);
void __cdecl FUN_002da380(png_row_info *ri, png_byte *row, png_color_16 *trans_values, png_color_16 *background, png_color_16 *background_1, void *gamma_table, void *gamma_from_1, void *gamma_to_1, void *gamma_16_table, void *gamma_16_from_1, void *gamma_16_to_1, int gamma_shift);
void __cdecl FUN_002db320(png_row_info *ri, png_byte *row, void *gamma_table, void *gamma_16_table, int gamma_shift);
void __cdecl FUN_002d95c0(png_row_info *ri, png_byte *row);
void __cdecl FUN_002dbc50(png_row_info *ri, png_byte *row, void *palette_lookup, void *dither_index);
void __cdecl FUN_002dd2e0(png_row_info *ri, png_byte *row);
void __cdecl FUN_002d93f0(png_row_info *ri, png_byte *row, png_byte *shift);
void __cdecl FUN_002d92c0(png_row_info *ri, png_byte *row);
void __cdecl FUN_002dd5c0(png_row_info *ri, png_byte *row);
void __cdecl FUN_002dd350(png_row_info *ri, png_byte *row);
void __cdecl FUN_002d9840(png_row_info *ri, png_byte *row, unsigned int filler, unsigned int flags);
void __cdecl FUN_002d9720(png_row_info *ri, png_byte *row);
void __cdecl FUN_002d9610(png_row_info *ri, png_byte *row);
void __cdecl FUN_002dd310(png_row_info *ri, png_byte *row);

void __cdecl FUN_002dcd90(png_struct *png_ptr)
{
    if (png_ptr->row_buf == 0) {
        char msg[50];
        sprintf(msg, "NULL row buffer for row %ld, pass %d", png_ptr->row_number, png_ptr->pass);
        FUN_002e69a0(png_ptr, msg);
    }
    if (png_ptr->transformations & 0x1000) {
        if (png_ptr->row_info.color_type == 3) {
            FUN_002db6b0(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->palette, png_ptr->trans, png_ptr->num_trans);
        } else if (png_ptr->num_trans != 0) {
            FUN_002db8d0(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->trans_values);
        } else {
            FUN_002db8d0(&png_ptr->row_info, png_ptr->row_buf + 1, 0);
        }
    }
    if (png_ptr->transformations & 0x40000)
        FUN_002dd3a0(&png_ptr->row_info, png_ptr->row_buf + 1, 0x80);
    if (png_ptr->transformations & 0x600000) {
        if (FUN_002d9c30(png_ptr, &png_ptr->row_info, png_ptr->row_buf + 1)) {
            png_ptr->rgb_to_gray_status = 1;
            if (png_ptr->transformations == 0x400000)
                FUN_002e69d0(png_ptr, "png_do_rgb_to_gray found nongray pixel");
            if (png_ptr->transformations == 0x200000)
                FUN_002e69a0(png_ptr, "png_do_rgb_to_gray found nongray pixel");
        }
    }
    if ((png_ptr->transformations & 0x4000) && !(png_ptr->flags & 0x20000))
        FUN_002d9ae0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if ((png_ptr->transformations & 0x80) && (png_ptr->num_trans != 0 || (png_ptr->color_type & 4)))
        FUN_002da380(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->trans_values, &png_ptr->background, &png_ptr->background_1, png_ptr->gamma_table, png_ptr->gamma_from_1, png_ptr->gamma_to_1, png_ptr->gamma_16_table, png_ptr->gamma_16_from_1, png_ptr->gamma_16_to_1, png_ptr->gamma_shift);
    if ((png_ptr->transformations & 0x2000)
        && !((png_ptr->transformations & 0x80) && (png_ptr->num_trans != 0 || (png_ptr->color_type & 4)))
        && png_ptr->color_type != 3)
        FUN_002db320(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->gamma_table, png_ptr->gamma_16_table, png_ptr->gamma_shift);
    if (png_ptr->transformations & 0x400)
        FUN_002d95c0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x40) {
        FUN_002dbc50(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->palette_lookup, png_ptr->dither_index);
        if (png_ptr->row_info.rowbytes == 0)
            FUN_002e69a0(png_ptr, "png_do_dither returned rowbytes=0");
    }
    if (png_ptr->transformations & 0x20)
        FUN_002dd2e0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8)
        FUN_002d93f0(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->shift);
    if (png_ptr->transformations & 0x4)
        FUN_002d92c0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x1)
        FUN_002dd5c0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x10000)
        FUN_002dd350(&png_ptr->row_info, png_ptr->row_buf + 1);
    if ((png_ptr->transformations & 0x4000) && (png_ptr->flags & 0x20000))
        FUN_002d9ae0(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8000)
        FUN_002d9840(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->filler, png_ptr->flags);
    if (png_ptr->transformations & 0x80000)
        FUN_002d9720(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x20000)
        FUN_002d9610(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x10)
        FUN_002dd310(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x100000) {
        if (png_ptr->read_user_transform_fn != 0)
            png_ptr->read_user_transform_fn(png_ptr, &png_ptr->row_info, png_ptr->row_buf + 1);
    }
}
