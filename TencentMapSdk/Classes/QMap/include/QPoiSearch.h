/*
 ============================================================================
 Name           : QPoiSearch.h
 Author         : 腾讯SOSO地图API
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPoiInfo,QPoiData,QCityInfoForPoi,QPoiResult declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "QTypes.h"

/**
 *QPoiType:POI类型
 *Author:ksnowlv
 **/
typedef enum
{
    QPoiTypeCommon  = 0,/**POI类型:无特殊类型标记人普通POI**/
    QPoiTypeBusStation,/**POI类型:公交站**/
    QPoiTypeSubwayStation,/**POI类型:地铁站**/
    QPoiTypeBusLine,/**POI类型:公交线**/
    QPoiTypeAear,/**POI类型:行政区划**/
    
}QPoiType;

/**
 *QPoiInfo:POI数据信息
 *Author:ksnowlv
 **/
@interface QPoiInfo : NSObject

/**POI的类型**/
@property(nonatomic, assign) QPoiType  type;
/**POI的UID**/
@property(nonatomic, strong) NSString* uid;
/**POI的名称**/
@property(nonatomic, strong) NSString* name;
/**POI的详细地址**/
@property(nonatomic, strong) NSString* address;
/**POI的电话**/
@property(nonatomic, strong) NSString* phone;
/**POI的分类**/
@property(nonatomic, strong) NSString* classes;
/**POI的详细描述**/
@property(nonatomic, strong) NSString* poiInfo;
/**POI的地理坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

/**
 *QPoiData:POI数据
 *Author:ksnowlv
 **/
@interface QPoiData : NSObject

/**本次POI搜索的总结果数**/
@property(nonatomic, assign) NSInteger totalPoiNum;
/**当前页的POI结果数**/
@property(nonatomic, assign) NSInteger curPoiNum;
/**本次POI搜索的总页数**/
@property(nonatomic, assign) NSInteger pageNum;
/**当前页的索引**/
@property(nonatomic, assign) NSInteger pageIndex;
/**POI列表，成员是QPoiInfo**/
@property(nonatomic, strong) NSArray* poiInfoList;

@end


/**
 *QCityInfoForPoi:POI搜索下的城市信息
 *Author:ksnowlv
 **/
@interface QCityInfoForPoi : NSObject

/**所在的省，如果为直辖市，则为直辖市名称**/
@property(nonatomic, strong) NSString* provinceName;
/**城市名，如果为直辖市，则为直辖市名称**/
@property(nonatomic, strong) NSString* name;
/**该城市POI的数目**/
@property(nonatomic, assign) NSInteger poiNum;

@end

/**
 *QPoiResult:POI搜索结果
 *Author:ksnowlv
 **/
@interface QPoiSearchResult : NSObject
/**
 当errorCode为QPoiSearchPoiData时, data是QPoiData
 当errorCode为QPoiSearchCityData时, data是QPoiInfo
 当errorCode为QPoiSearchCrossCityData时, data是NSArray存放的是QCityInfoForPoi
 其他为非正常状态,可以参见QErrorCode
 **/
@property(nonatomic, assign) QErrorCode errorCode;
/**搜索结果，和errorCode有一一对应关系**/
@property(nonatomic, strong) id data;	
/**搜索的POI所在的城市**/
@property(nonatomic, strong) NSString* cityName;
/**搜索的POI的关键字**/
@property(nonatomic, strong) NSString* keyWord;

@end


/**
 *QSmartTripsResult:智能提示的结果
 *Author:ksnowlv
 **/
@interface QSmartTripsResult : NSObject
/**
 当errorCode为QSmartTripsList时, data是NSArray,存放的是NSString
 其他为非正常状态,可以参见QErrorCode
 **/
@property(nonatomic, assign) QErrorCode errorCode;
/**搜索结果，和errorCode有一一对应关系**/
@property(nonatomic, strong) id data;

@end

