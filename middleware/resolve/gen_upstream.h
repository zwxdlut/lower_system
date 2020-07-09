/**
 * @file   gen_upstream.h
 * @author Auto generated
 * @note   Created on 2020/5/28 
 */

#ifndef __GEN_UPSTREAM_H__
#define __GEN_UPSTREAM_H__

#include <stdint.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/
/**
 * @name GB32960.
 * @{
 */
#define GB32960_ID                                              0x8000    /**< GB32960 */
#define CAR_STATUS_START_BIT                                    0         /**< ����״̬. */
#define CAR_STATUS_BIT_LEN                                      8
#define CAR_STATUS_MIN                                          0x01
#define CAR_STATUS_MAX                                          0x03
#define CHARGING_STATUS_START_BIT                               8         /**< ���״̬. */
#define CHARGING_STATUS_BIT_LEN                                 8
#define CHARGING_STATUS_MIN                                     0x01
#define CHARGING_STATUS_MAX                                     0x04
#define RUNNING_MODE_START_BIT                                  16        /**< ����ģʽ. */
#define RUNNING_MODE_BIT_LEN                                    8
#define RUNNING_MODE_MIN                                        0x01
#define RUNNING_MODE_MAX                                        0x03
#define SPEED_START_BIT                                         24        /**< ����. */
#define SPEED_BIT_LEN                                           16
#define SPEED_MIN                                               0
#define SPEED_MAX                                               2200
#define ODO_START_BIT                                           40        /**< �����. */
#define ODO_BIT_LEN                                             32
#define ODO_MIN                                                 0
#define ODO_MAX                                                 9999999
#define TOTAL_VOL_START_BIT                                     72        /**< �ܵ�ѹ. */
#define TOTAL_VOL_BIT_LEN                                       16
#define TOTAL_VOL_MIN                                           0
#define TOTAL_VOL_MAX                                           10000
#define TOTAL_CUR_START_BIT                                     88        /**< �ܵ���. */
#define TOTAL_CUR_BIT_LEN                                       16
#define TOTAL_CUR_MIN                                           0
#define TOTAL_CUR_MAX                                           20000
#define SOC_START_BIT                                           104       /**< SOC. */
#define SOC_BIT_LEN                                             8
#define SOC_MIN                                                 0
#define SOC_MAX                                                 100
#define DCDC_STATUS_START_BIT                                   112       /**< DC/DC״̬. */
#define DCDC_STATUS_BIT_LEN                                     8
#define DCDC_STATUS_MIN                                         0x01
#define DCDC_STATUS_MAX                                         0x02
#define SHIFT_START_BIT                                         120       /**< ��λ. */
#define SHIFT_BIT_LEN                                           8
#define SHIFT_MIN                                               0x00
#define SHIFT_MAX                                               0x3F
#define INSULATION_RESISTANCE_START_BIT                         128       /**< ��Ե����. */
#define INSULATION_RESISTANCE_BIT_LEN                           16
#define INSULATION_RESISTANCE_MIN                               0
#define INSULATION_RESISTANCE_MAX                               60000
#define ACCELERATROR_PEDAL_POS_START_BIT                        144       /**< ����̤��λ��. */
#define ACCELERATROR_PEDAL_POS_BIT_LEN                          8
#define ACCELERATROR_PEDAL_POS_MIN                              0
#define ACCELERATROR_PEDAL_POS_MAX                              100
#define BRAKE_PEDAL_POS_START_BIT                               152       /**< �ƶ�̤��λ��. */
#define BRAKE_PEDAL_POS_BIT_LEN                                 8
#define BRAKE_PEDAL_POS_MIN                                     0
#define BRAKE_PEDAL_POS_MAX                                     100
#define MOTOR_NUM_START_BIT                                     160       /**< �����������. */
#define MOTOR_NUM_BIT_LEN                                       8
#define MOTOR_NUM_MIN                                           1
#define MOTOR_NUM_MAX                                           1
#define MOTOR_STATUS_START_BIT                                  168       /**< �������״̬. */
#define MOTOR_STATUS_BIT_LEN                                    8
#define MOTOR_STATUS_MIN                                        0x01
#define MOTOR_STATUS_MAX                                        0x04
#define MOTOR_MCU_TEM_START_BIT                                 176       /**< ��������������¶�. */
#define MOTOR_MCU_TEM_BIT_LEN                                   8
#define MOTOR_MCU_TEM_MIN                                       0
#define MOTOR_MCU_TEM_MAX                                       250
#define MOTOR_SPEED_START_BIT                                   184       /**< �������ת��. */
#define MOTOR_SPEED_BIT_LEN                                     16
#define MOTOR_SPEED_MIN                                         0
#define MOTOR_SPEED_MAX                                         65531
#define MOTOR_TORQUE_START_BIT                                  200       /**< �������ת��. */
#define MOTOR_TORQUE_BIT_LEN                                    16
#define MOTOR_TORQUE_MIN                                        0
#define MOTOR_TORQUE_MAX                                        65531
#define MOTOR_TEM_START_BIT                                     216       /**< ��������¶�. */
#define MOTOR_TEM_BIT_LEN                                       8
#define MOTOR_TEM_MIN                                           0
#define MOTOR_TEM_MAX                                           250
#define MOTOR_MCU_VOL_START_BIT                                 224       /**< ������������������ѹ. */
#define MOTOR_MCU_VOL_BIT_LEN                                   16
#define MOTOR_MCU_VOL_MIN                                       0
#define MOTOR_MCU_VOL_MAX                                       60000
#define MOTOR_MCU_CUR_START_BIT                                 240       /**< �������������ĸ�ߵ���. */
#define MOTOR_MCU_CUR_BIT_LEN                                   16
#define MOTOR_MCU_CUR_MIN                                       0
#define MOTOR_MCU_CUR_MAX                                       20000
#define FUEL_BAT_VOL_START_BIT                                  256       /**< ȼ�ϵ�ص�ѹ. */
#define FUEL_BAT_VOL_BIT_LEN                                    16
#define FUEL_BAT_VOL_MIN                                        0
#define FUEL_BAT_VOL_MAX                                        20000
#define FUEL_BAT_CUR_START_BIT                                  272       /**< ȼ�ϵ�ص���. */
#define FUEL_BAT_CUR_BIT_LEN                                    16
#define FUEL_BAT_CUR_MIN                                        0
#define FUEL_BAT_CUR_MAX                                        20000
#define FUEL_BAT_CONSUME_RATE_START_BIT                         288       /**< ȼ��������. */
#define FUEL_BAT_CONSUME_RATE_BIT_LEN                           16
#define FUEL_BAT_CONSUME_RATE_MIN                               0
#define FUEL_BAT_CONSUME_RATE_MAX                               60000
#define FUEL_BAT_TEM_PROB_NUM_START_BIT                         304       /**< ȼ�ϵ���¶�̽�����. */
#define FUEL_BAT_TEM_PROB_NUM_BIT_LEN                           16
#define FUEL_BAT_TEM_PROB_NUM_MIN                               0
#define FUEL_BAT_TEM_PROB_NUM_MAX                               0
#define ARGON_SYS_MAX_TEM_START_BIT                             320       /**< ��ϵͳ������¶�. */
#define ARGON_SYS_MAX_TEM_BIT_LEN                               16
#define ARGON_SYS_MAX_TEM_MIN                                   0
#define ARGON_SYS_MAX_TEM_MAX                                   2400
#define ARGON_SYS_MAX_TEM_PROB_NO_START_BIT                     336       /**< ��ϵͳ������¶�̽�����. */
#define ARGON_SYS_MAX_TEM_PROB_NO_BIT_LEN                       8
#define ARGON_SYS_MAX_TEM_PROB_NO_MIN                           1
#define ARGON_SYS_MAX_TEM_PROB_NO_MAX                           252
#define HYDROGEN_MAX_DENSITY_START_BIT                          344       /**< �������Ũ��. */
#define HYDROGEN_MAX_DENSITY_BIT_LEN                            16
#define HYDROGEN_MAX_DENSITY_MIN                                0
#define HYDROGEN_MAX_DENSITY_MAX                                60000
#define HYDROGEN_MAX_DENSITY_SENSOR_NO_START_BIT                360       /**< �������Ũ�ȴ���������. */
#define HYDROGEN_MAX_DENSITY_SENSOR_NO_BIT_LEN                  8
#define HYDROGEN_MAX_DENSITY_SENSOR_NO_MIN                      1
#define HYDROGEN_MAX_DENSITY_SENSOR_NO_MAX                      252
#define HYDROGEN_MAX_PRESSURE_START_BIT                         368       /**< �������ѹ��. */
#define HYDROGEN_MAX_PRESSURE_BIT_LEN                           16
#define HYDROGEN_MAX_PRESSURE_MIN                               0
#define HYDROGEN_MAX_PRESSURE_MAX                               1000
#define HYDROGEN_MAX_PRESSURE_SENSOR_NO_START_BIT               384       /**< �������ѹ������������. */
#define HYDROGEN_MAX_PRESSURE_SENSOR_NO_BIT_LEN                 8
#define HYDROGEN_MAX_PRESSURE_SENSOR_NO_MIN                     1
#define HYDROGEN_MAX_PRESSURE_SENSOR_NO_MAX                     252
#define HIGH_PRESSURE_DCDC_STATUS_START_BIT                     392       /**< ��ѹDC/DC״̬. */
#define HIGH_PRESSURE_DCDC_STATUS_BIT_LEN                       8
#define HIGH_PRESSURE_DCDC_STATUS_MIN                           0x01
#define HIGH_PRESSURE_DCDC_STATUS_MAX                           0x02
#define ENGINE_STATUS_START_BIT                                 400       /**< ������״̬. */
#define ENGINE_STATUS_BIT_LEN                                   8
#define ENGINE_STATUS_MIN                                       0x01
#define ENGINE_STATUS_MAX                                       0x02
#define CRANKSHAFT_SPEED_START_BIT                              408       /**< ����ת��. */
#define CRANKSHAFT_SPEED_BIT_LEN                                16
#define CRANKSHAFT_SPEED_MIN                                    0
#define CRANKSHAFT_SPEED_MAX                                    60000
#define FUEL_CONSUME_RATE_START_BIT                             424       /**< ȼ��������. */
#define FUEL_CONSUME_RATE_BIT_LEN                               16
#define FUEL_CONSUME_RATE_MIN                                   0
#define FUEL_CONSUME_RATE_MAX                                   60000
#define HIGHEST_VOL_CELL_NO_START_BIT                           440       /**< ��ߵ�ѹ��ص������. */
#define HIGHEST_VOL_CELL_NO_BIT_LEN                             8
#define HIGHEST_VOL_CELL_NO_MIN                                 1
#define HIGHEST_VOL_CELL_NO_MAX                                 250
#define HIGHEST_CELL_VOL_START_BIT                              448       /**< ��ص����ѹ���ֵ. */
#define HIGHEST_CELL_VOL_BIT_LEN                                16
#define HIGHEST_CELL_VOL_MIN                                    0
#define HIGHEST_CELL_VOL_MAX                                    15000
#define LOWEST_VOL_CELL_NO_START_BIT                            464       /**< ��͵�ѹ��ص������. */
#define LOWEST_VOL_CELL_NO_BIT_LEN                              8
#define LOWEST_VOL_CELL_NO_MIN                                  1
#define LOWEST_VOL_CELL_NO_MAX                                  250
#define LOWEST_CELL_VOL_START_BIT                               472       /**< ��ص����ѹ���ֵ. */
#define LOWEST_CELL_VOL_BIT_LEN                                 16
#define LOWEST_CELL_VOL_MIN                                     0
#define LOWEST_CELL_VOL_MAX                                     15000
#define HIGHEST_TEM_PROBE_NO_START_BIT                          488       /**< ����¶�̽�����. */
#define HIGHEST_TEM_PROBE_NO_BIT_LEN                            8
#define HIGHEST_TEM_PROBE_NO_MIN                                1
#define HIGHEST_TEM_PROBE_NO_MAX                                250
#define HIGHEST_PROBE_TEM_START_BIT                             496       /**< ����¶�ֵ. */
#define HIGHEST_PROBE_TEM_BIT_LEN                               8
#define HIGHEST_PROBE_TEM_MIN                                   0
#define HIGHEST_PROBE_TEM_MAX                                   250
#define LOWEST_TEM_PROBE_NO_START_BIT                           504       /**< ����¶�̽�����. */
#define LOWEST_TEM_PROBE_NO_BIT_LEN                             8
#define LOWEST_TEM_PROBE_NO_MIN                                 1
#define LOWEST_TEM_PROBE_NO_MAX                                 250
#define LOWEST_PROBE_TEM_START_BIT                              512       /**< ����¶�ֵ. */
#define LOWEST_PROBE_TEM_BIT_LEN                                8
#define LOWEST_PROBE_TEM_MIN                                    0
#define LOWEST_PROBE_TEM_MAX                                    250
#define ALARM_HIGHEST_LEVEL_START_BIT                           520       /**< ��߱����ȼ�. */
#define ALARM_HIGHEST_LEVEL_BIT_LEN                             8
#define ALARM_HIGHEST_LEVEL_MIN                                 0x00
#define ALARM_HIGHEST_LEVEL_MAX                                 0x03
#define ALRARM_RESERVE_START_BIT                                528       /**< ͨ�ñ�����־Ԥ��. */
#define ALRARM_RESERVE_BIT_LEN                                  13
#define ALRARM_RESERVE_MIN                                      0
#define ALRARM_RESERVE_MAX                                      1
#define ALARM_TEM_DIFF_START_BIT                                541       /**< �¶Ȳ��챨��. */
#define ALARM_TEM_DIFF_BIT_LEN                                  1
#define ALARM_TEM_DIFF_MIN                                      0
#define ALARM_TEM_DIFF_MAX                                      1
#define ALARM_BAT_OVER_TEM_START_BIT                            542       /**< ��ظ��±���. */
#define ALARM_BAT_OVER_TEM_BIT_LEN                              1
#define ALARM_BAT_OVER_TEM_MIN                                  0
#define ALARM_BAT_OVER_TEM_MAX                                  1
#define ALARM_BAT_OVER_VOL_START_BIT                            543       /**< ���ش���װ�����͹�ѹ����. */
#define ALARM_BAT_OVER_VOL_BIT_LEN                              1
#define ALARM_BAT_OVER_VOL_MIN                                  0
#define ALARM_BAT_OVER_VOL_MAX                                  1
#define ALARM_BAT_UNDER_VOL_START_BIT                           544       /**< ���ش���װ������Ƿѹ����. */
#define ALARM_BAT_UNDER_VOL_BIT_LEN                             1
#define ALARM_BAT_UNDER_VOL_MIN                                 0
#define ALARM_BAT_UNDER_VOL_MAX                                 1
#define ALARM_SOC_LOW_START_BIT                                 545       /**< SOC�ͱ���. */
#define ALARM_SOC_LOW_BIT_LEN                                   1
#define ALARM_SOC_LOW_MIN                                       0
#define ALARM_SOC_LOW_MAX                                       1
#define ALARM_CELL_OVER_VOL_START_BIT                           546       /**< �����ع�ѹ����. */
#define ALARM_CELL_OVER_VOL_BIT_LEN                             1
#define ALARM_CELL_OVER_VOL_MIN                                 0
#define ALARM_CELL_OVER_VOL_MAX                                 1
#define ALARM_CELL_UNDER_VOL_START_BIT                          547       /**< ������Ƿѹ����. */
#define ALARM_CELL_UNDER_VOL_BIT_LEN                            1
#define ALARM_CELL_UNDER_VOL_MIN                                0
#define ALARM_CELL_UNDER_VOL_MAX                                1
#define ALARM_SOC_HIGH_START_BIT                                548       /**< SOC���߱���. */
#define ALARM_SOC_HIGH_BIT_LEN                                  1
#define ALARM_SOC_HIGH_MIN                                      0
#define ALARM_SOC_HIGH_MAX                                      1
#define ALARM_SOC_JUMP_START_BIT                                549       /**< SOC���䱨��. */
#define ALARM_SOC_JUMP_BIT_LEN                                  1
#define ALARM_SOC_JUMP_MIN                                      0
#define ALARM_SOC_JUMP_MAX                                      1
#define ALARM_BAT_NOT_MATCH_START_BIT                           550       /**< �ɳ�索��ϵͳ��ƥ�䱨��. */
#define ALARM_BAT_NOT_MATCH_BIT_LEN                             1
#define ALARM_BAT_NOT_MATCH_MIN                                 0
#define ALARM_BAT_NOT_MATCH_MAX                                 1
#define ALARM_CELL_CONS_DIFF_START_BIT                          551       /**< ������һ���Բ��. */
#define ALARM_CELL_CONS_DIFF_BIT_LEN                            1
#define ALARM_CELL_CONS_DIFF_MIN                                0
#define ALARM_CELL_CONS_DIFF_MAX                                1
#define ALARM_INSULATION_START_BIT                              552       /**< ��Ե����. */
#define ALARM_INSULATION_BIT_LEN                                1
#define ALARM_INSULATION_MIN                                    0
#define ALARM_INSULATION_MAX                                    1
#define ALARM_DCDC_TEM_START_BIT                                553       /**< DCDC�¶ȱ���. */
#define ALARM_DCDC_TEM_BIT_LEN                                  1
#define ALARM_DCDC_TEM_MIN                                      0
#define ALARM_DCDC_TEM_MAX                                      1
#define ALARM_BRAKE_START_BIT                                   554       /**< �ƶ�ϵͳ����. */
#define ALARM_BRAKE_BIT_LEN                                     1
#define ALARM_BRAKE_MIN                                         0
#define ALARM_BRAKE_MAX                                         1
#define ALARM_DCDC_STATUS_START_BIT                             555       /**< DCDC״̬����. */
#define ALARM_DCDC_STATUS_BIT_LEN                               1
#define ALARM_DCDC_STATUS_MIN                                   0
#define ALARM_DCDC_STATUS_MAX                                   1
#define ALARM_MOTOR_MCU_TEM_START_BIT                           556       /**< ��������������¶ȱ���. */
#define ALARM_MOTOR_MCU_TEM_BIT_LEN                             1
#define ALARM_MOTOR_MCU_TEM_MIN                                 0
#define ALARM_MOTOR_MCU_TEM_MAX                                 1
#define ALARM_HIGH_VOL_LOCK_LOOP_START_BIT                      557       /**< ��ѹ����״̬����. */
#define ALARM_HIGH_VOL_LOCK_LOOP_BIT_LEN                        1
#define ALARM_HIGH_VOL_LOCK_LOOP_MIN                            0
#define ALARM_HIGH_VOL_LOCK_LOOP_MAX                            1
#define ALARM_MOTOR_TEM_START_BIT                               558       /**< ��������¶ȱ���. */
#define ALARM_MOTOR_TEM_BIT_LEN                                 1
#define ALARM_MOTOR_TEM_MIN                                     0
#define ALARM_MOTOR_TEM_MAX                                     1
#define ALARM_BAT_OVER_CHARGE_START_BIT                         559       /**< ���ش���װ�����͹���. */
#define ALARM_BAT_OVER_CHARGE_BIT_LEN                           1
#define ALARM_BAT_OVER_CHARGE_MIN                               0
#define ALARM_BAT_OVER_CHARGE_MAX                               1
#define CELL_NUM_START_BIT                                      560       /**< ����������. */
#define CELL_NUM_BIT_LEN                                        16
#define CELL_NUM_MIN                                            0
#define CELL_NUM_MAX                                            120
#define CELL_VOL_001_START_BIT                                  576       /**< ������001��ѹ. */
#define CELL_VOL_001_BIT_LEN                                    16
#define CELL_VOL_001_MIN                                        0
#define CELL_VOL_001_MAX                                        60000
#define CELL_VOL_002_START_BIT                                  592       /**< ������002��ѹ. */
#define CELL_VOL_002_BIT_LEN                                    16
#define CELL_VOL_002_MIN                                        0
#define CELL_VOL_002_MAX                                        60000
#define CELL_VOL_003_START_BIT                                  608       /**< ������003��ѹ. */
#define CELL_VOL_003_BIT_LEN                                    16
#define CELL_VOL_003_MIN                                        0
#define CELL_VOL_003_MAX                                        60000
#define CELL_VOL_004_START_BIT                                  624       /**< ������004��ѹ. */
#define CELL_VOL_004_BIT_LEN                                    16
#define CELL_VOL_004_MIN                                        0
#define CELL_VOL_004_MAX                                        60000
#define CELL_VOL_005_START_BIT                                  640       /**< ������005��ѹ. */
#define CELL_VOL_005_BIT_LEN                                    16
#define CELL_VOL_005_MIN                                        0
#define CELL_VOL_005_MAX                                        60000
#define CELL_VOL_006_START_BIT                                  656       /**< ������006��ѹ. */
#define CELL_VOL_006_BIT_LEN                                    16
#define CELL_VOL_006_MIN                                        0
#define CELL_VOL_006_MAX                                        60000
#define CELL_VOL_007_START_BIT                                  672       /**< ������007��ѹ. */
#define CELL_VOL_007_BIT_LEN                                    16
#define CELL_VOL_007_MIN                                        0
#define CELL_VOL_007_MAX                                        60000
#define CELL_VOL_008_START_BIT                                  688       /**< ������008��ѹ. */
#define CELL_VOL_008_BIT_LEN                                    16
#define CELL_VOL_008_MIN                                        0
#define CELL_VOL_008_MAX                                        60000
#define CELL_VOL_009_START_BIT                                  704       /**< ������009��ѹ. */
#define CELL_VOL_009_BIT_LEN                                    16
#define CELL_VOL_009_MIN                                        0
#define CELL_VOL_009_MAX                                        60000
#define CELL_VOL_010_START_BIT                                  720       /**< ������010��ѹ. */
#define CELL_VOL_010_BIT_LEN                                    16
#define CELL_VOL_010_MIN                                        0
#define CELL_VOL_010_MAX                                        60000
#define CELL_VOL_011_START_BIT                                  736       /**< ������011��ѹ. */
#define CELL_VOL_011_BIT_LEN                                    16
#define CELL_VOL_011_MIN                                        0
#define CELL_VOL_011_MAX                                        60000
#define CELL_VOL_012_START_BIT                                  752       /**< ������012��ѹ. */
#define CELL_VOL_012_BIT_LEN                                    16
#define CELL_VOL_012_MIN                                        0
#define CELL_VOL_012_MAX                                        60000
#define CELL_VOL_013_START_BIT                                  768       /**< ������013��ѹ. */
#define CELL_VOL_013_BIT_LEN                                    16
#define CELL_VOL_013_MIN                                        0
#define CELL_VOL_013_MAX                                        60000
#define CELL_VOL_014_START_BIT                                  784       /**< ������014��ѹ. */
#define CELL_VOL_014_BIT_LEN                                    16
#define CELL_VOL_014_MIN                                        0
#define CELL_VOL_014_MAX                                        60000
#define CELL_VOL_015_START_BIT                                  800       /**< ������015��ѹ. */
#define CELL_VOL_015_BIT_LEN                                    16
#define CELL_VOL_015_MIN                                        0
#define CELL_VOL_015_MAX                                        60000
#define CELL_VOL_016_START_BIT                                  816       /**< ������016��ѹ. */
#define CELL_VOL_016_BIT_LEN                                    16
#define CELL_VOL_016_MIN                                        0
#define CELL_VOL_016_MAX                                        60000
#define CELL_VOL_017_START_BIT                                  832       /**< ������017��ѹ. */
#define CELL_VOL_017_BIT_LEN                                    16
#define CELL_VOL_017_MIN                                        0
#define CELL_VOL_017_MAX                                        60000
#define CELL_VOL_018_START_BIT                                  848       /**< ������018��ѹ. */
#define CELL_VOL_018_BIT_LEN                                    16
#define CELL_VOL_018_MIN                                        0
#define CELL_VOL_018_MAX                                        60000
#define CELL_VOL_019_START_BIT                                  864       /**< ������019��ѹ. */
#define CELL_VOL_019_BIT_LEN                                    16
#define CELL_VOL_019_MIN                                        0
#define CELL_VOL_019_MAX                                        60000
#define CELL_VOL_020_START_BIT                                  880       /**< ������020��ѹ. */
#define CELL_VOL_020_BIT_LEN                                    16
#define CELL_VOL_020_MIN                                        0
#define CELL_VOL_020_MAX                                        60000
#define CELL_VOL_021_START_BIT                                  896       /**< ������021��ѹ. */
#define CELL_VOL_021_BIT_LEN                                    16
#define CELL_VOL_021_MIN                                        0
#define CELL_VOL_021_MAX                                        60000
#define CELL_VOL_022_START_BIT                                  912       /**< ������022��ѹ. */
#define CELL_VOL_022_BIT_LEN                                    16
#define CELL_VOL_022_MIN                                        0
#define CELL_VOL_022_MAX                                        60000
#define CELL_VOL_023_START_BIT                                  928       /**< ������023��ѹ. */
#define CELL_VOL_023_BIT_LEN                                    16
#define CELL_VOL_023_MIN                                        0
#define CELL_VOL_023_MAX                                        60000
#define CELL_VOL_024_START_BIT                                  944       /**< ������024��ѹ. */
#define CELL_VOL_024_BIT_LEN                                    16
#define CELL_VOL_024_MIN                                        0
#define CELL_VOL_024_MAX                                        60000
#define CELL_VOL_025_START_BIT                                  960       /**< ������025��ѹ. */
#define CELL_VOL_025_BIT_LEN                                    16
#define CELL_VOL_025_MIN                                        0
#define CELL_VOL_025_MAX                                        60000
#define CELL_VOL_026_START_BIT                                  976       /**< ������026��ѹ. */
#define CELL_VOL_026_BIT_LEN                                    16
#define CELL_VOL_026_MIN                                        0
#define CELL_VOL_026_MAX                                        60000
#define CELL_VOL_027_START_BIT                                  992       /**< ������027��ѹ. */
#define CELL_VOL_027_BIT_LEN                                    16
#define CELL_VOL_027_MIN                                        0
#define CELL_VOL_027_MAX                                        60000
#define CELL_VOL_028_START_BIT                                  1008      /**< ������028��ѹ. */
#define CELL_VOL_028_BIT_LEN                                    16
#define CELL_VOL_028_MIN                                        0
#define CELL_VOL_028_MAX                                        60000
#define CELL_VOL_029_START_BIT                                  1024      /**< ������029��ѹ. */
#define CELL_VOL_029_BIT_LEN                                    16
#define CELL_VOL_029_MIN                                        0
#define CELL_VOL_029_MAX                                        60000
#define CELL_VOL_030_START_BIT                                  1040      /**< ������030��ѹ. */
#define CELL_VOL_030_BIT_LEN                                    16
#define CELL_VOL_030_MIN                                        0
#define CELL_VOL_030_MAX                                        60000
#define CELL_VOL_031_START_BIT                                  1056      /**< ������031��ѹ. */
#define CELL_VOL_031_BIT_LEN                                    16
#define CELL_VOL_031_MIN                                        0
#define CELL_VOL_031_MAX                                        60000
#define CELL_VOL_032_START_BIT                                  1072      /**< ������032��ѹ. */
#define CELL_VOL_032_BIT_LEN                                    16
#define CELL_VOL_032_MIN                                        0
#define CELL_VOL_032_MAX                                        60000
#define CELL_VOL_033_START_BIT                                  1088      /**< ������033��ѹ. */
#define CELL_VOL_033_BIT_LEN                                    16
#define CELL_VOL_033_MIN                                        0
#define CELL_VOL_033_MAX                                        60000
#define CELL_VOL_034_START_BIT                                  1104      /**< ������034��ѹ. */
#define CELL_VOL_034_BIT_LEN                                    16
#define CELL_VOL_034_MIN                                        0
#define CELL_VOL_034_MAX                                        60000
#define CELL_VOL_035_START_BIT                                  1120      /**< ������035��ѹ. */
#define CELL_VOL_035_BIT_LEN                                    16
#define CELL_VOL_035_MIN                                        0
#define CELL_VOL_035_MAX                                        60000
#define CELL_VOL_036_START_BIT                                  1136      /**< ������036��ѹ. */
#define CELL_VOL_036_BIT_LEN                                    16
#define CELL_VOL_036_MIN                                        0
#define CELL_VOL_036_MAX                                        60000
#define CELL_VOL_037_START_BIT                                  1152      /**< ������037��ѹ. */
#define CELL_VOL_037_BIT_LEN                                    16
#define CELL_VOL_037_MIN                                        0
#define CELL_VOL_037_MAX                                        60000
#define CELL_VOL_038_START_BIT                                  1168      /**< ������038��ѹ. */
#define CELL_VOL_038_BIT_LEN                                    16
#define CELL_VOL_038_MIN                                        0
#define CELL_VOL_038_MAX                                        60000
#define CELL_VOL_039_START_BIT                                  1184      /**< ������039��ѹ. */
#define CELL_VOL_039_BIT_LEN                                    16
#define CELL_VOL_039_MIN                                        0
#define CELL_VOL_039_MAX                                        60000
#define CELL_VOL_040_START_BIT                                  1200      /**< ������040��ѹ. */
#define CELL_VOL_040_BIT_LEN                                    16
#define CELL_VOL_040_MIN                                        0
#define CELL_VOL_040_MAX                                        60000
#define CELL_VOL_041_START_BIT                                  1216      /**< ������041��ѹ. */
#define CELL_VOL_041_BIT_LEN                                    16
#define CELL_VOL_041_MIN                                        0
#define CELL_VOL_041_MAX                                        60000
#define CELL_VOL_042_START_BIT                                  1232      /**< ������042��ѹ. */
#define CELL_VOL_042_BIT_LEN                                    16
#define CELL_VOL_042_MIN                                        0
#define CELL_VOL_042_MAX                                        60000
#define CELL_VOL_043_START_BIT                                  1248      /**< ������043��ѹ. */
#define CELL_VOL_043_BIT_LEN                                    16
#define CELL_VOL_043_MIN                                        0
#define CELL_VOL_043_MAX                                        60000
#define CELL_VOL_044_START_BIT                                  1264      /**< ������044��ѹ. */
#define CELL_VOL_044_BIT_LEN                                    16
#define CELL_VOL_044_MIN                                        0
#define CELL_VOL_044_MAX                                        60000
#define CELL_VOL_045_START_BIT                                  1280      /**< ������045��ѹ. */
#define CELL_VOL_045_BIT_LEN                                    16
#define CELL_VOL_045_MIN                                        0
#define CELL_VOL_045_MAX                                        60000
#define CELL_VOL_046_START_BIT                                  1296      /**< ������046��ѹ. */
#define CELL_VOL_046_BIT_LEN                                    16
#define CELL_VOL_046_MIN                                        0
#define CELL_VOL_046_MAX                                        60000
#define CELL_VOL_047_START_BIT                                  1312      /**< ������047��ѹ. */
#define CELL_VOL_047_BIT_LEN                                    16
#define CELL_VOL_047_MIN                                        0
#define CELL_VOL_047_MAX                                        60000
#define CELL_VOL_048_START_BIT                                  1328      /**< ������048��ѹ. */
#define CELL_VOL_048_BIT_LEN                                    16
#define CELL_VOL_048_MIN                                        0
#define CELL_VOL_048_MAX                                        60000
#define CELL_VOL_049_START_BIT                                  1344      /**< ������049��ѹ. */
#define CELL_VOL_049_BIT_LEN                                    16
#define CELL_VOL_049_MIN                                        0
#define CELL_VOL_049_MAX                                        60000
#define CELL_VOL_050_START_BIT                                  1360      /**< ������050��ѹ. */
#define CELL_VOL_050_BIT_LEN                                    16
#define CELL_VOL_050_MIN                                        0
#define CELL_VOL_050_MAX                                        60000
#define CELL_VOL_051_START_BIT                                  1376      /**< ������051��ѹ. */
#define CELL_VOL_051_BIT_LEN                                    16
#define CELL_VOL_051_MIN                                        0
#define CELL_VOL_051_MAX                                        60000
#define CELL_VOL_052_START_BIT                                  1392      /**< ������052��ѹ. */
#define CELL_VOL_052_BIT_LEN                                    16
#define CELL_VOL_052_MIN                                        0
#define CELL_VOL_052_MAX                                        60000
#define CELL_VOL_053_START_BIT                                  1408      /**< ������053��ѹ. */
#define CELL_VOL_053_BIT_LEN                                    16
#define CELL_VOL_053_MIN                                        0
#define CELL_VOL_053_MAX                                        60000
#define CELL_VOL_054_START_BIT                                  1424      /**< ������054��ѹ. */
#define CELL_VOL_054_BIT_LEN                                    16
#define CELL_VOL_054_MIN                                        0
#define CELL_VOL_054_MAX                                        60000
#define CELL_VOL_055_START_BIT                                  1440      /**< ������055��ѹ. */
#define CELL_VOL_055_BIT_LEN                                    16
#define CELL_VOL_055_MIN                                        0
#define CELL_VOL_055_MAX                                        60000
#define CELL_VOL_056_START_BIT                                  1456      /**< ������056��ѹ. */
#define CELL_VOL_056_BIT_LEN                                    16
#define CELL_VOL_056_MIN                                        0
#define CELL_VOL_056_MAX                                        60000
#define CELL_VOL_057_START_BIT                                  1472      /**< ������057��ѹ. */
#define CELL_VOL_057_BIT_LEN                                    16
#define CELL_VOL_057_MIN                                        0
#define CELL_VOL_057_MAX                                        60000
#define CELL_VOL_058_START_BIT                                  1488      /**< ������058��ѹ. */
#define CELL_VOL_058_BIT_LEN                                    16
#define CELL_VOL_058_MIN                                        0
#define CELL_VOL_058_MAX                                        60000
#define CELL_VOL_059_START_BIT                                  1504      /**< ������059��ѹ. */
#define CELL_VOL_059_BIT_LEN                                    16
#define CELL_VOL_059_MIN                                        0
#define CELL_VOL_059_MAX                                        60000
#define CELL_VOL_060_START_BIT                                  1520      /**< ������060��ѹ. */
#define CELL_VOL_060_BIT_LEN                                    16
#define CELL_VOL_060_MIN                                        0
#define CELL_VOL_060_MAX                                        60000
#define CELL_VOL_061_START_BIT                                  1536      /**< ������061��ѹ. */
#define CELL_VOL_061_BIT_LEN                                    16
#define CELL_VOL_061_MIN                                        0
#define CELL_VOL_061_MAX                                        60000
#define CELL_VOL_062_START_BIT                                  1552      /**< ������062��ѹ. */
#define CELL_VOL_062_BIT_LEN                                    16
#define CELL_VOL_062_MIN                                        0
#define CELL_VOL_062_MAX                                        60000
#define CELL_VOL_063_START_BIT                                  1568      /**< ������063��ѹ. */
#define CELL_VOL_063_BIT_LEN                                    16
#define CELL_VOL_063_MIN                                        0
#define CELL_VOL_063_MAX                                        60000
#define CELL_VOL_064_START_BIT                                  1584      /**< ������064��ѹ. */
#define CELL_VOL_064_BIT_LEN                                    16
#define CELL_VOL_064_MIN                                        0
#define CELL_VOL_064_MAX                                        60000
#define CELL_VOL_065_START_BIT                                  1600      /**< ������065��ѹ. */
#define CELL_VOL_065_BIT_LEN                                    16
#define CELL_VOL_065_MIN                                        0
#define CELL_VOL_065_MAX                                        60000
#define CELL_VOL_066_START_BIT                                  1616      /**< ������066��ѹ. */
#define CELL_VOL_066_BIT_LEN                                    16
#define CELL_VOL_066_MIN                                        0
#define CELL_VOL_066_MAX                                        60000
#define CELL_VOL_067_START_BIT                                  1632      /**< ������067��ѹ. */
#define CELL_VOL_067_BIT_LEN                                    16
#define CELL_VOL_067_MIN                                        0
#define CELL_VOL_067_MAX                                        60000
#define CELL_VOL_068_START_BIT                                  1648      /**< ������068��ѹ. */
#define CELL_VOL_068_BIT_LEN                                    16
#define CELL_VOL_068_MIN                                        0
#define CELL_VOL_068_MAX                                        60000
#define CELL_VOL_069_START_BIT                                  1664      /**< ������069��ѹ. */
#define CELL_VOL_069_BIT_LEN                                    16
#define CELL_VOL_069_MIN                                        0
#define CELL_VOL_069_MAX                                        60000
#define CELL_VOL_070_START_BIT                                  1680      /**< ������070��ѹ. */
#define CELL_VOL_070_BIT_LEN                                    16
#define CELL_VOL_070_MIN                                        0
#define CELL_VOL_070_MAX                                        60000
#define CELL_VOL_071_START_BIT                                  1696      /**< ������071��ѹ. */
#define CELL_VOL_071_BIT_LEN                                    16
#define CELL_VOL_071_MIN                                        0
#define CELL_VOL_071_MAX                                        60000
#define CELL_VOL_072_START_BIT                                  1712      /**< ������072��ѹ. */
#define CELL_VOL_072_BIT_LEN                                    16
#define CELL_VOL_072_MIN                                        0
#define CELL_VOL_072_MAX                                        60000
#define CELL_VOL_073_START_BIT                                  1728      /**< ������073��ѹ. */
#define CELL_VOL_073_BIT_LEN                                    16
#define CELL_VOL_073_MIN                                        0
#define CELL_VOL_073_MAX                                        60000
#define CELL_VOL_074_START_BIT                                  1744      /**< ������074��ѹ. */
#define CELL_VOL_074_BIT_LEN                                    16
#define CELL_VOL_074_MIN                                        0
#define CELL_VOL_074_MAX                                        60000
#define CELL_VOL_075_START_BIT                                  1760      /**< ������075��ѹ. */
#define CELL_VOL_075_BIT_LEN                                    16
#define CELL_VOL_075_MIN                                        0
#define CELL_VOL_075_MAX                                        60000
#define CELL_VOL_076_START_BIT                                  1776      /**< ������076��ѹ. */
#define CELL_VOL_076_BIT_LEN                                    16
#define CELL_VOL_076_MIN                                        0
#define CELL_VOL_076_MAX                                        60000
#define CELL_VOL_077_START_BIT                                  1792      /**< ������077��ѹ. */
#define CELL_VOL_077_BIT_LEN                                    16
#define CELL_VOL_077_MIN                                        0
#define CELL_VOL_077_MAX                                        60000
#define CELL_VOL_078_START_BIT                                  1808      /**< ������078��ѹ. */
#define CELL_VOL_078_BIT_LEN                                    16
#define CELL_VOL_078_MIN                                        0
#define CELL_VOL_078_MAX                                        60000
#define CELL_VOL_079_START_BIT                                  1824      /**< ������079��ѹ. */
#define CELL_VOL_079_BIT_LEN                                    16
#define CELL_VOL_079_MIN                                        0
#define CELL_VOL_079_MAX                                        60000
#define CELL_VOL_080_START_BIT                                  1840      /**< ������080��ѹ. */
#define CELL_VOL_080_BIT_LEN                                    16
#define CELL_VOL_080_MIN                                        0
#define CELL_VOL_080_MAX                                        60000
#define CELL_VOL_081_START_BIT                                  1856      /**< ������081��ѹ. */
#define CELL_VOL_081_BIT_LEN                                    16
#define CELL_VOL_081_MIN                                        0
#define CELL_VOL_081_MAX                                        60000
#define CELL_VOL_082_START_BIT                                  1872      /**< ������082��ѹ. */
#define CELL_VOL_082_BIT_LEN                                    16
#define CELL_VOL_082_MIN                                        0
#define CELL_VOL_082_MAX                                        60000
#define CELL_VOL_083_START_BIT                                  1888      /**< ������083��ѹ. */
#define CELL_VOL_083_BIT_LEN                                    16
#define CELL_VOL_083_MIN                                        0
#define CELL_VOL_083_MAX                                        60000
#define CELL_VOL_084_START_BIT                                  1904      /**< ������084��ѹ. */
#define CELL_VOL_084_BIT_LEN                                    16
#define CELL_VOL_084_MIN                                        0
#define CELL_VOL_084_MAX                                        60000
#define CELL_VOL_085_START_BIT                                  1920      /**< ������085��ѹ. */
#define CELL_VOL_085_BIT_LEN                                    16
#define CELL_VOL_085_MIN                                        0
#define CELL_VOL_085_MAX                                        60000
#define CELL_VOL_086_START_BIT                                  1936      /**< ������086��ѹ. */
#define CELL_VOL_086_BIT_LEN                                    16
#define CELL_VOL_086_MIN                                        0
#define CELL_VOL_086_MAX                                        60000
#define CELL_VOL_087_START_BIT                                  1952      /**< ������087��ѹ. */
#define CELL_VOL_087_BIT_LEN                                    16
#define CELL_VOL_087_MIN                                        0
#define CELL_VOL_087_MAX                                        60000
#define CELL_VOL_088_START_BIT                                  1968      /**< ������088��ѹ. */
#define CELL_VOL_088_BIT_LEN                                    16
#define CELL_VOL_088_MIN                                        0
#define CELL_VOL_088_MAX                                        60000
#define CELL_VOL_089_START_BIT                                  1984      /**< ������089��ѹ. */
#define CELL_VOL_089_BIT_LEN                                    16
#define CELL_VOL_089_MIN                                        0
#define CELL_VOL_089_MAX                                        60000
#define CELL_VOL_090_START_BIT                                  2000      /**< ������090��ѹ. */
#define CELL_VOL_090_BIT_LEN                                    16
#define CELL_VOL_090_MIN                                        0
#define CELL_VOL_090_MAX                                        60000
#define CELL_VOL_091_START_BIT                                  2016      /**< ������091��ѹ. */
#define CELL_VOL_091_BIT_LEN                                    16
#define CELL_VOL_091_MIN                                        0
#define CELL_VOL_091_MAX                                        60000
#define CELL_VOL_092_START_BIT                                  2032      /**< ������092��ѹ. */
#define CELL_VOL_092_BIT_LEN                                    16
#define CELL_VOL_092_MIN                                        0
#define CELL_VOL_092_MAX                                        60000
#define CELL_VOL_093_START_BIT                                  2048      /**< ������093��ѹ. */
#define CELL_VOL_093_BIT_LEN                                    16
#define CELL_VOL_093_MIN                                        0
#define CELL_VOL_093_MAX                                        60000
#define CELL_VOL_094_START_BIT                                  2064      /**< ������094��ѹ. */
#define CELL_VOL_094_BIT_LEN                                    16
#define CELL_VOL_094_MIN                                        0
#define CELL_VOL_094_MAX                                        60000
#define CELL_VOL_095_START_BIT                                  2080      /**< ������095��ѹ. */
#define CELL_VOL_095_BIT_LEN                                    16
#define CELL_VOL_095_MIN                                        0
#define CELL_VOL_095_MAX                                        60000
#define CELL_VOL_096_START_BIT                                  2096      /**< ������096��ѹ. */
#define CELL_VOL_096_BIT_LEN                                    16
#define CELL_VOL_096_MIN                                        0
#define CELL_VOL_096_MAX                                        60000
#define CELL_VOL_097_START_BIT                                  2112      /**< ������097��ѹ. */
#define CELL_VOL_097_BIT_LEN                                    16
#define CELL_VOL_097_MIN                                        0
#define CELL_VOL_097_MAX                                        60000
#define CELL_VOL_098_START_BIT                                  2128      /**< ������098��ѹ. */
#define CELL_VOL_098_BIT_LEN                                    16
#define CELL_VOL_098_MIN                                        0
#define CELL_VOL_098_MAX                                        60000
#define CELL_VOL_099_START_BIT                                  2144      /**< ������099��ѹ. */
#define CELL_VOL_099_BIT_LEN                                    16
#define CELL_VOL_099_MIN                                        0
#define CELL_VOL_099_MAX                                        60000
#define CELL_VOL_100_START_BIT                                  2160      /**< ������100��ѹ. */
#define CELL_VOL_100_BIT_LEN                                    16
#define CELL_VOL_100_MIN                                        0
#define CELL_VOL_100_MAX                                        60000
#define CELL_VOL_101_START_BIT                                  2176      /**< ������101��ѹ. */
#define CELL_VOL_101_BIT_LEN                                    16
#define CELL_VOL_101_MIN                                        0
#define CELL_VOL_101_MAX                                        60000
#define CELL_VOL_102_START_BIT                                  2192      /**< ������102��ѹ. */
#define CELL_VOL_102_BIT_LEN                                    16
#define CELL_VOL_102_MIN                                        0
#define CELL_VOL_102_MAX                                        60000
#define CELL_VOL_103_START_BIT                                  2208      /**< ������103��ѹ. */
#define CELL_VOL_103_BIT_LEN                                    16
#define CELL_VOL_103_MIN                                        0
#define CELL_VOL_103_MAX                                        60000
#define CELL_VOL_104_START_BIT                                  2224      /**< ������104��ѹ. */
#define CELL_VOL_104_BIT_LEN                                    16
#define CELL_VOL_104_MIN                                        0
#define CELL_VOL_104_MAX                                        60000
#define CELL_VOL_105_START_BIT                                  2240      /**< ������105��ѹ. */
#define CELL_VOL_105_BIT_LEN                                    16
#define CELL_VOL_105_MIN                                        0
#define CELL_VOL_105_MAX                                        60000
#define CELL_VOL_106_START_BIT                                  2256      /**< ������106��ѹ. */
#define CELL_VOL_106_BIT_LEN                                    16
#define CELL_VOL_106_MIN                                        0
#define CELL_VOL_106_MAX                                        60000
#define CELL_VOL_107_START_BIT                                  2272      /**< ������107��ѹ. */
#define CELL_VOL_107_BIT_LEN                                    16
#define CELL_VOL_107_MIN                                        0
#define CELL_VOL_107_MAX                                        60000
#define CELL_VOL_108_START_BIT                                  2288      /**< ������108��ѹ. */
#define CELL_VOL_108_BIT_LEN                                    16
#define CELL_VOL_108_MIN                                        0
#define CELL_VOL_108_MAX                                        60000
#define CELL_VOL_109_START_BIT                                  2304      /**< ������109��ѹ. */
#define CELL_VOL_109_BIT_LEN                                    16
#define CELL_VOL_109_MIN                                        0
#define CELL_VOL_109_MAX                                        60000
#define CELL_VOL_110_START_BIT                                  2320      /**< ������110��ѹ. */
#define CELL_VOL_110_BIT_LEN                                    16
#define CELL_VOL_110_MIN                                        0
#define CELL_VOL_110_MAX                                        60000
#define CELL_VOL_111_START_BIT                                  2336      /**< ������111��ѹ. */
#define CELL_VOL_111_BIT_LEN                                    16
#define CELL_VOL_111_MIN                                        0
#define CELL_VOL_111_MAX                                        60000
#define CELL_VOL_112_START_BIT                                  2352      /**< ������112��ѹ. */
#define CELL_VOL_112_BIT_LEN                                    16
#define CELL_VOL_112_MIN                                        0
#define CELL_VOL_112_MAX                                        60000
#define CELL_VOL_113_START_BIT                                  2368      /**< ������113��ѹ. */
#define CELL_VOL_113_BIT_LEN                                    16
#define CELL_VOL_113_MIN                                        0
#define CELL_VOL_113_MAX                                        60000
#define CELL_VOL_114_START_BIT                                  2384      /**< ������114��ѹ. */
#define CELL_VOL_114_BIT_LEN                                    16
#define CELL_VOL_114_MIN                                        0
#define CELL_VOL_114_MAX                                        60000
#define CELL_VOL_115_START_BIT                                  2400      /**< ������115��ѹ. */
#define CELL_VOL_115_BIT_LEN                                    16
#define CELL_VOL_115_MIN                                        0
#define CELL_VOL_115_MAX                                        60000
#define CELL_VOL_116_START_BIT                                  2416      /**< ������116��ѹ. */
#define CELL_VOL_116_BIT_LEN                                    16
#define CELL_VOL_116_MIN                                        0
#define CELL_VOL_116_MAX                                        60000
#define CELL_VOL_117_START_BIT                                  2432      /**< ������117��ѹ. */
#define CELL_VOL_117_BIT_LEN                                    16
#define CELL_VOL_117_MIN                                        0
#define CELL_VOL_117_MAX                                        60000
#define CELL_VOL_118_START_BIT                                  2448      /**< ������118��ѹ. */
#define CELL_VOL_118_BIT_LEN                                    16
#define CELL_VOL_118_MIN                                        0
#define CELL_VOL_118_MAX                                        60000
#define CELL_VOL_119_START_BIT                                  2464      /**< ������119��ѹ. */
#define CELL_VOL_119_BIT_LEN                                    16
#define CELL_VOL_119_MIN                                        0
#define CELL_VOL_119_MAX                                        60000
#define CELL_VOL_120_START_BIT                                  2480      /**< ������120��ѹ. */
#define CELL_VOL_120_BIT_LEN                                    16
#define CELL_VOL_120_MIN                                        0
#define CELL_VOL_120_MAX                                        60000
#define PROBE_TEMP_NUM_START_BIT                                2496      /**< �¶�̽�����. */
#define PROBE_TEMP_NUM_BIT_LEN                                  16
#define PROBE_TEMP_NUM_MIN                                      0
#define PROBE_TEMP_NUM_MAX                                      40
#define PROBE_TEMP_001_START_BIT                                2512      /**< ̽��001�¶�ֵ. */
#define PROBE_TEMP_001_BIT_LEN                                  8
#define PROBE_TEMP_001_MIN                                      0
#define PROBE_TEMP_001_MAX                                      250
#define PROBE_TEMP_002_START_BIT                                2520      /**< ̽��002�¶�ֵ. */
#define PROBE_TEMP_002_BIT_LEN                                  8
#define PROBE_TEMP_002_MIN                                      0
#define PROBE_TEMP_002_MAX                                      250
#define PROBE_TEMP_003_START_BIT                                2528      /**< ̽��003�¶�ֵ. */
#define PROBE_TEMP_003_BIT_LEN                                  8
#define PROBE_TEMP_003_MIN                                      0
#define PROBE_TEMP_003_MAX                                      250
#define PROBE_TEMP_004_START_BIT                                2536      /**< ̽��004�¶�ֵ. */
#define PROBE_TEMP_004_BIT_LEN                                  8
#define PROBE_TEMP_004_MIN                                      0
#define PROBE_TEMP_004_MAX                                      250
#define PROBE_TEMP_005_START_BIT                                2544      /**< ̽��005�¶�ֵ. */
#define PROBE_TEMP_005_BIT_LEN                                  8
#define PROBE_TEMP_005_MIN                                      0
#define PROBE_TEMP_005_MAX                                      250
#define PROBE_TEMP_006_START_BIT                                2552      /**< ̽��006�¶�ֵ. */
#define PROBE_TEMP_006_BIT_LEN                                  8
#define PROBE_TEMP_006_MIN                                      0
#define PROBE_TEMP_006_MAX                                      250
#define PROBE_TEMP_007_START_BIT                                2560      /**< ̽��007�¶�ֵ. */
#define PROBE_TEMP_007_BIT_LEN                                  8
#define PROBE_TEMP_007_MIN                                      0
#define PROBE_TEMP_007_MAX                                      250
#define PROBE_TEMP_008_START_BIT                                2568      /**< ̽��008�¶�ֵ. */
#define PROBE_TEMP_008_BIT_LEN                                  8
#define PROBE_TEMP_008_MIN                                      0
#define PROBE_TEMP_008_MAX                                      250
#define PROBE_TEMP_009_START_BIT                                2576      /**< ̽��009�¶�ֵ. */
#define PROBE_TEMP_009_BIT_LEN                                  8
#define PROBE_TEMP_009_MIN                                      0
#define PROBE_TEMP_009_MAX                                      250
#define PROBE_TEMP_010_START_BIT                                2584      /**< ̽��010�¶�ֵ. */
#define PROBE_TEMP_010_BIT_LEN                                  8
#define PROBE_TEMP_010_MIN                                      0
#define PROBE_TEMP_010_MAX                                      250
#define PROBE_TEMP_011_START_BIT                                2592      /**< ̽��011�¶�ֵ. */
#define PROBE_TEMP_011_BIT_LEN                                  8
#define PROBE_TEMP_011_MIN                                      0
#define PROBE_TEMP_011_MAX                                      250
#define PROBE_TEMP_012_START_BIT                                2600      /**< ̽��012�¶�ֵ. */
#define PROBE_TEMP_012_BIT_LEN                                  8
#define PROBE_TEMP_012_MIN                                      0
#define PROBE_TEMP_012_MAX                                      250
#define PROBE_TEMP_013_START_BIT                                2608      /**< ̽��013�¶�ֵ. */
#define PROBE_TEMP_013_BIT_LEN                                  8
#define PROBE_TEMP_013_MIN                                      0
#define PROBE_TEMP_013_MAX                                      250
#define PROBE_TEMP_014_START_BIT                                2616      /**< ̽��014�¶�ֵ. */
#define PROBE_TEMP_014_BIT_LEN                                  8
#define PROBE_TEMP_014_MIN                                      0
#define PROBE_TEMP_014_MAX                                      250
#define PROBE_TEMP_015_START_BIT                                2624      /**< ̽��015�¶�ֵ. */
#define PROBE_TEMP_015_BIT_LEN                                  8
#define PROBE_TEMP_015_MIN                                      0
#define PROBE_TEMP_015_MAX                                      250
#define PROBE_TEMP_016_START_BIT                                2632      /**< ̽��016�¶�ֵ. */
#define PROBE_TEMP_016_BIT_LEN                                  8
#define PROBE_TEMP_016_MIN                                      0
#define PROBE_TEMP_016_MAX                                      250
#define PROBE_TEMP_017_START_BIT                                2640      /**< ̽��017�¶�ֵ. */
#define PROBE_TEMP_017_BIT_LEN                                  8
#define PROBE_TEMP_017_MIN                                      0
#define PROBE_TEMP_017_MAX                                      250
#define PROBE_TEMP_018_START_BIT                                2648      /**< ̽��018�¶�ֵ. */
#define PROBE_TEMP_018_BIT_LEN                                  8
#define PROBE_TEMP_018_MIN                                      0
#define PROBE_TEMP_018_MAX                                      250
#define PROBE_TEMP_019_START_BIT                                2656      /**< ̽��019�¶�ֵ. */
#define PROBE_TEMP_019_BIT_LEN                                  8
#define PROBE_TEMP_019_MIN                                      0
#define PROBE_TEMP_019_MAX                                      250
#define PROBE_TEMP_020_START_BIT                                2664      /**< ̽��020�¶�ֵ. */
#define PROBE_TEMP_020_BIT_LEN                                  8
#define PROBE_TEMP_020_MIN                                      0
#define PROBE_TEMP_020_MAX                                      250
#define PROBE_TEMP_021_START_BIT                                2672      /**< ̽��021�¶�ֵ. */
#define PROBE_TEMP_021_BIT_LEN                                  8
#define PROBE_TEMP_021_MIN                                      0
#define PROBE_TEMP_021_MAX                                      250
#define PROBE_TEMP_022_START_BIT                                2680      /**< ̽��022�¶�ֵ. */
#define PROBE_TEMP_022_BIT_LEN                                  8
#define PROBE_TEMP_022_MIN                                      0
#define PROBE_TEMP_022_MAX                                      250
#define PROBE_TEMP_023_START_BIT                                2688      /**< ̽��023�¶�ֵ. */
#define PROBE_TEMP_023_BIT_LEN                                  8
#define PROBE_TEMP_023_MIN                                      0
#define PROBE_TEMP_023_MAX                                      250
#define PROBE_TEMP_024_START_BIT                                2696      /**< ̽��024�¶�ֵ. */
#define PROBE_TEMP_024_BIT_LEN                                  8
#define PROBE_TEMP_024_MIN                                      0
#define PROBE_TEMP_024_MAX                                      250
#define PROBE_TEMP_025_START_BIT                                2704      /**< ̽��025�¶�ֵ. */
#define PROBE_TEMP_025_BIT_LEN                                  8
#define PROBE_TEMP_025_MIN                                      0
#define PROBE_TEMP_025_MAX                                      250
#define PROBE_TEMP_026_START_BIT                                2712      /**< ̽��026�¶�ֵ. */
#define PROBE_TEMP_026_BIT_LEN                                  8
#define PROBE_TEMP_026_MIN                                      0
#define PROBE_TEMP_026_MAX                                      250
#define PROBE_TEMP_027_START_BIT                                2720      /**< ̽��027�¶�ֵ. */
#define PROBE_TEMP_027_BIT_LEN                                  8
#define PROBE_TEMP_027_MIN                                      0
#define PROBE_TEMP_027_MAX                                      250
#define PROBE_TEMP_028_START_BIT                                2728      /**< ̽��028�¶�ֵ. */
#define PROBE_TEMP_028_BIT_LEN                                  8
#define PROBE_TEMP_028_MIN                                      0
#define PROBE_TEMP_028_MAX                                      250
#define PROBE_TEMP_029_START_BIT                                2736      /**< ̽��029�¶�ֵ. */
#define PROBE_TEMP_029_BIT_LEN                                  8
#define PROBE_TEMP_029_MIN                                      0
#define PROBE_TEMP_029_MAX                                      250
#define PROBE_TEMP_030_START_BIT                                2744      /**< ̽��030�¶�ֵ. */
#define PROBE_TEMP_030_BIT_LEN                                  8
#define PROBE_TEMP_030_MIN                                      0
#define PROBE_TEMP_030_MAX                                      250
#define PROBE_TEMP_031_START_BIT                                2752      /**< ̽��031�¶�ֵ. */
#define PROBE_TEMP_031_BIT_LEN                                  8
#define PROBE_TEMP_031_MIN                                      0
#define PROBE_TEMP_031_MAX                                      250
#define PROBE_TEMP_032_START_BIT                                2760      /**< ̽��032�¶�ֵ. */
#define PROBE_TEMP_032_BIT_LEN                                  8
#define PROBE_TEMP_032_MIN                                      0
#define PROBE_TEMP_032_MAX                                      250
#define PROBE_TEMP_033_START_BIT                                2768      /**< ̽��033�¶�ֵ. */
#define PROBE_TEMP_033_BIT_LEN                                  8
#define PROBE_TEMP_033_MIN                                      0
#define PROBE_TEMP_033_MAX                                      250
#define PROBE_TEMP_034_START_BIT                                2776      /**< ̽��034�¶�ֵ. */
#define PROBE_TEMP_034_BIT_LEN                                  8
#define PROBE_TEMP_034_MIN                                      0
#define PROBE_TEMP_034_MAX                                      250
#define PROBE_TEMP_035_START_BIT                                2784      /**< ̽��035�¶�ֵ. */
#define PROBE_TEMP_035_BIT_LEN                                  8
#define PROBE_TEMP_035_MIN                                      0
#define PROBE_TEMP_035_MAX                                      250
#define PROBE_TEMP_036_START_BIT                                2792      /**< ̽��036�¶�ֵ. */
#define PROBE_TEMP_036_BIT_LEN                                  8
#define PROBE_TEMP_036_MIN                                      0
#define PROBE_TEMP_036_MAX                                      250
#define PROBE_TEMP_037_START_BIT                                2800      /**< ̽��037�¶�ֵ. */
#define PROBE_TEMP_037_BIT_LEN                                  8
#define PROBE_TEMP_037_MIN                                      0
#define PROBE_TEMP_037_MAX                                      250
#define PROBE_TEMP_038_START_BIT                                2808      /**< ̽��038�¶�ֵ. */
#define PROBE_TEMP_038_BIT_LEN                                  8
#define PROBE_TEMP_038_MIN                                      0
#define PROBE_TEMP_038_MAX                                      250
#define PROBE_TEMP_039_START_BIT                                2816      /**< ̽��039�¶�ֵ. */
#define PROBE_TEMP_039_BIT_LEN                                  8
#define PROBE_TEMP_039_MIN                                      0
#define PROBE_TEMP_039_MAX                                      250
#define PROBE_TEMP_040_START_BIT                                2824      /**< ̽��040�¶�ֵ. */
#define PROBE_TEMP_040_BIT_LEN                                  8
#define PROBE_TEMP_040_MIN                                      0
#define PROBE_TEMP_040_MAX                                      250
#define VCU_620_START_BIT                                       2832      /**< VCU_620h����. */
#define VCU_620_BIT_LEN                                         64
#define VCU_620_MIN                                             0
#define VCU_620_MAX                                             0xFFFFFFFFFFFFFFFF
#define VCU_623_START_BIT                                       2896      /**< VCU_623h����. */
#define VCU_623_BIT_LEN                                         64
#define VCU_623_MIN                                             0
#define VCU_623_MAX                                             0xFFFFFFFFFFFFFFFF
#define RECHARGE_START_BIT                                      2960      /**< �������. */
#define RECHARGE_BIT_LEN                                        16
#define RECHARGE_MIN                                            0
#define RECHARGE_MAX                                            65531
#define CRASH_STATUS_START_BIT                                  2976      /**< ������ײ״̬. */
#define CRASH_STATUS_BIT_LEN                                    8
#define CRASH_STATUS_MIN                                        0x00
#define CRASH_STATUS_MAX                                        0x10
#define AVG_ELE_CONSUME_START_BIT                               2984      /**< ƽ�����. */
#define AVG_ELE_CONSUME_BIT_LEN                                 8
#define AVG_ELE_CONSUME_MIN                                     0x00
#define AVG_ELE_CONSUME_MAX                                     0xFA
#define SUN_ROOF_GLASS_STATUS_START_BIT                         2992      /**< �촰����״̬. */
#define SUN_ROOF_GLASS_STATUS_BIT_LEN                           3
#define SUN_ROOF_GLASS_STATUS_MIN                               0x01
#define SUN_ROOF_GLASS_STATUS_MAX                               0x02
#define SUN_ROOF_CURTAIN_STATUS_START_BIT                       2995      /**< �촰����״̬. */
#define SUN_ROOF_CURTAIN_STATUS_BIT_LEN                         3
#define SUN_ROOF_CURTAIN_STATUS_MIN                             0x01
#define SUN_ROOF_CURTAIN_STATUS_MAX                             0x02
#define SUN_ROOF_GLASS_POS_START_BIT                            2998      /**< �촰����λ��. */
#define SUN_ROOF_GLASS_POS_BIT_LEN                              2
#define SUN_ROOF_GLASS_POS_MIN                                  0x00
#define SUN_ROOF_GLASS_POS_MAX                                  0x03
#define LF_WIN_STATUS_START_BIT                                 3000      /**< ��ǰ��״̬. */
#define LF_WIN_STATUS_BIT_LEN                                   3
#define LF_WIN_STATUS_MIN                                       0x00
#define LF_WIN_STATUS_MAX                                       0x07
#define LR_WIN_STATUS_START_BIT                                 3003      /**< ���״̬. */
#define LR_WIN_STATUS_BIT_LEN                                   3
#define LR_WIN_STATUS_MIN                                       0x00
#define LR_WIN_STATUS_MAX                                       0x07
#define RF_WIN_STATUS_START_BIT                                 3006      /**< ��ǰ��״̬. */
#define RF_WIN_STATUS_BIT_LEN                                   3
#define RF_WIN_STATUS_MIN                                       0x00
#define RF_WIN_STATUS_MAX                                       0x07
#define RR_WIN_STATUS_START_BIT                                 3009      /**< �Һ�״̬. */
#define RR_WIN_STATUS_BIT_LEN                                   3
#define RR_WIN_STATUS_MIN                                       0x00
#define RR_WIN_STATUS_MAX                                       0x07
#define LF_WIN_OPENED_VALUE_START_BIT                           3012      /**< ��ǰ������ֵ. */
#define LF_WIN_OPENED_VALUE_BIT_LEN                             7
#define LF_WIN_OPENED_VALUE_MIN                                 0
#define LF_WIN_OPENED_VALUE_MAX                                 100
#define LR_WIN_OPENED_VALUE_START_BIT                           3019      /**< ��󴰿���ֵ. */
#define LR_WIN_OPENED_VALUE_BIT_LEN                             7
#define LR_WIN_OPENED_VALUE_MIN                                 0
#define LR_WIN_OPENED_VALUE_MAX                                 100
#define RF_WIN_OPENED_VALUE_START_BIT                           3026      /**< ��ǰ������ֵ. */
#define RF_WIN_OPENED_VALUE_BIT_LEN                             7
#define RF_WIN_OPENED_VALUE_MIN                                 0
#define RF_WIN_OPENED_VALUE_MAX                                 100
#define RR_WIN_OPENED_VALUE_START_BIT                           3033      /**< ��ǰ������ֵ. */
#define RR_WIN_OPENED_VALUE_BIT_LEN                             7
#define RR_WIN_OPENED_VALUE_MIN                                 0
#define RR_WIN_OPENED_VALUE_MAX                                 100
#define OUT_TEM_START_BIT                                       3040      /**< �����¶ȣ�ƫ����-400. */
#define OUT_TEM_BIT_LEN                                         16
#define OUT_TEM_MIN                                             0
#define OUT_TEM_MAX                                             2500
#define IN_TEM_1_START_BIT                                      3056      /**< �����¶�1��ƫ����-400. */
#define IN_TEM_1_BIT_LEN                                        16
#define IN_TEM_1_MIN                                            0
#define IN_TEM_1_MAX                                            1270
#define IN_TEM_2_START_BIT                                      3072      /**< �����¶�2��ƫ����-400. */
#define IN_TEM_2_BIT_LEN                                        16
#define IN_TEM_2_MIN                                            0
#define IN_TEM_2_MAX                                            1270
#define AIR_VOLUME_1_START_BIT                                  3088      /**< ʵ�ʷ���1. */
#define AIR_VOLUME_1_BIT_LEN                                    4
#define AIR_VOLUME_1_MIN                                        0x00
#define AIR_VOLUME_1_MAX                                        0x0A
#define AIR_VOLUME_2_START_BIT                                  3092      /**< ʵ�ʷ���2. */
#define AIR_VOLUME_2_BIT_LEN                                    4
#define AIR_VOLUME_2_MIN                                        0x00
#define AIR_VOLUME_2_MAX                                        0x0A
#define BLW_STATUS_START_BIT                                    3096      /**< �ķ��״̬. */
#define BLW_STATUS_BIT_LEN                                      3
#define BLW_STATUS_MIN                                          0x00
#define BLW_STATUS_MAX                                          0x01
#define KEY_AC_START_BIT                                        3099      /**< AC����. */
#define KEY_AC_BIT_LEN                                          2
#define KEY_AC_MIN                                              0x01
#define KEY_AC_MAX                                              0x02
#define REAR_DE_FROSE_START_BIT                                 3101      /**< ���˪. */
#define REAR_DE_FROSE_BIT_LEN                                   2
#define REAR_DE_FROSE_MIN                                       0x01
#define REAR_DE_FROSE_MAX                                       0x02
#define FRONT_DE_FROSE_START_BIT                                3103      /**< ǰ��˪. */
#define FRONT_DE_FROSE_BIT_LEN                                  2
#define FRONT_DE_FROSE_MIN                                      0x01
#define FRONT_DE_FROSE_MAX                                      0x02
#define KEY_CYCLE_START_BIT                                     3105      /**< ѭ��ģʽ. */
#define KEY_CYCLE_BIT_LEN                                       2
#define KEY_CYCLE_MIN                                           0x01
#define KEY_CYCLE_MAX                                           0x02
#define KEY_MODE_START_BIT                                      3107      /**< ����ģʽ. */
#define KEY_MODE_BIT_LEN                                        3
#define KEY_MODE_MIN                                            0x01
#define KEY_MODE_MAX                                            0x03
#define LOW_BEAM_START_BIT                                      3110      /**< �����״̬. */
#define LOW_BEAM_BIT_LEN                                        2
#define LOW_BEAM_MIN                                            0x01
#define LOW_BEAM_MAX                                            0x02
#define HIGH_BEAM_START_BIT                                     3112      /**< Զ���״̬. */
#define HIGH_BEAM_BIT_LEN                                       2
#define HIGH_BEAM_MIN                                           0x01
#define HIGH_BEAM_MAX                                           0x02
#define LT_LAMP_START_BIT                                       3114      /**< ��ת��״̬. */
#define LT_LAMP_BIT_LEN                                         2
#define LT_LAMP_MIN                                             0x01
#define LT_LAMP_MAX                                             0x02
#define RT_LAMP_START_BIT                                       3116      /**< ��ת��״̬. */
#define RT_LAMP_BIT_LEN                                         2
#define RT_LAMP_MIN                                             0x01
#define RT_LAMP_MAX                                             0x02
#define POS_LAMP_START_BIT                                      3118      /**< λ�õ�״̬. */
#define POS_LAMP_BIT_LEN                                        2
#define POS_LAMP_MIN                                            0x01
#define POS_LAMP_MAX                                            0x02
#define FRONT_FOG_LAMP_START_BIT                                3120      /**< ǰ���״̬. */
#define FRONT_FOG_LAMP_BIT_LEN                                  2
#define FRONT_FOG_LAMP_MIN                                      0x01
#define FRONT_FOG_LAMP_MAX                                      0x02
#define REAR_FOG_LAMP_START_BIT                                 3122      /**< �����״̬. */
#define REAR_FOG_LAMP_BIT_LEN                                   2
#define REAR_FOG_LAMP_MIN                                       0x01
#define REAR_FOG_LAMP_MAX                                       0x02
#define LF_DOOR_STATUS_START_BIT                                3124      /**< ��ǰ��״̬. */
#define LF_DOOR_STATUS_BIT_LEN                                  1
#define LF_DOOR_STATUS_MIN                                      0x00
#define LF_DOOR_STATUS_MAX                                      0x01
#define LR_DOOR_STATUS_START_BIT                                3125      /**< �����״̬. */
#define LR_DOOR_STATUS_BIT_LEN                                  1
#define LR_DOOR_STATUS_MIN                                      0x00
#define LR_DOOR_STATUS_MAX                                      0x01
#define RF_DOOR_STATUS_START_BIT                                3126      /**< ��ǰ��״̬. */
#define RF_DOOR_STATUS_BIT_LEN                                  1
#define RF_DOOR_STATUS_MIN                                      0x00
#define RF_DOOR_STATUS_MAX                                      0x01
#define RR_DOOR_STATUS_START_BIT                                3127      /**< �Һ���״̬. */
#define RR_DOOR_STATUS_BIT_LEN                                  1
#define RR_DOOR_STATUS_MIN                                      0x00
#define RR_DOOR_STATUS_MAX                                      0x01
#define BACK_DOOR_STATUS_START_BIT                              3128      /**< ����״̬. */
#define BACK_DOOR_STATUS_BIT_LEN                                1
#define BACK_DOOR_STATUS_MIN                                    0x00
#define BACK_DOOR_STATUS_MAX                                    0x01
#define LF_DOOR_LOCK_STATUS_START_BIT                           3129      /**< ��ǰ����״̬. */
#define LF_DOOR_LOCK_STATUS_BIT_LEN                             1
#define LF_DOOR_LOCK_STATUS_MIN                                 0x00
#define LF_DOOR_LOCK_STATUS_MAX                                 0x01
#define LR_DOOR_LOCK_STATUS_START_BIT                           3130      /**< �������״̬. */
#define LR_DOOR_LOCK_STATUS_BIT_LEN                             1
#define LR_DOOR_LOCK_STATUS_MIN                                 0x00
#define LR_DOOR_LOCK_STATUS_MAX                                 0x01
#define RF_DOOR_LOCK_STATUS_START_BIT                           3131      /**< ��ǰ����״̬. */
#define RF_DOOR_LOCK_STATUS_BIT_LEN                             1
#define RF_DOOR_LOCK_STATUS_MIN                                 0x00
#define RF_DOOR_LOCK_STATUS_MAX                                 0x01
#define RR_DOOR_LOCK_STATUS_START_BIT                           3132      /**< �Һ�����״̬. */
#define RR_DOOR_LOCK_STATUS_BIT_LEN                             1
#define RR_DOOR_LOCK_STATUS_MIN                                 0x00
#define RR_DOOR_LOCK_STATUS_MAX                                 0x01
#define BACK_DOOR_LOCK_STATUS_START_BIT                         3133      /**< ������״̬. */
#define BACK_DOOR_LOCK_STATUS_BIT_LEN                           1
#define BACK_DOOR_LOCK_STATUS_MIN                               0x00
#define BACK_DOOR_LOCK_STATUS_MAX                               0x01
#define BATTERY_VOL_START_BIT                                   3134      /**< ��ƿ��ѹ�����ȣ�0.16����λ��V. */
#define BATTERY_VOL_BIT_LEN                                     7
#define BATTERY_VOL_MIN                                         0x00
#define BATTERY_VOL_MAX                                         0x71
#define BODY_GUARD_STATUS_START_BIT                             3141      /**< �������״̬. */
#define BODY_GUARD_STATUS_BIT_LEN                               2
#define BODY_GUARD_STATUS_MIN                                   0x00
#define BODY_GUARD_STATUS_MAX                                   0x03
#define PRIVATE_INFO_LOCK_START_BIT                             3143      /**< �п�������. */
#define PRIVATE_INFO_LOCK_BIT_LEN                               2
#define PRIVATE_INFO_LOCK_MIN                                   0x01
#define PRIVATE_INFO_LOCK_MAX                                   0x02
#define BRAKE_PEDAL_STATUS_VALID_START_BIT                      3145      /**< �ƶ�̤��״̬��Чֵ. */
#define BRAKE_PEDAL_STATUS_VALID_BIT_LEN                        1
#define BRAKE_PEDAL_STATUS_VALID_MIN                            0
#define BRAKE_PEDAL_STATUS_VALID_MAX                            1
#define BRAKE_PEDAL_STATUS_START_BIT                            3146      /**< �ƶ�̤��״̬. */
#define BRAKE_PEDAL_STATUS_BIT_LEN                              1
#define BRAKE_PEDAL_STATUS_MIN                                  0
#define BRAKE_PEDAL_STATUS_MAX                                  1
#define BRAKE_PEDAL_POS_VALID_START_BIT                         3147      /**< �ƶ�̤��λ����Ч��. */
#define BRAKE_PEDAL_POS_VALID_BIT_LEN                           1
#define BRAKE_PEDAL_POS_VALID_MIN                               0
#define BRAKE_PEDAL_POS_VALID_MAX                               1
#define ACCELERATROR_PEDAL_POS_VALID_START_BIT                  3148      /**< ����̤��λ����Ч��. */
#define ACCELERATROR_PEDAL_POS_VALID_BIT_LEN                    1
#define ACCELERATROR_PEDAL_POS_VALID_MIN                        0
#define ACCELERATROR_PEDAL_POS_VALID_MAX                        1
#define PADDING_START_BIT                                       3149      /**< �ֽڶ���. */
#define PADDING_BIT_LEN                                         3
#define PADDING_MIN                                             0x00
#define PADDING_MAX                                             0x7F
#define GB32960_DATA_LEN                                        394
#define GB32960_INIT_VALUES 0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x0C,0x00,0x00,0x00,0x00,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x15,0x3E,0xAA,0xA0,0x7C,0x01,0x00
/* Data on UART as follow */ 
/* AA 55 8C 01 00 80 02 03 01 00 00 00 00 00 00 00 00 00 00 00 02 0C 00 00 00 00 01 03 00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF 00 00 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 00 00 FF 00 00 FF 00 FF 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 00 00 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 FC 00 00 00 00 00 00 00 00 00 00 00 FF 15 3E AA A0 7C 01 00 */
/** @} */ /* GB32960. */

#endif /* __GEN_UPSTREAM_H__ */
