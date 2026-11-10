// hulk-netplay: the Cloudflare Worker for online co-op (docs/multiplayer.md, section 3).
//
// Two jobs, both on the Workers Free plan:
//   1. ICE servers: short-lived Cloudflare Realtime TURN credentials, cut down to what the game's ICE
//      agent (libjuice: UDP only) can use. Without the TURN secrets: Cloudflare's free STUN only.
//   2. Rooms: a short code the host reads out and the guest types in; through the room the two sides
//      swap their libjuice descriptions (juice_get_local_description / juice_set_remote_description)
//      and trickled candidates, by HTTP polling. One Durable Object (SQLite backend) per room.
//
// Routes (all JSON; errors are {error: "..."} with a 4xx/5xx status):
//   POST /ice  (alias /turn)     -> {iceServers:[{urls:[...], username?, credential?}], ttl, turn, note?}
//   POST /rooms                  {settings?}  -> 201 {code, token, role:"host", expiresAt}
//   POST /rooms/<code>/join      {}           -> 200 {token, role:"guest", settings, expiresAt}
//   POST /rooms/<code>/settings  {settings}   (host) -> {ok:true}
//   POST /rooms/<code>/signal    {description?, candidates?:[...], gatheringDone?}  -> {ok:true}
//   GET  /rooms/<code>           -> {role, joined, settings, peer:{description, candidates, gatheringDone}, expiresAt}
//   DELETE /rooms/<code>         -> {ok:true}   (either side ends the room)
// Room calls after create/join carry "Authorization: Bearer <token>" (the token create/join returned).
//
// Limits (vars in wrangler.jsonc; defaults below): a daily ceiling on minted TURN credentials and on
// rooms created (one global counter Durable Object, reset each UTC day); per room a request budget, at
// most MAX_SIGNAL_POSTS signal posts and MAX_CANDIDATES candidates per side; sizes capped below. Rooms
// end ROOM_JOIN_TTL_S after creation if nobody joined, and ROOM_TTL_S after creation in any case.
//
// The Durable Object classes are plain classes (constructor(state, env) + fetch), so this module also
// loads in plain node for test/worker_test.mjs.

const CF_TURN_API = "https://rtc.live.cloudflare.com/v1/turn/keys/";
const STUN_ONLY = [{ urls: ["stun:stun.cloudflare.com:3478"] }];

// a code: 6 characters from 29 that are hard to mistake for each other (no 0/O, 1/I/L, U/V)
const CODE_ALPHABET = "23456789ABCDEFGHJKMNPQRSTWXYZ";
const CODE_LEN = 6;
const CODE_RE = new RegExp(`^[${CODE_ALPHABET}]{${CODE_LEN}}$`);
const TOKEN_RE = /^[0-9a-f]{32}$/;

const MAX_BODY = 16 * 1024;          // any request body
const MAX_SETTINGS = 4 * 1024;       // the host's settings blob, as JSON text
const MAX_DESCRIPTION = 4 * 1024;    // one libjuice description
const MAX_CANDIDATE = 256;           // one "a=candidate:..." line
const MAX_CANDIDATES = 32;           // candidates per side, in total
const MAX_SIGNAL_POSTS = 24;         // signal posts per side
const DESC_RE = /^[\x20-\x7e\r\n\t]*$/;   // printable ASCII and line breaks only

const DEFAULTS = {
  ICE_TTL_S: 4 * 3600,          // credential life
  ICE_DAILY_CAP: 2000,          // TURN credentials minted per UTC day, all players
  ROOM_DAILY_CAP: 5000,         // rooms created per UTC day
  ROOM_JOIN_TTL_S: 600,         // an unjoined room ends after this
  ROOM_TTL_S: 7200,             // any room ends after this
  ROOM_REQUEST_CAP: 200,        // requests a room answers in its life (both sides)
  ICE_UDP_PORTS: "3478,443",    // the TURN/STUN ports handed to the game
};

