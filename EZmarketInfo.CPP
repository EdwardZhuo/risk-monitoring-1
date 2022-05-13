#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ThostFtdcTraderApi.h"
#include "EZmarketInfo.H"

using namespace std;

EZmarketInfo::EZmarketInfo()
{
///交易日
//EZmarketInfo::EZTradingDay;
///合约代码
//EZmarketInfo::EZInstrumentID;
///交易所代码
//EZmarketInfo::EZExchangeID;
///合约在交易所的代码
//EZmarketInfo::EZExchangeInstID;
///最新价
//EZmarketInfo::EZLastPrice;
///上次结算价
//EZmarketInfo::EZPreSettlementPrice;
///昨收盘
//EZmarketInfo::EZPreClosePrice;
///昨持仓量
//EZmarketInfo::EZPreOpenInterest;
///今开盘
//EZmarketInfo::EZOpenPrice;
///最高价
//EZmarketInfo::EZHighestPrice;
///最低价
//EZmarketInfo::EZLowestPrice;
///数量
//EZmarketInfo::EZVolume;
///成交金额
//EZmarketInfo::EZTurnover;
///持仓量
EZmarketInfo::EZOpenInterest = 0;
///今收盘
//EZmarketInfo::EZClosePrice;
///本次结算价
//EZmarketInfo::EZSettlementPrice;
///涨停板价
//EZmarketInfo::EZUpperLimitPrice;
///跌停板价
//EZmarketInfo::EZLowerLimitPrice;
///昨虚实度
//EZmarketInfo::EZPreDelta;
///今虚实度
//EZmarketInfo::EZCurrDelta;
///最后修改时间
//EZmarketInfo::EZUpdateTime;
///最后修改毫秒
//EZmarketInfo::EZUpdateMillisec;
///申买价一
//EZmarketInfo::EZBidPrice1;
///申买量一
//EZmarketInfo::EZBidVolume1;
///申卖价一
//EZmarketInfo::EZAskPrice1;
///申卖量一
//EZmarketInfo::EZAskVolume1;
///申买价二
//EZmarketInfo::EZBidPrice2;
///申买量二
//EZmarketInfo::EZBidVolume2;
///申卖价二
//EZmarketInfo::EZAskPrice2;
///申卖量二
//EZmarketInfo::EZAskVolume2;
///申买价三
//EZmarketInfo::EZBidPrice3;
///申买量三
//EZmarketInfo::EZBidVolume3;
///申卖价三
//EZmarketInfo::EZAskPrice3;
///申卖量三
//EZmarketInfo::EZAskVolume3;
///申买价四
//EZmarketInfo::EZBidPrice4;
///申买量四
//EZmarketInfo::EZBidVolume4;
///申卖价四
//EZmarketInfo::EZAskPrice4;
///申卖量四
//EZmarketInfo::EZAskVolume4;
///申买价五
//EZmarketInfo::EZBidPrice5;
///申买量五
//EZmarketInfo::EZBidVolume5;
///申卖价五
//EZmarketInfo::EZAskPrice5;
///申卖量五
//EZmarketInfo::EZAskVolume5;
///当日均价
//EZmarketInfo::EZAveragePrice;
///业务日期
//EZmarketInfo::EZActionDay;
}
void EZmarketInfo::update(CThostFtdcDepthMarketDataField* EZpDepthMarketData)
{
    ///交易日
    //EZTradingDay = EZpDepthMarketData->TradingDay;
    ///合约代码
    //EZInstrumentID = EZpDepthMarketData->InstrumentID;
    ///交易所代码
    //EZExchangeID = EZpDepthMarketData->ExchangeID;
    ///合约在交易所的代码
    //EZExchangeInstID = EZpDepthMarketData->ExchangeInstID;
    ///最新价
    //EZLastPrice = EZpDepthMarketData->LastPrice;
    ///上次结算价
    //EZPreSettlementPrice = EZpDepthMarketData->PreSettlementPrice;
    ///昨收盘
    //EZPreClosePrice = EZpDepthMarketData->PreClosePrice;
    ///昨持仓量
    //EZPreOpenInterest = EZpDepthMarketData->PreOpenInterest;
    ///今开盘
    //EZOpenPrice = EZpDepthMarketData->OpenPrice;
    ///最高价
    //EZHighestPrice = EZpDepthMarketData->HighestPrice;
    ///最低价
    //EZLowestPrice = EZpDepthMarketData->LowestPrice;
    ///数量
    //EZVolume = EZpDepthMarketData->Volume;
    ///成交金额
    //EZTurnover = EZpDepthMarketData->Turnover;
    ///持仓量
    EZOpenInterest = EZpDepthMarketData->OpenInterest;
    ///今收盘
    //EZClosePrice = EZpDepthMarketData->ClosePrice;
    ///本次结算价
    //EZSettlementPrice = EZpDepthMarketData->SettlementPrice;
    ///涨停板价
    //EZUpperLimitPrice = EZpDepthMarketData->UpperLimitPrice;
    ///跌停板价
    //EZLowerLimitPrice = EZpDepthMarketData->LowerLimitPrice;
    ///昨虚实度
    //EZPreDelta = EZpDepthMarketData->PreDelta;
    ///今虚实度
    //EZCurrDelta = EZpDepthMarketData->CurrDelta;
    ///最后修改时间
    //EZUpdateTime = EZpDepthMarketData->UpdateTime;
    ///最后修改毫秒
    //EZUpdateMillisec = EZpDepthMarketData->UpdateMillisec;
    ///申买价一
    //EZBidPrice1 = EZpDepthMarketData->BidPrice1;
    ///申买量一
    //EZBidVolume1 = EZpDepthMarketData->BidVolume1;
    ///申卖价一
    //EZAskPrice1 = EZpDepthMarketData->AskPrice1;
    ///申卖量一
    //EZAskVolume1 = EZpDepthMarketData->AskVolume1;
    ///申买价二
    //EZBidPrice2 = EZpDepthMarketData->BidPrice2;
    ///申买量二
    //EZBidVolume2 = EZpDepthMarketData->BidVolume2;
    ///申卖价二
    //EZAskPrice2 = EZpDepthMarketData->AskPrice2;
    ///申卖量二
    //EZAskVolume2 = EZpDepthMarketData->AskVolume2;
    ///申买价三
    //EZBidPrice3 = EZpDepthMarketData->BidPrice3;
    ///申买量三
    //EZBidVolume3 = EZpDepthMarketData->BidVolume3;
    ///申卖价三
    //EZAskPrice3 = EZpDepthMarketData->AskPrice3;
    ///申卖量三
    //EZAskVolume3 = EZpDepthMarketData->AskVolume3;
    ///申买价四
    //EZBidPrice4 = EZpDepthMarketData->BidPrice4;
    ///申买量四
    //EZBidVolume4 = EZpDepthMarketData->BidVolume4;
    ///申卖价四
    //EZAskPrice4 = EZpDepthMarketData->AskPrice4;
    ///申卖量四
    //EZAskVolume4 = EZpDepthMarketData->AskVolume4;
    ///申买价五
    //EZBidPrice5 = EZpDepthMarketData->BidPrice5;
    ///申买量五
    //EZBidVolume5 = EZpDepthMarketData->BidVolume5;
    ///申卖价五
    //EZAskPrice5 = EZpDepthMarketData->AskPrice5;
    ///申卖量五
    //EZAskVolume5 = EZpDepthMarketData->AskVolume5;
    ///当日均价
    //EZAveragePrice = EZpDepthMarketData->AveragePrice;
    ///业务日期
    //EZActionDay = EZpDepthMarketData->ActionDay;
}
//void EZmarketInfo::getEZTradingDay(){};
    ///合约代码
    //void EZmarketInfo::getEZInstrumentID(){};
    ///交易所代码
    //void EZmarketInfo::getEZExchangeID(){};
    ///合约在交易所的代码
    //void EZmarketInfo::getEZExchangeInstID(){};
    ///最新价
    //void EZmarketInfo::getEZLastPrice(){};
    ///上次结算价
    //void EZmarketInfo::getEZPreSettlementPrice(){};
    ///昨收盘
    //void EZmarketInfo::getEZPreClosePrice(){};
    ///昨持仓量
    //void EZmarketInfo::getEZPreOpenInterest(){};
    ///今开盘
    //void EZmarketInfo::getEZOpenPrice(){};
    ///最高价
    //void EZmarketInfo::getEZHighestPrice(){};
    ///最低价
    //void EZmarketInfo::getEZLowestPrice(){};
    ///数量
    //void EZmarketInfo::getEZVolume(){};
    ///成交金额
    //void EZmarketInfo::getEZTurnover(){};
    ///持仓量
    double EZmarketInfo::getEZOpenInterest(){
        return EZOpenInterest;
    };
    ///今收盘
    //void EZmarketInfo::getEZClosePrice(){};
    ///本次结算价
    //void EZmarketInfo::getEZSettlementPrice(){};
    ///涨停板价
    //void EZmarketInfo::getEZUpperLimitPrice(){};
    ///跌停板价
    //void EZmarketInfo::getEZLowerLimitPrice(){};
    ///昨虚实度
    //void EZmarketInfo::getEZPreDelta(){};
    ///今虚实度
    //void EZmarketInfo::getEZCurrDelta(){};
    ///最后修改时间
    //void EZmarketInfo::getEZUpdateTime(){};
    ///最后修改毫秒
    //void EZmarketInfo::getEZUpdateMillisec(){};
    ///申买价一
    //void EZmarketInfo::getEZBidPrice1(){};
    ///申买量一
    //void EZmarketInfo::getEZBidVolume1(){};
    ///申卖价一
    //void EZmarketInfo::getEZAskPrice1(){};
    ///申卖量一
    //void EZmarketInfo::getEZAskVolume1(){};
    ///申买价二
    //void EZmarketInfo::getEZBidPrice2(){};
    ///申买量二
    //void EZmarketInfo::getEZBidVolume2(){};
    ///申卖价二
    //void EZmarketInfo::getEZAskPrice2(){};
    ///申卖量二
    //void EZmarketInfo::getEZAskVolume2(){};
    ///申买价三
    //void EZmarketInfo::getEZBidPrice3(){};
    ///申买量三
    //void EZmarketInfo::getEZBidVolume3(){};
    ///申卖价三
    //void EZmarketInfo::getEZAskPrice3(){};
    ///申卖量三
    //void EZmarketInfo::getEZAskVolume3(){};
    ///申买价四
    //void EZmarketInfo::getEZBidPrice4(){};
    ///申买量四
    //void EZmarketInfo::getEZBidVolume4(){};
    ///申卖价四
    //void EZmarketInfo::getEZAskPrice4(){};
    ///申卖量四
    //void EZmarketInfo::getEZAskVolume4(){};
    ///申买价五
    //void EZmarketInfo::getEZBidPrice5(){};
    ///申买量五
    //void EZmarketInfo::getEZBidVolume5(){};
    ///申卖价五
    //void EZmarketInfo::getEZAskPrice5(){};
    ///申卖量五
    //void EZmarketInfo::getEZAskVolume5(){};
    ///当日均价
    //void EZmarketInfo::getEZAveragePrice(){};
    ///业务日期
    //void EZmarketInfo::getEZActionDay(){};

    EZmarketInfo::EZmarketInfo(const EZmarketInfo& another)
    {
        EZOpenInterest = another.EZOpenInterest;
    }

    EZmarketInfo& EZmarketInfo::operator=(const EZmarketInfo& another)
    {
        EZOpenInterest = another.EZOpenInterest;
        return *this;
    }