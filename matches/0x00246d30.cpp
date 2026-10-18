// FUN_00246d30 @ 0x00246d30
struct LineSink {
    char pad00[0x20];
    char gotLine;         // 0x20
    char pad21[7];
    char keepNewline;     // 0x28
    bool FUN_00246cc0(const char* text, int length);
};

// Splits text on '\n', feeding each line to the sink.
bool FUN_00246d30(LineSink* sink, const char* text, int length)
{
    const char* end = text + length;
    const char* cur = text;
    const char* lineStart = text;
    while (cur < end) {
        if (*cur == '\n') {
            if (sink->keepNewline) {
                cur++;
                if (!sink->FUN_00246cc0(lineStart, cur - lineStart))
                    return false;
            } else {
                if (!sink->FUN_00246cc0(lineStart, cur - lineStart))
                    return false;
                cur++;
            }
            lineStart = cur;
            sink->gotLine = 1;
        } else {
            cur++;
        }
    }
    return sink->FUN_00246cc0(lineStart, cur - lineStart);
}
