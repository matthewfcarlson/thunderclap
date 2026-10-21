// STATUS: equivalent (tools/equiv.py level 3: 19896 inputs, branch coverage 4/4)
// core::FileWriteRequest::vfunc_1 @ 0x00274060
namespace core {
struct Backend_274060 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual int write(unsigned handle, char* name, unsigned mode, unsigned position, void* buffer, unsigned size, unsigned* written, unsigned* state, unsigned flags);
 unsigned FUN_00272880();
};
struct Lock_274060 { virtual void lock(); virtual void unlock(); };
struct File {
 unsigned unknown0;
 Lock_274060 lock;
 unsigned unknown8;
 Backend_274060* backend;
 unsigned unknown10;
 unsigned status;
 char padding18[6];
 char name[0x102];
 unsigned mode;
 unsigned position;
 unsigned state;
 char padding12c[0x30];
 unsigned handle;
};
struct FileWriteRequest {
 virtual void vfunc_0();
 virtual int vfunc_1();
 virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 unsigned unknown4;
 File* file;
 void* buffer;
 unsigned size;
 unsigned flags;
};
int FileWriteRequest::vfunc_1() {
 unsigned written = (unsigned)this;
 Backend_274060* backend = file->backend;
 int result = 1;
 if (size != 0) {
 result = backend->write(file->handle, file->name, file->mode, file->position, buffer, size, &written, &file->state, flags);
 if (result == 1) file->position += written;
 }
 unsigned status = backend->FUN_00272880();
 (&file->lock)->lock();
 file->status = status;
 (&file->lock)->unlock();
 return result;
}
}