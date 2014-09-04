#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EquipmentList.h"
#include "Sensor.h"


/* 传感器名称表 */
char SensorTable[40][16] = {
		"瓦斯", "高低浓度瓦斯", "风速", "温度", "风压",
		"负压", "水位", "粉尘", "氧气", "一氧化碳", 
		"二氧化碳", "管道瓦斯", "管道温度", "管道负压", "管道流量",
	
	  "开停", "开关", "风门", "风机", "风筒",
		"馈电", "烟雾", "", "", "",
		
		"钩数", "产量", "累计方式", "", "",
		
		"开停", "开关", "风门", "风机", "风筒",
		"馈电", "烟雾", "", "", "",
};

/* 端口表 */
char PortTable[8][16] = {
		"频率输入", "AD输入", "开关输入", "累计输入", "RS485-1",
		"RS485-2", "RS485-3", "RS485-4"
};

//extern Upload_Info netUploadData;    /* 需要通过网络上传的数据 */

void setConfig_Analogue( void* dest, void* src );     /* 配置模拟量传感器信息 */
void setConfig_Switch( void* dest, void* src );       /* 配置开关量传感器信息 */
void setConfig_Accumulate( void* dest, void* src );   /* 配置累计量传感器信息 */
void setConfig_Tristate( void* dest, void* src );     /* 配置三态开关量传感器信息 */

void setUpload(Upload_Info *dest, Upload_Info *src);  /* 获取或更改上传信息 */

void uploadData( Upload_Info *data );                 /* 网络获取需要上传的信息 */

Upload_Info 			getUploadInfo(Upload_Info src);     /* 获取上传信息 */
TestpointShowInfo getShowInfo( Testpoint *tp );       /* 获取测点显示信息 */
void showAllInfo(Testpoint *tp);                      /* 调试用：显示测点内所有信息 */

/* 由传感器编号获取传感器名称 */
char *getSensorName( INT16U sensorName )
{
		switch( sensorName / 10000 )
		{
				case SENSOR_ANALOGUE: return SensorTable[ sensorName%100-1 ];
				case SENSOR_SWITCH: return SensorTable[ sensorName%10-1+15 ];
				case SENSOR_ACCUMULATE: return SensorTable[ sensorName%10-1+25 ];
				case SENSOR_TRISTATE: return SensorTable[ sensorName%10-1+30 ];
		}
	
		return "\0";
}

/* 由端口编号获取端口名称 */
char *getPortType( INT16U portType )
{
		INT16U tp = portType / 16;
		if ( tp < 4 ) return PortTable[ tp ];
		else if ( tp < 12 ) return PortTable[4];
		else if ( tp < 20 )	return PortTable[5];
		else if ( tp < 28 ) return PortTable[6];
		else if ( tp < 36 ) return PortTable[7];
		else return "\0"; 
}

/* 获取模拟量传感器的测点显示信息 */
TestpointShowInfo getShowInfo_Analogue(Testpoint *tp)
{
    Analogue_Config     *_analogue;
    TestpointShowInfo testShow = { "\0", "\0", "\0", "\0", "\0" };

    if ( tp == NULL ) return testShow;

    _analogue = ( Analogue_Config* )tp->config;
    if ( _analogue == NULL ) return testShow;
		sprintf( testShow.location, "%s", _analogue->location );
		sprintf( testShow.sensorType, "%u", _analogue->sensorName );
		sprintf( testShow.portType, "%u", _analogue->portType );

    sprintf( testShow.testpointNo, "%u", tp->upload.testpointNo );
    sprintf( testShow.collectData, "%u", tp->upload.collectData );

    return testShow;
}

/* 获取开关量传感器的测点显示信息 */
TestpointShowInfo getShowInfo_Switch(Testpoint *tp)
{
    Switch_Config       *_switch;
    TestpointShowInfo testShow = { "\0", "\0", "\0", "\0", "\0" };

    if ( tp == NULL ) return testShow;

		_switch = ( Switch_Config* )tp->config;
		if ( _switch == NULL ) return testShow;
		sprintf( testShow.location, "%s", _switch->location );
		sprintf( testShow.sensorType, "%u", _switch->sensorName );
		sprintf( testShow.portType, "%u", _switch->portType );
	 
    sprintf( testShow.testpointNo, "%u", tp->upload.testpointNo );
    sprintf( testShow.collectData, "%u", tp->upload.collectData );

    return testShow;
}

