/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-5      SummerGift   first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtthread.h>
#include <board.h>

#if defined(BSP_USING_ON_CHIP_FLASH)
extern const struct fal_flash_dev stm32_onchip_flash;
#endif /* BSP_USING_ON_CHIP_FLASH */

/* ========================= Device Configuration ========================== */
#ifdef BSP_USING_ON_CHIP_FLASH
#define ONCHIP_FLASH_DEV     &stm32_onchip_flash,  
#else
#define ONCHIP_FLASH_DEV    
#endif /* BSP_USING_ON_CHIP_FLASH */

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    ONCHIP_FLASH_DEV                                                 \
}

/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG

#ifdef BSP_USING_ON_CHIP_FLASH
#define ONCHIP_FLASH_PATITION          {FAL_PART_MAGIC_WROD, "app",   "onchip_flash",   0,           496 * 1024, 0},      \
                                       {FAL_PART_MAGIC_WROD, "param", "onchip_flash",   496* 1024,   16 * 1024,  0},
#else
#define ONCHIP_FLASH_PATITION
#endif

/* partition table */
#define FAL_PART_TABLE                                               \
{                                                                    \
    ONCHIP_FLASH_PATITION                                            \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
