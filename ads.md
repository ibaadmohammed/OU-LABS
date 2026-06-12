#include <RTL.h>

#include <LPC214X.H>

#include "serial0.h"

extern void init_serial(void);

OS_TID tsk1, tsk2;

OS_MUT mutex1;

__task void task1(void)
{
    while(1)
    {
        putStrS0("\n\r Task1");

        os_dly_wait(100);

        os_mut_wait(mutex1, 0xffff);

        os_mut_release(mutex1);
    }
}

__task void task2(void)
{
    while(1)
    {
        os_mut_wait(mutex1, 0xffff);

        putStrS0("\n\r Task2");

        x = getCharS0();

        os_mut_release(mutex1);
    }
}

__task void init(void)
{
    initSerial0(9600);

    os_mut_init(mutex1);

    tsk1 = os_tsk_create(task1, 10);

    tsk2 = os_tsk_create(task2, 1);

    os_tsk_delete_self();
}

int main(void)
{
    os_sys_init(init);
}