/* 获取累计量传感器的测点显示信息 */
TestpointShowInfo getShowInfo_Accumulate(Testpoint *tp)
{
    Accumulate_Config   *_accumulate;
    TestpointShowInfo testShow = { "\0", "\0", "\0", "\0", "\0" };

    if ( tp == NULL ) return testShow;

		_accumulate = ( Accumulate_Config* )tp->config;
		if ( _accumulate == NULL ) return testShow;
		sprintf( testShow.location, "%s", _accumulate->location );
		sprintf( testShow.sensorType, "%u", _accumulate->sensorName );
		sprintf( testShow.portType, "%u", _accumulate->portType );        

    sprintf( testShow.testpointNo, "%u", tp->upload.testpointNo );
    sprintf( testShow.collectData, "%u", tp->upload.collectData );

    return testShow;
}

/* 获取三态开关量传感器的测点显示信息 */
TestpointShowInfo getShowInfo_Tristate(Testpoint *tp)
{
    Tristate_Config     *_tristate;
    TestpointShowInfo testShow = { "\0", "\0", "\0", "\0", "\0" };

    if ( tp == NULL ) return testShow;

		_tristate = ( Tristate_Config* )tp->config;
		if ( _tristate == NULL ) return testShow;
		sprintf( testShow.location, "%s", _tristate->location );
		sprintf( testShow.sensorType, "%u", _tristate->sensorName );
		sprintf( testShow.portType, "%u", _tristate->portType );

    sprintf( testShow.testpointNo, "%u", tp->upload.testpointNo );
    sprintf( testShow.collectData, "%u", tp->upload.collectData );

    return testShow;
}


/*
		Show All Config Info for Debug

*/
void showAllInfo(Testpoint *tp)
{
    Analogue_Config     *_analogue;
    Switch_Config       *_switch;
    Accumulate_Config   *_accumulate;
    Tristate_Config     *_tristate;

    if ( tp == NULL ) return;

    printf("The Upload Infomation below:\n");
    printf("testpointNo = %u\n", tp->upload.testpointNo );
    printf("collectData = %u\n", tp->upload.collectData );
    printf("sensorState = %d\n", tp->upload.sensorState );
    printf("collectTime = %s\n", tp->upload.collectTime );

    printf("The Config Infomation below:\n");
    switch( tp->EquipmentType )
    {
        case SENSOR_ANALOGUE:
            _analogue = ( Analogue_Config* )tp->config;
            if ( _analogue == NULL ) return;
            printf("testpointNo = %u\n", _analogue->testpointNo );
            printf("sensorName = %u\n",  _analogue->sensorName );
            printf("location = %s\n", _analogue->location );
            printf("portType = %u\n", _analogue->portType );
            printf("outputControl = %u\n", _analogue->outputControl );
            printf("outage : %u~%u\n", _analogue->outage.minval, _analogue->outage.maxval );
            printf("recover : %u~%u\n", _analogue->recover.minval, _analogue->recover.maxval );
            printf("alarm : %u~%u\n", _analogue->alarm.minval, _analogue->alarm.maxval );
            printf("liftAlarm : %u~%u\n", _analogue->liftAlarm.minval, _analogue->liftAlarm.maxval );
            printf("measureRange : %u~%u\n", _analogue->measureRange.minval, _analogue->measureRange.maxval );
            printf("coefficient = %.1f\n", _analogue->coefficient );
            break;

        case SENSOR_SWITCH:
            _switch = ( Switch_Config* )tp->config;
            if ( _switch == NULL ) return;
            printf("testpointNo = %u\n", _switch->testpointNo );
            printf("sensorName = %u\n",  _switch->sensorName );
            printf("location = %s\n", _switch->location );
            printf("portType = %u\n", _switch->portType );
            printf("outputControl = %u\n", _switch->outputControl );
            break;

        case SENSOR_ACCUMULATE:
            _accumulate = ( Accumulate_Config* )tp->config;
            if ( _accumulate == NULL ) return;
            printf("testpointNo = %u\n", _accumulate->testpointNo );
            printf("sensorName = %u\n",  _accumulate->sensorName );
            printf("location = %s\n", _accumulate->location );
            printf("portType = %u\n", _accumulate->portType );
            printf("measureMaxVal = %u\n", _accumulate->measureMaxVal );
            printf("coefficient = %.1f\n", _accumulate->coefficient );
            break;

        case SENSOR_TRISTATE:
            _tristate = ( Tristate_Config* )tp->config;
            if ( _tristate == NULL ) return;
            printf("testpointNo = %u\n", _tristate->testpointNo );
            printf("sensorName = %u\n",  _tristate->sensorName );
            printf("location = %s\n", _tristate->location );
            printf("portType = %u\n", _tristate->portType );
            printf("outputControl = %u\n", _tristate->outputControl );
            printf("correctRange : %u~%u\n", _tristate->correctRange.minval, _tristate->correctRange.maxval );
            break;
        default:
            break;
    }

    puts("*****************************");
    return;
}

