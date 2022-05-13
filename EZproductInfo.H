#ifndef _EZproductInfo_H_
#define _EZproductInfo_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ThostFtdcTraderApi.h"

using namespace std;

class EZproductInfo : public CThostFtdcTraderSpi
{
public:EZproductInfo();
	  
	  void update(CThostFtdcInvestorPositionField *EZpInvestorPosition);

	  ///合约代码
	  string getEZInstrumentID();
	  ///经纪公司代码
	  void getEZBrokerID();
	  ///投资者代码
	  void getEZInvestorID();
	  ///持仓多空方向
	  void getEZPosiDirection();
	  ///投机套保标志
	  void getEZHedgeFlag();
	  ///持仓日期
	  void getEZPositionDate();
	  ///上日持仓
	  void getEZYdPosition();
	  ///今日持仓
	  double getEZPosition();
	  ///多头冻结
	  void getEZLongFrozen();
	  ///空头冻结();
	  void getEZShortFrozen();
	  ///开仓冻结金额
	  void getEZLMoney();
	  ///开仓冻结金额
	  void getEZShortFrozenAmount();
	  ///开仓量
	  void getEZOpenVolume();
	  ///平仓量
	  void getEZCloseVolume();
	  ///开仓金额
	  void getEZOpenAmount();
	  ///平仓金额
	  void getEZCloseAmount();
	  ///持仓成本
	  void getEZPositionCost();
	  ///上次占用的保证金
	  void getEZPreMargin();
	  ///占用的保证金();
	  void getEZUseMargin();
	  ///冻结的保证金
	  void getEZFrozenMargin();
	  ///冻结的资金
	  void getEZFrozenCash();
	  ///冻结的手续费
	  void getEZFrozenCommission();
	  ///资金差额
	  void getEZCashIn();
	  ///手续费
	  void getEZCommission();
	  ///平仓盈亏
	  void getEZCloseProfit();
	  ///持仓盈亏
	  void getEZPositionProfit();
	  ///上次结算价
	  void getEZPreSettlementPrice();
	  ///本次结算价
	  void getEZSettlementPrice();
	  ///交易日
	  void getEZTradingDay();
	  ///结算编号
	  void getEZSettlementID();
	  ///开仓成本
	  void getEZOpenCost();
	  ///交易所保证金
	  void getEZExchangeMargin();
	  ///组合成交形成的持仓
	  void getEZCombPosition();
	  ///组合多头冻结
	  void getEZCombLongFrozen();
	  ///组合空头冻结
	  void getEZCombShortFrozen();
	  ///逐日盯市平仓盈亏
	  void getEZCloseProfitByDate();
	  ///逐笔对冲平仓盈亏
	  void getEZCloseProfitByTrade();
	  ///今日持仓
	  double getEZTodayPosition();
	  ///保证金率
	  void getEZMarginRateByMoney();
	  ///保证金率(按手数)
	  void getEZMarginRateByVolume();
	  ///执行冻结
	  void getEZStrikeFrozen();
	  ///执行冻结金额
	  void getEZStrikeFrozenAmount();
	  ///放弃执行冻结
	  void getEZAbandonFrozen();
	  ///交易所代码
	  void getEZExchangeID();
	  ///执行冻结的昨仓
	  void getEZYdStrikeFrozen();
	  ///投资单元代码
	  void getEZInvestUnitID();
	  ///大商所持仓成本差值，只有大商所使用
	  void getEZPositionCostOffset();
	  ///空头仓位
	  //void getEZsellPosition();
	  /////多头仓位
	  //void getcallPosition();
	  /////总仓位
	  //int gettotalPosition();
private:
	CThostFtdcInvestorPositionField* EZpInvestorPosition;
	///合约代码
	string EZInstrumentID;
	///经纪公司代码
	string EZBrokerID;
	///投资者代码
	string EZInvestorID;
	///持仓多空方向
	int EZPosiDirection;
	///投机套保标志
	//EZHedgeFlag;
	///持仓日期
	string EZPositionDate;
	///上日持仓
	double EZYdPosition;
	///今日持仓
	double EZPosition;
	///多头冻结
	//EZLongFrozen;
	///空头冻结;
	//EZShortFrozen;
	///开仓冻结金额
	//EZLMoney;
	///开仓冻结金额
	//EZShortFrozenAmount;
	///开仓量
	//EZOpenVolume;
	///平仓量
	//EZCloseVolume;
	///开仓金额
	//EZOpenAmount;
	///平仓金额
	//EZCloseAmount;
	///持仓成本
	//EZPositionCost;
	///上次占用的保证金
	//EZPreMargin;
	///占用的保证金;
	double EZUseMargin;
	///冻结的保证金
	//EZFrozenMargin;
	///冻结的资金
	//EZFrozenCash;
	///冻结的手续费
	//EZFrozenCommission;
	///资金差额
	//EZCashIn;
	///手续费
	//EZCommission;
	///平仓盈亏
	//EZCloseProfit;
	///持仓盈亏
	//EZPositionProfit;
	///上次结算价
	double EZPreSettlementPrice;
	///本次结算价
	double EZSettlementPrice;
	///交易日
	string EZTradingDay;
	///结算编号
	//EZSettlementID;
	///开仓成本
	//EZOpenCost;
	///交易所保证金
	double EZExchangeMargin;
	///组合成交形成的持仓
	//EZCombPosition;
	///组合多头冻结
	//EZCombLongFrozen;
	///组合空头冻结
	//EZCombShortFrozen;
	///逐日盯市平仓盈亏
	//EZCloseProfitByDate;
	///逐笔对冲平仓盈亏
	//EZCloseProfitByTrade;
	///今日持仓
	double EZTodayPosition;
	///保证金率
	//EZMarginRateByMoney;
	///保证金率(按手数)
	//EZMarginRateByVolume;
	///执行冻结
	//EZStrikeFrozen;
	///执行冻结金额
	//EZStrikeFrozenAmount;
	///放弃执行冻结
	//EZAbandonFrozen;
	///交易所代码
	string EZExchangeID;
	///执行冻结的昨仓
	//EZYdStrikeFrozen;
	///投资单元代码
	//EZInvestUnitID;
	///大商所持仓成本差值，只有大商所使用
	//EZPositionCostOffset;
	///空头仓位
	//int EZsellPosition;
	/////多头仓位
	//int EZcallPosition;
	/////总仓位
	//int EZtotalPosition;
};
#endif