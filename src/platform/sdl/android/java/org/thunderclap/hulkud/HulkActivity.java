// The APK's activity (docs/native-android.md "Running the image"): SDL3's SDLActivity with the game's libmain.so,
// which carries SDL3 statically (tools/native_android_sdl.py --config app), so only "main" is loaded.
//
// The native side reads its configuration from the environment, as on the other targets (HULK_DATA_DIR,
// HULK_SAVE_DIR, HULK_TRACE_FILE, ...). Before SDL loads the library this activity sets the defaults for the app's own
// directories and then any HULK_* / SDL_* string extra of the launching intent, so a scripted run passes them with
// `am start -n org.thunderclap.hulkud/.HulkActivity --es HULK_TRACE_FILE ...`:
//   HULK_DATA_DIR   <files dir>/data if it holds default.xbe, else <external files dir>/data (the player's extracted
//                   disc, copied there by the player; never in the APK)
//   HULK_SAVE_DIR   <files dir>/save            HULK_TDATA_DIR / HULK_UDATA_DIR  <files dir>/tdata, /udata
//   HULK_TRACE_FILE <files dir>/trace.txt
package org.thunderclap.hulkud;

import android.content.Intent;
import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;
import android.util.Log;

import java.io.File;

import org.libsdl.app.SDLActivity;

public class HulkActivity extends SDLActivity {
    private static final String TAG = "hulk";

    private static void setenv(String k, String v, boolean overwrite) {
        try {
            Os.setenv(k, v, overwrite);
        } catch (ErrnoException e) {
            Log.w(TAG, "setenv " + k + ": " + e);
        }
    }

    private void configure() {
        File files = getFilesDir();
        File ext = getExternalFilesDir(null);
        // the internal one when it holds the disc (a scripted install through `run-as`: files that adb's shell writes
        // into the external dir belong to the shell, and the app cannot read them), else the external one
        File in_ = new File(files, "data");
        String data = (new File(in_, "default.xbe").exists() || ext == null ? in_ : new File(ext, "data")).getAbsolutePath();
        for (String d : new String[] {"save", "tdata", "udata"})
            new File(files, d).mkdirs();
        setenv("HULK_DATA_DIR", data, false);
        setenv("HULK_SAVE_DIR", new File(files, "save").getAbsolutePath(), false);
        setenv("HULK_TDATA_DIR", new File(files, "tdata").getAbsolutePath(), false);
        setenv("HULK_UDATA_DIR", new File(files, "udata").getAbsolutePath(), false);
        setenv("HULK_TRACE_FILE", new File(files, "trace.txt").getAbsolutePath(), false);
        Intent in = getIntent();
        Bundle ex = in != null ? in.getExtras() : null;
        if (ex != null) {
            for (String k : ex.keySet()) {
                Object v = ex.get(k);
                if (v instanceof String && (k.startsWith("HULK_") || k.startsWith("SDL_")))
                    setenv(k, (String) v, true);
            }
        }
        Log.i(TAG, "HULK_DATA_DIR=" + Os.getenv("HULK_DATA_DIR") + " HULK_TRACE_FILE=" + Os.getenv("HULK_TRACE_FILE"));
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        configure();
        super.onCreate(savedInstanceState);
    }

    @Override
    protected String[] getLibraries() {
        return new String[] {"main"};
    }
}
