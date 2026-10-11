"""Minimal GDB remote-protocol client for xemu's stub (-gdb tcp::1234).

Used by tools/hybrid_run.py for coverage (one-shot breakpoints on every patched function) and by the
determinism hooks to read state. Only what QEMU's i386 stub needs: Z0/z0 breakpoints, continue,
register and memory reads, interrupt.
"""
import socket
import struct
import threading
import time


class Gdb:
    def __init__(self, host="127.0.0.1", port=1234, timeout=30):
        t0 = time.time()
        while True:
            try:
                self.s = socket.create_connection((host, port), timeout=5)
                break
            except OSError:
                if time.time() - t0 > timeout:
                    raise
                time.sleep(0.5)
        self.s.settimeout(None)
        self.buf = b""
        self.lock = threading.Lock()
        self.cmd("QStartNoAckMode")
        self.noack = True

    # -- framing
    def _send(self, data):
        if isinstance(data, str):
            data = data.encode()
        pkt = b"$" + data + b"#%02x" % (sum(data) & 0xFF)
        self.s.sendall(pkt)

    def _recv_packet(self):
        while True:
            i = self.buf.find(b"$")
            if i >= 0:
                j = self.buf.find(b"#", i)
                if j >= 0 and len(self.buf) >= j + 3:
                    data = self.buf[i + 1:j]
                    self.buf = self.buf[j + 3:]
                    if not getattr(self, "noack", False):
                        self.s.sendall(b"+")
                    return data.decode("latin1")
            chunk = self.s.recv(65536)
            if not chunk:
                raise ConnectionError("gdb stub closed")
            self.buf += chunk

    def cmd(self, data):
        self._send(data)
        return self._recv_packet()

    # -- operations
    def set_break(self, addr):
        return self.cmd("Z0,%x,1" % addr) == "OK"

    def clear_break(self, addr):
        return self.cmd("z0,%x,1" % addr) == "OK"

    def regs(self):
        r = bytes.fromhex(self.cmd("g"))
        names = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi", "eip", "eflags")
        return dict(zip(names, struct.unpack_from("<10I", r)))

    def read(self, addr, n):
        out = b""
        while n > 0:
            k = min(n, 2048)
            r = self.cmd("m%x,%x" % (addr, k))
            if r.startswith("E"):
                raise IOError("read %#x: %s" % (addr, r))
            out += bytes.fromhex(r)
            addr += k
            n -= k
        return out

    def write(self, addr, data):
        return self.cmd("M%x,%x:%s" % (addr, len(data), data.hex())) == "OK"

    def cont(self):
        """Continue; returns the stop reply (blocks)."""
        self._send("c")
        return self._recv_packet()

    def interrupt(self):
        self.s.sendall(b"\x03")

    def close(self):
        try:
            self.s.close()
        except OSError:
            pass


class Coverage(threading.Thread):
    """One-shot breakpoints on `addrs`; records the first hit time of each, then removes it.

    The VM only stops for a first hit, so the cost is one stop per covered function."""

    def __init__(self, gdb, addrs, t0=None):
        super().__init__(daemon=True)
        self.g = gdb
        self.addrs = set(addrs)
        self.hits = {}
        self.t0 = t0 or time.time()
        self.stopping = False
        self.error = None

    def run(self):
        try:
            for a in self.addrs:
                self.g.set_break(a)
            while not self.stopping:
                rep = self.g.cont()
                if self.stopping:
                    break
                if not rep.startswith(("T", "S")):
                    continue
                eip = self.g.regs()["eip"]
                if eip in self.addrs and eip not in self.hits:
                    self.hits[eip] = round(time.time() - self.t0, 2)
                    self.g.clear_break(eip)
        except Exception as e:      # the VM went away
            self.error = repr(e)

    def stop(self):
        self.stopping = True
        try:
            self.g.interrupt()
        except OSError:
            pass
