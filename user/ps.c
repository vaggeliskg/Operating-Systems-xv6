#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
#include "kernel/stat.h"
#include "user/user.h"

// main function that prints the pstat struct for the not UNUSED processes
int main() {
    struct pstat ps;
    getpinfo(&ps);
    for(int i = 0 ; i < NPROC ; i++) {
        if(ps.state[i] >= 1 && ps.state[i] <= 5) {
            printf("PID: %d, PPID: %d, Name: %s, Priority: %d, State: %d, Size: %d\n",
                ps.pid[i],ps.ppid[i],ps.name[i],ps.priority[i],ps.state[i],ps.size[i]);
        }
        else {
            break;
        }
    }
    return 0;
}