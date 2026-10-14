// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00263160 @ 0x00263160
struct Text {
    char data[12];
    void FUN_00240170(const char *s);
    void FUN_0023fac0();
    void FUN_00240190(const char *s);
};

namespace audio {
class HalRsdFileStream {
public:
    HalRsdFileStream(const char *name, const char *path, int a3, int a4, int a5, int *a6, int a7);
    virtual void v0();
    Text name;
    Text path;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    unsigned char hasF28;
    char pad41[3];
    int f44;
};

HalRsdFileStream::HalRsdFileStream(const char *nameArg, const char *pathArg, int a3, int a4, int a5, int *a6, int a7)
{
    name.FUN_00240170(nameArg);
    path.FUN_0023fac0();
    f1c = a7;
    f30 = a3;
    f38 = a5;
    f44 = 0;
    f34 = a4;
    f3c = 0;
    f20 = 0;
    f2c = 0;
    f24 = 0;
    if (a6 == 0) {
        hasF28 = 0;
    } else {
        hasF28 = 1;
        f28 = *a6;
    }
    path.FUN_00240190(pathArg);
}
}
