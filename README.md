# PintOS_AlarmClock

Imperial Pintos project task 0

Was asked to reimplement the timer_sleep() in timer.c to avoid busy waiting;

achieved by creating a queue for new struct sema_tick (tick and semaphore) and unblock threads in semaphore with order of sleeping time in timer_interrupt()
