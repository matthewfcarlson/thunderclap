// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00292330 @ 0x00292330
struct Settings_292330 {
    unsigned width;
    unsigned height;
    unsigned depth;
    unsigned mode;
    unsigned format;
    unsigned primaryCapacity;
    unsigned secondaryCapacity;
    unsigned tertiaryCapacity;
    unsigned count;
    unsigned flags;
    unsigned reserved;
    unsigned char option0;
    unsigned char option1;
    unsigned char option2;
    unsigned char option3;
    unsigned char option4;
    void FUN_00292330();
};
void Settings_292330::FUN_00292330() {
    width = 640;
    height = 480;
    depth = 32;
    format = 7;
    mode = 2;
    flags = 17;
    reserved = 0;
    option0 = 0;
    option1 = 1;
    option2 = 0;
    primaryCapacity = 0x80000;
    secondaryCapacity = 0x8000;
    tertiaryCapacity = 0x4000;
    count = 8;
    option3 = 0;
    option4 = 0;
}
