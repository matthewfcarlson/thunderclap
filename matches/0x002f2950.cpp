struct V { char pad[8]; float value; };
extern const float Half;
float __cdecl FUN_002f2950(V* a, V* b) { return (a->value + b->value) * Half; }