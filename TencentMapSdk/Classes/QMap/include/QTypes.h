/*
 ============================================================================
 Name           : QTypes.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QTypes declaration
 ============================================================================
 */

#ifndef SOSOMapAPI_QTypes_h
#define SOSOMapAPI_QTypes_h

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
/**
 *QMapType:地图类型
 *Author:ksnowlv
 * edit by cleverzhang 2014-09-04
 **/
enum {
    QMapTypeStandard    = 0, /** 标准地图**/
    QMapTypeSatellite , /** 卫星地图，样式未开放，暂时设置无效**/
};
/* move here from QMMapView.h by cleverzhang 2014-08-19*/
enum {
	QMUserTrackingModeNone = 0, // the user's location is not followed
	QMUserTrackingModeFollow, // the map follows the user's location
	QMUserTrackingModeFollowWithHeading, // the map follows the user's location and heading
};
typedef NSInteger QMUserTrackingMode;

/**地图类型**/
typedef NSUInteger QMapType;

typedef NS_ENUM(NSInteger, QCoordinateType)
{
    QCoordinateTypeWGS84     = 1, // 标准的GPS坐标
    QCoordinateTypeGCJ02,         // 标准GPS坐标上加GCJ02偏移算法.
};

typedef NS_ENUM(NSUInteger, QMapLanguage) {
    QMapLanguageChinese = 0,
    //QMapLanguageEnglish = 1,  此版本不支持，只支持中文
};

enum {
    QMRouteDrawMultiColorLine = 0, // 彩虹蚯蚓线
    QMRouteDrawImaginaryLine, // 虚线
    QMRouteDrawDottedLine, // 点
    QMRouteDrawMultiColorCap, //彩虹蚯蚓线的端点图片类型
};
typedef NSUInteger QMRouteDrawType;


//end

/**
 *QErrorCode: errorCode>=0的类型表示正常的类型，其它类型为表示已知的错误类型
 *Author:ksnowlv
 **/
enum {
    QAppKeyCheckFail = -100,        /** 应用程序验证码验证失败**/
	QDataError = -5,                /** 网络接收的数据错误**/
    QParamError = -4,               /** 网络请求的参数错误**/
    QNetError = -3,                 /** 网络连接错误**/
    QServiceNotSupport = -2,        /** 服务暂不支持**/
    QNotFound= -1,                  /** 没有找到**/
    
	QErrorNone = 0,                 /** 正确，无错误**/
    QSmartTripsList,                /** 搜索建议，智能提示**/
    QPoiSearchResultPoiList,        /** POI搜索类型:城市内搜索POI列表**/
    QPoiSearchResultRoundPoi,       /** POI搜索类型:城市内搜索周边POI**/
    QPoiSearchResultCity,           /** POI搜索类型:城市**/
    QPoiSearchResultCrossCityList,  /** POI搜索类型:城市列表**/
    QRouteSearchResultBusList,      /** 路线搜索类型:公交路线搜索返回的起点或终点的选择列表**/
    QRouteSearchResultBusResult,    /** 路线搜索类型:公交路线搜索返回的结果**/
    QRouteSearchResultDriveList,    /** 路线搜索类型:驾车路线搜索返回的起点或终点的选择列表**/
    QRouteSearchResultDriveResult,  /** 路线搜索类型:驾车路线搜索返回的结果**/
    QBusLineSearchResultBusInfo,     /** 公交线搜索类型:公交线搜索返回的结果**/
    QNetWorkUnavailable,        /**网络不可用**/
    QNetWorkSignalWeak         /**网络信号弱**/
    
};
/*
 *导航线路图的颜色索引
 */
enum{
    RC_THROUGHED = 0,////走过的颜色，区别与其它颜色
    RC_LIGHT_BLUE1 = 1,  //0畅通，公交方案里的公交线路
    RC_RED = 2,
    RC_YELLOW = 3,
    RC_GREEN = 4,
    RC_LIGHT_BLUE = 5,
    RC_DARK_BLUE = 6,
    RC_TRANSPARENT = 7,//透明色，可以用其它路线绘制叠加
};

/*
 *导航线路图的颜色,RC_TRAFFIC只用于showSearchRoute: routeColor:
 */
enum{
    RC_TRAFFIC= -1, //根据路况来画导航图的颜色，只有设置RC_TRAFFIC才会动态更新路况
};


typedef int QMRouteColor;
/**QErrorCode**/
typedef NSUInteger QErrorCode;

#define QErrorDomain @"QErrorDomain"

typedef enum : NSUInteger {
    MAP_AUTONAV = 1,  //高德
    MAP_NAVINFO = 2,  //四维
} QMapDataType;

/*
 * 导航时地图的显示状态
 */

typedef NS_ENUM(NSInteger, QMapNaviShowMode)
{
    QMapNaviShowMode3DHeadingBestView = 1,//3D最佳视野模式（3D+车头朝上+最佳视野+自车点下移）
    QMapNaviShowMode2DNorthBestView,//2D最佳视野模式（2D+正北朝上+最佳视野+自车点居中）
    QMapNaviShowMode2DNorthOverView,//2D路线全览模式（2D+正北朝上+总览路线+自车点居中）
};

//定义动画类型
typedef NS_ENUM (NSInteger,QMapAnimationCurveType)
{
    QMapAnimationCurveEaseInOut, //default,缓进缓出
    QMapAnimationCurveEaseIn,//缓进
    QMapAnimationCurveEaseOut,//缓出
    QMapAnimationCurveLinear,//匀速
    QMapAnimationCurveNone, //没有动画
};

//定义第三方客户端类别
typedef NS_ENUM (NSInteger,QMapThirdPartyType)
{
    QMapThirdPartyTypeDefault, //default, 乘客端
    QMapThirdPartyTypeDidiPassenger, // 滴滴乘客端
    QMapThirdPartyTypeDidiSpecialDriver,//滴滴专快司机
    QMapThirdPartyTypeDidiTaxiDriver,//滴滴出租车司机
};

//定义底图蒙层层级
typedef NS_ENUM (NSInteger,QMapMaskColorLayer)
{
    QMapMaskColorLayerUnderMarker,
    QMapMaskColorLayerUnderRoute,
};

typedef NS_ENUM(NSInteger, QNetworkStatus) {
    QNotReachable = 0,
    QReachableViaWiFi,
    QReachableViaWWAN
};

///点击地图标注返回数据结构
@interface QMapPoi : NSObject
///点标注的名称
@property (nonatomic,copy,readonly) NSString* text;
///点标注的经纬度坐标
@property (nonatomic,assign,readonly) CLLocationCoordinate2D coordinate;

@end

#endif
