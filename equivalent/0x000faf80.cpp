// STATUS: equivalent (tools/equiv.py level 3: 16169 inputs, branch coverage 27/27)
// FUN_000faf80 @ 0x000faf80
// cl-flags: /GS

extern "C" unsigned char DAT_004e09f8[4];
extern "C" unsigned char DAT_004e09fc[4];
struct Item_faf80 {
    char pad0[4];
    Item_faf80 *next;
    void FUN_000f9b40(Item_faf80 *other);
};

class Script_faf80;
struct TokState {
    char *tok;
    Script_faf80 *owner;
};

struct Head_faf80 {
    Item_faf80 *first;
    Item_faf80 *last;
};

class Lines {
public:
    bool FUN_000f99d0(char *out);
    char pad0[0x10];
    int mark10;
    char pad14[4];
    int mark18;
};

class Script_faf80 {
public:
    Head_faf80 *head;
    Item_faf80 *FUN_000fa5a0(TokState *state, char *line, int index, int lineNo, char *copy);
    bool FUN_000faa40(Item_faf80 *it);
    Head_faf80 *FUN_000faf80(Lines *lines);
};

void *__cdecl FUN_0008d690(unsigned int size);
char *__cdecl FUN_003465c6(char *s, const char *delims);

struct Frame_faf80 {
    int lineNo;
    TokState ts;
    char line[0x100];
    char copy[0x100];
};

Head_faf80 *Script_faf80::FUN_000faf80(Lines *lines)
{
    Frame_faf80 f;
    f.ts.owner = this;
    lines->mark18 = lines->mark10;
    Head_faf80 *h = (Head_faf80 *)FUN_0008d690(8);
    if (h) {
        h->first = 0;
        h->last = 0;
    }
    head = h;
    f.lineNo = 1;
    bool ok = lines->FUN_000f99d0(f.line);
    {
        int i = 0;
        char c;
        do {
            c = f.line[i];
            f.copy[i] = c;
            i++;
        } while (c);
    }
    if (ok) {
        do {
            int index = 1;
            f.ts.tok = FUN_003465c6(f.line, " \t\n\r");
            while (f.ts.tok) {
                Item_faf80 *it = FUN_000fa5a0(&f.ts, f.line, index, f.lineNo, f.copy);
                if (!it)
                    break;
                if (!FUN_000faa40(it)) {
                    if (!(*(unsigned char*)DAT_004e09fc & 1)) {
                        *(unsigned*)DAT_004e09fc |= 1;
                        *(Item_faf80**)DAT_004e09f8 = it;
                    }
                    Item_faf80 *&last = *(Item_faf80**)DAT_004e09f8;
                    Head_faf80 *hd = head;
                    if (hd->first == 0) {
                        hd->first = it;
                    } else if (last != it) {
                        if (last->next)
                            last->next->FUN_000f9b40(it);
                        else
                            last->next = it;
                    }
                    last = it;
                }
                index++;
            }
            ok = lines->FUN_000f99d0(f.line);
            {
                int i = 0;
                char c;
                do {
                    c = f.line[i];
                    f.copy[i] = c;
                    i++;
                } while (c);
            }
            f.lineNo++;
        } while (ok);
    }
    Head_faf80 *result = head;
    return result;
}
