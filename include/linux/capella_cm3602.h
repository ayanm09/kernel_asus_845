/* include/linux/capella_cm3602.h
 *
 * Copyright (C) 2009 Google, Inc.
 * Author: Iliyan Malchev <malchev@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __LINUX_CAPELLA_CM3602_H
#define __LINUX_CAPELLA_CM3602_H

#include <linux/types.h>
#include <linux/ioctl.h>
//#ifdef ZD552KL_PHOENIX
#define CAPELLA_CM3602_IOCTL_MAGIC 'c'
#define CAPELLA_CM3602_IOCTL_GET_ENABLED \
		_IOR(CAPELLA_CM3602_IOCTL_MAGIC, 1, int *)
#define CAPELLA_CM3602_IOCTL_ENABLE \
		_IOW(CAPELLA_CM3602_IOCTL_MAGIC, 2, int *)
#define CAPELLA_CM3602_IOCTL_ENABLE_FAC \
		_IOW(CAPELLA_CM3602_IOCTL_MAGIC, 3, int *)
//#endif

/*ASUS - bevis chen-- add +*/
#define PBUFF_SIZE				16	/* Rx buffer size */

#define ASUS_PSENSOR_IOCTL_CLOSE		         _IO(CAPELLA_CM3602_IOCTL_MAGIC, 0x12)
#define ASUS_PSENSOR_IOCTL_START		         _IO(CAPELLA_CM3602_IOCTL_MAGIC, 0x13)
#define ASUS_PSENSOR_IOCTL_GETDATA             _IOR(CAPELLA_CM3602_IOCTL_MAGIC, 0x14, char[PBUFF_SIZE+1])

#define ASUS_PSENSOR_SETCALI_DATA	         _IOW(CAPELLA_CM3602_IOCTL_MAGIC, 0x15, int[2])
#define ASUS_PSENSOR_EN_CALIBRATION           _IOW(CAPELLA_CM3602_IOCTL_MAGIC, 0x16, char)
/*ASUS - bevis chen-- add -*/



#ifdef __KERNEL__
#define CAPELLA_CM3602 "capella_cm3602"
#define LS_PWR_ON					(1 << 0)
#define PS_PWR_ON					(1 << 1)
struct capella_cm3602_platform_data {
	int (*power)(int, uint8_t); /* power to the chip */
	int (*enable)(uint8_t); /* enable to the chip */
	int p_en; /* proximity-sensor enable */
	int p_out; /* proximity-sensor outpuCAPELLA_CM3602_IOCTL_ENABLE,t */
	int irq;
};
#endif /* __KERNEL__ */

#endif
