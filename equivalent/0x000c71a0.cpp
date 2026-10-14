// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c71a0 @ 0x000c71a0
struct Vector { unsigned int x, y, z; };
struct Handle { unsigned int low, high; };
struct Object {
 char pad[0x1b0c];
 float value;
 void FUN_000350c0(Vector* out);
};
struct Lookup { Object* FUN_00024280(unsigned int low, unsigned int high); };
struct Service {
 bool FUN_001dd7b0(Handle* handle);
 bool FUN_001dd660(Handle* handle, Vector* out);
 int FUN_001e3410(Handle* handle);
};
struct Manager { char pad0[0xc]; Service* service; char pad1[0x10]; Lookup* lookup; };
extern Manager* DAT_004dd700;
struct Entry { Vector position; Handle handle; char pad[12]; };
struct Owner { char pad[0x64]; Entry entries[1]; bool FUN_000c71a0(unsigned int index, Vector* out); };
bool Owner::FUN_000c71a0(unsigned int index, Vector* out) {
 Entry& e = entries[index];
 unsigned int low = e.handle.low, high = e.handle.high;
 Manager* manager = DAT_004dd700;
 Service* service = manager->service;
 if ((low | high) == 0) {
 out->x = e.position.x;
 out->y = e.position.y;
 out->z = e.position.z;
 return true;
 }
 Object* object = manager->lookup->FUN_00024280(low, high);
 if (object) {
 if (object->value <= 0.0f) return false;
 object->FUN_000350c0(out);
 return true;
 }
 if (!service->FUN_001dd7b0(&e.handle)) return false;
 if (!service->FUN_001dd660(&e.handle, out)) return false;
 return service->FUN_001e3410(&e.handle) > 0;
}
