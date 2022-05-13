#include <iostream>
#include <fstream>
#include <unordered_map>
#include "EZCTPTraderSpi.H"
#include <string.h>
#include <ctype.h>
#include <vector>
#include "EZCTP.H"
#include "EZproductInfo.H"




#define NewVariable(x) EZproductInfo_##x

using namespace std;
int EZCTPTraderSpi::requestID = 0;

EZCTPTraderSpi::EZCTPTraderSpi(CThostFtdcTraderApi* pTraderApi, const string& Investor, const string& Broker, const string& Password, const string& AppID, const string& AuthCode) : pTraderApiD(pTraderApi), InvestorD(Investor), BrokerD(Broker), PasswordD(Password), AppIDD(AppID), AuthCodeD(AuthCode)
	{
	EZCTPTraderSpi::requestID++;

	InstrumentIDToPassS = "na";
	PositionToPassI = 0;

	DepthPositionToPassI = 0;

	EZAuthenStatusD = FALSE;
	EZLoginStatusD = FALSE;
	EZPositionStatusD = FALSE;
	EZgetDepthMarketDataStatusD = FALSE;
	na = "";

	}


// ---- 自定义函数 ---- //
// 连接成功应答
void EZCTPTraderSpi::OnFrontConnected()
{
	cout << "=====建立网络连接成功 inside OnFrontConnected=====" << endl;
}

//客户端认证
void EZCTPTraderSpi::EZAuthen()
{
	CThostFtdcReqAuthenticateField pReqAu;
	//memset(&pReqAu, 0, sizeof(pReqAu));
	EZCTPString(pReqAu.BrokerID, BrokerD);
	EZCTPString(pReqAu.UserID, InvestorD);
	EZCTPString(pReqAu.AuthCode, AuthCodeD);
	EZCTPString(pReqAu.AppID, AppIDD);
	cout << "Requested ID: " << EZCTPTraderSpi::requestID << endl;
	int rt = pTraderApiD->ReqAuthenticate(&pReqAu, EZCTPTraderSpi::requestID);
	switch (rt)
	{
	case 0:
		cout << ">>>>>>发送认证请求成功>>>>>> "<< endl;
		break;
	case -1:
		cout << "ReqAuthenticate Network problem and failed to sent request" << endl;
		break;
	case -2:
		cout << "ReqAuthenticate Qiue is too long" << endl;
		break;
	case -3:
		cout << "ReqAuthenticate Requested too much" << endl;
	}
}
//EZAuthen()回调
void EZCTPTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (!bResult)
	{
		cout << "=====账户认证成功=====" << endl;
		EZAuthenStatusD = TRUE;
	}
	else
	{
		cerr << "返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
		EZAuthenStatusD = FALSE;
	}
}
//EZAuthen()状态
bool  EZCTPTraderSpi::EZAuthenStatus()
{
	return EZAuthenStatusD;
}

//账号登陆
void EZCTPTraderSpi::EZLogin()
{
	CThostFtdcReqUserLoginField loginReq;
	//memset(&loginReq, 10000, sizeof(loginReq));
	EZCTPString(loginReq.UserID, InvestorD);
	EZCTPString(loginReq.BrokerID, BrokerD);
	EZCTPString(loginReq.Password, PasswordD);

	cout << "ID: " << loginReq.UserID << endl;
	cout << "Bk: " << loginReq.BrokerID << endl;
	//	cout << "Pwd: " << loginReq.Password << endl;

	cout << "Requested ID: " << EZCTPTraderSpi::requestID << endl;
	int rt1 = pTraderApiD->ReqUserLogin(&loginReq, EZCTPTraderSpi::requestID);
	switch (rt1)
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
void EZCTPTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin,CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
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
bool EZCTPTraderSpi::EZLoginStatus()
{
	return EZLoginStatusD;
}

//获取持仓
void  EZCTPTraderSpi::EZgetPosition(string InstrumentS)
{
	CThostFtdcQryInvestorPositionField pInvPos;
	//memset(&pInvPos, 20000, sizeof(pInvPos));
	EZCTPString(pInvPos.BrokerID, BrokerD);
	EZCTPString(pInvPos.InvestorID, InvestorD);
	EZCTPString(pInvPos.InstrumentID, InstrumentS);
	int rtpInvPos = pTraderApiD->ReqQryInvestorPosition(&pInvPos, EZCTPTraderSpi::requestID);
	switch (rtpInvPos)
	{
	case 0:
		cout << ">>>>>>ReqQryInvestorPosition 请求成功" << endl;
		break;
	case -1:
		cout << "ReqQryInvestorPosition Network problem and failed to sent request" << endl;
		break;
	case -2:
		cout << "ReqQryInvestorPosition Qiue is too long" << endl;
		break;
	case -3:
		cout << "ReqQryInvestorPosition Requested too much" << endl;
	}
}
//EZgetPosition回调
void EZCTPTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (!bResult)
	{
		//cout << "=====OnRspQryInvestorPosition 成功=====" << endl;
		if (!bIsLast)
		{
			InstrumentIDToPassS = pInvestorPosition->InstrumentID;
			//cout << InstrumentIDToPassS << endl;

			EZLongShortDirection = pInvestorPosition->PosiDirection;
			//cout << EZLongShortDirection << endl;

			if (isdigit(InstrumentIDToPassS[2])) {
				if (EZLongShortDirection == 51) {
					InstrumentIDLongShort = InstrumentIDToPassS + "S";
					if (mapProduct.count(InstrumentIDLongShort) == 1) {
						mapProduct[InstrumentIDLongShort].update(pInvestorPosition);
					}
					else {
						static EZproductInfo NewVariable(InstrumentIDLongShort);
						mapProduct[InstrumentIDLongShort] = NewVariable(InstrumentIDLongShort);
					}
				}
				else {
					InstrumentIDLongShort = InstrumentIDToPassS + "L";
					if (mapProduct.count(InstrumentIDLongShort) == 1) {
						mapProduct[InstrumentIDLongShort].update(pInvestorPosition);
					}
					else {
						static EZproductInfo NewVariable(InstrumentIDLongShort);
						mapProduct[InstrumentIDLongShort] = NewVariable(InstrumentIDLongShort);
					}
				}
			}
			else
			{
				//cout << "not an instrument" << endl;
			}
		}
		else
		{
			InstrumentIDToPassS = pInvestorPosition->InstrumentID;
			//cout << InstrumentIDToPassS << endl;
			EZLongShortDirection = pInvestorPosition->PosiDirection;
			//cout << EZLongShortDirection << endl;
			if (isdigit(InstrumentIDToPassS[2])) {
				if (EZLongShortDirection == 51) {
					InstrumentIDLongShort = InstrumentIDToPassS + "S";
					if (mapProduct.count(InstrumentIDLongShort) == 1) {
						mapProduct[InstrumentIDLongShort].update(pInvestorPosition);
					}
					else {
						static EZproductInfo NewVariable(InstrumentIDLongShort);
						mapProduct[InstrumentIDLongShort] = NewVariable(InstrumentIDLongShort);
					}
				}
				else {
					InstrumentIDLongShort = InstrumentIDToPassS + "L";
					if (mapProduct.count(InstrumentIDLongShort) == 1) {
						mapProduct[InstrumentIDLongShort].update(pInvestorPosition);
					}
					else {
						static EZproductInfo NewVariable(InstrumentIDLongShort);
						mapProduct[InstrumentIDLongShort] = NewVariable(InstrumentIDLongShort);
					}
				}
			}
			else
			{
				//cout << "not an instrument" << endl;
			}
			CThostFtdcQryInvestorPositionField pInvPos1;
			////memset(&pInvPos, 20000, sizeof(pInvPos));
			EZCTPString(pInvPos1.BrokerID, BrokerD);
			EZCTPString(pInvPos1.InvestorID, InvestorD);
			EZCTPString(pInvPos1.InstrumentID, na);
			int rtpInvPos = pTraderApiD->ReqQryInvestorPosition(&pInvPos1, EZCTPTraderSpi::requestID);
		}
	}
	else
	{
		cerr << "返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
		EZPositionStatusD = FALSE;
	}
}


