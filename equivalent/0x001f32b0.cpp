// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f32b0 @ 0x001f32b0
struct Resource_1f32b0 { char pad[0x18]; int id; void FUN_001e8a90(); };
struct Manager_1f32b0 { char pad[0x518]; int context; };
struct State_1f32b0 { char pad[0x334]; int value; };
extern Manager_1f32b0* DAT_004e3690;
extern State_1f32b0* DAT_004e3760;
extern int DAT_004c7e3c;
extern int DAT_004e58b8;
extern int __cdecl FUN_00240750(int, int*);
extern int __cdecl FUN_0024ace0(int, int*, int, int);
extern void __cdecl FUN_00247890(int, int);
extern void __cdecl FUN_002478b0(int, float);
extern void __cdecl FUN_002478d0(int, int);
extern void __cdecl FUN_00247900(int, int);
struct Object { int unknown; int handle; Resource_1f32b0* resource; char pad[0x1c]; float mode; int initialize(Resource_1f32b0*, int, int); };
int Object::initialize(Resource_1f32b0* input, int flag, int option) {
 if (!input) return 0;
 resource = input;
 int id = input->id;
 int context = DAT_004e3690->context;
 int token = FUN_00240750(3000, &DAT_004c7e3c);
 int created = FUN_0024ace0(context, &DAT_004e58b8, id, token);
 handle = created;
 mode = (option & 255) ? 1.0f : 0.0f;
 FUN_00247890(created, DAT_004e3760->value);
 FUN_002478b0(handle, 1.0f);
 FUN_002478d0(handle, flag);
 FUN_00247900(handle, (flag & 255) ? 0 : option);
 resource->FUN_001e8a90();
 return 1;
}