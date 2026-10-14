struct StringValue_1f30e0 {
    char data[8];
    StringValue_1f30e0* FUN_0027b0e0(const char* text);
    void FUN_0027af70(StringValue_1f30e0* source);
    void FUN_0027af50();
};
struct Record_1f30e0 {
    StringValue_1f30e0 first;
    StringValue_1f30e0 second;
    StringValue_1f30e0 third;
    unsigned value;
    unsigned padding;
};
extern int DAT_004e3764;
extern Record_1f30e0 DAT_004e37b8[264];
void __stdcall FUN_001f30e0(const char* first, const char* second, const char* third, unsigned value) {
    if (DAT_004e3764 < 264) {
        StringValue_1f30e0 temporary;
        StringValue_1f30e0* source = temporary.FUN_0027b0e0(first);
        DAT_004e37b8[DAT_004e3764].first.FUN_0027af70(source);
        temporary.FUN_0027af50();
        source = temporary.FUN_0027b0e0(second);
        DAT_004e37b8[DAT_004e3764].second.FUN_0027af70(source);
        temporary.FUN_0027af50();
        source = temporary.FUN_0027b0e0(third);
        DAT_004e37b8[DAT_004e3764].third.FUN_0027af70(source);
        temporary.FUN_0027af50();
        int index = DAT_004e3764;
        DAT_004e37b8[index].value = value;
        DAT_004e3764 = index + 1;
    }
}