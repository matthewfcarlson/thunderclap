extern void* gExtension;
extern void* pddiExtensionVtable;
void FUN_00364800() {
    gExtension = &pddiExtensionVtable;
}
