// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 16/16)
// FUN_00244110 @ 0x00244110
struct Context { char pad[0x24]; int depth; };
struct Handle { Context* context; };
struct NameSource { const char* FUN_0023fb00(); };
NameSource* FUN_0024c710();
bool __cdecl FUN_00246f50(Context*, const char*, ...);
struct Properties { bool FUN_0025b970(Handle*); };
struct Writer {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual bool write(Handle*);
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void begin();
};
struct Object { Handle* handle; bool FUN_00244110(Writer*, Properties*); };
bool Object::FUN_00244110(Writer* writer, Properties* properties) {
 const char* first = FUN_0024c710()->FUN_0023fb00();
 writer->begin();
 const char* second = FUN_0024c710()->FUN_0023fb00();
 bool ok = FUN_00246f50(handle->context, "BeginObject %s \"%s\"\n", second, first);
 if (ok) ++handle->context->depth;
 if (properties) {
  if (!ok) return false;
  if (!FUN_00246f50(handle->context, "Properties:\n")) return false;
  if (!properties->FUN_0025b970(handle)) return false;
 } else if (!ok) return false;
 if (!writer->write(handle)) return false;
 --handle->context->depth;
 return FUN_00246f50(handle->context, "EndObject\n\n") ? true : false;
}