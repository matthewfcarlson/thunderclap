extern "C" __int64 getValue(const char*);
extern "C" __int64 globalValue;
void FUN_0035d930() {
    globalValue = getValue("load");
}