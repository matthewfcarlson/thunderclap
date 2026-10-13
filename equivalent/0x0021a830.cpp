// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 7/8, incomplete)
// FUN_0021a830 @ 0x0021a830
typedef void (__cdecl *WriteCallback)(void*, const void*, int, void*);
struct Writer { void* handle; WriteCallback write; void* context; };
struct Text { char pad[12]; int length; char bytes[1]; };
struct Entry { Text* text; int first; int second; };
struct Table { char pad[24]; Entry* entries; char pad2[28]; int count; };
struct Scratch { int length; union { const char* bytes; int value; }; };
// equiv-conv: FUN_0021a830 esi stack
void __cdecl FUN_0021a830(Writer* writer, Table* table) {
 const int count = table->count;
 int storedCount = count;
 Scratch scratch;
 writer->write(writer->handle, &storedCount, 4, writer->context);
 if (count <= 0) return;
 int remaining = count;
 for (int i = 0; remaining; ++i, --remaining) {
  Text* text = table->entries[i].text;
  if (text && text->bytes) {
   scratch.bytes = text->bytes;
   const int length = text->length + 1;
   scratch.length = length;
   writer->write(writer->handle, &scratch.length, 4, writer->context);
   writer->write(writer->handle, scratch.bytes, length, writer->context);
  } else {
   scratch.value = 0;
   writer->write(writer->handle, &scratch.value, 4, writer->context);
  }
  scratch.value = table->entries[i].first;
  writer->write(writer->handle, &scratch.value, 4, writer->context);
  scratch.value = table->entries[i].second;
  writer->write(writer->handle, &scratch.value, 4, writer->context);
 }
}
