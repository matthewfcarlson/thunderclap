/* The Android app's stdout / stderr (wand1; tools/wasm_android.py): an app process has no terminal, so a constructor
 * sends both through a pipe to logcat (tag "hulk"), and to HULK_LOG_FILE as well when the activity sets it (the
 * runner's and the module's messages: start-up, traps, the replay's summary lines). */
#include <android/log.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int s_pipe[2] = {-1, -1};
static int s_file = -1;

static void* pump(void* arg)
{
    (void)arg;
    char buf[4096], line[4096];
    size_t n = 0;
    ssize_t r;
    while ((r = read(s_pipe[0], buf, sizeof buf)) > 0) {
        if (s_file >= 0)
            write(s_file, buf, (size_t)r);
        for (ssize_t i = 0; i < r; i++) {
            if (buf[i] == '\n' || n == sizeof line - 1) {
                line[n] = 0;
                __android_log_write(ANDROID_LOG_INFO, "hulk", line);
                n = 0;
                if (buf[i] == '\n')
                    continue;
            }
            line[n++] = buf[i];
        }
    }
    return 0;
}

__attribute__((constructor)) static void hulk_android_log(void)
{
    const char* f = getenv("HULK_LOG_FILE");
    if (f && *f)
        s_file = open(f, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (pipe(s_pipe))
        return;
    setvbuf(stdout, 0, _IOLBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);
    dup2(s_pipe[1], 1);
    dup2(s_pipe[1], 2);
    pthread_t t;
    if (!pthread_create(&t, 0, pump, 0))
        pthread_detach(t);
}
