/*********************************************************************************/
/*函数名称:	strmcpy()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)字符数组拷贝；				
*修改日志：
*[2006-3-6 17:07] 	Ver. 1.00
		开始编写；
		完成；										
/*										 */
/*********************************************************************************/

void strmcpy(unsigned char dest[], unsigned char src[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		dest[i] = src[i];
	}
	dest[i] = '/0';
}

/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	bitmcpy()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)开关量数组拷贝；				
*修改日志：
*[2006-3-7 14:59] 	Ver. 1.00
		开始编写；
		完成；										
/*										 */
/*********************************************************************************/

void bitmcpy(int dest[], int src[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		dest[i] = src[i];
	}
}

/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	strmcmp()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)字符数组比较；相同则返回0，不相同则返回1；				
*修改日志：
*[2006-3-6 17:41] 	Ver. 1.00
		开始编写；
		完成；										
/*										 */
/*********************************************************************************/

int strmcmp(unsigned char str1[], unsigned char str2[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(str1[i] != str2[i])
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	Datamcmp()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)浮点数组比较；相同则返回0，不相同则返回1；				
*修改日志：
*[2006-3-6 18:05] 	Ver. 1.00
		开始编写；
		完成；		
*[2006-3-9 13:52]
		加了一层括号，以前是错误的
		if(!((data1[i] - data2[i] < 0.0001) && (data1[i] - data2[i] > -0.0001)))										
/*										 */
/*********************************************************************************/

int Datamcmp(float data1[], float data2[], int count)
{
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(!((data1[i] - data2[i] < 0.0001) && (data1[i] - data2[i] > -0.0001)))
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	Bitmcmp()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)开关量数组比较；相同则返回0，不相同则返回1；				
*修改日志：
*[2006-3-6 18:10] 	Ver. 1.00
		开始编写；
		完成；										
/*										 */
/*********************************************************************************/

int Bitmcmp(int data1[], int data2[], int count) 
{ 
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(data1[i] != data2[i])
		{
			return 1;		
		}
	}
	return 0;
}

/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	GetCRC16()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)CRC16校验； 返回校验码；				
*修改日志：
*[2005-11-28 16:40] 	Ver. 1.00
		开始编写；
		完成；										
/*										 */
/*********************************************************************************/

unsigned short GetCRC16(unsigned char *puchMsg, unsigned short usDataLen) 
{ 
	/* CRC 高位字节值表 */ 
	unsigned char auchCRCHi[256] = {
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
	}; 
	
	unsigned char auchCRCLo[256] = {
	0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
	0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
	0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 
	0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
	0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
	0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
	0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
	0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
	0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
	0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
	0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
	0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
	0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
	0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
	0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
	0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
	0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
	0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
	0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
	0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
	0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
	0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
	0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
	0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
	0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
	0x43, 0x83, 0x41, 0x81, 0x80, 0x40
	};
	
	unsigned char uchCRCHi = 0xFF ; /* 高CRC字节初始化 */ 
	unsigned char uchCRCLo = 0xFF ; /* 低CRC 字节初始化 */ 
	unsigned uIndex = 0; /* CRC循环中的索引 */ 
	
	while (usDataLen--) /* 传输消息缓冲区 */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* 计算CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (unsigned short)((unsigned short)uchCRCHi << 8 | uchCRCLo) ; 
} 
/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	SendRtuCmdToModBus()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)发送ModBus RTU 指令到 Modbus Slave,加上CRC16校验码； 				
*修改日志：
*[2005-11-28 16:40] 	Ver. 1.00
		开始编写；
		完成；	
*[2006-3-1 9:02]
		返回类型改为void；										
/*										 */
/*********************************************************************************/

void SendRtuCmdToModBus(int ModPort, unsigned char cmd[], unsigned short len)
{ 
	unsigned short CRC16;
	
  	CRC16=GetCRC16(cmd,len);
  	ToComBufn(ModPort,cmd,len);
  	ToCom(ModPort, (unsigned char)(CRC16 >> 8 & 0x00FF));  	/* send CRC16 high */
  	ToCom(ModPort, (unsigned char)(CRC16 & 0x00FF));  	/* send CRC16 low */  	
}
/*****************************************************************************/


