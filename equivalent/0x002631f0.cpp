// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002631f0 @ 0x002631f0
// equiv-map: ??0Text@@QAE@PBDH@Z = 0x0023fc40
// equiv-map: ??1Text@@QAE@XZ = 0x00240060
// equiv-map: ??0HalRsdFileStream@audio@@QAE@ABUText@@0HHHPAHH@Z = 0x00263160

inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Text {
    char data[12];
    Text(const char *s, int flag) throw();
    ~Text() throw();
};

namespace audio {
class HalRsdFileStream {
public:
    HalRsdFileStream(const Text &name, const Text &path, int a3, int a4, int a5, int *a6, int a7) throw();
    virtual void v0();
    char body[0x44];
};
}

void *FUN_00247530(void *pool) throw();
extern char DAT_004e7b98;

audio::HalRsdFileStream *__cdecl FUN_002631f0(const char *name, const char *path, int a3, int a4, int a5, int *a6, int a7)
{
    void *mem = FUN_00247530(&DAT_004e7b98);
    if (mem == 0)
        return 0;
    return new (mem) audio::HalRsdFileStream(Text(name, 2), Text(path, 2), a3, a4, a5, a6, a7);
}
