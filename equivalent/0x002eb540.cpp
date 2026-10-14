// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002eb540 @ 0x002eb540
// libpng png_set_sRGB_gAMA_and_cHRM
struct png_struct;
struct png_info;

void __cdecl FUN_002eb520(png_struct *png_ptr, png_info *info_ptr, int intent);                  // png_set_sRGB
void __cdecl FUN_002eb1f0(png_struct *png_ptr, png_info *info_ptr, double file_gamma);           // png_set_gAMA
void __cdecl FUN_002eb180(png_struct *png_ptr, png_info *info_ptr,
                          double white_x, double white_y, double red_x, double red_y,
                          double green_x, double green_y, double blue_x, double blue_y);          // png_set_cHRM

void __cdecl FUN_002eb540(png_struct *png_ptr, png_info *info_ptr, int intent)
{
    if (png_ptr == 0 || info_ptr == 0)
        return;

    FUN_002eb520(png_ptr, info_ptr, intent);
    FUN_002eb1f0(png_ptr, info_ptr, 0.45f);
    FUN_002eb180(png_ptr, info_ptr, 0.3127f, 0.329f, 0.64f, 0.33f, 0.3f, 0.6f, 0.15f, 0.06f);
}