/*********************************************************************************/
/*函数名称:	ReadModBusRtuSlave()							
*输入参数：	共 8 个参数；
*输出参数：	共 5 个参数；
*返回值：	成功与否	1：成功， 2：失败；
*需储存的参数： 共 0 个参数；	
*功能介绍：	
		(1)读取ModBusRtuSlave，并解码输出反馈字符串相关内容； 
		ReadModBusRtuSlave(COMPORT1, ModAddr, ModFunction, ModByteNum, 
			ModData, &ModDataLen, ModTimeout=10, waitTime=30)		
*修改日志：
*[2005-11-28 16:40] 	Ver. 1.00
		开始编写；
		完成；	
*[2006-3-1 9:23]
		增加了int counter = 0;
		unsigned char ModBusMessage[MOD_STR_MAX_LEN];	
*[2006-3-1 13:46]		
		增加了 strmcpy(ModData, ModBusMessage + 3, ModBusIdx - 5);									
/*										 */
/*********************************************************************************/

int ReadModBusRtuSlave(int ModPort, unsigned char *ModAddr, unsigned char *ModFunction, unsigned char *ModByteNum, 
	unsigned char ModData[], unsigned char *ModDataLen, unsigned ModTimeout, unsigned waitTime)
{ 	
	unsigned char data;
  	unsigned long t;
  	int i;
	unsigned short CRC16;
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	/* for(i=0; i> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		*ModByteNum = ModBusMessage[2];
		
		strmcpy(ModData, ModBusMessage + 3, ModBusIdx - 5);	
	/*	Print(" idx%d  ", ModBusIdx - 5);	/*test*/
		/*	for(i = 3; i < ModBusIdx - 2; i++)
		{
			ModData[i - 3] = ModBusMessage[i];
		}
		ModData[i] = '/0';	
		*/
	   	*ModDataLen = ModBusIdx - 5;
	   	/*	Print("{DataLen=%d}/n/r", *ModDataLen);	*/
	   	return 1;
	}
	else 
	{
		*ModDataLen = 0;
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ResponseFromModBusRtuSlave()							
*输入参数：	共 8 个参数；
*输出参数：	共 5 个参数；
*返回值：	成功与否	1：成功， 2：失败；
*需储存的参数： 共 0 个参数；	
*功能介绍：	
		(1)写参数到ModBusRtuSlave后，ModbusRtuSlave反馈字符串；
				
*修改日志：
*[2006-3-1 12:34] 	Ver. 1.00
		开始编写；
*[2006-3-1 12:48]		
		完成；	
*[2006-3-6 16:32]
		strcpy(totalStr, ModBusMessage);
		改为 strmcpy(totalStr, ModBusMessage, ModBusIdx);										
/*										 */
/*********************************************************************************/

int ResponseFromModBusRtuSlave(int ModPort, unsigned char totalStr[], 
	unsigned char *ModAddr, unsigned char *ModFunction, unsigned short *ModDataAddr, 
	unsigned short *ModDataNum, unsigned ModTimeout, unsigned waitTime)
{ 		
	unsigned char data;
  	unsigned long t;  	
	unsigned short CRC16;	
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	strmcpy(totalStr, ModBusMessage, ModBusIdx);
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	
	if((unsigned char)(CRC16 >> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		
		*ModDataAddr = (unsigned short)((unsigned short)ModBusMessage[2] << 8 | ModBusMessage[3]);
		*ModDataNum  = (unsigned short)((unsigned short)ModBusMessage[4] << 8 | ModBusMessage[5]);
					
	   	return 1;
	}
	else 
	{
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ResponseSingleBitFromModBus()							
*输入参数：	共 8 个参数；
*输出参数：	共 5 个参数；
*返回值：	成功与否	1：成功， 2：失败；
*需储存的参数： 共 0 个参数；	
*功能介绍：	
		(1)写参数到ModBusRtuSlave后，ModbusRtuSlave反馈字符串；
				
*修改日志：
*[2006-3-7 14:40] 	Ver. 1.00
		开始编写；
*[2006-3-7 14:40]		
		完成；											
/*										 */
/*********************************************************************************/

int ResponseSingleBitFromModBus(int ModPort, unsigned char totalStr[], 
	unsigned char *ModAddr, unsigned char *ModFunction, unsigned short *ModDataAddr, 
	unsigned short *ModDataState, unsigned ModTimeout, unsigned waitTime)
{ 		
	unsigned char data;
  	unsigned long t;  	
	unsigned short CRC16;	
	int ModBusIdx = 0;
	int counter = 0;
	unsigned char ModBusMessage[MOD_STR_MAX_LEN] = {'/0'};
	
  	while((!(IsCom(ModPort)) && (counter < waitTime)))
	{
		DelayMs(1);
		counter ++;
	}
	
	StopWatchStart(MODBUS_STOP_WATCH);
  	do
  	{
  		while(IsCom(ModPort) && (ModBusIdx < MOD_STR_MAX_LEN - 1))
  		{
     			data = ReadCom(ModPort);
     			ModBusMessage[ModBusIdx ++]=data;
     			StopWatchStart(MODBUS_STOP_WATCH);
			/*     Print("[%02X]",data); */
  		}
  		StopWatchReadValue(MODBUS_STOP_WATCH, &t);
	}
     	while(t <= ModTimeout);
     	  	
  	if (ModBusIdx == 0) return 0;
  	ModBusMessage[ModBusIdx] = '/0';
  	strmcpy(totalStr, ModBusMessage, ModBusIdx);
  	StopWatchStop(MODBUS_STOP_WATCH);
     		
	
	CRC16 = GetCRC16(ModBusMessage,ModBusIdx - 2);
	
	if((unsigned char)(CRC16 >> 8 & 0x00FF) == ModBusMessage[ModBusIdx - 2] && (unsigned char)(CRC16 & 0x00FF) == ModBusMessage[ModBusIdx - 1])
	{
		*ModAddr = ModBusMessage[0];
		*ModFunction = ModBusMessage[1];
		
		*ModDataAddr = (unsigned short)((unsigned short)ModBusMessage[2] << 8 | ModBusMessage[3]);
		if(ModBusMessage[4])   *ModDataState  = 1;
		else   *ModDataState  = 0;
					
	   	return 1;
	}
	else 
	{
		return 0;
		/* CRC16 error */
	/*	Print("{CRC16 Error}/n/r");	*/
	}    
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ChangeAllParameterDataByModBus()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1) 将MODBUSSLAVE返回的数据字符转化为参数值；
		(2) void *memcpy(void *dest, const void *src, size_t n)	
		(3) 四个字符的顺序应倒一下。			
*修改日志：
*[2006-3-1 14:10] 	Ver. 1.00
		开始编写；
*[2006-3-1 14:35]
		完成；	
*[2006-3-6 15:57]
		四个字符的顺序应倒一下。													
/*										 */
/*********************************************************************************/

void ChangeAllParameterDataByModBus(float parameterData[], unsigned char ModDataBack[], unsigned short num)
{
	int i;
	char singleStr[5] = {'/0','/0','/0','/0','/0'};	
	float *pf;
        float dataf = 0;       
        int len = 4;	
        
        pf = &dataf;
        	
	for(i = 0; i < num; i ++)
	{
		singleStr[0] = ModDataBack[i * 4 + 3];
		singleStr[1] = ModDataBack[i * 4 + 2];
		singleStr[2] = ModDataBack[i * 4 + 1];
		singleStr[3] = ModDataBack[i * 4 ];
		singleStr[4] = '/0';
		memcpy(pf, singleStr, len);
		parameterData[i] = *pf;
	/*	Print("%-6.2f/t", parameterData[i]);	/*test*/
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ChangeAllButtonsDataByModBus()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1) 将MODBUSSLAVE返回的数据字符转化为按钮值；				
*修改日志：
*[2006-3-1 14:03] 	Ver. 1.00
		开始编写；	
*[2006-3-1 14:10]
		完成；											
/*										 */
/*********************************************************************************/

void ChangeAllButtonsDataByModBus(int buttonData[], unsigned char ModDataBack[], unsigned short num)
{
	unsigned char button8Data = 0;
	int i, j;
		
	for(j = 0; j < (int)(num / 8); j ++)	
	{
		button8Data = ModDataBack[j];
		for(i = 0; i < 8; i ++)
		{
			buttonData[i + j * 8] = (int)(button8Data & (int) pow(2, i)) / (int) pow(2, i);
		}
	}
	button8Data = ModDataBack[j];
	for(i = 0; i < num % 8; i ++)
	{
		buttonData[i + j * 8] = (int)(button8Data & (int) pow(2, i)) / (int) pow(2, i);
	}	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WordDataToModbusStr()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)parameterData 或AIData转化为MODBUSSLAVE的WORD值的STR； 
		(2) void *memcpy(void *dest, const void *src, size_t n)	
		(3) 四个字符的顺序应倒一下。				
*修改日志：
*[2006-3-1 14:37] 	Ver. 1.00
		开始编写；
*[2006-3-1 14:49]		
		完成；	
*[2006-3-6 15:57]
		四个字符的顺序应倒一下。									
/*										 */
/*********************************************************************************/

void WordDataToModbusStr(unsigned char writeCmdStr[], float data[], unsigned short num, unsigned short startAddr)
{
	int i;
	char singleStr[5] = {'/0','/0','/0','/0','/0'};	
	float *pf;
	unsigned char *pstr;
        float dataf = 0;       
        int len = 4;	
        
        pf = &dataf;
        pstr = singleStr;
        	
	for(i = 0; i < num; i ++)
	{
		*pf = data[i];
		memcpy(pstr, pf, len);
		writeCmdStr[startAddr + i * 4 + 3] = singleStr[0];
		writeCmdStr[startAddr + i * 4 + 2] = singleStr[1];
		writeCmdStr[startAddr + i * 4 + 1] = singleStr[2];
		writeCmdStr[startAddr + i * 4 ] = singleStr[3];		
	}	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	BitDataToModbusStr()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)data转化为MODBUSSLAVE的WORD值的STR； 				
*修改日志：
*[2006-3-1 14:51] 	Ver. 1.00
		开始编写；	
*[2006-3-1 15:02]
		完成；										
/*										 */
/*********************************************************************************/

void BitDataToModbusStr(unsigned char writeCmdStr[], int data[], unsigned short num, unsigned short startAddr)
{
	int i, j;	
	unsigned char button8Data = 0;
		
	for(j = 0; j < (int)(num / 8); j ++)	
	{
		button8Data = 0;
		for(i = 0; i < 8; i ++)
		{
			button8Data += data[i + j * 8] * (int) pow(2, i);
		}
		writeCmdStr[startAddr + j] = button8Data;
	}
	
	if(num % 8)
	{
		button8Data = 0;
		for(i = 0; i < num % 8; i ++)
		{
			button8Data += data[i + j * 8] * (int) pow(2, i);
		}
		writeCmdStr[startAddr + j] = button8Data;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ReadWordFromModBusSlave()							
*输入参数：	共 2 个参数；
*输出参数：	共 1 个参数；
*返回值：	成功与否；
*需储存的参数： 共 1 个参数；	
*功能介绍：	
		(1) 从触摸屏中读取设定参数值；
		(2) 读取指令为 01 03 HA LA HN LN HC LC；其中 01 为MODBUSSLAVE的地址，
		    03 为读连续多个WORD寄存器的功能码，HA LA 为第一个寄存器的高低位地址，
		    HN LN 为寄存器数量的高低位，HC LC 为CRC校验码；
		(3) 触摸屏reset后各个参数归零，7188检测到此状态后向除摸屏发送设定参数；
*修改日志：
*[2005-11-28 16:51] 	Ver. 1.00
		开始编写；
*[2005-11-28 18:10]		
		完成初稿，未测试；
*[2006-3-3 9:38]
		static unsigned char oldModDataBack[400];改为形参；
*[2006-3-3 17:58]
		增加int kind形参；	
*[2006-3-6 16:34]		
		strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);	
*[2006-3-9 12:33]
		去掉		
		(strmcmp(oldModDataBack, ModDataBack, ModDataLenBack))									
/*										 */
/*********************************************************************************/

int ReadWordFromModBusSlave(int kind, int comPort, float parameterData[], unsigned short num, 
	unsigned short ModDataAddr, int parameterEEPROMAddr, unsigned char oldModDataBack[])
{			
	float parameterJudge[50];	
	
	unsigned char readCmdStr[15];
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 3;
	unsigned short ModDataNum;		
	unsigned short readCmdLen = 6;
	int isReadOK = 0;	
	
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned char ModByteNumBack = 0;
	unsigned char ModDataBack[MOD_STR_MAX_LEN] = {'/0'};

	unsigned char ModDataLenBack = 0;
	
/*	unsigned short ModWord[100];	*/
	
	int parameterDecimalEEPROM[PARAMETER_DATA_NUM] = PARAMETER_DECIMAL_EEPROM;	/* adjust */
	int parameterStartAddr = 0;
	char i7188Addr[5];
	strcpy(i7188Addr, I7188_ADDRESS);		/* adjust */
	
	if(kind == 1)
	{
		strcpy(i7188Addr, I7188_ADDRESS);
	}
	else if(kind == 2)
	{
		strcpy(i7188Addr, I7188_ADDRESS_2);
	}
	else if(kind == 3)
	{
		strcpy(i7188Addr, I7188_ADDRESS_3);
	}
		
	ModDataNum = (unsigned short)num * 2;
		
	readCmdStr[0] = ModAddr;
	readCmdStr[1] = ModFunction; 
	readCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	readCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	readCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	readCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	readCmdStr[6] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, readCmdStr, readCmdLen);
		
	isReadOK = ReadModBusRtuSlave(comPort, &ModAddrBack, &ModFunctionBack, &ModByteNumBack, 
		ModDataBack, &ModDataLenBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{	
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModByteNumBack == ModDataLenBack)) 
		{
			if (ModDataNum * 2 == ModDataLenBack)		/*!!!*/
			{					
				ChangeAllParameterDataByModBus(parameterJudge, ModDataBack, num);	
			/*	Print(" %f  %f  %f /t", parameterData[0], parameterData[1],parameterData[2]);	
				Print("/n%f  %f  %f /t", parameterJudge[0], parameterJudge[1],parameterJudge[2]);	
			*/	if(parameterJudge[0] >= 0.1)		/* 以温度设定值为判断点判断正确性 */
				{
				/*	Print(" cp1.5 /n");	*/
					
					if(Datamcmp(parameterData, parameterJudge, num))
					{
						Print(" cp1.6 /n");
						ChangeAllParameterDataByModBus(parameterData, ModDataBack, num);	
					
						if(IS_RS485)  Set485DirToTransmit(COMPORT1);
						SendParameterDataToPCForwardly(COMPORT1, parameterData, i7188Addr);
						if(IS_RS485)  WaitTransmitOver(COMPORT1);
						if(IS_RS485)  {DelayMs(2); Set485DirToReceive(COMPORT1);}
					
						WriteDataToEEPROM(parameterData, parameterDecimalEEPROM, num, parameterEEPROMAddr, parameterStartAddr);
					}
					
					strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);
				}
				else
				{
					/*未初始化，发送数据以初始*/					
					WriteMultipleWordToModBusSlave(comPort, parameterData, num, ModDataAddr);
				}
			/*	Print("/n %f  %f  %f /t", parameterData[0], parameterData[1],parameterData[2]); */
			}
			return 1;
		}
		else
		{
			/*收到的字符串不匹配*/
			return 0;
		}
	}
	else
	{
		/*未收到字符串或CRC校验出错*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ReadBitFromModBusSlave()							
*输入参数：	共 2 个参数；
*输出参数：	共 1 个参数；
*返回值：	成功与否；
*需储存的参数： 共 1 个参数；	
*功能介绍：	
		(1) 从触摸屏中读取按钮值；
		(2) 读取指令为 01 01 HA LA HN LN HC LC；其中 01 为MODBUSSLAVE的地址，
		    01 为读连续多个BIT线圈的功能码，HA LA 为第一个BIT的高低位地址，
		    HN LN 为BIT数量的高低位，HC LC 为CRC校验码；
*修改日志：
*[2005-11-28 18:10] 	Ver. 1.00
		开始编写；
*[2005-11-28 18:42]		
		完成初稿，未测试；
*[2006-3-3 9:38]
		static unsigned char oldModDataBack[400];改为形参；
*[2006-3-3 17:58]
		增加int kind形参；
*[2006-3-6 16:35]
		strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);	
*[2006-3-9 12:35]
		去掉 	(strmcmp(oldModDataBack, ModDataBack, ModDataLenBack))													
/*										 */
/*********************************************************************************/

int ReadBitFromModBusSlave(int kind, int comPort, int buttonData[], unsigned short num, 
	unsigned short ModDataAddr, int buttonNVRAMAddr, unsigned char oldModDataBack[])
{	
	int buttonJudge[30];
	unsigned char readCmdStr[15];
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 1;	
	unsigned short ModDataNum;	
	unsigned short readCmdLen = 6;
	int isReadOK = 0;	
	
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned char ModByteNumBack = 0;
	unsigned char ModDataBack[300] = {'/0'};

	unsigned char ModDataLenBack = 0;
	
/*	unsigned short ModBit[100];	*/
	char i7188Addr[5];
	strcpy(i7188Addr, I7188_ADDRESS);		/* adjust */
	
	if(kind == 1)
	{
		strcpy(i7188Addr, I7188_ADDRESS);
	}
	else if(kind == 2)
	{
		strcpy(i7188Addr, I7188_ADDRESS_2);
	}
	else if(kind == 3)
	{
		strcpy(i7188Addr, I7188_ADDRESS_3);
	}
	
	ModDataNum = (unsigned short)num;
	
	readCmdStr[0] = ModAddr;
	readCmdStr[1] = ModFunction; 
	readCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	readCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	readCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	readCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	readCmdStr[6] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, readCmdStr, readCmdLen);
		
	isReadOK = ReadModBusRtuSlave(comPort, &ModAddrBack, &ModFunctionBack, &ModByteNumBack, 
		ModDataBack, &ModDataLenBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{		
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModByteNumBack == ModDataLenBack)) 
		{
			ChangeAllButtonsDataByModBus(buttonJudge, ModDataBack, num);		
							
			if(Bitmcmp(buttonData, buttonJudge, num))
			{
				ChangeAllButtonsDataByModBus(buttonData, ModDataBack, num);		
			
				if(IS_RS485)  Set485DirToTransmit(COMPORT1);
				SendButtonDataToPC(COMPORT1, buttonData, i7188Addr);	
				if(IS_RS485)  WaitTransmitOver(COMPORT1);
				if(IS_RS485)  {DelayMs(2); Set485DirToReceive(COMPORT1);}
				WriteButtonToNVRAM(buttonData, num, buttonNVRAMAddr);	
			}					
							
			strmcpy(oldModDataBack, ModDataBack, ModDataLenBack);		
					
			return 1;
		}
		else
		{
			/*收到的字符串不匹配*/
			return 1;
		}
	}
	else
	{
		/*未收到字符串或CRC校验出错*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WriteMultipleWordToModBusSlave()							
*输入参数：	共 2 个参数；
*输出参数：	共 1 个参数；
*返回值：	成功与否；
*需储存的参数： 共 1 个参数；	
*功能介绍：	
		(1) 从触摸屏中写入设定参数值；
		(2) 指令为 01 16 HA LA HN LN HD LD ...... HC LC；其中 01 为MODBUSSLAVE的地址，
		    16 为写连续多个WORD寄存器的功能码，HA LA 为第一个寄存器的高低位地址，
		    HN LN 为寄存器数量的高低位，HC LC 为CRC校验码；
		    HD LD 为数据高低位；
*修改日志：
*[2005-11-28 18:43] 	Ver. 1.00
		开始编写；
*[2006-3-1 12:20]		
		中间隔了很多时间；
		完成初稿，未测试；							
/*										 */
/*********************************************************************************/

int WriteMultipleWordToModBusSlave(int comPort, float parameterData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[MOD_STR_MAX_LEN];				/* adjust */
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 16;	
	unsigned short ModDataNum;	
	unsigned short readCmdLen;
	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[300] = {'/0'};
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataNumBack;
	
	ModDataNum = (unsigned short)num * 2;
	byteCount = (unsigned short)num * 4;
	readCmdLen = 7 + byteCount;
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	writeCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	writeCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	writeCmdStr[6] = (unsigned char)(byteCount  & 0x00FF);
	WordDataToModbusStr(writeCmdStr, parameterData, num, 7);
	writeCmdStr[7 + byteCount] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
		
	isReadOK = ResponseFromModBusRtuSlave(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataNumBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{			
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataNum == ModDataNumBack)) 
		{			
			return 1;
		}
		else
		{			
			return 0;	
		}
	}
	else
	{
		/*未收到字符串或CRC校验出错*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WriteMultipleBitToModBusSlave()							
*输入参数：	共 2 个参数；
*输出参数：	共 1 个参数；
*返回值：	成功与否；
*需储存的参数： 共 1 个参数；	
*功能介绍：	
		(1) 从触摸屏中写入BIT；
		(2) 指令为 01 15 HA LA HN LN HD LD ...... HC LC；其中 01 为MODBUSSLAVE的地址，
		    16 为读连续多个WORD寄存器的功能码，HA LA 为第一个BIT的高低位地址，
		    HN LN 为BIT数量的高低位，HC LC 为CRC校验码；
		    HD LD 为数据高低位；
*修改日志：
*[2006-3-1 12:58] 	Ver. 1.00
		开始编写；	
*[2006-3-1 13:29]
		完成；								
/*										 */
/*********************************************************************************/

int WriteMultipleBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[100];		
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 15;
	unsigned short ModDataNum;		
	unsigned short readCmdLen;
	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[300] = {'/0'};
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataNumBack;
	
	ModDataNum = (unsigned short)num;
	if(num % 8)
		byteCount = (unsigned short)(num / 8 + 1);
	else 	byteCount = (unsigned short)(num / 8);
	
	readCmdLen = 7 + byteCount;
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);
	writeCmdStr[4] = (unsigned char)(ModDataNum >> 8 & 0x00FF);
	writeCmdStr[5] = (unsigned char)(ModDataNum & 0x00FF);	
	writeCmdStr[6] = (unsigned char)(byteCount  & 0x00FF);
	BitDataToModbusStr(writeCmdStr, DOData, num, 7);
	writeCmdStr[7 + byteCount] = '/0';
	
	ClearCom(comPort);
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
		
	isReadOK = ResponseFromModBusRtuSlave(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataNumBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{	
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataNum == ModDataNumBack)) 
		{
			return 1;
		}
		else
		{
			return 0;	
		}
	}
	else
	{
		/*未收到字符串或CRC校验出错*/
		return 0;
	}
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WriteSingleBitToModBusSlave()							
*输入参数：	共 2 个参数；
*输出参数：	共 1 个参数；
*返回值：	成功与否；
*需储存的参数： 共 1 个参数；	
*功能介绍：	
		(1) 从触摸屏中写入BIT；
		(2) 指令为 01 05 HA LA HD LD ...... HC LC；其中 01 为MODBUSSLAVE的地址，
		    05 为写单个BIT功能码，HA LA 为第一个BIT的高低位地址，
		    HN LN 为BIT数量的高低位，HC LC 为CRC校验码；
		    HD LD 为数据高低位；
*修改日志：
*[2006-3-7 14:06] 	Ver. 1.00
		开始编写；	
*[2006-3-7 14:40]
		完成；	
*[2006-3-9 12:44]
		去掉了等待接收反馈的功能；									
/*										 */
/*********************************************************************************/

int WriteSingleBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	unsigned char writeCmdStr[15];		
	unsigned char ModAddr = 1;
	unsigned char ModFunction = 5;
	unsigned short ModDataState;		
	unsigned short readCmdLen = 6;
/*	int isReadOK = 0;	
	
	unsigned short byteCount;
	unsigned char totalStrBack[100];
	unsigned char ModAddrBack = 0;
	unsigned char ModFunctionBack = 0;
	unsigned short ModDataAddrBack;
	unsigned short ModDataStateBack;
*/	
	ModDataState = DOData[num];
	
	writeCmdStr[0] = ModAddr;
	writeCmdStr[1] = ModFunction; 
	writeCmdStr[2] = (unsigned char)(ModDataAddr >> 8 & 0x00FF);
	writeCmdStr[3] = (unsigned char)(ModDataAddr & 0x00FF);		
	if(ModDataState)    writeCmdStr[4] = (unsigned char)(0x00FF);
	else  	writeCmdStr[4] = (unsigned char)(0x0000);	
	writeCmdStr[5] = (unsigned char)(0x0000);
	writeCmdStr[6] = '/0';
	
/*	ClearCom(comPort);	*/
	SendRtuCmdToModBus(comPort, writeCmdStr, readCmdLen);
	return 1;
	
/*		
	isReadOK = ResponseSingleBitFromModBus(comPort, totalStrBack, 
		&ModAddrBack, &ModFunctionBack, &ModDataAddrBack, 
		&ModDataStateBack, MOD_TIMEOUT, MOD_WAITTIME);
	
	if (1 == isReadOK)
	{		
		Print("/tB %u %u   %u %u  %u %u  %u %u", ModAddr, ModAddrBack, ModFunction, ModFunctionBack, ModDataAddr, ModDataAddrBack, ModDataState, ModDataStateBack);
		if((ModAddr == ModAddrBack) && (ModFunction == ModFunctionBack) && (ModDataAddr == ModDataAddrBack)
			&& (ModDataState == ModDataStateBack)) 
		{
			Print("/tretur sB1 /t");
			return 1;
		}
		else
		{
			Print("/tretur sB0 /t");
			return 0;	
		}
	}
	else
	{
		/*未收到字符串或CRC校验出错* /
		return 0;
	}
*/	
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WriteBitByBitToModBusSlave()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	成功与否；
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1) 一个一个地将BIT写如触摸屏中；
		(2) 可能很耗时；	
*修改日志：
*[2006-3-7 14:40] 	Ver. 1.00
		开始编写；	
*[2006-3-7 14:51]
		完成；								
/*										 */
/*********************************************************************************/

int WriteBitByBitToModBusSlave(int comPort, int DOData[], int dataOld[], unsigned short num, unsigned short ModDataAddr)
{	
	int i;
	
	for(i = 0; i < num; i ++)
	{
		if(DOData[i] != dataOld[i])
		{		
			DelayMs(1);
			WriteSingleBitToModBusSlave(comPort, DOData, i, ModDataAddr + i);					
		}
	}
	return 1;
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	WriteAllBitByBitToModBusSlave()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	成功与否；
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1) 一个一个地将BIT写如触摸屏中；
		(2) 可能很耗时；	
*修改日志：
*[2006-3-9 12:52] 	Ver. 1.00
		开始编写；	
*[2006-3-9 12:52]
		完成；								
/*										 */
/*********************************************************************************/

int WriteAllBitByBitToModBusSlave(int comPort, int DOData[], unsigned short num, unsigned short ModDataAddr)
{	
	int i;
	
	for(i = 0; i < num; i ++)
	{		
		DelayMs(1);
		WriteSingleBitToModBusSlave(comPort, DOData, i, ModDataAddr + i);					
		
	}
	return 1;
}

/*-------------------------------------------------------------------------------*/


/*********************************************************************************/
/*函数名称:	ListenToTouch()							
*输入参数：	共  个参数；
*输出参数：	共  个参数；
*返回值：	无；
*需储存的参数： 共  个参数；	
*功能介绍：	
		(1)监控Touch触摸屏；
		(2) init的工作给 WriteMultipleWordToModBusSlave 是否成功。
		(3) 必须要DelayMs(50)才能使一下个response正确。
*修改日志：
*[2006-3-1 17:19] 	Ver. 1.00
		开始编写；	
*[2006-3-1 17:33]
		完成；	
*[2006-3-9 14:10]
		测试通过；								
/*										 */
/*********************************************************************************/

void ListenToTouch(int comPort, int buttonData[], float parameterData[], int DOData[], float AIData[])
{
	int kind = 1;					/* adjust */
	
	unsigned short parameterNum = PARAMETER_DATA_NUM;
	unsigned short parameterAddr = PARAMETER_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short buttonNum = BUTTON_DATA_NUM;
	unsigned short buttonAddr = BUTTON_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short DONum = DIGITAL_OUT_DATA_NUM;
	unsigned short DOAddr = DO_MODBUS_ADDR_1;	/* adjust */
	
	unsigned short AINum = ANALOG_IN_DATA_NUM;
	unsigned short AIAddr = AI_MODBUS_ADDR_1;	/* adjust */
	
	int buttonNVRAMAddr = BUTTON_ADDR_1;		/* adjust */	
	int parameterEEPROMAddr = EEPROM_BLOCK;		/* adjust */
	
	static unsigned char oldModWordBack[MOD_STR_MAX_LEN] = {'/0'};	/* 以前的str */
	static unsigned char oldModBitBack[MOD_STR_MAX_LEN] = {'/0'};
	
	static int responseFromTouch_init = 0;		/*首次初始化*/
/*	static int responseFromTouch_P = 0;
	static int responseFromTouch_Btn = 0;	
	static int oldButtonData[30] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};
	static int oldDOData[30] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};
*/	
	int response;		/*test*/
	
/*	Print("/n/n");	*/
	if(0 == responseFromTouch_init)		/* 第一次写入Touch_Btn失败重新写 */
	{	
	/*	responseFromTouch_Btn = WriteMultipleBitToModBusSlave(comPort, buttonData, buttonNum, buttonAddr);
	*/	response = WriteAllBitByBitToModBusSlave(comPort, buttonData, buttonNum, buttonAddr);		
	/*	bitmcpy(oldButtonData, buttonData, buttonNum);	*/
	}
	else
	{
		/* 读取按钮值 */
		response = ReadBitFromModBusSlave(kind, comPort, buttonData, buttonNum, buttonAddr, buttonNVRAMAddr, oldModBitBack);
	}
	DelayMs(50);
/*	Print(" rb%d", response);	*/
	
	if(0 == responseFromTouch_init)			/* 第一次写入Touch_P失败重新写 */
	{		
		responseFromTouch_init = WriteMultipleWordToModBusSlave(comPort, parameterData, parameterNum, parameterAddr);
		response = responseFromTouch_init;
	/*	responseFromTouch_P = 1;	/*test*/
	}	
	else
	{
		/* 读取设定参数 */
		response = ReadWordFromModBusSlave(kind, comPort, parameterData, parameterNum, parameterAddr, parameterEEPROMAddr, oldModWordBack);
	}
	
/*	Print(" p%d", responseFromTouch_P);
	Print(" rp%d", response);	*/
	DelayMs(2);
	/* 写入开关量 */
/*	response = WriteMultipleBitToModBusSlave(comPort, DOData, DONum, DOAddr);	
*/	
	response = WriteAllBitByBitToModBusSlave(comPort, DOData, DONum, DOAddr);
/*	bitmcpy(oldDOData, DOData, DONum);	*/
		
/*	Print(" d%d", response);	*/
	DelayMs(40);
	/* 写入采样值 */
	response = WriteMultipleWordToModBusSlave(comPort, AIData, AINum, AIAddr);
/*	Print(" a%d", response);	*/
	if(response);
}

/*-------------------------------------------------------------------------------*/

