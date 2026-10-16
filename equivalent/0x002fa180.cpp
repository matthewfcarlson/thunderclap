// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa180 @ 0x002fa180
struct BoundsData {
    char reserved[24];
    unsigned int lower[3];
    unsigned int upper[3];
    unsigned int first[3];
    unsigned int gap;
    unsigned int second[3];
};
struct Transform {
    void FUN_002fa080(unsigned int, BoundsData *);
    void FUN_002fa180(unsigned int value);
};
void Transform::FUN_002fa180(unsigned int value)
{
    BoundsData bounds;
    bounds.lower[0] = 0x5368d4a5;
    bounds.lower[1] = 0x5368d4a5;
    bounds.lower[2] = 0x5368d4a5;
    bounds.upper[0] = 0xd368d4a5;
    bounds.upper[1] = 0xd368d4a5;
    bounds.upper[2] = 0xd368d4a5;
    bounds.first[0] = 0;
    bounds.first[1] = 0;
    bounds.first[2] = 0;
    bounds.second[0] = 0;
    bounds.second[1] = 0;
    bounds.second[2] = 0;
    FUN_002fa080(value, &bounds);
}