//EZgetPosition状态
bool EZCTPTraderSpi::EZgetPositionStatus()
{
	return EZPositionStatusD;
}
CThostFtdcInvestorPositionField  *EZCTPTraderSpi::test()
{
	return  pInvestorPositionTest;
}

void EZCTPTraderSpi::EZinstrumentIndex(string& tickerPass)
{
	string tickerPassLong = tickerPass + "L";
	string tickerPassShort = tickerPass + "S";
	static EZproductInfo NewVariable(tickerPassLong);
	static EZproductInfo NewVariable(tickerPassShort);
	mapProduct[tickerPassLong] = NewVariable(tickerPassLong);
	mapProduct[tickerPassShort] = NewVariable(tickerPassShort);

}
//返回请求的Market class
EZproductInfo EZCTPTraderSpi::EZRspPositionData(string& tickerPass,string & LongOrShort)
{
	//cout << mapTest[tickerPass].getEZOpenInterest() << endl;
	//cout <<tickerPass << endl;
	string tickerPassShortOrLong = tickerPass + LongOrShort;
	return mapProduct[tickerPassShortOrLong];
}

vector<string> EZCTPTraderSpi::EZgetVector()
{
	for (map<string, EZproductInfo>::iterator it = mapProduct.begin(); it != mapProduct.end(); ++it) {
		keys.push_back(it->first);
	}
	return keys;
}

//获取市场行情
void EZCTPTraderSpi::EZgetDepthMarketData(string InstrumentS)
{
	CThostFtdcQryDepthMarketDataField pDepMarData;
	//memset(& pDepMarData, 20000, sizeof( pDepMarData));
	EZCTPString(pDepMarData.InstrumentID, InstrumentS);
	int rtpDepMarData = pTraderApiD->ReqQryDepthMarketData(&pDepMarData, EZCTPTraderSpi::requestID);
	switch (rtpDepMarData)
	{
	case 0:
		cout << ">>>>>>ReqQryInvestorPosition 请求成功" << endl;
		break;
	case -1:
		cout << "ReqQryInvestorPosition Network problem and failed to sent request" << endl;
		break;
	case -2:
		cout << "ReqQryInvestorPosition Qiue is too long" << endl;
		break;
	case -3:
		cout << "ReqQryInvestorPosition Requested too much" << endl;
	}
}
//EZgetDepthMarketData回调
void EZCTPTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) 
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (!bResult)
	{
		cout << "=====OnRspQryDepthMarketData 成功=====" << endl;
		DepthPositionToPassI = pDepthMarketData->OpenInterest;
		cout << DepthPositionToPassI << endl;
		EZgetDepthMarketDataStatusD = TRUE;
	}
	else
	{
		cerr << "EZgetDepthMarketData返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
		EZgetDepthMarketDataStatusD = FALSE;
	}
}
//传导市场总持仓量
void  EZCTPTraderSpi::EZgetDepthMarketDataPass(double& positionA)
{
	positionA = DepthPositionToPassI;
}
//EZgetDepthMarketData状态
bool EZCTPTraderSpi::EZgetDepthMarketDataStatus()
{
	return EZgetDepthMarketDataStatusD;
}




// 断开连接通知
void EZCTPTraderSpi::OnFrontDisconnected(int nReason)
	{
	cerr << "=====网络连接断开=====" << endl;
	cerr << "错误码： " << nReason << endl;
	}

// 心跳超时警告
void EZCTPTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cerr << "=====网络心跳超时=====" << endl;
	cerr << "距上次连接时间： " << nTimeLapse << endl;
}

// 错误通知
void EZCTPTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	bool bResult = pRspInfo && (pRspInfo->ErrorID != 0);
	if (bResult)
		cerr << "返回错误--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
}

EZCTPTraderSpi::~EZCTPTraderSpi()
	{
	EZCTPTraderSpi::requestID--;
	cout << "Leaving: " << EZCTPTraderSpi::requestID << endl;
	//leave it to end user class to handle this
	}