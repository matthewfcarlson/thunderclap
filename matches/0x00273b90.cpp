struct File;
struct Lookup_273b90 {
    File* FUN_00277cb0();
    unsigned FUN_00277cd0();
};
struct Opener {
    bool FUN_002779b0(unsigned key, Lookup_273b90* lookup);
};
struct Manager_273b90 {
    void FUN_002728a0(int);
};
struct Lock_273b90 {
    virtual void lock();
    virtual void unlock();
};
struct File {
    unsigned header;
    Lock_273b90 mutex;
    unsigned field8;
    Manager_273b90* manager;
    char pad10[4];
    unsigned status;
    char pad18[4];
    unsigned char opened;
    char pad1d[0x128 - 0x1d];
    unsigned result;
    Lookup_273b90 lookup;
    char pad12d[0x15c - 0x12d];
    unsigned field15c;
    char pad160[4];
    unsigned field164;
};
namespace core {
struct FileOpenByKeyRequest {
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    unsigned field4;
    File* file;
    unsigned key;
    Opener* opener;
};
int FileOpenByKeyRequest::vfunc_1() {
    Manager_273b90* manager = file->manager;
    if (opener->FUN_002779b0(key, &file->lookup)) {
        File* source = file->lookup.FUN_00277cb0();
        file->field15c = source->field15c;
        file->result = file->lookup.FUN_00277cd0();
        file->opened = 1;
        file->field164 = source->field164;
        file->mutex.lock();
        file->status = 0;
        file->mutex.unlock();
        return 1;
    }
    manager->FUN_002728a0(1);
    file->mutex.lock();
    file->status = 1;
    file->mutex.unlock();
    return 0;
}
} // namespace core