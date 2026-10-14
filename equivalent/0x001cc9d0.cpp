// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001cc9d0 @ 0x001cc9d0
extern "C" void __cdecl FUN_00267830(char* destination, const char* source, int size);
struct Entry_1cc9d0 { float time; char text[256]; int id; };
struct Manager_1cc9d0 {
 char padding[0x110];
 Entry_1cc9d0 entries[16];
 int nextId;
 int FUN_001cc9d0(float time, const char* text);
};
int Manager_1cc9d0::FUN_001cc9d0(float time, const char* text) {
 if (time < 0.0f) return -1;
 const char* end = text;
 while (*end) ++end;
 if (end-text >= 256) return -1;
 for (int i=0; i<16; ++i) {
  if (entries[i].time == -1.0f) {
   entries[i].time = time;
   FUN_00267830(entries[i].text, text, 256);
   entries[i].id = nextId;
   ++nextId;
   return entries[i].id;
  }
 }
 return -1;
}