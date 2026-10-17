struct Palette {
    char pad[0xd30];
    unsigned int colors[4];
    unsigned int* FUN_00025930(unsigned int* out, int index);
};
unsigned int* Palette::FUN_00025930(unsigned int* out, int index) {
    if (index >= 0 && index < 4)
        *out = colors[index];
    else
        *out = 0xffff00ff;
    return out;
}