#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include "EZCTP.H"
#include "EZCTPMdSpi.H"
#include "EZCTPTraderSpi.H"
#include "EZproductInfo.H"
#include "EZmarketInfo.H"

#pragma comment(lib,"thostmduserapi_se.lib")
#pragma comment(lib,"thosttraderapi_se.lib")

using namespace std;

int main(int argc, char* argv[])
{
	char cMDAddressMarket[100];
	string frontMarket = "tcpFront";

	EZCTPString(cMDAddressMarket, frontMarket);

	const char* localFileDirMarket = "C:/Users/Administrator/Desktop/EZCTP/Test/LimitationMonitoring/account/Market";
	CThostFtdcMdApi* pEZCTPMdApiDMarket;
	EZCTPMdSpi* pEZCTPMdSpiDMarket;
	const string InvestorMarket = "username";
	const string BrokerMarket = "brokerID";
	const string PasswordMarket = "password";

	pEZCTPMdApiDMarket = CThostFtdcMdApi::CreateFtdcMdApi(localFileDirMarket,true,true);
	Sleep(1000);

	pEZCTPMdSpiDMarket = new EZCTPMdSpi(pEZCTPMdApiDMarket, InvestorMarket, BrokerMarket, PasswordMarket);      
	Sleep(1000);
	pEZCTPMdApiDMarket->RegisterSpi(pEZCTPMdSpiDMarket);               
	Sleep(1000);
	pEZCTPMdApiDMarket->RegisterFront(cMDAddressMarket);           
	pEZCTPMdApiDMarket->Init();
	Sleep(3000);//must delay, wait until all initialization completes
	cout << "after init()" << endl;
	pEZCTPMdSpiDMarket->EZLogin();
	while (pEZCTPMdSpiDMarket->EZLoginStatus() != TRUE)  Sleep(1000);
	
	ifstream in("C:/Users/Administrator/Desktop/future2.txt");
	string instrumentSMarket;
	int sizeMarket(0);
	while (getline(in, instrumentSMarket))
	{
		//cout << instrumentSMarket << endl;
		pEZCTPMdSpiDMarket->EZgetDepthMarketData(instrumentSMarket);
		sizeMarket++;
	}

	Sleep(5000);




	char cMDAddressZJJTEST[100];
	string frontZJJTEST = "tcpFront";
	EZCTPString(cMDAddressZJJTEST, frontZJJTEST);

	const char* localFileDirZJJTEST = "C:/Users/Administrator/Desktop/EZCTP/Test/LimitationMonitoring/account/ZJJTEST";
	CThostFtdcTraderApi* pEZCTPTraderApiDZJJTEST;
	EZCTPTraderSpi* pEZCTPTraderSpiDZJJTEST;
	const string InvestorZJJTEST = "username";
	const string BrokerZJJTEST = "brokerID";
	const string PasswordZJJTEST = "password";
	const string AppIDZJJTEST = "appID";
	const string AuthCodeZJJTEST = "authcode";


	pEZCTPTraderApiDZJJTEST = CThostFtdcTraderApi::CreateFtdcTraderApi(localFileDirZJJTEST);
	Sleep(1000);
	
	pEZCTPTraderSpiDZJJTEST = new EZCTPTraderSpi(pEZCTPTraderApiDZJJTEST, InvestorZJJTEST, BrokerZJJTEST, PasswordZJJTEST, AppIDZJJTEST, AuthCodeZJJTEST);     
	Sleep(1000);
	pEZCTPTraderApiDZJJTEST->RegisterSpi(pEZCTPTraderSpiDZJJTEST);               
	Sleep(1000);
	pEZCTPTraderApiDZJJTEST->RegisterFront(cMDAddressZJJTEST);           
	pEZCTPTraderApiDZJJTEST->Init();
	Sleep(3000);//must delay, wait until all initialization completes
	cout << "after init()" << endl;
	cout << "Version: " << pEZCTPTraderApiDZJJTEST->GetApiVersion() << endl;
	pEZCTPTraderSpiDZJJTEST->EZAuthen();
	while (pEZCTPTraderSpiDZJJTEST->EZAuthenStatus() != TRUE)  Sleep(1000);
	pEZCTPTraderSpiDZJJTEST->EZLogin();
	while (pEZCTPTraderSpiDZJJTEST->EZLoginStatus() != TRUE)  Sleep(1000);

	string InstrumentZJJTEST = "";
	pEZCTPTraderSpiDZJJTEST->EZgetPosition(InstrumentZJJTEST);
	Sleep(5000);
	cout << "Position have been ready" << endl;
	vector<string> EZcontractListZJJTEST;
	EZcontractListZJJTEST = pEZCTPTraderSpiDZJJTEST -> EZgetVector();
	vector<string>::iterator itZJJTEST;
	for (itZJJTEST = EZcontractListZJJTEST.begin(); itZJJTEST != EZcontractListZJJTEST.end(); itZJJTEST++)
	{
		cout << *itZJJTEST << endl;
	}
	EZproductInfo productInfoTestZJJTEST;


	while (1 < 2) {
		string contractZJJTEST;
		string LongOrShortZJJTEST;
		cout << "Please enter contract" << endl;
		cin >> contractZJJTEST;
		cout << "Please enter direction" << endl;
		cin >> LongOrShortZJJTEST;
		productInfoTestZJJTEST = pEZCTPTraderSpiDZJJTEST->EZRspPositionData(contractZJJTEST, LongOrShortZJJTEST);
		double productHold = productInfoTestZJJTEST.getEZPosition();
		cout << productHold << endl;

		EZmarketInfo tickerMarket;
		string typeTicker;
		cin >> typeTicker;
		tickerMarket = pEZCTPMdSpiDMarket->EZRspmarketData(typeTicker);
		cout << tickerMarket.getEZOpenInterest() << endl;
		cout << productHold / tickerMarket.getEZOpenInterest() << endl;
	}

	Sleep(INFINITE);
	return 0;
}



