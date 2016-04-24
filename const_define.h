#ifndef CONST_DEFINE_H
#define CONST_DEFINE_H

#define LOCAL_PATH_PREFIX "/home/program/"
#define UDISK_PATH_PREFIX "/media/pi/"
#define UDISK_LOGO_PATH  "/home/program/pic/udisk.png"
#define PRODUCE_LOGO_PATH "/home/program/pic/logo_small.png"
#define SOFT_VERSION "����汾:V1.2.6"
#define LOG_TEST

#define PEROID_LENGTH 6

enum RecoderIndex 
{ 
INDEX_TIME = 0,
INDEX_VOLTAGE_A = 1,
INDEX_VOLTAGE_B ,
INDEX_VOLTAGE_C ,
INDEX_VOLTAGE_AB ,
INDEX_VOLTAGE_BC ,
INDEX_VOLTAGE_CA ,
INDEX_CURRENT_A ,
INDEX_CURRENT_B ,
INDEX_CURRENT_C ,
INDEX_FREQUENCY,
INDEX_ACTIVEP ,
INDEX_REACTIVEP,
INDEX_APPARENTP ,
INDEX_FACTOR ,
INDEX_ENV_TEMP,
INDEX_ENV_HUMIDITY ,
INDEX_AIR_TEMP,
INDEX_AIR_PRESSURE ,
INDEX_FLOW ,
INDEX_VSP ,
INDEX_STATE ,
}; 


#endif // CONST_DEFINE_H
