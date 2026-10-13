// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001d17f0 @ 0x001d17f0
extern "C" {
int __cdecl FUN_00213290(void*, int);
void __cdecl FUN_00213380(void*, const char*, int);
void __cdecl FUN_00213600(void*, int);
void __cdecl FUN_002133d0(void*, const char*);
void __cdecl FUN_00212ed0(void*, int);
void __cdecl FUN_002139f0(void*, int, int, int);
const char* __cdecl FUN_00213190(void*, int);
void __cdecl FUN_00212d80(void*, int);
}
struct Object {
char padding[8];
void* state;
int status(void* context);
};
int Object::status(void* context) {
if (!FUN_00213290(state, -1)) return 0;
FUN_00213380(context, "coroutine", 9);
FUN_00213600(context, -10001);
FUN_002133d0(context, "status");
FUN_00213600(context, -2);
FUN_00212ed0(context, -3);
FUN_002139f0(context, 1, 1, 0);
const char* text = FUN_00213190(context, -1);
FUN_00212d80(context, -3);
const char* names[3] = {"dead", "running", "suspended"};
const int lengths[3] = {5, 8, 10};
const int results[3] = {3, 1, 2};
for (int n=0; n<3; ++n) {
int i=0;
while (i<lengths[n] && text[i]==names[n][i]) ++i;
if (i==lengths[n]) return results[n];
}
return 0;
}
