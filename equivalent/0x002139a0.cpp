// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_002139a0 @ 0x002139a0
struct Record { char pad[8]; char *end; };
void __cdecl FUN_002159e0(Record *record, char *position, int nresults);
void __cdecl FUN_002139a0(Record *record, int index, int nresults) {
    FUN_002159e0(record, record->end - (index * 8 + 8), nresults);
}