// hulk-netplay: the Cloudflare Worker for online co-op (docs/multiplayer.md, sections 3.1 and 18).
// Nothing here is deployed by the repo. Deploy steps: docs/multiplayer.md 18 ("Deploying the Worker").
//
// Two jobs, both on the Workers Free plan:
//   1. ICE servers: short-lived Cloudflare Realtime TURN credentials, cut down to what the game's ICE agent
//      (libjuice: UDP only) can use, for a room's members only. Without the TURN secrets: Cloudflare's free STUN only.
//   2. Lobbies (D246): an 8-digit code the host reads out and up to two guests type in (three Hulks); a star, each
//      guest connected to the host only. Through the room the host and each guest swap their libjuice
//      descriptions and trickled candidates, by HTTP polling. One Durable Object (SQLite backend) per room.
//
// Who may use it (wnet2, the handshake; docs/multiplayer.md 18.1):
//   - The app key (secret APP_KEY: the random key compiled into the app; tools/netplay_keys.py). Every request but
//     OPTIONS and GET / is signed: X-Hulk-Time (unix seconds), X-Hulk-Nonce (32 hex), X-Hulk-Sig = hex
//     HMAC-SHA256(APP_KEY, "hulk-v1\n" METHOD "\n" PATH "\n" TIME "\n" NONCE "\n" hex SHA-256(body)). A bad MAC, a
//     time more than SKEW_S (300 s) from the Worker's clock, or a nonce seen before is refused (401; code signature,
//     stale, replay). Without APP_KEY every signed route answers 503 (code nokey), unless ALLOW_UNSIGNED=1 (a local
//     development server only).
//   - Disc ownership (secret DISC_SPOTS: JSON [{f, o, n, h}], h = hex SHA-256 of n bytes of disc file f at offset o;
//     tools/netplay_keys.py samples them from the player's own disc: hashes only, never disc bytes). POST /challenge
//     names one spot at random with a one-time token (valid CHALLENGE_TTL_S); room create and join carry
//     {proof:{challenge, answer}}, answer = hex HMAC-SHA256(key = the spot's 32-byte hash, "hulk-disc-v1|" +
//     challenge). Wrong, missing, expired or reused: 403 (code disc). Without DISC_SPOTS no proof is asked for.
//   - Per-IP limits (CF-Connecting-IP) on /challenge, room create, join and ICE credentials (the IP_* vars).
//   - ICE credentials only for a room's members (POST /rooms/<code>/ice with the room's token), ICE_PER_ROOM a room.
//   - Peers authenticate each other: create gives the host the room's key (roomKey), join gives a guest its
//     peerKey = hex HMAC-SHA256(roomKey, "peer|SLOT|GEN"); the game's hello and welcome carry MACs under it
//     (run/app/netplay.cpp), so a peer that did not get that slot from this room is refused.
//
// Routes (all JSON; errors are {error: "...", code?} with a 4xx/5xx status):
//   GET  /                       -> {service, ok, auth, disc}   (unsigned: a health check)
//   POST /challenge              -> {disc:true, challenge, file, offset, length, expiresAt} | {disc:false}
//   POST /rooms                  {settings?, proof?}  -> 201 {code, token, roomKey, role:"host", slot:0, maxPlayers,
//                                                              expiresAt}
//   POST /rooms/<code>/join      {proof?}     -> 200 {token, peerKey, role:"guest", slot, gen, maxPlayers, settings,
//                                                     expiresAt} (409 when full)
//   POST /rooms/<code>/ice       (a member)   -> {iceServers:[{urls:[...], username?, credential?}], ttl, turn, note?}
//   POST /rooms/<code>/settings  {settings}   (host) -> {ok:true}
//   POST /rooms/<code>/signal    host: {to:<slot>, gen?, description?, candidates?, gatheringDone?};
//                                guest: {description?, candidates?, gatheringDone?}  -> {ok:true}
//   GET  /rooms/<code>           host:  {role, slot:0, settings, guests:[{slot, gen, description, candidates,
//                                        gatheringDone}], free, expiresAt}
//                                guest: {role, slot, gen, settings, peer:{description, candidates, gatheringDone},
//                                        expiresAt}
//   POST /rooms/<code>/leave     (guest) -> {ok:true, left:true}: the slot is free for another guest
//   DELETE /rooms/<code>         host: ends the room; guest: leaves (as /leave)
// Room calls after create/join carry "Authorization: Bearer <token>" (the token create/join returned).
//
// Limits (vars in wrangler.jsonc; defaults below): a daily ceiling on minted TURN credentials and on rooms created
// (one global Durable Object, which also keeps the per-IP counters and the nonces of requests made outside a room);
// per room a request budget, ICE_PER_ROOM credentials, at most MAX_SIGNAL_POSTS signal posts and MAX_CANDIDATES
// candidates per side; sizes capped below. Rooms end ROOM_JOIN_TTL_S after creation if nobody joined, and
// ROOM_TTL_S after creation in any case.
//
// The Durable Object classes are plain classes (constructor(state, env) + fetch), so this module also loads in
// plain node for test/worker_test.mjs and test/local_server.mjs.

