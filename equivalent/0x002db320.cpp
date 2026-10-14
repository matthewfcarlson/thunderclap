// STATUS: equivalent (tools/equiv.py level 3: 1603 inputs, branch coverage 69/69)
// FUN_002db320 @ 0x002db320
struct RowInfo_2db320 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

// libpng png_do_gamma
void __cdecl FUN_002db320(RowInfo_2db320 *row_info, unsigned char *row, unsigned char *gamma_table,
                          unsigned short **gamma_16_table, int gamma_shift)
{
    unsigned char *sp;
    unsigned int i;
    unsigned int row_width = row_info->width;

    if ((row_info->bit_depth <= 8 && gamma_table != 0) || (row_info->bit_depth == 16 && gamma_16_table != 0)) {
        switch (row_info->color_type) {
        case 2:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        case 6:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 4:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp += 2;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 0:
            if (row_info->bit_depth == 2) {
                sp = row;
                for (i = 0; i < row_width; i += 4) {
                    int a = *sp & 0xc0;
                    int b = *sp & 0x30;
                    int c = *sp & 0x0c;
                    int d = *sp & 0x03;
                    *sp = (unsigned char)(((int)gamma_table[a | (a >> 2) | (a >> 4) | (a >> 6)] & 0xc0) |
                                          (((int)gamma_table[(b << 2) | b | (b >> 2) | (b >> 4)] >> 2) & 0x30) |
                                          (((int)gamma_table[(c << 4) | (c << 2) | c | (c >> 2)] >> 4) & 0x0c) |
                                          ((int)gamma_table[(d << 6) | (d << 4) | (d << 2) | d] >> 6));
                    sp++;
                }
            }
            if (row_info->bit_depth == 4) {
                sp = row;
                for (i = 0; i < row_width; i += 2) {
                    int msb = *sp & 0xf0;
                    int lsb = *sp & 0x0f;
                    *sp = (unsigned char)((((int)gamma_table[msb | (msb >> 4)]) & 0xf0) |
                                          (((int)gamma_table[(lsb << 4) | lsb]) >> 4));
                    sp++;
                }
            } else if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else if (row_info->bit_depth == 16) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        }
    }
}
