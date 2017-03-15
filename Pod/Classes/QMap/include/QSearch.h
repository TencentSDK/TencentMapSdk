/*
 ============================================================================
 Name           : QSearch.h
 Author         : 腾讯SOSO地图API
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QSearch declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "RouteResult.h"
#import "QRouteSearch.h"

/**前向声明**/
@protocol QSearchDelegate;
@class QSearchInternal;


/**
 *QSearch:POI，周边，路线，公交，驾车等搜索服务
 *Author:ksnowlv
 **/
@interface QSearch : NSObject
{
    QSearchInternal* _internal;
}

/**Search Delegate**/
@property(nonatomic, weak) id<QSearchDelegate> delegate;

//驾车路线搜索参数：是否避免收费道路,默认值NO
@property(nonatomic, assign) BOOL notoll;

//驾车路线搜索参数：是否结合路况,默认值YES
@property(nonatomic, assign) BOOL traffic;

//驾车路线搜索参数：行车方向角度(默认-1.0,0~360顺时针角度值)
@property(nonatomic, assign) float angle;

//订单相关信息
@property(nonatomic, retain) QOrderExtraInfo* qOrderExtraInfo;

/**
 *根据地理坐标获取城市名
 *@param locationCoordinate2D 地理坐标
 *@return 成功返回城市名，否则返回nil
 */
- (NSString*)getCityNameFromPos:(CLLocationCoordinate2D)locationCoordinate2D;

/**
 *导航路线搜索
 *异步函数，返回结果在QSearchDelegate的notifyNavRouteSearchResult通知
 *@param start 检索的起点
 *@param end 检索的终点
 *@param driveSearchType 驾车路线搜索类型，见QDriveSearchType的定义
 *@param bNoHighway 是否走高速
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)navRouteSearchWithLocation:(QPlaceInfo*)start
                               end:(QPlaceInfo*)end
               withDriveSearchType:(QDriveSearchType)driveSearchType
                         noHighway:(BOOL)bNoHighway;

/**
 *区分车辆类型的导航路线搜索
 *异步函数，返回结果在QSearchDelegate的notifyNavRouteSearchResult通知
 *@param start 检索的起点
 *@param end 检索的终点
 *@param driveSearchType 驾车路线搜索类型，见QDriveSearchType的定义
 *@param bNoHighway 是否走高速
 *@param vehicle 指定车型 　vehicle=bus:大巴，针对超高大型巴士汽车 vehicle=driving (必须为小写字母)普通小客车,缺省值可以不设置
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)navRouteSearchWithLocation:(QPlaceInfo*)start
                               end:(QPlaceInfo*)end
               withDriveSearchType:(QDriveSearchType)driveSearchType
                         noHighway:(BOOL)bNoHighway
                           vehicle:(NSString*)vehicle;


/**
 *包含途经点的导航路线搜索
 *异步函数，返回结果在QSearchDelegate的notifyNavRouteSearchResult通知
 *@param lineArray 包括起点终点和途经点的列表
 *@param driveSearchType 驾车路线搜索类型，见QDriveSearchType的定义
 *@param bNoHighway 是否走高速
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)navRouteSearchWithLocationArray:(NSArray*)lineArray
                    withDriveSearchType:(QDriveSearchType)driveSearchType
                              noHighway:(BOOL)bNoHighway;

/**
 *区分车辆类型的途经点导航路线搜索
 *异步函数，返回结果在QSearchDelegate的notifyNavRouteSearchResult通知
 *@param lineArray 包括起点终点和途经点的列表
 *@param driveSearchType 驾车路线搜索类型，见QDriveSearchType的定义
  *@param bNoHighway 是否走高速
  *@param vehicle 指定车型 　vehicle=bus:大巴，针对超高大型巴士汽车 vehicle=driving (必须为小写字母)普通小客车,缺省值可以不设置
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)navRouteSearchWithLocationArray:(NSArray*)lineArray
                    withDriveSearchType:(QDriveSearchType)driveSearchType
                              noHighway:(BOOL)bNoHighway
                                vehicle:(NSString*)vehicle;

/**
 * 取消路线规划请求
 */
-(void)cancelNavRoultSearchRequset;

/**
 *设置大巴路线点串，需要在调用路线搜索请求前调用，取消或再次发起算路请求需清除,设置点串后，调用算路接口无需再设置起终点；如果算路需要同时设置途径点，途径点的点经纬度需要控制在点串内数据包含的范围
 *@param (NSArray *)points:点串数组，元素类型为QPlaceInfo
 */
- (void)setRoutePoints:(NSArray *)points;

- (NSArray *)routePoints;

/**
 *如果之前的算路请求设置了大巴路线点串，调用该接口清除
 */
- (void)clearPoints;

/**
 *步行导航路线搜索
 *@param start 检索的起点
 *@param end 检索的终点
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)walkNavRouteSearchWithLocation:(QPlaceInfo*)start
                                   end:(QPlaceInfo*)end;
@end


/**
 *QSearchDelegate:POI，周边，路线，公交，驾车等搜索结果的通知
 *Author:ksnowlv
 **/
@protocol QSearchDelegate<NSObject>

@optional
/**
 *返回导航搜索结果
 */
- (void)notifyNavRouteSearchResult:(RouteResult*)routeSearchResult;

/**
 *返回导航搜索错误结果 (废弃)
 */
- (void)notifyNavRouteSearchDidFail __attribute__ ((deprecated("use - (void)notifyNavRouteSearchDidFailWithError:(QRouteSearchError *)error instead")));

/**
 * 返回导航搜索错误结果
 * @param error 错误类型
 *       Error domain: QErrorDomain
 *         Error code: 1> QNotFound 无数据
 *                     2> QNetError 网络连接错误
 */
- (void)notifyNavRouteSearchDidFailWithError:(QRouteSearchError *)error;

/**
 * 返回取消路线规划请求的结果
 * @param result 结果类型
 */
- (void)notifyCancelNavRouteSearchRequestResult:(BOOL)result;

@end