const CF_TURN_API = "https://rtc.live.cloudflare.com/v1/turn/keys/";
const STUN_ONLY = [{ urls: ["stun:stun.cloudflare.com:3478"] }];

// a code: 8 digits (wnet1): a guest enters it with a gamepad, a digit a menu row (no keyboard on a handheld), and
// it reads out easily ("1234 5678"); 10^8 codes against at most a few thousand live rooms
const CODE_ALPHABET = "0123456789";
const CODE_LEN = 8;
const CODE_RE = new RegExp(`^[${CODE_ALPHABET}]{${CODE_LEN}}$`);
const TOKEN_RE = /^[0-9a-f]{32}$/;
const NONCE_RE = /^[0-9a-f]{32}$/;
const HEX64_RE = /^[0-9a-f]{64}$/;

const MAX_BODY = 16 * 1024;          // any request body
const MAX_SETTINGS = 4 * 1024;       // the host's settings blob, as JSON text
const MAX_DESCRIPTION = 4 * 1024;    // one libjuice description
const MAX_CANDIDATE = 256;           // one "a=candidate:..." line
const MAX_CANDIDATES = 32;           // candidates per side, in total
const MAX_SIGNAL_POSTS = 24;         // signal posts per side
const DESC_RE = /^[\x20-\x7e\r\n\t]*$/;   // printable ASCII and line breaks only
const SKEW_S = 300;                  // a signed request's time may be this far from ours
const NONCE_KEEP_MS = (2 * SKEW_S + 120) * 1000;   // nonces are kept past any time a replay could still carry
const MAX_NONCES_PER_MINUTE = 4000;  // one minute's bucket (a store value); past it requests wait for the next minute

const DEFAULTS = {
  ICE_TTL_S: 4 * 3600,          // credential life
  ICE_DAILY_CAP: 2000,          // TURN credentials minted per UTC day, all players
  ICE_PER_ROOM: 8,              // credentials one room may ask for (each player once, plus retries)
  ROOM_DAILY_CAP: 5000,         // rooms created per UTC day
  ROOM_JOIN_TTL_S: 600,         // an unjoined room ends after this
  ROOM_TTL_S: 7200,             // any room ends after this
  ROOM_REQUEST_CAP: 1500,       // requests a room answers in its life (all players: 2 h of polls every 10 s)
  ROOM_MAX_PLAYERS: 3,          // the host and two guests (2..4)
  ICE_UDP_PORTS: "3478,443",    // the TURN/STUN ports handed to the game
  CHALLENGE_TTL_S: 120,         // a disc challenge must be answered within this
  IP_CHALLENGES_PER_10MIN: 40,  // per IP address
  IP_ROOMS_PER_HOUR: 12,
  IP_JOINS_PER_10MIN: 30,       // (also what a code guesser gets: 30 tries in 10^8)
  IP_ICE_PER_HOUR: 30,
};
// per-IP limits: kind -> [var, window in seconds]
const IP_LIMITS = {
  challenge: ["IP_CHALLENGES_PER_10MIN", 600],
  rooms: ["IP_ROOMS_PER_HOUR", 3600],
  join: ["IP_JOINS_PER_10MIN", 600],
  ice: ["IP_ICE_PER_HOUR", 3600],
};

const CORS = {
  "Access-Control-Allow-Origin": "*",
  "Access-Control-Allow-Methods": "GET, POST, DELETE, OPTIONS",
  "Access-Control-Allow-Headers": "Content-Type, Authorization, X-Hulk-Time, X-Hulk-Nonce, X-Hulk-Sig",
};

function json(body, status = 200) {
  return new Response(JSON.stringify(body), {
    status,
    headers: { "Content-Type": "application/json", "Cache-Control": "no-store", ...CORS },
  });
}
const fail = (status, error, extra) => json({ error, ...extra }, status);

function num(env, name) {
  const v = Number(env[name]);
  return Number.isFinite(v) && v > 0 ? v : DEFAULTS[name];
}

// ---- crypto (WebCrypto: Workers and node 18+) ----
const enc = new TextEncoder();
const hex = (buf) => Array.from(new Uint8Array(buf), (x) => x.toString(16).padStart(2, "0")).join("");
function unhex(h) {
  const out = new Uint8Array(h.length >> 1);
  for (let i = 0; i < out.length; i++) out[i] = parseInt(h.substr(2 * i, 2), 16);
  return out;
}
const keyBytes = (k) => (/^[0-9a-fA-F]+$/.test(k) && k.length % 2 === 0 && k.length >= 32 ? unhex(k.toLowerCase()) : enc.encode(k));
export async function hmacHex(key, msg) {
  const k = await crypto.subtle.importKey("raw", key, { name: "HMAC", hash: "SHA-256" }, false, ["sign"]);
  return hex(await crypto.subtle.sign("HMAC", k, typeof msg === "string" ? enc.encode(msg) : msg));
}
export async function sha256Hex(data) {
  return hex(await crypto.subtle.digest("SHA-256", typeof data === "string" ? enc.encode(data) : data));
}

