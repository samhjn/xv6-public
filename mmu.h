#ifndef __MMU_H
#define __MMU_H

// This file contains definitions for the
// riscv memory management unit (MMU).

// An Sv32 virtual address 'la' has a three-part structure as follows:
// (priv spec 1.10 P60) 
//
// +--------10------+-------10-------+---------12----------+
// |  Virtual Page  |  Virtual Page  |      page offset    |
// |     Number     |     Number     |                     |
// +----------------+----------------+---------------------+
//  \--- VPN[1] ---/ \--- VPN[0] ---/

#define VPN1SHIFT        12      // offset of PTX in a linear address
#define VPN0SHIFT        22      // offset of PDX in a linear address
// Virtual page number level 1
#define VPN1(va)         (((uint)(va) >> VPN1SHIFT) & 0x3FF)

// Virtual page number level 2
#define VPN0(va)         (((uint)(va) >> VPN0SHIFT) & 0x3FF)

// Construct virtual address from indexes and offset
#define PGADDR(a, b, o) ((uint)((a) << VPN1SHIFT | (b) << VPN0SHIFT | (o)))

// Page table constants.
#define NPTENTRIES      1024    // # PTEs per page table
#define PGSIZE          4096    // bytes mapped by a page

#define PGSHIFT         12      // log2(PGSIZE)


#define PGROUNDUP(sz)  (((sz)+PGSIZE-1) & ~(PGSIZE-1))
#define PGROUNDDOWN(a) (((a)) & ~(PGSIZE-1))

// Page table entry flags.
#define PTE_V           0x001   // Valid
#define PTE_R           0x002   // Readable
#define PTE_W           0x004   // Writeable
#define PTE_X           0x008   // Executable
#define PTE_U           0x010   // User mode
#define PTE_G           0x020   // Global
#define PTE_A           0x040   // Accessed
#define PTE_D           0x080   // Dirty

// Address in page table or page directory entry
#define PTE_ADDR(pte)   ((uint)(pte) & ~0x3FF)
#define PTE_FLAGS(pte)  ((uint)(pte) &  0x3FF)

typedef uint pte_t;

#endif

#endif
