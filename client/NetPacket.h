#ifndef __NETPACKET_H__
#define __NETPACKET_H__

typedef enum
{
	PKG_Timesyn 	= 0x00,//return the same
	PKG_UpdateExe 	= 0x01,
	PKG_Command 	= 0x03,//cmd
	PKG_BasicNew 	= 0x04,//update basic file
	PKG_BasicAuto   = 0x05,//basic feature Auto
	PKG_BasicRun    = 0x06,//basic feature Run 
	PKG_VariableAuto= 0x07,//Variable feature Auto
	PKG_OutputAuto 	= 0x08,//Output feature Auto
	PKG_UpdateXml 	= 0x09,//Update XML file
	PKG_OutputValue = 0x0A,//Set Output value
	PKG_VariableValue  = 0x0B,//Set Variable value
	PKG_PidConfig   = 0x0C,//Set pid config 
	PKG_WeekAuto 	= 0x0D,//Set week date auto 
	PKG_WeekValue   = 0x0E,//Set week date value
	PKG_YearAuto    = 0x0F,//Set year date auto
	PKG_YearValue   = 0x10,//Set year date value 
	PKG_RunTimeMap  = 0x11,//reset runtime table
	PKG_BasicSend   = 0x12,//is send local
	PKG_VariableEnable = 0x13,//Enable/Disable varaible/input/output
	PKG_UpdateTimeTable = 0x14,//update time tables
	PKG_SensorType 	= 0x15,//set sensor type
	PKG_VarStore    = 0x16,//set variable store to db
	PKG_VioRuntime  = 0x17,//set input output variable runtime 
	PKG_NewPid      = 0x18,//set new pid config 

	PKG_Updating 	= 0xA1,
	PKG_Version 	= 0xA2,
	PKG_Excuting 	= 0xA3,//cmd
	PKG_Variable 	= 0xA4,
	PKG_BoardStatus = 0xA5,//all boards status
	PKG_Dalarm 		= 0xA6,//dalarm message
	PKG_SendPid 	= 0xA7,//upload pid value
	PKG_SendLocal 	= 0xA8,//upload local variable of basic files 
	PKG_IsRunning 	= 0xA9,//upload if basic file is running status
	PKG_ErrorLine 	= 0xAA,//upload current error basic line
	PKG_IoTimeout 	= 0xAB,//io port timeout, there is a problem at that port
}NetPkg;

class NetPacket
{
protected:
    char m_data[1<<14];

public:
	NetPacket(void);

public:
	void SetLength(const int);
	void SetCommand(const int);
	void SetData(const char*, const int);
	bool MakePacket(const char*, const char, const int);
	void ShowData(void)const;
	void ShowString(void)const;

public:
	const void* GetData(void)const;
	const int GetLength(void)const;
};
#endif//__NETPACKET_H__