function randomHex(bytes) {
  return hex(crypto.getRandomValues(new Uint8Array(bytes)));
}

function newCode() {
  // rejection sampling: no bias towards the first characters
  const n = CODE_ALPHABET.length, limit = 256 - (256 % n);
  let out = "";
  while (out.length < CODE_LEN) {
    for (const x of crypto.getRandomValues(new Uint8Array(16))) {
      if (x < limit && out.length < CODE_LEN) out += CODE_ALPHABET[x % n];
    }
  }
  return out;
}

// the body text (already read) as a JSON object, or a Response saying why not
function parseBody(text, { optional = false } = {}) {
  if (text.trim() === "") return optional ? {} : fail(400, "JSON body required");
  let v;
  try { v = JSON.parse(text); } catch { return fail(400, "body is not JSON"); }
  if (v === null || typeof v !== "object" || Array.isArray(v)) return fail(400, "body must be a JSON object");
  return v;
}

function bearer(request) {
  const m = /^Bearer ([0-9a-f]{32})$/.exec(request.headers.get("Authorization") || "");
  return m ? m[1] : null;
}

const clientIp = (request) => request.headers.get("CF-Connecting-IP") || "unknown";

// ---- the app key: signed requests ----
// {ok:true, nonce, ts} or a Response. The nonce is only checked for form here; the Durable Object that handles the
// request records it (a room's own requests in the room, the others in the global Quota object).
async function checkSignature(request, url, body, env) {
  if (!env.APP_KEY) {
    if (env.ALLOW_UNSIGNED === "1") return { ok: true, nonce: null, ts: Date.now() };
    return fail(503, "this server has no app key", { code: "nokey" });
  }
  const t = request.headers.get("X-Hulk-Time") || "", nonce = request.headers.get("X-Hulk-Nonce") || "";
  const sig = (request.headers.get("X-Hulk-Sig") || "").toLowerCase();
  if (!/^\d{1,12}$/.test(t) || !NONCE_RE.test(nonce) || !HEX64_RE.test(sig))
    return fail(401, "unsigned request", { code: "signature" });
  const msg = `hulk-v1\n${request.method}\n${url.pathname}\n${t}\n${nonce}\n${await sha256Hex(body)}`;
  if (!same(await hmacHex(keyBytes(env.APP_KEY), msg), sig)) return fail(401, "bad signature", { code: "signature" });
  const ts = Number(t) * 1000;
  if (Math.abs(ts - Date.now()) > SKEW_S * 1000)
    return fail(401, "stale timestamp: the device's clock is off", { code: "stale", serverTime: Math.floor(Date.now() / 1000) });
  return { ok: true, nonce, ts };
}

// record NONCES ([{n, t}]) in STORAGE: false when one was seen (a replay), "full" when the minute is full
async function takeNonces(storage, nonces, now) {
  const byBucket = new Map();
  for (const { n, t } of nonces) {
    const b = Math.floor(t / 60000);
    if (!byBucket.has(b)) byBucket.set(b, []);
    byBucket.get(b).push(n);
  }
  const lists = new Map();
  for (const [b, ns] of byBucket) {
    const list = (await storage.get(`n:${b}`)) || [];
    for (const n of ns) if (list.includes(n)) return false;
    if (list.length + ns.length > MAX_NONCES_PER_MINUTE) return "full";
    lists.set(b, list.concat(ns));
  }
  for (const [b, list] of lists) await storage.put(`n:${b}`, list);
  // forget buckets older than any time a replay could carry
  const idx = new Set((await storage.get("n:index")) || []);
  for (const b of lists.keys()) idx.add(b);
  const cutoff = Math.floor((now - NONCE_KEEP_MS) / 60000);
  for (const b of [...idx]) if (b < cutoff) { await storage.delete(`n:${b}`); idx.delete(b); }
  await storage.put("n:index", [...idx]);
  return true;
}

// ---- disc ownership ----
function discSpots(env) {
  if (!env.DISC_SPOTS) return null;
  let spots;
  try { spots = typeof env.DISC_SPOTS === "string" ? JSON.parse(env.DISC_SPOTS) : env.DISC_SPOTS; } catch { return null; }
  if (!Array.isArray(spots)) return null;
  spots = spots.filter((s) => s && typeof s.f === "string" && Number.isInteger(s.o) && s.o >= 0 &&
                              Number.isInteger(s.n) && s.n > 0 && s.n <= 1 << 20 && HEX64_RE.test(String(s.h).toLowerCase()));
  return spots.length ? spots : null;
}
// the challenge tokens' key: the Worker's own, derived from the spot table (a secret the app does not hold), so a
// client can neither pick its spot nor make up a token
const challengeKey = async (env) => unhex(await sha256Hex("hulk-challenge-v1|" + env.DISC_SPOTS));