/* 修改测点中需要上传的信息 */
void setUpload(Upload_Info *dest, Upload_Info *src)
{
    dest->collectData = src->collectData;
    dest->sensorState = src->sensorState;
    strcpy( dest->collectTime, src->collectTime );
    return;
}

/* 获取测点中需要上传的信息 */
Upload_Info getUploadInfo(Upload_Info src)
{
    return src;
}

/* 配置模拟量传感器 */
void setConfig_Analogue( void* dest, void* src )
{
    Analogue_Config *_dest, *_src;
    if ( dest == NULL || src == NULL ) return;

    _dest = ( Analogue_Config* )dest;
    _src = ( Analogue_Config* )src;

    _dest->testpointNo   = _src->testpointNo;
    _dest->sensorName    = _src->sensorName;
    _dest->portType      = _src->portType;
    _dest->outputControl = _src->outputControl;

    _dest->outage        = _src->outage;
    _dest->recover       = _src->recover;
    _dest->alarm         = _src->alarm;
    _dest->liftAlarm     = _src->liftAlarm;
    _dest->measureRange  = _src->measureRange;

    _dest->coefficient   = _src->coefficient;

    strcpy( _dest->location, _src->location );
    return;
}

/* 配置开关量传感器 */
void setConfig_Switch( void* dest, void* src )
{
    Switch_Config *_dest, *_src;
    if ( dest == NULL || src == NULL ) return;

    _dest = ( Switch_Config* )dest;
    _src  = ( Switch_Config* )src;

    _dest->testpointNo   = _src->testpointNo;
    _dest->sensorName    = _src->sensorName;
    _dest->portType      = _src->portType;
    _dest->outputControl = _src->outputControl;

    strcpy( _dest->location, _src->location );

    return;
}

/* 配置累计量传感器 */
void setConfig_Accumulate( void* dest, void* src )
{
    Accumulate_Config *_dest, *_src;
    if ( dest == NULL || src == NULL ) return;

    _dest = (Accumulate_Config *)dest;
    _src  = (Accumulate_Config *)src;

    _dest->testpointNo   = _src->testpointNo;
    _dest->sensorName    = _src->sensorName;

    _dest->portType      = _src->portType;
    _dest->measureMaxVal = _src->measureMaxVal;
    _dest->coefficient   = _src->coefficient;

    strcpy( _dest->location, _src->location );
    return;
}

/* 配置三态开关量传感器 */
void setConfig_Tristate( void* dest, void* src )
{
    Tristate_Config *_dest, *_src;
    if ( dest == NULL || src == NULL ) return;

    _dest = ( Tristate_Config * )dest;
    _src  = ( Tristate_Config * )src;

    printf("** %d %d\n", _dest->testpointNo, _src->testpointNo );

    _dest->testpointNo   = _src->testpointNo;
    _dest->sensorName    = _src->sensorName;

    _dest->portType      = _src->portType;
    _dest->outputControl = _src->outputControl;
    _dest->correctRange  = _src->correctRange;

    strcpy( _dest->location, _src->location );
    return;
}

/* 网络获取需要上传的信息 *
void uploadData( Upload_Info *data )
{
		netUploadData.testpointNo = data->testpointNo;
		netUploadData.sensorState = data->sensorState;
		netUploadData.collectData = data->collectData;
		strcpy( netUploadData.collectTime, data->collectTime );
	
		return;
}
*/