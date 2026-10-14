// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0031a5f0 @ 0x0031a5f0
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
struct State {
 char pad0[0x20];
 float first;
 float second;
 char pad1[0x38];
 void FUN_0031a830();
};
struct Object {
 char* begin;
 char* current;
 char* end;
 unsigned int spare;
 State state;
 unsigned int arg1;
 unsigned int arg3;
 unsigned int arg2;
 unsigned int arg4;
 unsigned int flags;
 unsigned int untouched;
 unsigned int zero[7];
 Object* FUN_0031a5f0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int f);
};
Object* Object::FUN_0031a5f0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int f) {
 begin = 0; current = 0; end = 0;
 state.FUN_0031a830();
 arg1 = a; arg3 = c; arg2 = b; arg4 = d; flags = f;
 zero[0]=0; zero[1]=0; zero[2]=0; zero[3]=0; zero[4]=0; zero[5]=0; zero[6]=0;
 char* memory = (char*)FUN_0008d6d0(1000);
 begin = memory;
 if (memory) { current = memory; end = memory + 1000; }
 else { current = 0; end = 0; }
 if ((f & 6) == 2) { state.first = 1.0f; state.second = 0.0f; }
 else if ((f & 6) == 4) { state.first = 0.0f; state.second = 1.0f; }
 return this;
}