async function makeChallenge(env, spots) {
  const i = crypto.getRandomValues(new Uint32Array(1))[0] % spots.length;
  const exp = Math.floor(Date.now() / 1000) + num(env, "CHALLENGE_TTL_S");
  const body = `${i}.${exp}.${randomHex(16)}`;
  const tok = `${body}.${(await hmacHex(await challengeKey(env), body)).slice(0, 32)}`;
  return { disc: true, challenge: tok, file: spots[i].f, offset: spots[i].o, length: spots[i].n, expiresAt: exp * 1000 };
}

// {ok:true, once:{n, t}} (the challenge's one-time nonce) or a Response
async function checkProof(env, proof) {
  const spots = discSpots(env);
  if (!spots) return { ok: true, once: null };
  const bad = (why) => fail(403, why, { code: "disc" });
  if (!proof || typeof proof !== "object" || typeof proof.challenge !== "string" || typeof proof.answer !== "string")
    return bad("a disc proof is required");
  const m = /^(\d{1,3})\.(\d{1,12})\.([0-9a-f]{32})\.([0-9a-f]{32})$/.exec(proof.challenge);
  if (!m) return bad("not a challenge from this server");
  const [, si, exp, rnd, mac] = m;
  const body = `${si}.${exp}.${rnd}`;
  if (!same((await hmacHex(await challengeKey(env), body)).slice(0, 32), mac)) return bad("not a challenge from this server");
  if (Number(exp) * 1000 < Date.now()) return bad("the disc challenge expired");
  const spot = spots[Number(si)];
  if (!spot) return bad("not a challenge from this server");
  const want = await hmacHex(unhex(spot.h.toLowerCase()), "hulk-disc-v1|" + proof.challenge);
  if (!same(want, proof.answer.toLowerCase())) return bad("wrong disc answer");
  return { ok: true, once: { n: "c" + rnd, t: Number(exp) * 1000 } };
}

// ---- the global guard: per-IP limits, nonces outside rooms, daily counters (one Durable Object) ----
async function guard(env, msg) {
  const stub = env.QUOTA.get(env.QUOTA.idFromName("global"));
  const r = await stub.fetch("https://quota/guard", { method: "POST", body: JSON.stringify(msg) });
  return r.json();
}
// a Response for a refused guard answer, or null
function guardFail(g) {
  if (g.ok) return null;
  if (g.why === "replay") return fail(401, "replayed request", { code: "replay" });
  if (g.why === "challenge") return fail(403, "the disc challenge was used already", { code: "disc" });
  if (g.why === "rate") return fail(429, "too many requests from this network: try again later", { code: "rate" });
  if (g.why === "daily") return fail(429, g.note || "the daily cap is reached", { code: "daily" });
  return fail(503, "busy: try again", { code: "busy" });
}
function ipLimit(env, kind) {
  const [v, w] = IP_LIMITS[kind];
  return { kind, limit: num(env, v), window: w };
}

export class Quota {
  constructor(state) { this.storage = state.storage; }
  async fetch(request) {
    const op = new URL(request.url).pathname.slice(1);
    const msg = await request.json();
    const now = Date.now();
    if (op === "take") {        // a daily counter alone
      const r = await this.daily(msg.kind, msg.cap, now);
      return json({ ok: r });
    }
    if (op !== "guard") return json({ ok: false }, 400);
    // 1. nonces (the request's, a disc challenge's)
    const nonces = [];
    if (msg.nonce) nonces.push({ n: msg.nonce, t: msg.ts });
    if (msg.once) nonces.push(msg.once);
    if (nonces.length) {
      // (a challenge's nonce seen before is "challenge", the request's "replay")
      if (msg.once && !(await takeNonces(this.storage, [msg.once], now)))
        return json({ ok: false, why: "challenge" });
      const t = msg.nonce ? await takeNonces(this.storage, [{ n: msg.nonce, t: msg.ts }], now) : true;
      if (t === "full") return json({ ok: false, why: "busy" });
      if (!t) return json({ ok: false, why: "replay" });
    }
    // 2. the per-IP limit
    if (msg.rate) {
      const { kind, limit, window } = msg.rate;
      const w = Math.floor(now / (window * 1000));
      const key = `r:${kind}:${w}`;
      const map = (await this.storage.get(key)) || {};
      const n = map[msg.ip] || 0;
      if (n >= limit) return json({ ok: false, why: "rate" });
      map[msg.ip] = n + 1;
      await this.storage.put(key, map);
      const idx = (await this.storage.get(`r:index:${kind}`)) || [];
      if (!idx.includes(w)) {
        for (const old of idx.filter((x) => x < w)) await this.storage.delete(`r:${kind}:${old}`);
        await this.storage.put(`r:index:${kind}`, [w]);
      }
    }
    // 3. a daily counter
    if (msg.daily && !(await this.daily(msg.daily.kind, msg.daily.cap, now)))
      return json({ ok: false, why: "daily", note: msg.daily.note });
    return json({ ok: true });
  }
  async daily(kind, cap, now) {
    if (kind !== "ice" && kind !== "rooms") return false;
    const day = new Date(now).toISOString().slice(0, 10);
    let rec = (await this.storage.get(kind)) || { day, n: 0 };
    if (rec.day !== day) rec = { day, n: 0 };
    if (rec.n >= cap) return false;
    rec.n++;
    await this.storage.put(kind, rec);
    return true;
  }
}

// ---- ICE servers ----

// keep what a UDP-only ICE agent can use: stun: and turn: with UDP transport, on the allowed ports
export function udpOnly(urls, ports) {
  const out = [];
  for (const u of [].concat(urls || [])) {
    if (typeof u !== "string") continue;
    const m = /^(stun|turn):(\[[0-9a-fA-F:.]+\]|[A-Za-z0-9.-]+)(?::(\d+))?(\?.*)?$/.exec(u);
    if (!m) continue;   // turns:, stuns:, anything odd
    const [, scheme, , port = "3478", query = ""] = m;
    const transport = /[?&]transport=([a-z]+)/i.exec(query);
    if (transport && transport[1].toLowerCase() !== "udp") continue;
    if (scheme === "stun" && query) continue;
    if (!ports.has(Number(port))) continue;
    out.push(u);
  }
  return out;
}

// (test/local_server.mjs replaces this to hand out its local relay; the room and IP checks still run)
export const hooks = { iceServers: null };

async function iceServers(env, ip) {
  const ttl = Math.min(num(env, "ICE_TTL_S"), 48 * 3600);
  const ports = new Set(String(env.ICE_UDP_PORTS || DEFAULTS.ICE_UDP_PORTS).split(",").map((p) => Number(p.trim())));
  const stunOnly = (note, status = 200) => json({ iceServers: STUN_ONLY, ttl, turn: false, note }, status);

  const g = await guard(env, { ip, rate: ipLimit(env, "ice"),
                               daily: env.TURN_KEY_ID && env.TURN_KEY_API_TOKEN && !hooks.iceServers
                                 ? { kind: "ice", cap: num(env, "ICE_DAILY_CAP") } : null });
  if (!g.ok) {
    if (g.why === "daily") return stunOnly("the daily TURN credential cap is reached: STUN only until 00:00 UTC", 429);
    return guardFail(g);
  }
  if (hooks.iceServers) return hooks.iceServers(env);
  if (!env.TURN_KEY_ID || !env.TURN_KEY_API_TOKEN) return stunOnly("TURN is not configured on this server: STUN only");

  let r;
  try {
    r = await fetch(`${CF_TURN_API}${encodeURIComponent(env.TURN_KEY_ID)}/credentials/generate-ice-servers`, {
      method: "POST",
      headers: { Authorization: `Bearer ${env.TURN_KEY_API_TOKEN}`, "Content-Type": "application/json" },
      body: JSON.stringify({ ttl }),
    });
  } catch {
    return stunOnly("the TURN service did not answer: STUN only", 502);
  }
  if (!r.ok) return stunOnly(`the TURN service refused (${r.status}): STUN only`, 502);
  let body;
  try { body = await r.json(); } catch { return stunOnly("the TURN service answered nonsense: STUN only", 502); }

  const servers = [];
  for (const s of Array.isArray(body?.iceServers) ? body.iceServers : []) {
    const urls = udpOnly(s?.urls, ports);
    if (!urls.length) continue;
    const entry = { urls };
    if (typeof s.username === "string") entry.username = s.username;
    if (typeof s.credential === "string") entry.credential = s.credential;
    servers.push(entry);
  }
  if (!servers.some((s) => s.urls.some((u) => u.startsWith("turn:"))))
    return stunOnly("the TURN service gave no UDP relay: STUN only", 502);
  return json({ iceServers: servers, ttl, turn: true });
}

// ---- rooms ----
//
// A room is a lobby of up to ROOM_MAX_PLAYERS (3: the host and two guests) in a star: each guest connects to the
// host only (one libjuice agent per guest on the host, one on each guest), and the host relays the inputs. The host
// is slot 0; a guest takes the lowest free slot (1, 2). A slot freed by a guest who left can be taken again: every
// join gives the slot a new generation (`gen`), and the host's signalling for that slot starts afresh with it, so a
// late post for the previous guest never reaches the new one.

function checkSettings(s) {
  if (s === undefined) return null;
  const text = JSON.stringify(s);
  if (text === undefined) return "settings must be JSON";
  if (text.length > MAX_SETTINGS) return `settings over ${MAX_SETTINGS} bytes`;
  return null;
}

