#ifndef _EZCTTraderSpi_H_
#define _EZCTPTraderSpi_H_

// ---- 派生的行情类 ---- //
#include <vector>
#include "ThostFtdcTraderApi.h"
#include <string.h>
#include <iostream>
#include <map>
#include "EZproductInfo.H"


using namespace std;



class EZCTPTraderSpi : public CThostFtdcTraderSpi
{
	// ---- 继承自CTP父类的回调接口并实现 ---- //
public:
	EZCTPTraderSpi(CThostFtdcTraderApi* pTraderApi, const string& Investor, const string& Broker, const string& Password, const string& AppID, const string& AuthCode);
	//登陆账号
	// 连接成功应答
	void OnFrontConnected();
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文

	//客户端认证
	void EZAuthen();
	//EZAuthen()回调
	void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//EZAuthen()状态
	bool  EZAuthenStatus();

	//账号登陆
	void EZLogin();
	//EZLogin应答
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//EZLogin状态
	bool EZLoginStatus();

	//获取持仓
	void  EZgetPosition(string InstrumentS);
	//EZgetPosition)回调
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//传导合约名字和持仓,一般用于获取全部持仓的时候
	void  EZgetPositionDataPass(string& strA, double& positionA);
	//传导持仓，一般用于传入合约，获取相应持仓
	double  EZgetPositionDataPass();
	//EZgetPosition状态
	bool EZgetPositionStatus();
	CThostFtdcInvestorPositionField *test();
	void EZinstrumentIndex(string& tickerPass);
	//返回请求的Market class
	EZproductInfo EZRspPositionData(string& tickerPass, string& LongOrShort);


	//获取市场行情
	void EZgetDepthMarketData(string InstrumentS);
	//EZgetDepthMarketData回调
	void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//传导市场总持仓量
	void EZgetDepthMarketDataPass(double& positionA);
	//EZgetDepthMarketData状态
	bool EZgetDepthMarketDataStatus();

	map<string, EZproductInfo> EZgatMap();
	//return contract list
	vector<string> EZgetVector();

	// 断开连接通知
	void OnFrontDisconnected(int nReason);

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void OnHeartBeatWarning(int nTimeLapse);

	///错误应答
	void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	~EZCTPTraderSpi();

private:
	CThostFtdcTraderApi* pTraderApiD;
	std::map<string, EZproductInfo> mapProduct;
	std::map<string, double> EZmapPosition;
	std::string ticker;
	std::string accountD;
	std::string InvestorD;
	std::string BrokerD;
	std::string PasswordD;
	std::string AuthCodeD;
	std::string AppIDD;

	std::string InstrumentIDToPassS;
	double PositionToPassI;
	double PositionToPassTI;
	double PositionToPassYI;
	int EZLongShortDirection;
	string InstrumentIDLongShort;
	string na;
	vector<string> keys;


	int DepthPositionToPassI;
	CThostFtdcInvestorPositionField  *pInvestorPositionTest;
	bool EZAuthenStatusD;
	bool EZLoginStatusD;
	bool EZPositionStatusD;
	bool EZgetDepthMarketDataStatusD;

	string instrumentA[];
	static int requestID;
	/*
	WYSArrayOfWYSString instrumentsD[WYSFuturesProductEnum::size];
	WYSArrayOfWYSCTPCallBackData dataD[WYSFuturesProductEnum::size];
	*/
};

#endif