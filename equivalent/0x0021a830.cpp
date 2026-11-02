// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 7/7)
// FUN_0021a830 @ 0x0021a830
typedef void (__cdecl *WriteCallback)(void*, const void*, int, void*);
struct Writer_21a830 { void* handle; WriteCallback write; void* context; };
struct Text_21a830 { char pad[12]; int length; char bytes[1]; };
struct Entry_21a830 { Text_21a830* text; int first; int second; };
struct Table_21a830 { char pad[24]; Entry_21a830* entries; char pad2[28]; int count; };
struct Scratch_21a830 { int length; union { const char* bytes; int value; }; };
// equiv-conv: FUN_0021a830 esi stack
extern "C" void __cdecl FUN_0021a830(void * writer, void * table) {
 const int count = ((Table_21a830 *)table)->count;
 int storedCount = count;
 Scratch_21a830 scratch;
 ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, &storedCount, 4, ((Writer_21a830 *)writer)->context);
 if (count <= 0) return;
 int remaining = count;
 for (int i = 0; remaining; ++i, --remaining) {
  Text_21a830* text = ((Table_21a830 *)table)->entries[i].text;
  if (text && text->bytes) {
   scratch.bytes = text->bytes;
   const int length = text->length + 1;
   scratch.length = length;
   ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, &scratch.length, 4, ((Writer_21a830 *)writer)->context);
   ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, scratch.bytes, length, ((Writer_21a830 *)writer)->context);
  } else {
   scratch.value = 0;
   ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, &scratch.value, 4, ((Writer_21a830 *)writer)->context);
  }
  scratch.value = ((Table_21a830 *)table)->entries[i].first;
  ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, &scratch.value, 4, ((Writer_21a830 *)writer)->context);
  scratch.value = ((Table_21a830 *)table)->entries[i].second;
  ((Writer_21a830 *)writer)->write(((Writer_21a830 *)writer)->handle, &scratch.value, 4, ((Writer_21a830 *)writer)->context);
 }
}
