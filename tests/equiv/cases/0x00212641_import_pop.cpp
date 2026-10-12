struct AnsiString {
    unsigned short length;
    unsigned short maxLength;
    char *buffer;
};
struct ObjectAttributes {
    void *rootDirectory;
    AnsiString *objectName;
    unsigned int attributes;
};
struct IoStatusBlock {
    int status;
    int information;
};
struct DirInfo {
    char pad0[0x28];
    unsigned int endOfFileLow;
    int endOfFileHigh;
    char pad30[8];
    unsigned int attributes;
    unsigned int nameLength;
    char name[1];
};
struct Frame {
    ObjectAttributes attr;
    IoStatusBlock iosb;
    AnsiString ansi;
    unsigned char restart;
    unsigned int count;
    int padFrame; /* original keeps saved ebp above its locals */
};

extern int (__stdcall *DAT_003f2d9c)(void *handle, void *event, void *apc, void *ctx, IoStatusBlock *iosb,
                                      void *info, unsigned int length, int infoClass, void *fileName,
                                      unsigned int restart);
extern void (__stdcall *DAT_003f2bec)(AnsiString *dest, const char *src);
extern int (__stdcall *DAT_003f2be8)(void **handle, unsigned int access, ObjectAttributes *attr,
                                      IoStatusBlock *iosb, unsigned int share, unsigned int options);
extern int (__stdcall *DAT_003f2be0)(void *handle);

int __stdcall FUN_00212641(void *dir, unsigned int *clusters, DirInfo *info)
{
    Frame f;
    int status;
    unsigned int *total = clusters;

    f.restart = 1;
    f.count = 0;
    for (;;) {
        status = DAT_003f2d9c(dir, 0, 0, 0, &f.iosb, info, 0x146, 1, 0, *(unsigned int *)&f.restart);
        f.restart = 0;
        if (status < 0)
            break;
        f.count++;
        if (info->attributes & 0x10) {
            info->name[info->nameLength] = 0;
            DAT_003f2bec(&f.ansi, info->name);
            f.attr.rootDirectory = dir;
            f.attr.objectName = &f.ansi;
            f.attr.attributes = 0x40;
            status = DAT_003f2be8((void **)&clusters, 0x100001, &f.attr, &f.iosb, 3, 0x4021);
            if (status >= 0) {
                status = FUN_00212641((void *)clusters, total, info);
                DAT_003f2be0((void *)clusters);
            }
        } else {
            if (info->endOfFileHigh != 0) {
                *total = 50001;
                break;
            }
            unsigned int size = info->endOfFileLow;
            unsigned int need = ((size & 0x3fff) != 0) + (size >> 14);
            if (need < 50001)
                *total += need;
        }
        if (*total >= 50001) {
            *total = 50001;
            break;
        }
        if (status < 0)
            break;
    }
    unsigned int blocks = f.count ? f.count << 6 : 1;
    *total += ((blocks & 0x3fff) != 0) + (blocks >> 14);
    if (*total >= 50001)
        *total = 50001;
    if (status == 0x80000006 || status == 0xc000000f)
        status = 0;
    return status;
}
