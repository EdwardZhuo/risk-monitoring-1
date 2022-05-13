#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "ThostFtdcTraderApi.h"
#include "EZproductInfo.H"

using namespace std;

EZproductInfo::EZproductInfo()
{
	///合约代码
	EZproductInfo::EZInstrumentID = "na";
	///经纪公司代码
	EZproductInfo::EZBrokerID = "na";
	///投资者代码
	EZproductInfo::EZInvestorID = "na";
	///持仓多空方向
	EZproductInfo::EZPosiDirection = 0;
	///投机套保标志
	//EZHedgeFlag;
	///持仓日期
	EZproductInfo::EZPositionDate = "na";
	///上日持仓
	EZproductInfo::EZYdPosition = 0.0;
	///今日持仓
	EZproductInfo::EZPosition = 0.0;
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
	EZUseMargin = 0.0;
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
	EZproductInfo::EZPreSettlementPrice = 0.0;
	///本次结算价
	EZproductInfo::EZSettlementPrice = 0.0;
	///交易日
	EZproductInfo::EZTradingDay = "na";
	///结算编号
	//EZSettlementID;
	///开仓成本
	//EZOpenCost;
	///交易所保证金
	EZproductInfo::EZExchangeMargin = 0.0;
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
	EZproductInfo::EZTodayPosition = 0.0;
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
	EZproductInfo::EZExchangeID = "na";
	///执行冻结的昨仓
	//EZYdStrikeFrozen;
	///投资单元代码
	//EZInvestUnitID;
	///大商所持仓成本差值，只有大商所使用
	//EZPositionCostOffset;
	///空头仓位
	//EZproductInfo::EZsellPosition = 0;
	/////多头仓位
	//EZproductInfo::EZcallPosition = 0;
	/////总仓位
	//EZproductInfo::EZtotalPosition = 0;
}
void EZproductInfo::update(CThostFtdcInvestorPositionField *EZpInvestorPosition)
{
	///合约代码
	EZInstrumentID = EZpInvestorPosition->InstrumentID;
	///经纪公司代码
	EZBrokerID = EZpInvestorPosition->BrokerID;
	///投资者代码
	EZInvestorID = EZpInvestorPosition->InvestorID;
	///持仓多空方向
	EZPosiDirection = EZpInvestorPosition->PosiDirection;
	///投机套保标志
	//EZHedgeFlag = EZpInvestorPosition->HedgeFlag;
	///持仓日期
	EZPositionDate = EZpInvestorPosition->PositionDate;
	///上日持仓
	EZYdPosition = EZpInvestorPosition->YdPosition;
	///今日持仓
	EZPosition = EZpInvestorPosition->Position;
	///多头冻结
	//EZLongFrozen = EZpInvestorPosition->LongFrozen;
	///空头冻结
	//EZShortFrozen = EZpInvestorPosition->ShortFrozen;
	///开仓冻结金额
	//EZLMoney = EZpInvestorPosition->LongFrozenAmount;
	///开仓冻结金额
	//EZShortFrozenAmount = EZpInvestorPosition->ShortFrozenAmount;
	///开仓量
	//EZOpenVolume = EZpInvestorPosition->OpenVolume;
	///平仓量
	//EZCloseVolume = EZpInvestorPosition->CloseVolume;
	///开仓金额
	//EZOpenAmount = EZpInvestorPosition->OpenAmount;
	///平仓金额
	//EZCloseAmount = EZpInvestorPosition->CloseAmount;
	///持仓成本
	//EZPositionCost = EZpInvestorPosition->PositionCost;
	///上次占用的保证金
	//EZPreMargin = EZpInvestorPosition->PreMargin;
	///占用的保证金
	EZUseMargin = EZpInvestorPosition->UseMargin;
	///冻结的保证金
	//EZFrozenMargin = EZpInvestorPosition->FrozenMargin;
	///冻结的资金
	//EZFrozenCash = EZpInvestorPosition->FrozenCash;
	///冻结的手续费
	//EZFrozenCommission = EZpInvestorPosition->FrozenCommission;
	///资金差额
	//EZCashIn = EZpInvestorPosition->CashIn;
	///手续费
	//EZCommission = EZpInvestorPosition->Commission;
	///平仓盈亏
	//EZCloseProfit = EZpInvestorPosition->CloseProfit;
	///持仓盈亏
	//EZPositionProfit = EZpInvestorPosition->PositionProfit;
	///上次结算价
	EZPreSettlementPrice = EZpInvestorPosition->PreSettlementPrice;
	///本次结算价
	EZSettlementPrice = EZpInvestorPosition->SettlementPrice;
	///交易日
	EZTradingDay = EZpInvestorPosition->TradingDay;
	///结算编号
	//EZSettlementID = EZpInvestorPosition->SettlementID;
	///开仓成本
	//EZOpenCost = EZpInvestorPosition->OpenCost;
	///交易所保证金
	EZExchangeMargin = EZpInvestorPosition->ExchangeMargin;
	///组合成交形成的持仓
	//EZCombPosition = EZpInvestorPosition->CombPosition;
	///组合多头冻结
	//EZCombLongFrozen = EZpInvestorPosition->CombLongFrozen;
	///组合空头冻结
	//EZCombShortFrozen = EZpInvestorPosition->CombShortFrozen;
	///逐日盯市平仓盈亏
	//EZCloseProfitByDate = EZpInvestorPosition->CloseProfitByDate;
	///逐笔对冲平仓盈亏
	//EZCloseProfitByTrade = EZpInvestorPosition->CloseProfitByTrade;
	///今日持仓
	EZTodayPosition = EZpInvestorPosition->TodayPosition;
	///保证金率
	//EZMarginRateByMoney = EZpInvestorPosition->MarginRateByMoney;
	///保证金率(按手数)
	//EZMarginRateByVolume = EZpInvestorPosition->MarginRateByVolume;
	///执行冻结
	//EZStrikeFrozen = EZpInvestorPosition->StrikeFrozen;
	///执行冻结金额
	//EZStrikeFrozenAmount = EZpInvestorPosition->StrikeFrozenAmount;
	///放弃执行冻结
	//EZAbandonFrozen = EZpInvestorPosition->AbandonFrozen;
	///交易所代码
	EZExchangeID = EZpInvestorPosition->ExchangeID;
	///执行冻结的昨仓
	//EZYdStrikeFrozen = EZpInvestorPosition->YdStrikeFrozen;
	///投资单元代码
	//EZInvestUnitID = EZpInvestorPosition->InvestUnitID;
	///大商所持仓成本差值，只有大商所使用
	//EZPositionCostOffset = EZpInvestorPosition->PositionCostOffset;
//	if (EZPosiDirection == 3) {
//		EZsellPosition = EZPosition;
//	}
//	else {
//		EZcallPosition = EZPosition;
//	}
}
///合约代码
string EZproductInfo::getEZInstrumentID() {
	
	return EZInstrumentID;
};
///经纪公司代码
void EZproductInfo::getEZBrokerID() {};
///投资者代码
void EZproductInfo::getEZInvestorID() {};
///持仓多空方向
void EZproductInfo::getEZPosiDirection() {};
///投机套保标志
void EZproductInfo::getEZHedgeFlag() {};
///持仓日期
void EZproductInfo::getEZPositionDate() {};
///上日持仓
void EZproductInfo::getEZYdPosition() {};
///今日持仓
double EZproductInfo::getEZPosition() {
	return EZPosition;
};
///多头冻结
void EZproductInfo::getEZLongFrozen() {};
///空头冻结(){};
void EZproductInfo::getEZShortFrozen() {};
///开仓冻结金额
void EZproductInfo::getEZLMoney() {};
///开仓冻结金额
void EZproductInfo::getEZShortFrozenAmount() {};
///开仓量
void EZproductInfo::getEZOpenVolume() {};
///平仓量
void EZproductInfo::getEZCloseVolume() {};
///开仓金额
void EZproductInfo::getEZOpenAmount() {};
///平仓金额
void EZproductInfo::getEZCloseAmount() {};
///持仓成本
void EZproductInfo::getEZPositionCost() {};
///上次占用的保证金
void EZproductInfo::getEZPreMargin() {};
///占用的保证金(){};
void EZproductInfo::getEZUseMargin() {};
///冻结的保证金
void EZproductInfo::getEZFrozenMargin() {};
///冻结的资金
void EZproductInfo::getEZFrozenCash() {};
///冻结的手续费
void EZproductInfo::getEZFrozenCommission() {};
///资金差额
void EZproductInfo::getEZCashIn() {};
///手续费
void EZproductInfo::getEZCommission() {};
///平仓盈亏
void EZproductInfo::getEZCloseProfit() {};
///持仓盈亏
void EZproductInfo::getEZPositionProfit() {};
///上次结算价
void EZproductInfo::getEZPreSettlementPrice() {};
///本次结算价
void EZproductInfo::getEZSettlementPrice() {};
///交易日
void EZproductInfo::getEZTradingDay() {};
///结算编号
void EZproductInfo::getEZSettlementID() {};
///开仓成本
void EZproductInfo::getEZOpenCost() {};
///交易所保证金
void EZproductInfo::getEZExchangeMargin() {};
///组合成交形成的持仓
void EZproductInfo::getEZCombPosition() {};
///组合多头冻结
void EZproductInfo::getEZCombLongFrozen() {};
///组合空头冻结
void EZproductInfo::getEZCombShortFrozen() {};
///逐日盯市平仓盈亏
void EZproductInfo::getEZCloseProfitByDate() {};
///逐笔对冲平仓盈亏
void EZproductInfo::getEZCloseProfitByTrade() {};
///今日持仓
double EZproductInfo::getEZTodayPosition() {
	return 0;
};
///保证金率
void EZproductInfo::getEZMarginRateByMoney() {};
///保证金率(按手数)
void EZproductInfo::getEZMarginRateByVolume() {};
///执行冻结
void EZproductInfo::getEZStrikeFrozen() {};
///执行冻结金额
void EZproductInfo::getEZStrikeFrozenAmount() {};
///放弃执行冻结
void EZproductInfo::getEZAbandonFrozen() {};
///交易所代码
void EZproductInfo::getEZExchangeID() {};
///执行冻结的昨仓
void EZproductInfo::getEZYdStrikeFrozen() {};
///投资单元代码
void EZproductInfo::getEZInvestUnitID() {};
///大商所持仓成本差值，只有大商所使用
void EZproductInfo::getEZPositionCostOffset() {};
///空头仓位
//void EZproductInfo::getEZsellPosition() {};
/////多头仓位
//void EZproductInfo::getcallPosition() {};
/////总仓位
//int EZproductInfo::gettotalPosition() {
//	EZtotalPosition = EZsellPosition + EZcallPosition;
//	return EZtotalPosition;
//};
