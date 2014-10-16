/****************************************Copyright (c)**************************************************
**                               Guangzhou ZHIYUAN electronics Co.,LTD.
**                                     
**                                 http://www.zyinside.com
**
**--------------File Info-------------------------------------------------------------------------------
** File Name:          config.h
** Last modified Date: 2006-01-06
** Last Version:       v2.0
** Descriptions:       用户配置头文件
**
**------------------------------------------------------------------------------------------------------
** Created By:         黄绍斌
** Created date:       2005-12-31 
** Version:            v1.0
** Descriptions:       创建
**
**------------------------------------------------------------------------------------------------------
** Modified by:        甘达
** Modified date:      2006-01-06 
** Version:            v2.0
** Descriptions:       修改用于S3C2410
**
**------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:      
** Version:            
** Descriptions:        
**
********************************************************************************************************/
//这一段无需改动
#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL  		(void *)0
#endif

typedef unsigned char  uint8;                   // 无符号8位整型变量
typedef signed   char  int8;                    // 有符号8位整型变量
typedef unsigned short uint16;                  // 无符号16位整型变量
typedef signed   short int16;                   // 有符号16位整型变量
typedef unsigned int   uint32;                  // 无符号32位整型变量
typedef signed   int   int32;                   // 有符号32位整型变量
typedef float          fp32;                    // 单精度浮点数(32位长度)
typedef double         fp64;                    // 双精度浮点数(64位长度)


/********************************/
/*      uC/OS-II的特殊代码      */
/********************************/
#define     USER_USING_MODE    0x10             // 用户模式,ARM代码
                                                // 只能是0x10,0x30,0x1f,0x3f之一
//#include   "INCLUDES.H"                                        
          
                                           
/********************************/
/*        ARM的特殊代码         */
/********************************/
// 这一段无需改动
//#include    "S3C2410.h"
#include    <stdio.h>
#include    <ctype.h>
#include    <stdlib.h>
// IRQ中断向量地址表
//extern  uint32 VICVectAddr[];


/********************************/
/*      应用程序配置            */
/********************************/
#include    <stdio.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <setjmp.h>
#include    <rt_misc.h>

// 以下根据需要改动
//#include    "uart.h"
//#include    "lcddriver.h"
//#include    "target.h"
//#include    "..\..\Arm_Pc\pc.h"

/* 系统时钟宏定义，用于串口配置 */
#define     FCLK		(200*1000000)	// 系统时钟，修改此参数必须同时修改startup.s的参数
#define     HCLK		(FCLK/2)		// HCLK只能为FCLK除上1、2 
#define     PCLK		(HCLK/2)	    // PCLK只能为HCLK除上1、2 

/* 是否显示液晶背景图片 */
#define     DISP_BGPIC  0               // 非0时表示需要显示


/********************************/
/*       用户包含文件           */
/********************************/
// 以下根据需要改动
/**********************************
** ZLG/MODBUS TRU相关头文件与配置
***********************************/
#define 	UCOSII						// 在uC/OS-II下使用本必须定义该宏
#include	"MBMaster.h"					// MODBUS从机栈头文件

void IniUART1(uint32 bps);					// Modbus使用的串行口
void  UART1_Exception(void);				// Modbus使用串行口的中断服务函数

void TimersInit(void);						// Modbus使用定时器初始化
void T15_Exception(void);					// Modbus T15定时器中断服务函数
void T35_Exception(void);					// Modbus T35定时器中断服务函数
void T10ms_Exception(void);				// Modbus T10MS定时器中断服务函数


/********************************/
/*       用户定义内容           */
/********************************/
// 以下根据需要改动


/********************************************************************************************************
**                            End Of File
********************************************************************************************************/