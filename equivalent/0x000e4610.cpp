// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000e4610 @ 0x000e4610
struct Object { char pad[0x858]; char text[1]; void FUN_000e4610(const char *source); }; void Object::FUN_000e4610(const char *source) { char *destination = text; char c; do { c = *source++; *destination++ = c; } while (c != 0); }