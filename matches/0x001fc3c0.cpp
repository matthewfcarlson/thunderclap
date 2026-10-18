// FUN_001fc3c0 @ 0x001fc3c0
struct Name_1fc3c0 {
    int word;
    void FUN_0027b040(const char *name);
};

class XmlNode {
public:
    char pad0[0xc];
    const char *name;       // 0xc
    unsigned char FUN_00336600(const char *key, float *a, float *b, float *c);
};

void __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class Transform_1fc3c0 {
public:
    char pad0[8];
    Name_1fc3c0 name;              // 8
    char padc[4];
    float tx;               // 0x10
    float ty;               // 0x14
    float tz;               // 0x18
    float rotation;         // 0x1c
    char label[0x20];       // 0x20
    void FUN_001fc3c0(XmlNode *node);
};

void Transform_1fc3c0::FUN_001fc3c0(XmlNode *node)
{
    const char *nodeName = node->name;
    FUN_000964a0(label, 0x20, "%s", nodeName);
    name.FUN_0027b040(nodeName);

    float x, y, z;
    if (node->FUN_00336600("translate", &x, &y, &z)) {
        tx = x;
        ty = y;
        tz = -z;
    }
    if (node->FUN_00336600("rotate", &x, &y, &z) == 1)
        rotation = y * -0.01745329238474369f;
}
