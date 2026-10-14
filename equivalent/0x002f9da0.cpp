// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f9da0 @ 0x002f9da0
struct Block {
    int w[6];
};
struct PartA {
    char data[0x10];
    void FUN_002f9990(const PartA *src);
};
struct PartB {
    char data[0x10];
    void FUN_002f9a00(const PartB *src);
};
struct Pose {
    Block first;
    Block second;
    PartA a;
    PartB b;
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
