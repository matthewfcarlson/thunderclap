// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b7860 @ 0x000b7860
class FEObject { public: virtual void o0(); };

struct LabelText {
    void FUN_000f8500(const char* text, int value, int flag);
};

class TextLabel : public FEObject {
public:
    char pad04[0x14];
    LabelText label;                  // 0x18
};

struct Journal {
    bool FUN_00092860(const void* key);
};

struct Entry {
    char pad0[0x34];
    char key[1];
};

FEObject* __cdecl FUN_000fc260(const char* name);
int __cdecl FUN_000fc1b0();

class FileLock {
public:
    char pad0[0x4c];
    Journal* journal;
    void FUN_000b7860(Entry* entry);
};

void FileLock::FUN_000b7860(Entry* entry) {
    if (!journal)
        return;
    TextLabel* text = dynamic_cast<TextLabel*>(FUN_000fc260("blonsky_file_lock_label"));
    if (!text)
        return;
    bool found = journal->FUN_00092860(entry->key);
    text->label.FUN_000f8500(found ? "" : "TBS_BLONSKY_FILE_FOUND", FUN_000fc1b0(), 1);
}
