// The game (wand1): SDL3's SDLActivity running libmain.so (tools/wasm_android.py: the wasm2c module, the runner, SDL3
// and bgfx statically; native.c's main is SDL_main). The runner reads its configuration from the environment, as the
// macOS app does; this activity sets the Android defaults before SDL loads the library, then any HULK_* / SDL_* string
// extra of the launching intent, so a scripted run passes settings with `am start --es` (SetupActivity forwards them):
//   HULK_DATA_DIR     the disc SetupActivity found (extra), else <files dir>/disc; a picked disc image or pack (extra
//                     DISC_URI, a content URI) is opened here and passed as its descriptor, "fd:N" (run/disc.h)
//   HULK_SAVE_DIR     <files dir>/save         HULK_TDATA_DIR / HULK_UDATA_DIR  <files dir>/tdata, /udata
//   HULK_APP_DIR      <files dir> (texture and model packs: <files dir>/mods; the settings file is in the save dir)
//   HULK_GFX_RENDERER vulkan (gles: bgfx's OpenGL ES; null: the headless build's run)
//   HULK_LOG_FILE     <files dir>/log.txt (stdout / stderr; also logcat, tag "hulk")
package org.thunderclap.hulkud;

import android.content.Intent;
import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;
import android.util.Log;

import java.io.File;

import org.libsdl.app.SDLActivity;

public class GameActivity extends SDLActivity {
    static final String TAG = "hulk";
    static final String DISC_URI = "org.thunderclap.hulkud.DISC_URI";
    private android.os.ParcelFileDescriptor disc;      // (kept open for the process: the runner reads its fd)

    static void setenv(String k, String v, boolean overwrite) {
        try {
            Os.setenv(k, v, overwrite);
        } catch (ErrnoException e) {
            Log.w(TAG, "setenv " + k + ": " + e);
        }
    }

    private void configure() {
        File files = getFilesDir();
        for (String d : new String[] {"save", "tdata", "udata", "mods"})
            new File(files, d).mkdirs();
        Intent in = getIntent();
        Bundle ex = in != null ? in.getExtras() : null;
        if (ex != null) {
            for (String k : ex.keySet()) {
                Object v = ex.get(k);
                if (v instanceof String && (k.startsWith("HULK_") || k.startsWith("SDL_")))
                    setenv(k, (String) v, true);
            }
        }
        String uri = ex != null && ex.get(DISC_URI) instanceof String ? (String) ex.get(DISC_URI) : null;
        if (uri != null) {
            try {
                disc = getContentResolver().openFileDescriptor(android.net.Uri.parse(uri), "r");
                setenv("HULK_DATA_DIR", "fd:" + disc.getFd(), true);
            } catch (Exception e) {
                Log.e(TAG, "the disc image " + uri + " cannot be opened: " + e);
            }
        }
        setenv("HULK_DATA_DIR", new File(files, "disc").getAbsolutePath(), false);
        setenv("HULK_SAVE_DIR", new File(files, "save").getAbsolutePath(), false);
        setenv("HULK_TDATA_DIR", new File(files, "tdata").getAbsolutePath(), false);
        setenv("HULK_UDATA_DIR", new File(files, "udata").getAbsolutePath(), false);
        setenv("HULK_APP_DIR", files.getAbsolutePath(), false);
        setenv("HULK_GFX_RENDERER", "vulkan", false);
        File ff = new File(files, "ffmpeg");    // the player's own FFmpeg (libavformat.so ...), else the APK's lib dir
        setenv("HULK_FFMPEG_DIR", new File(ff, "libavformat.so").exists() ? ff.getAbsolutePath()
               : getApplicationInfo().nativeLibraryDir, false);
        setenv("SDL_ORIENTATIONS", "LandscapeLeft LandscapeRight", false);     // (SDL's hint, read from the environment)
        setenv("HULK_LOG_FILE", new File(files, "log.txt").getAbsolutePath(), false);
        Log.i(TAG, "HULK_DATA_DIR=" + Os.getenv("HULK_DATA_DIR") + " HULK_GFX_RENDERER=" + Os.getenv("HULK_GFX_RENDERER"));
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

    // Online co-op's HTTP (wnet1; run/app/netplay_util.cpp android_http): the lobby server is https, and Android has no
    // libcurl. Called from the runner's own threads; answers "STATUS\n" + body, or "0\n" + the error.
    public static String hulkHttp(String method, String url, String body, String bearer, int timeoutMs) {
        java.net.HttpURLConnection c = null;
        try {
            c = (java.net.HttpURLConnection) new java.net.URL(url).openConnection();
            c.setConnectTimeout(timeoutMs);
            c.setReadTimeout(timeoutMs);
            c.setRequestMethod(method);
            c.setRequestProperty("Content-Type", "application/json");
            if (bearer != null && !bearer.isEmpty())
                c.setRequestProperty("Authorization", "Bearer " + bearer);
            if (!method.equals("GET") && !method.equals("DELETE")) {
                c.setDoOutput(true);
                byte[] b = body.getBytes(java.nio.charset.StandardCharsets.UTF_8);
                c.setFixedLengthStreamingMode(b.length);
                try (java.io.OutputStream o = c.getOutputStream()) {
                    o.write(b);
                }
            }
            int status = c.getResponseCode();
            java.io.InputStream in = status < 400 ? c.getInputStream() : c.getErrorStream();
            java.io.ByteArrayOutputStream out = new java.io.ByteArrayOutputStream();
            if (in != null) {
                byte[] buf = new byte[8192];
                for (int n; (n = in.read(buf)) > 0 && out.size() < (1 << 20);)
                    out.write(buf, 0, n);
                in.close();
            }
            return status + "\n" + out.toString("UTF-8");
        } catch (Exception e) {
            return "0\n" + e;
        } finally {
            if (c != null)
                c.disconnect();
        }
    }
}
