#ifndef __RISCV_H

#define __RISCV_H

#include "types.h"

// Routines to let C code use special RISC-V instructions.

// CSR instructions
#define csrrw(old_csr,csr,value) \
    asm volatile("CSRRW %0, %1, %2": \
                 "=r"(*old_csr): \
                 "i"(csr), "r"(value));

#define csrrs(old_csr,csr,value) \
    asm volatile("CSRRS %0, %1, %2": \
                 "=r"(*old_csr): \
                 "i"(csr), "r"(value));

#define csrrc(old_csr,csr,value) \
    asm volatile("CSRRC %0, %1, %2": \
                 "=r"(*old_csr): \
                 "i"(csr), "r"(value)); \


// CSR address
#define     CSR_SSTATUS         0x100
#define     CSR_SSDELEG         0x102
#define     CSR_SIDELEG         0x103
#define     CSR_SIE             0x104
#define     CSR_STVEC           0x105
#define     CSR_SCOUNTEREN      0x106

#define     CSR_SSCRATCH        0x140
#define     CSR_SEPC            0x141
#define     CSR_SCAUSE          0x142
#define     CSR_STVAL           0x143
#define     CSR_SIP             0x144

#define     CSR_SATP            0x180

#define satp(mode, asid, ppn) \
    ((mode << 31) | ((asid & 0x1ff) << 22) | (ppn & 0x3fffff))


#endif