const SIGNAL_FIELDS = new Set(["to", "gen", "description", "candidates", "gatheringDone"]);
function checkSignal(b) {
  for (const k of Object.keys(b)) if (!SIGNAL_FIELDS.has(k)) return `unknown field ${k}`;
  if (b.to !== undefined && !(Number.isInteger(b.to) && b.to >= 1 && b.to <= 8)) return "to must be a guest slot";
  if (b.gen !== undefined && !(Number.isInteger(b.gen) && b.gen >= 1)) return "gen must be a positive integer";
  if (b.description !== undefined) {
    if (typeof b.description !== "string" || !b.description.length) return "description must be a non-empty string";
    if (b.description.length > MAX_DESCRIPTION) return `description over ${MAX_DESCRIPTION} bytes`;
    if (!DESC_RE.test(b.description)) return "description has characters outside printable ASCII";
  }
  if (b.candidates !== undefined) {
    if (!Array.isArray(b.candidates) || b.candidates.length > MAX_CANDIDATES) return `candidates must be an array of at most ${MAX_CANDIDATES}`;
    for (const c of b.candidates) {
      if (typeof c !== "string" || !c.length || c.length > MAX_CANDIDATE || !/^[\x20-\x7e]+$/.test(c))
        return `each candidate must be one printable line of at most ${MAX_CANDIDATE} bytes`;
    }
  }
  if (b.gatheringDone !== undefined && typeof b.gatheringDone !== "boolean") return "gatheringDone must be a boolean";
  if (b.description === undefined && b.candidates === undefined && b.gatheringDone === undefined) return "nothing to post";
  return null;
}

const roomStub = (env, code) => env.ROOMS.get(env.ROOMS.idFromName(code));
const roomCall = (env, code, op, payload) =>
  roomStub(env, code).fetch(`https://room/${op}`, { method: "POST", body: JSON.stringify({ code, ...payload }) });

async function challengeRoute(request, env, sig) {
  const spots = discSpots(env);
  const bad = guardFail(await guard(env, { ip: clientIp(request), nonce: sig.nonce, ts: sig.ts,
                                           rate: ipLimit(env, "challenge") }));
  if (bad) return bad;
  if (!spots) return json({ disc: false });
  return json(await makeChallenge(env, spots));
}

async function createRoom(request, env, text, sig) {
  const b = parseBody(text, { optional: true });
  if (b instanceof Response) return b;
  for (const k of Object.keys(b)) if (k !== "settings" && k !== "proof") return fail(400, `unknown field ${k}`);
  const bad = checkSettings(b.settings);
  if (bad) return fail(400, bad);
  const proof = await checkProof(env, b.proof);
  if (proof instanceof Response) return proof;
  const g = guardFail(await guard(env, { ip: clientIp(request), nonce: sig.nonce, ts: sig.ts, once: proof.once,
                                         rate: ipLimit(env, "rooms"),
                                         daily: { kind: "rooms", cap: num(env, "ROOM_DAILY_CAP"),
                                                  note: "the daily room cap is reached: try again after 00:00 UTC" } }));
  if (g) return g;
  for (let i = 0; i < 5; i++) {   // a taken code is rare (10^8); try a few
    const code = newCode(), token = randomHex(16), secret = randomHex(32);
    const r = await roomCall(env, code, "init", { token, secret, settings: b.settings ?? null });
    if (r.status !== 409) return r;
  }
  return fail(503, "no free room code: try again");
}

async function roomRoute(request, env, code, action, text, sig) {
  if (!CODE_RE.test(code)) return fail(400, "bad room code");
  const method = request.method;
  if (action === "join" && method === "POST") {
    const b = parseBody(text, { optional: true });
    if (b instanceof Response) return b;
    for (const k of Object.keys(b)) if (k !== "proof") return fail(400, `unknown field ${k}`);
    const proof = await checkProof(env, b.proof);
    if (proof instanceof Response) return proof;
    const g = guardFail(await guard(env, { ip: clientIp(request), nonce: sig.nonce, ts: sig.ts, once: proof.once,
                                           rate: ipLimit(env, "join") }));
    if (g) return g;
    return roomCall(env, code, "join", { token: randomHex(16) });
  }
  const token = bearer(request);
  if (!token) return fail(401, "Authorization: Bearer <token> required");
  const auth = { token, nonce: sig.nonce, ts: sig.ts };
  if (action === "" && method === "GET") return roomCall(env, code, "poll", auth);
  if (action === "" && method === "DELETE") return roomCall(env, code, "close", auth);
  if (action === "leave" && method === "POST") return roomCall(env, code, "leave", auth);
  if (action === "ice" && method === "POST") {
    const r = await roomCall(env, code, "ice", auth);
    if (r.status !== 200) return r;
    return iceServers(env, clientIp(request));
  }
  if ((action === "signal" || action === "settings") && method === "POST") {
    const b = parseBody(text);
    if (b instanceof Response) return b;
    if (action === "signal") {
      const bad = checkSignal(b);
      if (bad) return fail(400, bad);
      return roomCall(env, code, "signal", { ...auth, signal: b });
    }
    if (b.settings === undefined) return fail(400, "settings required");
    const bad = checkSettings(b.settings);
    if (bad) return fail(400, bad);
    return roomCall(env, code, "settings", { ...auth, settings: b.settings });
  }
  return fail(405, "method not allowed");
}

