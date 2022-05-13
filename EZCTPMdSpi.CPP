
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
#include "ThostFtdcMdApi.h"
#include "EZCTPMdSpi.H"
#include "EZCTP.H"
#include "EZmarketInfo.H"
#define NewVariable(x) EZmarketInfo_##x


using namespace std;
int EZCTPMdSpi::requestID = 0;

EZCTPMdSpi::EZCTPMdSpi(CThostFtdcMdApi* pMdApi, const string& Investor, const string& Broker, const string& Password) : pMdApiD(pMdApi), InvestorD(Investor), BrokerD(Broker), PasswordD(Password)
{
	EZCTPMdSpi::requestID++;
	EZAuthenStatusD = FALSE;
	EZLoginStatusD = FALSE;
	EZgetDepthMarketDataStatusD = FALSE;
}


// ---- 自定义函数 ---- //
// 连接成功应答
void EZCTPMdSpi::OnFrontConnected()
{
	cout << "=====建立网络连接成功 inside OnFrontConnected=====" << endl;
}

//账号登陆
void EZCTPMdSpi::EZLogin()
{
	CThostFtdcReqUserLoginField loginReq;
	//memset(&loginReq, 10000, sizeof(loginReq));
	EZCTPString(loginReq.UserID, InvestorD);
	EZCTPString(loginReq.BrokerID, BrokerD);
	EZCTPString(loginReq.Password, PasswordD);

	cout << "ID: " << loginReq.UserID << endl;
	cout << "Bk: " << loginReq.BrokerID << endl;

	cout << "Requested ID: " << EZCTPMdSpi::requestID << endl;
	int rtReqUserLogin = pMdApiD->ReqUserLogin(&loginReq, EZCTPMdSpi::requestID);
	switch (rtReqUserLogin)
	{
	case 0:
		cout << ">>>>>>ReqUserLogin请求成功" << endl;
		break;
	case -1:
		cout << "ReqUserLogin Network problem and failed to sent request" << endl;
		break;
	case -2:
		cout << "ReqUserLogin Qiue is too long" << endl;
		break;
	case -3:
		cout << "ReqUserLogin Requested too much" << endl;
	}
}
//EZLogin应答
void EZCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (!bResult)
	{
		cout << "=====账户登录成功=====" << endl;
		EZLoginStatusD = TRUE;
	}
	else
	{
		cerr << "返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
		EZLoginStatusD = FALSE;
	}
}
//EZLogin状态
bool EZCTPMdSpi::EZLoginStatus()
{
	return EZLoginStatusD;
}


//获取市场行情
void EZCTPMdSpi::EZgetDepthMarketData(string &InstrumentS)
{
	char* instrumentC = new char[24];
	EZCTPString(instrumentC, InstrumentS);
	int rtpDepMarData = pMdApiD->SubscribeMarketData(&instrumentC, 1);
	switch (rtpDepMarData)
	{
	case 0:
		cout << ">>>>>>SubscribeMarketData 请求成功" << endl;
		break;
	case -1:
		cout << "SubscribeMarketData Network problem and failed to sent request" << endl;
		break;
	case -2:
		cout << "SubscribeMarketData Qiue is too long" << endl;
		break;
	case -3:
		cout << "SubscribeMarketData Requested too much" << endl;
	}
}
//EZgetDepthMarketData回调
void EZCTPMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) 
{

	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (!bResult)
	{
		cout << "=====OnRspSubMarketData 成功=====" << endl;
	}
	else
	{
		cerr << "EZgetDepthMarketData返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
		EZgetDepthMarketDataStatusD = FALSE;
	}
}
//EZgetDepthMarketData状态
bool EZCTPMdSpi::EZgetDepthMarketDataStatus()
{
	return EZgetDepthMarketDataStatusD;
}
//回调并写入准备好的Market class
void  EZCTPMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) 
{
	//cout << "OnRtnDepthMarketData 成功" << endl;
	//cout << pDepthMarketData->OpenInterest << endl;
	ticker = pDepthMarketData->InstrumentID;
	//cout << ticker << endl;
	mapTest[ticker].update(pDepthMarketData);
	//cout << mapTest[ticker].getEZOpenInterest() << endl;
}

//初始化创建Market class
void EZCTPMdSpi::EZinstrumentIndex(string &tickerPass)
{
	static EZmarketInfo NewVariable(tickerPass);
	mapTest[tickerPass] = NewVariable(tickerPass);
}
//返回请求的Market class
EZmarketInfo EZCTPMdSpi::EZRspmarketData(string &tickerPass)
{
	//cout << mapTest[tickerPass].getEZOpenInterest() << endl;
	//cout <<tickerPass << endl;

	return mapTest[tickerPass];
}



// 断开连接通知
void EZCTPMdSpi::OnFrontDisconnected(int nReason)
{
	cerr << "=====网络连接断开=====" << endl;
	cerr << "错误码： " << nReason << endl;
}

// 心跳超时警告
void EZCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cerr << "=====网络心跳超时=====" << endl;
	cerr << "距上次连接时间： " << nTimeLapse << endl;
}

// 错误通知
void EZCTPMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (bResult)
		cerr << "返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
}

EZCTPMdSpi::~EZCTPMdSpi()
{
	EZCTPMdSpi::requestID--;
	cout << "Leaving: " << EZCTPMdSpi::requestID << endl;
	//leave it to end user class to handle this
}