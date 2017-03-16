//
//  QDiDiUserOpStatistics.h
//  QMapKit
//
//  Created by NancyNan on 16/9/24.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

//埋点key
extern NSString * const MAP_NAME;
extern NSString * const MAP_DETAIL;
extern NSString * const MAP_IS_OUTWAY;

//失败原因一级分类
extern NSString * const CAR_ONLINE_SEARCH_SUCCESS;//请求成功
extern NSString * const CAR_ONLINE_SEARCH_DATAFAILED;//腾讯错误
extern NSString * const CAR_ONLINE_SEARCH_EXCEPTION;//滴滴错误
extern NSString * const CAR_ONLINE_SEARCH_NETUNABLE;//手机无网络
extern NSString * const CAR_ONLINE_SEARCH_NETFAILED;//网络请求连接不通

//失败原因二级分类
extern NSString * const DiDi_RET_ERROR;//滴滴返回错误码不为0
extern NSString * const TX_RET_ERROR;//腾讯返回错误码不为0
extern NSString * const PB_PARSE_FAIL;//PB解析失败
extern NSString * const JCE_PARSE_FAIL;//JCE解析失败
extern NSString * const DIDI_ROUTE_NULL;//滴滴返回有效数据为空
extern NSString * const TX_ROUTE_NULL;//腾讯返回有效数据为空
extern NSString * const TX_TYPE_ERROR;//腾讯返回的路线类型，不是44也不是94
extern NSString * const TX_PARAM_ERROR;//腾讯返回的回包数据为空

//参数错误分类
extern NSString * const START_IS_INVALID;
extern NSString * const END_IS_INVALID;
extern NSString * const START_END_BOTH_INVALID;
extern NSString * const MapView_Is_Nil;
extern NSString * const Req_Is_Nil;

//事件名
extern NSString * const EVENT_SCTX_DRIVER_PARAMS_OP;
extern NSString * const EVENT_SCTX_PASSENGER_PARAMS_OP;
extern NSString * const EVENT_NAVI_PARAMS_OP;
extern NSString * const EVENT_REAL_NAVI_DAU_OP;
extern NSString * const EVENT_SAMEROUTE_SEARCH_OP;
extern NSString * const EVENT_SCTX_SEARCH_DRIVER_OP;
extern NSString * const EVENT_ROUTE_SEARCH_OP;

//埋点上报类
/**
 以下面几个例子来讲解埋点上报接口的使用
 1.统计路线规划的总次数,NavRouteCalculate为路线规划事件名
 [QUserOpStatistics accumulateEvent:@"NavRouteCalculate"];
 2.统计路线规划的总次数，并要区分初次规划和偏航规划的占比,isOutway表示是否偏航，取值区间为[YES,NO];
 [QUserOpStatistics accumulateEvent:@"NavRouteCalculate" detail:[NSDictionary dictionaryWithObject:@"YES" forKey:@"isOutway"]];
 3.统计路线规划的总次数，并要区分初次规划和偏航规划的占比,导航使用场景，isOutway表示是否偏航，取值区间为[YES,NO]， scene表示导航场景，取值区间为[sctx,normal,yzx],分别表示司乘同显，普通导航，一致性;
 [QUserOpStatistics accumulateEvent:@"NavRouteCalculate" detail:[NSDictionary dictionaryWithObjects:@[@"YES", @"sctx"] forKeys:@[@"isOutway", @"scene"]]];
 4.统计路线规划的总次数，并要区分初次规划和偏航规划的占比,导航使用场景的占比，失败率，isOutway表示是否偏航，取值区间为[YES,NO]， scene表示导航使用场景，取值区间为[sctx,normal,yzx],分别表示司乘同显，普通导航，一致性，用isSuccess字段表示成功或失败, consumeTime表示事件的耗时;
 [QUserOpStatistics accumulateEvent:@"NavRouteCalculate" detail:[NSDictionary dictionaryWithObjects:@[@"YES", @"sctx"] forKeys:@[@"isOutway", @"scene"]] isSuccess:YES consumeTime:0.3];
*/

@interface QUserOpStatistics : NSObject

/**
 * @brief 上报一个事件，不能维度，只能统计事件上报的次数
 *
 * @param eventName 事件名
 *
 */
+ (void)accumulateEvent:(NSString *)eventName;

/**
 * @brief 上报一个事件，根据事件的取值进行维度，可以统计出总的事件上报次数和每个值的上报次数
 * 比如要统计路线规划失败的次数，并且要统计初次路线规划和偏航规划的占比，eventName定义为“NavCalculateFail”, value取值为[normal, outway],
 初次规划失败 [QDiDiUserOpStatistics accumulateEvent:@"NavRecalculateFail" value:@"normal"];
 偏航规划失败 [QDiDiUserOpStatistics accumulateEvent:@"NavRecalculateFail" value:@"outway"];
 * @param eventName 事件名
 * @param value 事件的值，为常量，用来进行维度
 *
 */

+ (void)accumulateEvent:(NSString *)eventName
                  value:(NSString *)value;

+ (void)accumulateEvent:(NSString *)eventName
                 detail:(NSDictionary *)params;

+ (void)accumulateEvent:(NSString *)eventName
                  value:(NSString *)value
              isSuccess:(BOOL)isSuccess;

+ (void)accumulateEvent:(NSString *)eventName
                 detail:(NSDictionary *)params
              isSuccess:(BOOL)isSuccess
            consumeTime:(CGFloat)consumeTime;

@end

@interface QUserOpStatistics (SCTX)

//失败率统计方法
+ (void)accumulateFailureRateWithEvent:(NSString *)eventName mapName:(NSString *)mapName map_detail:(NSString *)mapDetail isOutway:(BOOL)isOutway consumeTime:(CGFloat)comsumeTime;

/**
 * @brief API调用参数错误上报
 *
 * @param eventName 事件名
 *
 * @param mapName 参数错误类型
 */
+ (void)accumulateParamErrorWithEvent:(NSString *)eventName mapName:(NSString *)mapName;

/**
 * @brief API调用参数错误上报
 *
 * @param eventName 事件名
 *
 * @param mapName 参数错误类型
 *
 * @param mapDetail 参数错误详细信息
 */
+ (void)accumulateParamErrorWithEvent:(NSString *)eventName mapName:(NSString *)mapName map_detail:(NSString *)mapDetail;

@end
