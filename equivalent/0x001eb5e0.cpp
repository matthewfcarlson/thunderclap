// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001eb5e0 @ 0x001eb5e0
struct String {
 char data[8];
 void FUN_0027af00();
 void FUN_0027af30(const String&);
 void FUN_0027b040(const char*);
 void FUN_0027af50();
};
struct List {
 char data[72];
 void FUN_001ef320();
 void FUN_001ef370(const char*);
 void FUN_001ef3c0(String);
 void FUN_001ef350();
};
struct Lookup { void* FUN_00086310(); };
struct Display { void FUN_001efe20(List*, String*, unsigned int, float); };
void __cdecl FUN_001eb440(void*, List*);
struct Target {
 Display* display;
 Lookup* lookup;
 unsigned char enabled;
 void run(const String& input, unsigned int value, const char* text);
};
void Target::run(const String& input, unsigned int value, const char* text) {
 List items;
 items.FUN_001ef320();
 items.FUN_001ef370("Objects");
 items.FUN_001ef370("NIS");
 void* found = lookup->FUN_00086310();
 if (found) FUN_001eb440(found, &items);
 String copied;
 copied.FUN_0027af30(input);
 items.FUN_001ef3c0(copied);
 String label;
 label.FUN_0027af00();
 if (text && *text) label.FUN_0027b040(text);
 if (enabled) display->FUN_001efe20(&items, &label, value, 100.0f);
 label.FUN_0027af50();
 items.FUN_001ef350();
}