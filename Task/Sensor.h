#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include "os_cpu.h"

#define SENSOR_UNSURE                       0

#define SENSOR_ANALOGUE                     1
#define SENSOR_SWITCH                       2
#define SENSOR_ACCUMULATE                   3
#define SENSOR_TRISTATE                     4

#define SENSOR_METHANE                      10001
#define SENSOR_HIGH_LOW_METHANE             10002
#define SENSOR_WIND_SPEED                   10003
#define SENSOR_TEMPERATURE                  10004
#define SENSOR_WIND_PRESSURE                10005
#define SENSOR_NEGATIVE_PRESSURE            10006
#define SENSOR_WATER_LEVEL                  10007
#define SENSOR_DUST                         10008
#define SENSOR_OXYGEN                       10009
#define SENSOR_CARBON_MONOXIDE              10010
#define SENSOR_CARBON_DIOXIDE               10011
#define SENSOR_PIPE_METHANE                 10012
#define SENSOR_PIPE_TEMPERATURE             10013
#define SENSOR_PIPE_NEG_PRESSURE            10014
#define SENSOR_PIPE_FLOW                    10015

#define SENSOR_2_OPEN_OFF                   20001
#define SENSOR_2_SWITCH                     20002
#define SENSOR_2_AIR_DOOR                   20003
#define SENSOR_2_DRAUGHT_FAN                20004
#define SENSOR_2_AIR_DUCT                   20005
#define SENSOR_2_FEED                       20006
#define SENSOR_2_SMOKE                      20007

#define SENSOR_HOOK_NUM                     30001
#define SENSOR_PRODUCTION                   30002
#define SENSOR_TOTAL                        30003

#define SENSOR_3_OPEN_OFF                   40001
#define SENSOR_3_SWITCH                     40002
#define SENSOR_3_AIR_DOOR                   40003
#define SENSOR_3_DRAUGHT_FAN                40004
#define SENSOR_3_AIR_DUCT                   40005
#define SENSOR_3_FEED                       40006
#define SENSOR_3_SMOKE                      40007

typedef struct
{
    INT32U minval;
    INT32U maxval;
}Range;

typedef struct
{
    INT32U testpointNo;
    INT16U sensorName;
    char location[30];
    INT16U portType;
    INT16U outputControl;

    Range outage;
    Range recover;
    Range alarm;
    Range liftAlarm;
    Range measureRange;

    float coefficient;
}Analogue_Config;

typedef struct
{
    INT32U testpointNo;
    INT16U sensorName;
    char location[30];
    INT16U portType;
    INT16U outputControl;
}Switch_Config;

typedef struct
{
    INT32U testpointNo;
    INT16U sensorName;
    char location[30];
    INT16U portType;
    INT32U measureMaxVal;
    float coefficient;
}Accumulate_Config;

typedef struct
{
    INT32U testpointNo;
    INT16U sensorName;
    char location[30];
    INT16U portType;
    INT16U outputControl;
    Range correctRange;
}Tristate_Config;

typedef struct
{
    INT32U testpointNo;
    char collectTime[20];
    INT32U collectData;
    INT8U  sensorState;
}Upload_Info;


#endif // SENSOR_H_INCLUDED
