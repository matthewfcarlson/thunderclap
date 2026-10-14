// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 15/16, incomplete)
// FUN_0021aa00 @ 0x0021aa00
struct Writer_21aa00 { void* context; void (__cdecl *write)(void*, const void*, int, void*); void* extra; };
struct Text_21aa00 { char pad[12]; int length; char data[1]; };
struct Entry_21aa00 { int type; union { int value; Text_21aa00* text; }; };
struct Object { char pad0[8]; Entry_21aa00* entries; char padC[4]; void** children; char pad14[12]; void* auxiliary; char pad24[4]; int entryCount; char pad2C[8]; int childCount; };
void __cdecl FUN_0021ab30(void*, void*, Writer_21aa00*);
// equiv-conv: FUN_0021aa00 esi stack
void __cdecl FUN_0021aa00(Writer_21aa00* writer, Object* object) {
 int count = object->entryCount;
 int output = count;
 writer->write(writer->context, &output, 4, writer->extra);
 for (int i=0; i<count; ++i) {
  Entry_21aa00* entry = &object->entries[i];
  output = (output & ~255) | (entry->type & 255);
  writer->write(writer->context, &output, 1, writer->extra);
  if (entry->type == 3) {
   int value = entry->value;
   writer->write(writer->context, &value, 4, writer->extra);
  } else if (entry->type == 4) {
   Text_21aa00* text = entry->text;
   if (text && text->data) {
    char* data = text->data;
    int length = text->length + 1;
    output = length;
    writer->write(writer->context, &output, 4, writer->extra);
    writer->write(writer->context, data, length, writer->extra);
   } else {
    output = 0;
    writer->write(writer->context, &output, 4, writer->extra);
   }
  }
 }
 int children = object->childCount;
 output = children;
 writer->write(writer->context, &output, 4, writer->extra);
 for (int j=0; j<children; ++j) FUN_0021ab30(object->children[j], object->auxiliary, writer);
}
