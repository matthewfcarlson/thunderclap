extern "C" int g_filter;

int __stdcall SetFilter(int value) {
    int old = g_filter;
    g_filter = value;
    return old;
}
