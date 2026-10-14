// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f9da0 @ 0x002f9da0
struct Block_2f9da0 {
    int w[6];
};
struct PartA_2f9da0 {
    char data[0x10];
    void FUN_002f9990(const PartA_2f9da0 *src);
};
struct PartB_2f9da0 {
    char data[0x10];
    void FUN_002f9a00(const PartB_2f9da0 *src);
};
struct Pose {
    Block_2f9da0 first;
    Block_2f9da0 second;
    PartA_2f9da0 a;
    PartB_2f9da0 b;
    Pose *FUN_002f9da0(const Pose *src);
};

Pose *Pose::FUN_002f9da0(const Pose *src)
{
    first = src->first;
    second = src->second;
    a.FUN_002f9990(&src->a);
    b.FUN_002f9a00(&src->b);
    return this;
}
