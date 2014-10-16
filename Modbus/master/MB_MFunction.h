/****************************************Copyright (c)**************************************************
**                                  广州致远电子有限公司
**
**                                 http://www.21cm.com.cn
**
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			MB_MFunction.h
** Last modified Date:  2005-01-11
** Last Version:		1.0
** Descriptions:		
**
**------------------------------------------------------------------------------------------------------
** Created by:			ZhouLishan
** Created date:		2005-01-11
** Version:				1.0
** Descriptions:		
**
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/

#ifndef __MB_MFUNCTION_H
#define __MB_MFUNCTION_H

#include "stdint.h"
/*
 typedef struct __READ_PARAMET{
 	uint16_t RStartAddr;
 	uint16_t RQuantity;
 	uint16_t *DataPtr;
 }READ_PARAMET,PARAMETER_01,PARAMETER_03,PARAMETER_04,PARAMETER_16;

 typedef struct __WRITE_PARAMET{
 	uint16_t WStartAddr;
 	uint16_t WQuantity;
 	//uint8  ByteCount;
  	uint16_t *DataPtr;
 }WRITE_PARAMET;
*/

 typedef struct __RW_PARAMET{
 	uint16_t RStartAddr;
 	uint16_t RQuantity;
 	uint16_t WStartAddr;
 	uint16_t WQuantity;
  uint16_t *DataPtr;
 }RW_PARAMET,READ_PARAMET,WRITE_PARAMET;

 typedef struct __MASK_WRITE_REG{
 	uint16_t RefAddress;
 	uint16_t And_Mask;
 	uint16_t OR_Mask;
 }MASK_WRITE_REG;


#define COIL_ON 	0xff00
#define COIL_OFF 	0x0000
#endif