#include<stdint.h>



typedef enum
{
    HMI_Filter,
    Speed_Filter,
    Weight_Filter,
    FlowRate_Filter
}Filter_TypeDef_e;

typedef enum
{
    AI_CH0,
    AI_CH1,
    AI_CH2,
    AI_CH3,
    AI_CH4,
    AI_CH5,
    AI_CH6,
    AI_CH7,
    AI_CH8,
    AI_CH9,
    AI_CH10,
    AI_CH11,
    AI_CH12,
    AI_CH13,
    AI_CH14,
    AI_CH15
}AICH_TypeDef_e;

void LoadCellAndTacho(void);
void Calculate(void);
void LoadParameters(void);
void Calculate2(void);
void CommunicateWithDisplay(void);
void CheckStatus(void);
void GetSetPointAIN1(void);
void GetSetPointAIN2(void);
void GetSetPointAIN3(void);
void GetSetPointAIN4(void);
void FeederReady0(void);
void FeederReady1(void);
void FeederRunning0(void);
void FeederRunning1(void);
void BlockingAlarm0(void);
void BlockingAlarm1(void);
void TotalizatorPulse(void);
void BeltMisalignment0(void);
void BeltMisalignment1(void);
void WeightMax0(void);
void WeightMax1(void);
void WeightMin0(void);
void WeightMin1(void);
void WeightAlarm0(void);
void WeightAlarm1(void);
void WriteDrive(int DriveParameter);
void GetSetPoint(void);
void GetSetPointM(void);
void ModBus(void);
unsigned short CRC16 (const char *nData, unsigned int wLength);
void ZeroSpeed0(void);
void ZeroSpeed1(void);
 void LoadParametersWithOutTotal(void);
 void LoadCellIntegrationTest(void);
 float GetPotReference(void);
 float GetPotReferenceAIN1(void);
 float GetPotReferenceAIN2(void);
 float GetPotReferenceAIN3(void);
 float GetPotReferenceAIN4(void);
 float ReadTacho(void);
 void CommunicateWithModule(void);
 void LocalMode0(void);
 void LocalMode1(void);
 void initHW(void);
 void ExecutePID(void);
 uint8_t GateOpenCommand(void);
 uint8_t GateCloseCommand(void);
 uint8_t GateStopCommand(void);
 void initT32(void);
 void stop_T32(void);
 void start_T32(void);
 uint32_t restart_T32(void);
 void Out_Gate_Reference(void);
 void Gate_Open_0(void);
 void Gate_Open_1(void);
 void Gate_Close_0(void);
 void  Gate_Close_1(void);
 void Tare_Calibration(void);
 float Dynamic_Tare_Calibration(void);
  void GetDriveReference(void);
  int Get_AIN(int channel, Filter_TypeDef_e filter);
void initT45(int peroid);
uint8_t Check_Enable(void);
uint8_t Check_Drive_Healthy(void);
uint8_t Check_Zero_Speed(void);
uint8_t Check_Belt_Deviation(void);