// One room. Storage key "room": {code, created, joinBy, endsAt, requests, ice, settings, everJoined, gens, secret,
// host:{token, sides:{<slot>: side}}, guests:{<slot>: {token, gen, joinedAt, side} | null}};
// side = {description, candidates, gatheringDone, posts}. host.sides[k] is the host's agent for guest slot k.
// Keys "n:<minute>" / "n:index": the nonces of the members' signed requests.
export class Room {
  constructor(state, env) {
    this.storage = state.storage;
    this.env = env || {};
  }

  maxGuests() {
    const n = Math.floor(num(this.env, "ROOM_MAX_PLAYERS"));
    return Math.min(Math.max(n, 2), 4) - 1;
  }

  async end() {
    await this.storage.deleteAll();
  }

  async alarm() {
    const room = await this.storage.get("room");
    if (!room || Date.now() >= this.deadline(room)) await this.end();
    else await this.storage.setAlarm(this.deadline(room));
  }

  deadline(room) {
    return room.everJoined ? room.endsAt : Math.min(room.joinBy, room.endsAt);
  }

  async fetch(request) {
    const op = new URL(request.url).pathname.slice(1);
    const msg = await request.json();
    const now = Date.now();
    let room = await this.storage.get("room");
    if (room && now >= this.deadline(room)) {
      await this.end();
      room = null;
    }

    if (op === "init") {
      if (room) return fail(409, "code taken");
      const joinTtl = num(this.env, "ROOM_JOIN_TTL_S") * 1000, ttl = num(this.env, "ROOM_TTL_S") * 1000;
      const guests = {};
      for (let k = 1; k <= this.maxGuests(); k++) guests[k] = null;
      room = {
        code: msg.code, created: now, joinBy: now + joinTtl, endsAt: now + ttl, requests: 1, ice: 0,
        settings: msg.settings ?? null, everJoined: false, gens: 0, secret: msg.secret,
        host: { token: msg.token, sides: {} }, guests,
      };
      await this.storage.put("room", room);
      await this.storage.setAlarm(this.deadline(room));
      return json({ code: msg.code, token: msg.token, roomKey: msg.secret, role: "host", slot: 0,
                    maxPlayers: this.maxGuests() + 1, expiresAt: this.deadline(room) }, 201);
    }

    if (!room) return fail(404, "no such room (or it expired)");
    if (room.requests >= num(this.env, "ROOM_REQUEST_CAP")) return fail(429, "this room has used its request budget");
    room.requests++;
    const save = () => this.storage.put("room", room);

    if (op === "join") {
      const slot = Object.keys(room.guests).map(Number).sort((a, b) => a - b).find((k) => !room.guests[k]);
      if (slot === undefined) {
        await save();
        return fail(409, "the room is full");
      }
      room.gens++;
      room.guests[slot] = { token: msg.token, gen: room.gens, joinedAt: now, side: emptySide() };
      room.host.sides[slot] = emptySide();
      room.everJoined = true;
      await save();
      await this.storage.setAlarm(this.deadline(room));
      return json({ token: msg.token, peerKey: await peerKey(room.secret, slot, room.gens), role: "guest", slot,
                    gen: room.gens, maxPlayers: this.maxGuests() + 1, settings: room.settings,
                    expiresAt: this.deadline(room) });
    }

    const who = whoIs(room, msg.token);
    if (!who) {
      await save();
      return fail(403, "wrong token for this room");
    }
    if (msg.nonce) {      // (a member's signed request: once only)
      const t = await takeNonces(this.storage, [{ n: msg.nonce, t: msg.ts }], now);
      if (t !== true) {
        await save();
        return t === "full" ? fail(503, "busy: try again", { code: "busy" }) : fail(401, "replayed request", { code: "replay" });
      }
    }

    if (op === "poll") {
      await save();
      if (who.role === "host") {
        const guests = [];
        for (const [k, g] of Object.entries(room.guests)) {
          if (!g) continue;
          guests.push({ slot: Number(k), gen: g.gen, description: g.side.description, candidates: g.side.candidates,
                        gatheringDone: g.side.gatheringDone });
        }
        const free = Object.values(room.guests).filter((g) => !g).length;
        return json({ role: "host", slot: 0, settings: room.settings, guests, free, expiresAt: this.deadline(room) });
      }
      const g = room.guests[who.slot], p = room.host.sides[who.slot] || emptySide();
      return json({
        role: "guest", slot: who.slot, gen: g.gen, settings: room.settings,
        peer: { description: p.description, candidates: p.candidates, gatheringDone: p.gatheringDone },
        expiresAt: this.deadline(room),
      });
    }
    if (op === "ice") {
      if ((room.ice || 0) >= num(this.env, "ICE_PER_ROOM")) {
        await save();
        return fail(429, "this room has used its ICE credentials", { code: "rate" });
      }
      room.ice = (room.ice || 0) + 1;
      await save();
      return json({ ok: true });
    }
    if (op === "close") {
      if (who.role === "guest") {   // a guest's DELETE leaves; the host's ends the room
        room.guests[who.slot] = null;
        delete room.host.sides[who.slot];
        await save();
        return json({ ok: true, left: true });
      }
      await this.end();
      return json({ ok: true });
    }
    if (op === "leave") {
      if (who.role === "host") {
        await save();
        return fail(400, "the host ends the room with DELETE");
      }
      room.guests[who.slot] = null;
      delete room.host.sides[who.slot];
      await save();
      return json({ ok: true, left: true });
    }
    if (op === "settings") {
      if (who.role !== "host") {
        await save();
        return fail(403, "only the host sets the settings");
      }
      room.settings = msg.settings;
      await save();
      return json({ ok: true });
    }
    if (op === "signal") {
      const sig = msg.signal;
      let s;
      if (who.role === "host") {
        const g = room.guests[sig.to];
        if (!sig.to || !g) {
          await save();
          return fail(sig.to ? 409 : 400, sig.to ? "no guest in that slot" : "the host's signal needs `to` (a guest slot)");
        }
        if (sig.gen !== undefined && sig.gen !== g.gen) {
          await save();
          return fail(409, "that guest has left (another took the slot)");
        }
        s = room.host.sides[sig.to];
      } else {
        if (sig.to !== undefined) {
          await save();
          return fail(400, "a guest signals the host only");
        }
        s = room.guests[who.slot].side;
      }
      if (s.posts >= MAX_SIGNAL_POSTS) {
        await save();
        return fail(429, `at most ${MAX_SIGNAL_POSTS} signal posts per side`);
      }
      if (sig.candidates && s.candidates.length + sig.candidates.length > MAX_CANDIDATES) {
        await save();
        return fail(413, `at most ${MAX_CANDIDATES} candidates per side`);
      }
      s.posts++;
      if (sig.description !== undefined) s.description = sig.description;   // a restart replaces it
      if (sig.candidates) s.candidates.push(...sig.candidates);
      if (sig.gatheringDone) s.gatheringDone = true;
      await save();
      return json({ ok: true });
    }
    return fail(404, "unknown room operation");
  }
}

