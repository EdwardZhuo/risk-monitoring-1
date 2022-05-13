#ifndef _EZmarketInfo_H_
#define _EZmarketInfo_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ThostFtdcMdApi.h"


using namespace std;

class EZmarketInfo : public CThostFtdcMdSpi
{
public:
    EZmarketInfo();

    EZmarketInfo(const EZmarketInfo& another);
    EZmarketInfo& operator=(const EZmarketInfo& another);

	  
	void update(CThostFtdcDepthMarketDataField* EZpDepthMarketData);

    ///交易日
    //void getEZTradingDay();
    ///合约代码
    //void getEZInstrumentID();
    ///交易所代码
    //void getEZExchangeID();
    ///合约在交易所的代码
    //void getEZExchangeInstID();
    ///最新价
    //void getEZLastPrice();
    ///上次结算价
    //void getEZPreSettlementPrice();
    ///昨收盘
    //void getEZPreClosePrice();
    ///昨持仓量
    //void getEZPreOpenInterest();
    ///今开盘
    //void getEZOpenPrice();
    ///最高价
    //void getEZHighestPrice();
    ///最低价
    //void getEZLowestPrice();
    ///数量
    //void getEZVolume();
    ///成交金额
    //void getEZTurnover();
    ///持仓量
    double getEZOpenInterest();
    ///今收盘
    //void getEZClosePrice();
    ///本次结算价
    //void getEZSettlementPrice();
    ///涨停板价
    //void getEZUpperLimitPrice();
    ///跌停板价
    //void getEZLowerLimitPrice();
    ///昨虚实度
    //void getEZPreDelta();
    ///今虚实度
    //void getEZCurrDelta();
    ///最后修改时间
    //void getEZUpdateTime();
    ///最后修改毫秒
    //void getEZUpdateMillisec();
    ///申买价一
    //void getEZBidPrice1();
    ///申买量一
    //void getEZBidVolume1();
    ///申卖价一
    //void getEZAskPrice1();
    ///申卖量一
    //void getEZAskVolume1();
    ///申买价二
    //void getEZBidPrice2();
    ///申买量二
    //void getEZBidVolume2();
    ///申卖价二
    //void getEZAskPrice2();
    ///申卖量二
    //void getEZAskVolume2();
    ///申买价三
    //void getEZBidPrice3();
    ///申买量三
    //void getEZBidVolume3();
    ///申卖价三
    //void getEZAskPrice3();
    ///申卖量三
    //void getEZAskVolume3();
    ///申买价四
    //void getEZBidPrice4();
    ///申买量四
    //void getEZBidVolume4();
    ///申卖价四
    //void getEZAskPrice4();
    ///申卖量四
    //void getEZAskVolume4();
    ///申买价五
    //void getEZBidPrice5();
    ///申买量五
    //void getEZBidVolume5();
    ///申卖价五
    //void getEZAskPrice5();
    ///申卖量五
    //void getEZAskVolume5();
    ///当日均价
    //void getEZAveragePrice();
    ///业务日期
    //void getEZActionDay();
private:
    ///交易日
    //EZTradingDay;
    ///合约代码
    //EZInstrumentID;
    ///交易所代码
    //EZExchangeID;
    ///合约在交易所的代码
    //EZExchangeInstID;
    ///最新价
    //EZLastPrice;
    ///上次结算价
    //EZPreSettlementPrice;
    ///昨收盘
    //EZPreClosePrice;
    ///昨持仓量
    //EZPreOpenInterest;
    ///今开盘
    //EZOpenPrice;
    ///最高价
    //EZHighestPrice;
    ///最低价
    //EZLowestPrice;
    ///数量
    //EZVolume;
    ///成交金额
    //EZTurnover;
    ///持仓量
    double EZOpenInterest;
    ///今收盘
    //EZClosePrice;
    ///本次结算价
    //EZSettlementPrice;
    ///涨停板价
    //EZUpperLimitPrice;
    ///跌停板价
    //EZLowerLimitPrice;
    ///昨虚实度
    //EZPreDelta;
    ///今虚实度
    //EZCurrDelta;
    ///最后修改时间
    //EZUpdateTime;
    ///最后修改毫秒
    //EZUpdateMillisec;
    ///申买价一
    //EZBidPrice1;
    ///申买量一
    //EZBidVolume1;
    ///申卖价一
    //EZAskPrice1;
    ///申卖量一
    //EZAskVolume1;
    ///申买价二
    //EZBidPrice2;
    ///申买量二
    //EZBidVolume2;
    ///申卖价二
    //EZAskPrice2;
    ///申卖量二
    //EZAskVolume2;
    ///申买价三
    //EZBidPrice3;
    ///申买量三
    //EZBidVolume3;
    ///申卖价三
    //EZAskPrice3;
    ///申卖量三
    //EZAskVolume3;
    ///申买价四
    //EZBidPrice4;
    ///申买量四
    //EZBidVolume4;
    ///申卖价四
    //EZAskPrice4;
    ///申卖量四
    //EZAskVolume4;
    ///申买价五
    //EZBidPrice5;
    ///申买量五
    //EZBidVolume5;
    ///申卖价五
    //EZAskPrice5;
    ///申卖量五
    //EZAskVolume5;
    ///当日均价
    //EZAveragePrice;
    ///业务日期
    //EZActionDay;
};
#endif