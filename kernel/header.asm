section .multiboot_h
mbh_start:
  dd 0xe85250d6
  dd 0
  dd mbh_end - mbh_start
  dd 0x100000000 - (0xe85250d6 + 0 + (mbh_end - mbh_start))

  dw 0
  dw 0
  dd 8
mbh_end: