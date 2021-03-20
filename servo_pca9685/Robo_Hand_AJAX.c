/* For usleep() */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>

/* Driver configuration */
#include "ti_drivers_config.h"
#include "servo_pca9685.h"
/*
 *  ======== mainThread ========
 */

void *mainThread(void *arg0)
{
    t_hand *lst;
    lst = (t_hand *)malloc(sizeof(t_hand));
    lst->f1 = 11;
    lst->f2 = 14;
    lst->f3 = 15;
    lst->f4 = 13;
    lst->f5 = 12;

    /* Call driver init functions */
    GPIO_init();
    PCA_ServoInit();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn on user LED */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
    while (1) {
        usleep(100000);
        PCA_ServoWrite(SRV_LED_1, 0);
        PCA_ServoWrite(SRV_LED_2, 0);
        PCA_ServoWrite(SRV_LED_3, 0);
        PCA_ServoWrite(SRV_LED_4, 0);
        PCA_ServoWrite(SRV_LED_5, 0);
        sleep(1);
        PCA_ServoWrite(SRV_LED_1, 180);
        PCA_ServoWrite(SRV_LED_2, 180);
        PCA_ServoWrite(SRV_LED_3, 180);
        PCA_ServoWrite(SRV_LED_4, 180);
        PCA_ServoWrite(SRV_LED_5, 180);
        sleep(2);
        PCA_ServoWrite(SRV_LED_4, 0);
        PCA_ServoWrite(SRV_LED_3, 0);
        sleep(4);
        PCA_ServoWrite(SRV_LED_1, 0);
        PCA_ServoWrite(SRV_LED_2, 0);
        PCA_ServoWrite(SRV_LED_3, 0);
        PCA_ServoWrite(SRV_LED_4, 0);
        PCA_ServoWrite(SRV_LED_5, 0);
        sleep(2);
        PCA_ServoWrite(SRV_LED_3, 180);
        PCA_ServoWrite(SRV_LED_2, 180);
        sleep(1);
        PCA_ServoWrite(SRV_LED_3, 0);
        PCA_ServoWrite(SRV_LED_2, 0);
        sleep(1);
        PCA_ServoWrite(SRV_LED_3, 180);
        PCA_ServoWrite(SRV_LED_2, 180);
        sleep(1);
        PCA_ServoWrite(SRV_LED_3, 0);
        PCA_ServoWrite(SRV_LED_2, 0);
        sleep(1);
        PCA_ServoWrite(SRV_LED_3, 180);
        PCA_ServoWrite(SRV_LED_2, 180);
        sleep(1);
        GPIO_toggle(CONFIG_GPIO_LED_0);
    }
}
