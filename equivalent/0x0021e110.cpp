// STATUS: equivalent (tools/equiv.py level 3: 11558 inputs, branch coverage 12/12)
// FUN_0021e110 @ 0x0021e110
// FUN_0021e110 @ 0x0021e110
struct Resource { char pad[0x24]; int replacement; };
struct Owner { char pad[0x1c]; Resource* resource; };
struct Entry { Entry* next; int type; int first; int second; };
struct Source { int unused; int value; };
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00220850(void *, int);
// equiv-conv: FUN_0021e110 ecx eax edi
extern "C" void FUN_0021e110(void * owner, void * entry_, void * source)
{
    Entry * entry = (Entry *)entry_;
    Resource* resource = ((Owner *)owner)->resource;
    int replacement = resource->replacement;
    bool changed = false;
    for (; entry; entry = entry->next) {
        if (entry->type == 8) {
            if (entry->first == ((Source *)source)->value) {
                changed = true;
                entry->first = replacement;
            }
            if (entry->second == ((Source *)source)->value) {
                changed = true;
                entry->second = replacement;
            }
        }
    }
    if (changed) {
        FUN_00220bd0((Resource *)resource, 0, resource->replacement, (int)(((Source *)source)->value), 0);
        FUN_00220850((Resource *)resource, 1);
    }
}
