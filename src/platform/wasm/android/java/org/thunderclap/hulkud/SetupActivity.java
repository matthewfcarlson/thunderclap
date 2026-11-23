// First launch on Android (wand1; docs/wasm-port.md "The Android app"): where the game is. The Android counterpart of
// run/app/start.cpp (wui1), driven by the gamepad alone (handhelds with built-in controls: D-pad / stick to move, A to
// choose, B to go back; the system's folder picker is used as it is).
//
// The game is the player's own disc: the extracted folder (default.xbe and the .rcf archives), the Xbox disc image
// (.iso) or a disc pack (tools/disc_pack.py, .hulkdisc; wpkg1). In order:
//   1. a launching intent that names HULK_DATA_DIR (scripted runs: `am start -n .../.SetupActivity --es HULK_DATA_DIR ..`);
//   2. <files dir>/disc: the copy made by an earlier choice (or by `adb shell run-as ... ` on a debug build);
//   3. <external files dir>/disc (Android/data/org.thunderclap.hulkud/files/disc) when the app can read it, then
//      game.hulkdisc or game.iso there or in <files dir> (`tools/wasm_android.py install --game` puts it in <files>);
//   4. the image or pack chosen before (its content URI, kept with a persisted read permission);
//   5. a chooser: a message with "Choose the disc folder" / "Choose a disc image or pack" / "Quit", then the system's
//      picker (Storage Access Framework). A folder is checked as start.cpp checks it (an XBE whose certificate carries
//      the game's title ID, every archive rcfs.txt lists) and copied into <files dir>/disc (the game reads files by
//      path; a SAF folder gives only content URIs). An image or pack is checked by its header and read in place:
//      GameActivity opens it and hands the runner its descriptor (HULK_DATA_DIR=fd:N, run/disc.h), no copy. A bad
//      choice says why and asks again.
// Every HULK_* / SDL_* string extra is passed on to GameActivity. Nothing of the game is in this source but the ID.
package org.thunderclap.hulkud;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.StatFs;
import android.provider.DocumentsContract;
import android.util.Log;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SetupActivity extends Activity {
    static final String TAG = "hulk";
    static final int kTitleId = 0x56550039;    // the certificate's title ID of The Incredible Hulk: UD
    static final int PICK = 1, PICK_FILE = 2;
    static final String PREFS = "hulk", GAME_URI = "game_uri";

    private TextView msg;
    private Button choose, chooseFile, quit;
    private volatile boolean copying;
    private final Handler ui = new Handler(Looper.getMainLooper());

    // ------------------------------------------------------------------ the check (start.cpp checkDisc)
    interface Disc {
        InputStream open(String name) throws IOException;     // null when missing
        String where();
    }

    static String check(Disc d) {
        byte[] h = new byte[0x200];
        int certId;
        try (InputStream in = d.open("default.xbe")) {
            if (in == null) return "There is no default.xbe in\n" + d.where() + ".";
            int n = readFully(in, h);
            if (n < 0x120 || h[0] != 'X' || h[1] != 'B' || h[2] != 'E' || h[3] != 'H')
                return "default.xbe is not an Xbox executable (XBE).";
            long base = le32(h, 0x104), cert = le32(h, 0x118);
            if (cert <= base) return "default.xbe is not an Xbox executable (XBE).";
            long skip = cert - base - n;
            if (skip < 0) {
                if (cert - base + 12 > n) return "default.xbe is not an Xbox executable (XBE).";
                certId = (int) le32(h, (int) (cert - base) + 8);
            } else {
                while (skip > 0) {
                    long s = in.skip(skip);
                    if (s <= 0) return "default.xbe is not an Xbox executable (XBE).";
                    skip -= s;
                }
                byte[] c = new byte[12];
                if (readFully(in, c) != 12) return "default.xbe is not an Xbox executable (XBE).";
                certId = (int) le32(c, 8);
            }
        } catch (IOException e) {
            return "default.xbe cannot be read: " + e.getMessage();
        }
        if (certId != kTitleId)
            return String.format("default.xbe is another Xbox game (title ID %08X), not The Incredible Hulk: "
                                 + "Ultimate Destruction.", certId);
        String list;
        try (InputStream in = d.open("rcfs.txt")) {
            if (in == null) return "rcfs.txt is missing from\n" + d.where() + ".\nCopy the whole disc, not only default.xbe.";
            byte[] b = new byte[1024];
            list = new String(b, 0, Math.max(0, readFully(in, b)), "ISO-8859-1");
        } catch (IOException e) {
            return "rcfs.txt cannot be read: " + e.getMessage();
        }
        List<String> missing = new ArrayList<>();
        for (String t : list.split("[,\\s]+")) {
            if (!t.toLowerCase().endsWith(".rcf")) continue;
            try (InputStream in = d.open(t)) {
                if (in == null) missing.add(t);
            } catch (IOException e) {
                missing.add(t);
            }
        }
        if (!missing.isEmpty())
            return "The disc in\n" + d.where() + "\nis incomplete: " + String.join(", ", missing)
                + (missing.size() > 1 ? " are" : " is") + " missing.\nCopy the whole disc.";
        return null;
    }

    static int readFully(InputStream in, byte[] b) throws IOException {
        int n = 0, r;
        while (n < b.length && (r = in.read(b, n, b.length - n)) > 0) n += r;
        return n;
    }

    static long le32(byte[] b, int o) {
        return (b[o] & 0xffL) | (b[o + 1] & 0xffL) << 8 | (b[o + 2] & 0xffL) << 16 | (b[o + 3] & 0xffL) << 24;
    }

    static Disc dirDisc(final File dir) {
        return new Disc() {
            public InputStream open(String name) throws IOException {
                File f = new File(dir, name);
                return f.isFile() ? new FileInputStream(f) : null;
            }
            public String where() { return dir.getAbsolutePath(); }
        };
    }

    // a SAF tree: its files by name (the top level; the disc's own folders are copied too, but checked by top level)
    static class Entry { String id, name, mime; long size; }

    List<Entry> children(Uri tree, String parentId) {
        List<Entry> out = new ArrayList<>();
        Uri u = DocumentsContract.buildChildDocumentsUriUsingTree(tree, parentId);
        String[] cols = {DocumentsContract.Document.COLUMN_DOCUMENT_ID, DocumentsContract.Document.COLUMN_DISPLAY_NAME,
                         DocumentsContract.Document.COLUMN_MIME_TYPE, DocumentsContract.Document.COLUMN_SIZE};
        try (Cursor c = getContentResolver().query(u, cols, null, null, null)) {
            while (c != null && c.moveToNext()) {
                Entry e = new Entry();
                e.id = c.getString(0);
                e.name = c.getString(1);
                e.mime = c.getString(2);
                e.size = c.isNull(3) ? 0 : c.getLong(3);
                out.add(e);
            }
        }
        return out;
    }

    Disc treeDisc(final Uri tree, final String rootId) {
        final Map<String, Entry> top = new HashMap<>();
        for (Entry e : children(tree, rootId)) top.put(e.name.toLowerCase(), e);
        final ContentResolver cr = getContentResolver();
        return new Disc() {
            public InputStream open(String name) throws IOException {
                Entry e = top.get(name.toLowerCase());
                if (e == null || DocumentsContract.Document.MIME_TYPE_DIR.equals(e.mime)) return null;
                return cr.openInputStream(DocumentsContract.buildDocumentUriUsingTree(tree, e.id));
            }
            public String where() { return "the chosen folder"; }
        };
    }

    // ------------------------------------------------------------------ start
    @Override
    protected void onCreate(Bundle saved) {
        super.onCreate(saved);
        Bundle ex = getIntent() != null ? getIntent().getExtras() : null;
        if (ex != null && ex.get("HULK_DATA_DIR") instanceof String) {
            launch(null);
            return;
        }
        File disc = new File(getFilesDir(), "disc");
        String why = null;
        if (disc.isDirectory()) {
            why = check(dirDisc(disc));
            if (why == null) { launch(disc); return; }
            why = "The game copied before is gone or changed. " + why;
        }
        File ext = getExternalFilesDir(null);
        if (ext != null && new File(ext, "disc").isDirectory()) {
            String w = check(dirDisc(new File(ext, "disc")));
            if (w == null) { launch(new File(ext, "disc")); return; }
            if (why == null) why = w;
        }
        for (File dir : new File[] {ext, getFilesDir()}) {
            for (String n : new String[] {"game.hulkdisc", "game.iso"}) {
                File f = dir == null ? null : new File(dir, n);
                if (f == null || !f.isFile()) continue;
                String w = imageCheck(f.getAbsolutePath(), null);
                if (w == null) { launch(f); return; }
                if (why == null) why = w;
            }
        }
        String uri = getSharedPreferences(PREFS, MODE_PRIVATE).getString(GAME_URI, null);
        if (uri != null) {
            String w = imageCheck(null, Uri.parse(uri));
            if (w == null) { launchUri(Uri.parse(uri)); return; }
            if (why == null) why = "The disc image chosen before is gone or changed. " + w;
        }
        buildUi();
        show(why);
    }

    // ------------------------------------------------------------------ disc images and packs (wpkg1)
    // null when the file (a path, or a content URI) starts as a disc pack or holds an Xbox (XDVDFS) volume at 0 or at
    // a full image's game partition; the runner checks the game itself (start.cpp checkDisc)
    String imageCheck(String path, Uri uri) {
        try (android.os.ParcelFileDescriptor pfd = path != null
                 ? android.os.ParcelFileDescriptor.open(new File(path), android.os.ParcelFileDescriptor.MODE_READ_ONLY)
                 : getContentResolver().openFileDescriptor(uri, "r");
             FileInputStream in = new FileInputStream(pfd.getFileDescriptor())) {
            java.nio.channels.FileChannel ch = in.getChannel();
            java.nio.ByteBuffer b = java.nio.ByteBuffer.allocate(20);
            if (ch.read(b, 0) == 20 && new String(b.array(), 0, 8, "ISO-8859-1").equals("HULKDISC")) return null;
            for (long base : new long[] {0, 0x18300000L}) {
                b.clear();
                if (ch.read(b, base + 32 * 2048) == 20
                    && new String(b.array(), 0, 20, "ISO-8859-1").equals("MICROSOFT*XBOX*MEDIA")) return null;
            }
            return "That file is not an Xbox disc image (.iso) or a disc pack (.hulkdisc).";
        } catch (Exception e) {
            return "The file cannot be read: " + e.getMessage();
        }
    }

    void launchUri(Uri uri) {
        Intent g = new Intent(this, GameActivity.class);
        Bundle ex = getIntent() != null ? getIntent().getExtras() : null;
        if (ex != null) g.putExtras(ex);
        g.putExtra(GameActivity.DISC_URI, uri.toString());
        startActivity(g);
        finish();
    }

    void pickFile() {
        Intent i = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        i.addCategory(Intent.CATEGORY_OPENABLE);
        i.setType("*/*");
        try {
            startActivityForResult(i, PICK_FILE);
        } catch (Exception e) {
            show("This device has no file picker (" + e.getMessage() + ").");
        }
    }

    void launch(File disc) {
        Intent g = new Intent(this, GameActivity.class);
        Bundle ex = getIntent() != null ? getIntent().getExtras() : null;
        if (ex != null) g.putExtras(ex);
        if (disc != null) g.putExtra("HULK_DATA_DIR", disc.getAbsolutePath());
        startActivity(g);
        finish();
    }

    void buildUi() {
        LinearLayout l = new LinearLayout(this);
        l.setOrientation(LinearLayout.VERTICAL);
        l.setGravity(Gravity.CENTER);
        l.setBackgroundColor(Color.BLACK);
        l.setPadding(64, 32, 64, 32);
        msg = new TextView(this);
        msg.setTextColor(Color.WHITE);
        msg.setTextSize(18);
        msg.setGravity(Gravity.CENTER);
        msg.setPadding(0, 0, 0, 32);
        l.addView(msg);
        choose = new Button(this);
        choose.setText("Choose the disc folder");
        choose.setOnClickListener(v -> pick());
        l.addView(choose);
        chooseFile = new Button(this);
        chooseFile.setText("Choose a disc image or pack");
        chooseFile.setOnClickListener(v -> pickFile());
        l.addView(chooseFile);
        quit = new Button(this);
        quit.setText("Quit");
        quit.setOnClickListener(v -> finish());
        l.addView(quit);
        setContentView(l);
    }

    void show(String why) {
        msg.setText((why != null ? why + "\n\n" : "") + "Hulk needs your own copy of the game: choose the folder that "
                    + "holds the extracted disc (default.xbe and the .rcf archives; it is copied into the app's "
                    + "storage, about 2.3 GB), or the disc image (.iso) or a disc pack (.hulkdisc), which is read "
                    + "where it is.");
        choose.setEnabled(true);
        chooseFile.setEnabled(true);
        quit.setEnabled(true);
        choose.requestFocus();
    }

    void pick() {
        Intent i = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
        try {
            startActivityForResult(i, PICK);
        } catch (Exception e) {
            show("This device has no folder picker (" + e.getMessage() + "). Copy the disc with adb instead: "
                 + "see docs/wasm-port.md \"The Android app\".");
        }
    }

    // gamepad: A chooses, B goes back (the buttons take focus from the D-pad / stick as usual)
    @Override
    public boolean dispatchKeyEvent(KeyEvent e) {
        int k = e.getKeyCode();
        if (k == KeyEvent.KEYCODE_BUTTON_A)
            return super.dispatchKeyEvent(new KeyEvent(e.getDownTime(), e.getEventTime(), e.getAction(),
                                                       KeyEvent.KEYCODE_DPAD_CENTER, e.getRepeatCount()));
        if (k == KeyEvent.KEYCODE_BUTTON_B) {
            if (e.getAction() == KeyEvent.ACTION_UP && !copying) finish();
            return true;
        }
        return super.dispatchKeyEvent(e);
    }

    @Override
    public void onBackPressed() {
        if (!copying) finish();
    }

    @Override
    protected void onActivityResult(int req, int res, Intent data) {
        super.onActivityResult(req, res, data);
        if (req == PICK_FILE) {
            if (res != RESULT_OK || data == null || data.getData() == null) { show(null); return; }
            Uri u = data.getData();
            try {
                getContentResolver().takePersistableUriPermission(u, Intent.FLAG_GRANT_READ_URI_PERMISSION);
            } catch (SecurityException e) {
                Log.w(TAG, "no persistable permission for " + u + ": " + e);
            }
            String w = imageCheck(null, u);
            if (w != null) { show(w); return; }
            getSharedPreferences(PREFS, MODE_PRIVATE).edit().putString(GAME_URI, u.toString()).apply();
            launchUri(u);
            return;
        }
        if (req != PICK) return;
        if (res != RESULT_OK || data == null || data.getData() == null) { show(null); return; }
        final Uri tree = data.getData();
        final String rootId = DocumentsContract.getTreeDocumentId(tree);
        choose.setEnabled(false);
        chooseFile.setEnabled(false);
        quit.setEnabled(false);
        msg.setText("Checking the folder…");
        copying = true;
        new Thread(() -> {
            String why;
            try {
                why = check(treeDisc(tree, rootId));
                if (why == null) why = copy(tree, rootId);
            } catch (Exception e) {
                Log.e(TAG, "setup", e);
                why = "Reading the folder failed: " + e;
            }
            final String w = why;
            ui.post(() -> {
                copying = false;
                if (w == null) launch(new File(getFilesDir(), "disc"));
                else show(w);
            });
        }).start();
    }

    // ------------------------------------------------------------------ the copy
    long total, done;

    void sizes(Uri tree, String id, List<Entry> files, List<String> paths, String prefix) {
        for (Entry e : children(tree, id)) {
            if (DocumentsContract.Document.MIME_TYPE_DIR.equals(e.mime)) {
                sizes(tree, e.id, files, paths, prefix + e.name + "/");
            } else {
                files.add(e);
                paths.add(prefix + e.name);
                total += e.size;
            }
        }
    }

    String copy(Uri tree, String rootId) throws IOException {
        List<Entry> files = new ArrayList<>();
        List<String> paths = new ArrayList<>();
        total = done = 0;
        sizes(tree, rootId, files, paths, "");
        File tmp = new File(getFilesDir(), "disc.part"), disc = new File(getFilesDir(), "disc");
        deleteTree(tmp);
        long free = new StatFs(getFilesDir().getAbsolutePath()).getAvailableBytes();
        if (free < total + (64L << 20))
            return String.format("Not enough space: the disc needs %.1f GB, %.1f GB is free.", total / 1e9, free / 1e9);
        ContentResolver cr = getContentResolver();
        byte[] buf = new byte[1 << 20];
        long lastUi = 0;
        for (int i = 0; i < files.size(); i++) {
            File out = new File(tmp, paths.get(i));
            out.getParentFile().mkdirs();
            try (InputStream in = cr.openInputStream(DocumentsContract.buildDocumentUriUsingTree(tree, files.get(i).id));
                 OutputStream o = new FileOutputStream(out)) {
                int r;
                while ((r = in.read(buf)) > 0) {
                    o.write(buf, 0, r);
                    done += r;
                    long now = System.currentTimeMillis();
                    if (now - lastUi > 250) {
                        lastUi = now;
                        final String t = String.format("Copying the disc… %d%% (%s)", total > 0 ? done * 100 / total : 0,
                                                       paths.get(i));
                        ui.post(() -> msg.setText(t));
                    }
                }
            }
        }
        String why = check(dirDisc(tmp));
        if (why != null) return why;
        deleteTree(disc);
        if (!tmp.renameTo(disc)) return "Could not move the copy into place.";
        return null;
    }

    static void deleteTree(File f) {
        File[] k = f.listFiles();
        if (k != null) for (File c : k) deleteTree(c);
        f.delete();
    }
}
