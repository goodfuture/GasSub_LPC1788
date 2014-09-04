#ifndef EQUIPMENTLIST_H_INCLUDED
#define EQUIPMENTLIST_H_INCLUDED

#include "Sensor.h"
#include "ucos_ii.h"

typedef struct
{
    char   testpointNo[34];
    char   location[32];
    char   sensorType[16];
    char   collectData[8];
    char   portType[8];
}TestpointShowInfo;

typedef struct Testpoint
{
    int EquipmentType;
    void               *config;             /* config info */
    Upload_Info         upload;             /* upload info */

    OS_EVENT *EquipmentSem;
    struct Testpoint* prev;
    struct Testpoint* next;

    void (*setConfig)(void *dest, void *src);
    void (*setUpload)(Upload_Info *dest, Upload_Info *src);
    void (*showAllInfo)(struct Testpoint *tp);
    Upload_Info (*getUploadInfo)(Upload_Info src);
		TestpointShowInfo (*getShowInfo)(struct Testpoint *tp);
}Testpoint;

#endif // EQUIPMENTLIST_H_INCLUDED
