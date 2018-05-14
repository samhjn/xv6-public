#ifndef __RISCV_H

#define __RISCV_H

#include "types.h"

// Routines to let C code use special RISC-V instructions.

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


#endif
