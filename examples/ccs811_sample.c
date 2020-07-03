/*
 * Copyright (c) 2020, RudyLo <luhuadong@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-06-21     luhuadong    the first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "ccs811.h"

#define CCS811_I2C_BUS_NAME       "i2c1"

/* cat_ccs811 */
static void cat_ccs811(void)
{
    ccs811_device_t ccs811 = ccs811_create(CCS811_I2C_BUS_NAME);

    if(!ccs811) 
    {
        rt_kprintf("(CCS811) Init failed\n");
        return;
    }

    rt_uint16_t loop = 10;

    while(loop--)
    {
        /* Read TVOC and eCO2 */
        if(!ccs811_measure(ccs811)) 
        {
            rt_kprintf("(CCS811) Measurement failed\n");
            ccs811_delete(ccs811);
            break;
        }

        rt_kprintf("[%2u] TVOC: %d ppb, eCO2: %d ppm\n", loop, ccs811->eTVOC, ccs811->eCO2);
        rt_thread_mdelay(2000);
    }
    
    ccs811_delete(ccs811);
}
#ifdef FINSH_USING_MSH
MSH_CMD_EXPORT(cat_ccs811, read ccs811 TVOC and eCO2);
#endif
