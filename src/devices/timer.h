#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>
#include <list.h>
#include "threads/synch.h"

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

/*define a structure with properties of semaphore and ticks*/
struct sema_tick {
    struct semaphore sema;
    int64_t ticks;
    struct list_elem elem; 
};

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/*comparison function*/
bool tick_comparison(const struct list_elem *elem_a, const struct list_elem *elem_b, void *);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */
