// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 21/22, incomplete)
// FUN_00211745 @ 0x00211745
namespace XAPILIB {
void __stdcall SetLastError(unsigned int code);
}
namespace xboxkrnl {
void __stdcall XcSHAInit(void* ctx);
void __stdcall XcSHAUpdate(void* ctx, const void* data, unsigned int len);
void __stdcall XcSHAFinal(void* ctx, void* digest);
}

struct ImageInfo {
    char pad00[8];
    void* field8;
};
extern ImageInfo* DAT_00010118;

struct SectionHeader {
    char pad00[0x20];
    unsigned char flags;
    char pad21[0x2f];
    unsigned int f50;
    unsigned int size;
    unsigned int digest[5];
    char pad6c[0x88 - 0x6c];
};

struct Control {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
};

struct Section {
    unsigned int magic;
    char* start;
    char* end;
    char* data;
    char* table;
    unsigned int f14;
    char pad18[0x10];
    unsigned int f28;
};

struct Frame {
    char sha[0x74];
    SectionHeader header;
    unsigned int digest[5];
    Control ctl;
};

unsigned int __stdcall FUN_002109f1(unsigned int name, unsigned int access, unsigned int share, unsigned int a3,
                                    unsigned int disposition, unsigned int flags, unsigned int tmpl);
int __stdcall FUN_00210fbf(unsigned int file, void* a0, int one, SectionHeader* out);
int __stdcall FUN_002110a0(unsigned int file, SectionHeader* header, Section* section);
int __stdcall FUN_0020ff8d(unsigned int file, char* buffer, unsigned int size, unsigned int* got, Control* ctl);
int __stdcall FUN_0020bbc2(unsigned int file);
Section* __stdcall FUN_0020a2b5(unsigned int size, unsigned int tag);
void __stdcall FUN_0020a355(void* p, unsigned int tag);

Section* __stdcall FUN_00211745(void* a0, unsigned int a1)
{
    Frame f;
    Section* sec = 0;
    bool closed = false;

    unsigned int file = FUN_002109f1(a1, 0x80000000, 1, 0, 3, 0, 0);
    if (file == 0xffffffff)
        return 0;

    void* arg = a0;
    if (arg == 0)
        arg = DAT_00010118->field8;

    if (FUN_00210fbf(file, arg, 1, &f.header)) {
        if ((f.header.flags & 1) && f.header.size != 0) {
            sec = FUN_0020a2b5(f.header.size + 0x98, 0x24830000);
            if (sec == 0) {
                XAPILIB::SetLastError(8);
            } else {
                sec->table = (char*)sec + 0x28;
                sec->f28 = 0;
                sec->f14 = 0;
                sec->data = sec->table + 0x70;
                if (FUN_002110a0(file, &f.header, sec)) {
                    f.ctl.f0 = 0;
                    f.ctl.f4 = 0;
                    f.ctl.f8 = 0;
                    f.ctl.fc = 0;
                    f.ctl.f10 = 0;
                    f.ctl.f8 = f.header.f50;
                    if (FUN_0020ff8d(file, sec->data, f.header.size, &a1, &f.ctl) && f.header.size == a1) {
                        char* base = sec->data;
                        sec->start = base + *(unsigned int*)(base + 8);
                        sec->end = base + *(unsigned int*)(base + 8);
                        FUN_0020bbc2(file);
                        closed = true;
                        xboxkrnl::XcSHAInit(f.sha);
                        xboxkrnl::XcSHAUpdate(f.sha, sec->data, f.header.size);
                        xboxkrnl::XcSHAFinal(f.sha, f.digest);
                        bool same = true;
                        for (int i = 0; i < 5 && same; i++)
                            same = (f.digest[i] == f.header.digest[i]);
                        if (same) {
                            sec->magic = 0x66736378;
                            return sec;
                        }
                    }
                }
            }
        } else {
            XAPILIB::SetLastError(2);
        }
    }
    if (!closed)
        FUN_0020bbc2(file);
    if (sec)
        FUN_0020a355(sec, 0x24830000);
    return 0;
}
