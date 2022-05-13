#ifndef _EZCTPMdSpi_H_
#define _EZCTPMdSpi_H_

#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
#include "ThostFtdcMdApi.h"
#include "EZCTPMdSpi.H"
#include "EZCTP.H"
#include "EZmarketInfo.H"

using namespace std;



class EZCTPMdSpi : public CThostFtdcMdSpi
{
	// ---- 继承自CTP父类的回调接口并实现 ---- //
public:
	EZCTPMdSpi(CThostFtdcMdApi* pTraderApi, const string& Investor, const string& Broker, const string& Password);
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

	//账号登陆
	void EZLogin();
	//EZLogin应答
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//EZLogin状态
	bool EZLoginStatus();


	//获取市场行情
	void EZgetDepthMarketData(string& InstrumentS);
	//EZgetDepthMarketData回调
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	//EZgetDepthMarketData状态
	bool EZgetDepthMarketDataStatus();
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData);

	//建立市场合约class
	void EZinstrumentIndex(string &tickerPass);

	//返回市场数据
	EZmarketInfo EZRspmarketData(string& tickerPass);


	// 断开连接通知
	void OnFrontDisconnected(int nReason);

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void OnHeartBeatWarning(int nTimeLapse);

	///错误应答
	void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);



	~EZCTPMdSpi();

private:
	map<string, EZmarketInfo> mapTest;
	string ticker;
	CThostFtdcMdApi* pMdApiD;
	std::string accountD;
	std::string InvestorD;
	std::string BrokerD;
	std::string PasswordD;


	bool EZAuthenStatusD;
	bool EZLoginStatusD;
	bool EZgetDepthMarketDataStatusD;

	static int requestID;
};

#endif