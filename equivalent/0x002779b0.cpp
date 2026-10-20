// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 8/8)
// FUN_002779b0 @ 0x002779b0
struct Entry_2779b0 { unsigned int unused, value4, value8, valueC, value10; };
// equiv-conv: FUN_00277310 eax edi stack stack
Entry_2779b0* __cdecl FUN_00277310(void* table, unsigned int stride, unsigned int count, unsigned int key);
struct Info_2779b0 { char pad[0x14]; unsigned int value14, value18; };
struct Provider_2779b0 { Info_2779b0* FUN_00272bc0(); };
struct Output_2779b0 { void FUN_00277c40(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); };
struct CementLibrary_2779b0 {
 char pad0[0x18]; Provider_2779b0* provider; unsigned int value1C; unsigned int state;
 char pad24[0x21]; unsigned char mode; char pad46[0x12]; unsigned int value58; void* table; unsigned int count;
 bool FUN_002779b0(unsigned int key, Output_2779b0* output);
};
bool CementLibrary_2779b0::FUN_002779b0(unsigned int key, Output_2779b0* output) {
 if (state != 1) return false;
 unsigned int stride = mode ? 12 : 20;
 Entry_2779b0* entry = FUN_00277310(table, stride, count, key);
 if (!entry) return false;
 unsigned int extra = 0;
 unsigned int selected = entry->value8;
 if (!mode) { extra = entry->value10; selected = entry->valueC; }
 Info_2779b0* info = provider->FUN_00272bc0();
 output->FUN_00277c40(value1C, entry->value4, selected, entry->value8, extra, info->value14, info->value18, value58);
 return true;
}
