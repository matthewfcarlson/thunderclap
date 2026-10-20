// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001d3600 @ 0x001d3600
#include "compat/ptr.h"
struct Stream {
 virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(char*, unsigned int, int);
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual unsigned int size();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void reset(); virtual void slot22(); virtual bool valid();
};
extern void __cdecl thunk_FUN_002710d0(Stream**, const char*, int,int,int,int,int,int);
extern char* __cdecl FUN_0008d6d0(hulk_uintptr);
extern void __cdecl FUN_0008d340(void*);
struct Object {
 int unknown; int status; unsigned int context;
 int FUN_001d2810(unsigned int, char*, unsigned int, const char*);
 int target(const char* name, unsigned int unused);
};
int Object::target(const char* name, unsigned int unused) {
 const char* savedName = name;
 Stream* stream;
 thunk_FUN_002710d0(&stream, savedName,0,0,1,0,1,1);
 stream->reset();
 if (!stream->valid()) { stream->release(); return 0; }
 unsigned int length = stream->size();
 if (!length) { stream->release(); return status; }
 char* buffer = FUN_0008d6d0(length + 1);
 stream->read(buffer,length,1);
 stream->reset();
 buffer[length] = 0;
 stream->release();
 int result = FUN_001d2810(context,buffer,length,savedName);
 status = result ? 0 : 3;
 FUN_0008d340(buffer);
 return status;
}