const CORS = {
  "Access-Control-Allow-Origin": "*",
  "Access-Control-Allow-Methods": "GET, POST, DELETE, OPTIONS",
  "Access-Control-Allow-Headers": "Content-Type, Authorization",
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

function randomHex(bytes) {
  const b = crypto.getRandomValues(new Uint8Array(bytes));
  return Array.from(b, (x) => x.toString(16).padStart(2, "0")).join("");
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

// the request body as JSON (an object), or a Response saying why not
async function readBody(request, { optional = false } = {}) {
  const len = Number(request.headers.get("Content-Length") || 0);
  if (len > MAX_BODY) return fail(413, "body too large");
  const text = await request.text();
  if (text.length > MAX_BODY) return fail(413, "body too large");
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

async function iceServers(env) {
  const ttl = Math.min(num(env, "ICE_TTL_S"), 48 * 3600);
  const ports = new Set(String(env.ICE_UDP_PORTS || DEFAULTS.ICE_UDP_PORTS).split(",").map((p) => Number(p.trim())));
  const stunOnly = (note, status = 200) => json({ iceServers: STUN_ONLY, ttl, turn: false, note }, status);

  if (!env.TURN_KEY_ID || !env.TURN_KEY_API_TOKEN) return stunOnly("TURN is not configured on this server: STUN only");

  const quota = await counter(env, "ice", num(env, "ICE_DAILY_CAP"));
  if (!quota.ok) return stunOnly("the daily TURN credential cap is reached: STUN only until 00:00 UTC", 429);

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

// ---- the daily counters (one Durable Object for the whole Worker) ----

async function counter(env, kind, cap) {
  const stub = env.QUOTA.get(env.QUOTA.idFromName("global"));
  const r = await stub.fetch("https://quota/take", { method: "POST", body: JSON.stringify({ kind, cap }) });
  return r.json();
}

export class Quota {
  constructor(state) { this.storage = state.storage; }
  async fetch(request) {
    const { kind, cap } = await request.json();
    if (kind !== "ice" && kind !== "rooms") return json({ ok: false }, 400);
    const day = new Date(Date.now()).toISOString().slice(0, 10);
    let rec = (await this.storage.get(kind)) || { day, n: 0 };
    if (rec.day !== day) rec = { day, n: 0 };
    if (rec.n >= cap) return json({ ok: false, n: rec.n });
    rec.n++;
    await this.storage.put(kind, rec);
    return json({ ok: true, n: rec.n });
  }
}

// ---- rooms ----

function checkSettings(s) {
  if (s === undefined) return null;
  const text = JSON.stringify(s);
  if (text === undefined) return "settings must be JSON";
  if (text.length > MAX_SETTINGS) return `settings over ${MAX_SETTINGS} bytes`;
  return null;
}

function checkSignal(b) {
  for (const k of Object.keys(b))
    if (k !== "description" && k !== "candidates" && k !== "gatheringDone") return `unknown field ${k}`;
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

async function createRoom(request, env) {
  const b = await readBody(request, { optional: true });
  if (b instanceof Response) return b;
  const bad = checkSettings(b.settings);
  if (bad) return fail(400, bad);
  const quota = await counter(env, "rooms", num(env, "ROOM_DAILY_CAP"));
  if (!quota.ok) return fail(429, "the daily room cap is reached: try again after 00:00 UTC");
  for (let i = 0; i < 5; i++) {   // a taken code is rare (29^6 ~ 595 million); try a few
    const code = newCode(), token = randomHex(16);
    const r = await roomCall(env, code, "init", { token, settings: b.settings ?? null });
    if (r.status !== 409) return r;
  }
  return fail(503, "no free room code: try again");
}

async function roomRoute(request, env, code, action) {
  if (!CODE_RE.test(code)) return fail(400, "bad room code");
  const method = request.method;
  if (action === "join" && method === "POST") {
    const b = await readBody(request, { optional: true });
    if (b instanceof Response) return b;
    return roomCall(env, code, "join", { token: randomHex(16) });
  }
  const token = bearer(request);
  if (!token) return fail(401, "Authorization: Bearer <token> required");
  if (action === "" && method === "GET") return roomCall(env, code, "poll", { token });
  if (action === "" && method === "DELETE") return roomCall(env, code, "close", { token });
  if ((action === "signal" || action === "settings") && method === "POST") {
    const b = await readBody(request);
    if (b instanceof Response) return b;
    if (action === "signal") {
      const bad = checkSignal(b);
      if (bad) return fail(400, bad);
      return roomCall(env, code, "signal", { token, signal: b });
    }
    if (b.settings === undefined) return fail(400, "settings required");
    const bad = checkSettings(b.settings);
    if (bad) return fail(400, bad);
    return roomCall(env, code, "settings", { token, settings: b.settings });
  }
  return fail(405, "method not allowed");
}

// One room. Storage key "room": {code, created, joinBy, endsAt, requests, settings,
// host:{token, side}, guest:{token, side} | null}; side = {description, candidates, gatheringDone, posts}.
export class Room {
  constructor(state, env) {
    this.storage = state.storage;
    this.env = env || {};
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
    return room.guest ? room.endsAt : Math.min(room.joinBy, room.endsAt);
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
      room = {
        code: msg.code, created: now, joinBy: now + joinTtl, endsAt: now + ttl, requests: 1,
        settings: msg.settings ?? null,
        host: { token: msg.token, side: emptySide() }, guest: null,
      };
      await this.storage.put("room", room);
      await this.storage.setAlarm(this.deadline(room));
      return json({ code: msg.code, token: msg.token, role: "host", expiresAt: this.deadline(room) }, 201);
    }

    if (!room) return fail(404, "no such room (or it expired)");
    if (room.requests >= num(this.env, "ROOM_REQUEST_CAP")) return fail(429, "this room has used its request budget");
    room.requests++;

    if (op === "join") {
      if (room.guest) {
        await this.storage.put("room", room);
        return fail(409, "the room is full");
      }
      room.guest = { token: msg.token, side: emptySide() };
      await this.storage.put("room", room);
      await this.storage.setAlarm(this.deadline(room));
      return json({ token: msg.token, role: "guest", settings: room.settings, expiresAt: this.deadline(room) });
    }

    const role = whoIs(room, msg.token);
    if (!role) {
      await this.storage.put("room", room);
      return fail(403, "wrong token for this room");
    }
    const me = room[role], peer = role === "host" ? room.guest : room.host;

    if (op === "poll") {
      await this.storage.put("room", room);
      const p = peer ? peer.side : emptySide();
      return json({
        role, joined: !!room.guest, settings: room.settings,
        peer: { description: p.description, candidates: p.candidates, gatheringDone: p.gatheringDone },
        expiresAt: this.deadline(room),
      });
    }
    if (op === "close") {
      await this.end();
      return json({ ok: true });
    }
    if (op === "settings") {
      if (role !== "host") {
        await this.storage.put("room", room);
        return fail(403, "only the host sets the settings");
      }
      room.settings = msg.settings;
      await this.storage.put("room", room);
      return json({ ok: true });
    }
    if (op === "signal") {
      const s = me.side, sig = msg.signal;
      if (s.posts >= MAX_SIGNAL_POSTS) {
        await this.storage.put("room", room);
        return fail(429, `at most ${MAX_SIGNAL_POSTS} signal posts per side`);
      }
      if (sig.candidates && s.candidates.length + sig.candidates.length > MAX_CANDIDATES) {
        await this.storage.put("room", room);
        return fail(413, `at most ${MAX_CANDIDATES} candidates per side`);
      }
      s.posts++;
      if (sig.description !== undefined) s.description = sig.description;   // a restart replaces it
      if (sig.candidates) s.candidates.push(...sig.candidates);
      if (sig.gatheringDone) s.gatheringDone = true;
      await this.storage.put("room", room);
      return json({ ok: true });
    }
    return fail(404, "unknown room operation");
  }
}

const emptySide = () => ({ description: null, candidates: [], gatheringDone: false, posts: 0 });

function whoIs(room, token) {
  if (!TOKEN_RE.test(token || "")) return null;
  if (same(room.host.token, token)) return "host";
  if (room.guest && same(room.guest.token, token)) return "guest";
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
      if (path === "/ice" || path === "/turn") {
        if (request.method !== "POST") return fail(405, "POST only");
        return await iceServers(env);
      }
      if (path === "/rooms") {
        if (request.method !== "POST") return fail(405, "POST only");
        return await createRoom(request, env);
      }
      const m = /^\/rooms\/([^/]{1,16})(?:\/(join|signal|settings))?$/.exec(path);
      if (m) return await roomRoute(request, env, m[1].toUpperCase(), m[2] || "");
      if (path === "" && request.method === "GET") return json({ service: "hulk-netplay", ok: true });
      return fail(404, "not found");
    } catch (e) {
      return fail(500, "internal error");
    }
  },
};