const emptySide = () => ({ description: null, candidates: [], gatheringDone: false, posts: 0 });
// a guest's key for the game's hello (the host derives the same from roomKey)
export const peerKey = (secret, slot, gen) => hmacHex(unhex(secret), `peer|${slot}|${gen}`);

function whoIs(room, token) {
  if (!TOKEN_RE.test(token || "")) return null;
  if (same(room.host.token, token)) return { role: "host", slot: 0 };
  for (const [k, g] of Object.entries(room.guests))
    if (g && same(g.token, token)) return { role: "guest", slot: Number(k) };
  return null;
}

function same(a, b) {   // constant time
  if (a.length !== b.length) return false;
  let d = 0;
  for (let i = 0; i < a.length; i++) d |= a.charCodeAt(i) ^ b.charCodeAt(i);
  return d === 0;
}

// ---- entry ----

export default {
  async fetch(request, env) {
    const url = new URL(request.url);
    if (request.method === "OPTIONS") return new Response(null, { status: 204, headers: CORS });
    try {
      const path = url.pathname.replace(/\/+$/, "");
      if (path === "" && request.method === "GET")
        return json({ service: "hulk-netplay", ok: true, auth: !!env.APP_KEY, disc: !!discSpots(env) });
      if (Number(request.headers.get("Content-Length") || 0) > MAX_BODY) return fail(413, "body too large");
      const text = ["GET", "HEAD"].includes(request.method) ? "" : await request.text();
      if (text.length > MAX_BODY) return fail(413, "body too large");
      const sig = await checkSignature(request, url, text, env);
      if (sig instanceof Response) return sig;
      if (path === "/challenge") {
        if (request.method !== "POST") return fail(405, "POST only");
        return await challengeRoute(request, env, sig);
      }
      if (path === "/rooms") {
        if (request.method !== "POST") return fail(405, "POST only");
        return await createRoom(request, env, text, sig);
      }
      if (path === "/ice" || path === "/turn") return fail(410, "ICE servers are for a room's members: POST /rooms/<code>/ice");
      const m = /^\/rooms\/([^/]{1,16})(?:\/(join|signal|settings|leave|ice))?$/.exec(path);
      if (m) return await roomRoute(request, env, m[1].toUpperCase(), m[2] || "", text, sig);
      return fail(404, "not found");
    } catch (e) {
      return fail(500, "internal error");
    }
  },
};
