// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000c9390 @ 0x000c9390
struct Entry { int active; char reserved[0x2c]; int handle; char tail[4]; };
struct Worker { void FUN_001e5bc0(int); };
struct Service { char pad[12]; Worker *worker; };
extern Service *DAT_004dd700;
struct Manager { char pad[0x9d * 0x38]; Entry entries[32]; void FUN_000c9390(int unused, int index); };
void Manager::FUN_000c9390(int unused, int index) {
    if (index >= 0 && index < 32) {
        Entry *entry = &entries[index];
        if (entry->active && entry) {
            DAT_004dd700->worker->FUN_001e5bc0(entry->handle);
            entry->handle = -1;
            entry->active = 0;
        }
    }
}