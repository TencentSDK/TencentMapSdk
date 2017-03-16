/*
 ============================================================================
 Name           : QRouteSearch.h
 Author         : 腾讯SOSO地图API
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QRouteNode,QPlaceInfo,QTaxiInfo,QRouteSegmentForBus,QRouteInfoForBus..... declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "QTypes.h"

/**
 *QPlaceInfo:地点信息
 *Author:ksnowlv
 **/
@interface QPlaceInfo : NSObject

/**地点的名称**/
@property(nonatomic, strong) NSString* name;
/**地点的详细地址信息**/
@property(nonatomic, strong) NSString* address;
/**地点的坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

/**标示该地点是不是一个城市**/
@property(nonatomic, assign) BOOL isCity;

/**标示该地点所在的城市**/
@property(nonatomic, strong)NSString* city;

@property(nonatomic,strong)NSString* uid;

@end


/**
 *QTaxiInfo:出租车信息
 *Author:ksnowlv
 **/
@interface QTaxiInfo : NSObject

/**打车距离(单位:m)**/
@property(nonatomic, assign) NSInteger distance;
/**打车时间(单位:minute)**/
@property(nonatomic, assign) NSInteger time;

/**白天打车总的费用(单位:元)**/
@property(nonatomic, assign) NSInteger dayTotalFee;
/**白天打车起步价**/
@property(nonatomic, assign) NSInteger dayStartFee;
/**白天打车每公里多少元**/
@property(nonatomic, assign) NSInteger dayFeePerKM;
/**白天出租运营的时间段**/
@property(nonatomic, strong) NSString* dayTime;

/**夜晚打车总的费用**/
@property(nonatomic, assign) NSInteger nightTotalFee;
/**夜晚打车起步价**/
@property(nonatomic ,assign) NSInteger nightStartFee;
/**夜晚打车每公里多少元**/
@property(nonatomic, assign) NSInteger nightFeePerKM;
/**夜晚出租运营的时间段**/
@property(nonatomic, strong) NSString* nightTime;

@end


/**
 *QRouteBusSegmentType:公交路段的类型
 *Author:ksnowlv
 **/
typedef enum  {
    QRouteSegmentTypeWalk = 0,  /**公交路段的类型:步行**/
    QRouteSegmentTypeBus,       /**公交路段的类型:公交**/
    QRouteSegmentTypeSubway,    /**公交路段的类型:地铁**/
    QRouteSegmentTypeFinish,    /**公交路段的类型:终点**/
} QRouteBusSegmentType;

/**
 *QWalkDirectionType:行走方向的类型
 *Author:ksnowlv
 **/
typedef enum {
    QWalkDirectionEast = 0,     /**行走方向的类型:东**/
    QWalkDirectionNorthEast,    /**行走方向的类型:东北**/
    QWalkDirectionNorth,        /**行走方向的类型:北**/
    QWalkDirectionNorthWest,    /**行走方向的类型:西北**/
    QWalkDirectionWest,         /**行走方向的类型:西**/
    QWalkDirectionSouthWest,    /**行走方向的类型:西南**/
    QWalkDirectionSouth,        /**行走方向的类型:南**/
    QWalkDirectionSouthEast,    /**行走方向的类型:东南**/
    
}QWalkDirectionType;

/**
 *QRouteSegmentForBus:公交的路段信息
 *Author:ksnowlv
 **/
@interface QRouteSegmentForBus : NSObject

/**公交路段距离(单位:m)**/
@property(nonatomic, assign) NSUInteger distance;
/**公交路段名称**/
@property(nonatomic, strong) NSString* name;
/**公交路段总站数**/
@property(nonatomic, assign) NSUInteger stationNum;
/**公交路段运行时间(单位:minute)**/
@property(nonatomic, assign) NSUInteger time;
/**公交路段类型**/
@property(nonatomic, assign) QRouteBusSegmentType type;
/**该公交路段在哪上车**/
@property(nonatomic, strong) NSString* whereGetOn;
/**该公交路段在哪下车**/
@property(nonatomic, strong) NSString* whereGetOff;
/**QWalkDirectionType**/
@property(nonatomic, assign) QWalkDirectionType walkDirection;
/** 该公交路段起点在路线节点中的索引**/
@property(nonatomic, assign) NSInteger startIndex;
/** 该公交路段终点在路线节点中的索引**/
@property(nonatomic, assign) NSInteger endIndex;

@end

/**
 *QRouteInfoForBus:公交的路线信息
 *Author:ksnowlv
 **/
@interface QRouteInfoForBus : NSObject

/**路线花费时间(单位:minute)**/
@property(nonatomic, assign) NSInteger time;
/**路线路程(单位:m)**/
@property(nonatomic, assign) NSInteger distance;
/**路线类型**/
@property(nonatomic, assign) NSInteger type;
/**路线的路段信息，存放的是QRouteSegmentForBus**/
@property(nonatomic, strong) NSArray* routeSegmentList;
/**线路各个地理坐标点数组**/
@property(nonatomic, readonly) CLLocationCoordinate2D* routeNodeList;
/**线路各个地理坐标点个数**/
@property(nonatomic, readonly) NSUInteger routeNodeCount;

/**
 *根据指定坐标点生成一段路线
 *@param routeNodeList 指定的地理坐标点数组
 *@param routeNodeCount 坐标点的个数
 *@return NULL
 */
- (void)setRouteNodeList:(CLLocationCoordinate2D *)routeNodeList withRouteNodeCount:(NSUInteger)routeNodeCount;

@end


/**
 *QBusSearchType:公交搜索的类型
 *Author:ksnowlv
 **/
typedef enum  {
    QBusSearchShortCut  = 0,    /**公交搜索的类型:快捷**/
    QBusSearchLessTransfer,     /**公交搜索的类型:少换乘**/
    QBusSearchLessWalk,         /**公交搜索的类型:少步行**/
    QBusSearchNoSubway          /**公交搜索的类型:不走高速**/
}QBusSearchType;

/**
 *QRoutePlan:路线方案
 *Author:ksnowlv
 **/
@interface QRoutePlan : NSObject

/**公交搜索的类型，调用者调用busSearch:start:end:withBusSearchType:时传入的**/
@property(nonatomic, assign) QBusSearchType busSearchType;
/**公交搜索的起点信息**/
@property(nonatomic, strong) QPlaceInfo* start;
/**公交搜索的终点信息**/
@property(nonatomic, strong) QPlaceInfo* end;
/**公交搜索的路线列表，存放的是QRouteInfoForBus**/
@property(nonatomic, strong) NSMutableArray* routeInfoList;
/**公交时间(单位:minute)**/
@property(nonatomic, assign) NSInteger time;

@end

/**
 *QDriveSearchType:驾车搜索的类型
 *Author:ksnowlv
 **/
typedef enum  {
    QDriveSearchShortTime  = 0,  /**驾车搜索的类型:时间段**/
    QDriveSearchShortDistance = 2, /**驾车搜索的类型:距离短**/
} QDriveSearchType;


/**
 *QDriveSegmentFeeType:驾车的路段的收费类型
 *Author:ksnowlv
 **/
typedef enum  {
     QDriveSegmentFeeFree  = 0, /** 驾车时路段的收费类型:全路段免费**/
     QDriveSegmentFeeAll,       /** 驾车时路段的收费类型:全路段收费**/
     QDriveSegmentFeePartial    /** 驾车时路段的收费类型:部分路段收费**/
} QDriveSegmentFeeType;


/**
 *QRouteSegmentForDrive:驾车的路段信息
 *Author:ksnowlv
 **/
@interface QRouteSegmentForDrive : NSObject

/** 驾车路段的动作**/
@property(nonatomic, strong) NSString* action;
/** 驾车路段的描述**/
@property(nonatomic, strong) NSString* textInfo;
/** 该驾车路段起点在路线节点中的索引**/
@property(nonatomic, assign) NSInteger startIndex;
/** 该驾车路段终点在路线节点中的索引**/
@property(nonatomic, assign) NSInteger endIndex;
/** 驾车路段的收费类型**/
@property(nonatomic, assign) QDriveSegmentFeeType feeType;
/** 驾车路段的路程(单位:m)**/
@property(nonatomic, assign) NSInteger roadLength;
/** 驾车路段的主要地点列表,存放的是QPlaceInfo对象**/
@property(nonatomic, strong) NSArray* keyPlaceList;
/** 驾车路段的停车场列表,存放的是QPlaceInfo对象**/
@property(nonatomic, strong) NSArray* parkingList;

@end


/**前向声明**/
@class QPlaceInfo;

/**
 *QRouteInfoForDrive:驾车的路线信息
 *Author:ksnowlv
 **/
@interface QRouteInfoForDrive : NSObject

/**驾车搜索的起点信息**/
@property(nonatomic, strong) QPlaceInfo* start;
/**驾车搜索的终点点信息**/
@property(nonatomic, strong) QPlaceInfo* end;
/**驾车路线所用时间**/
@property(nonatomic, assign) NSInteger time;
/**驾车路线的路程(单位:m)**/
@property(nonatomic, assign) NSInteger distance;
/**驾车路线的路经的主要地点数目**/
@property(nonatomic, assign) NSInteger keyPlaceNum;
/**驾车路线的路经的停车场数目**/
@property(nonatomic, assign) NSInteger parkingNum;
/**驾车路线的地理坐标点数组**/
@property(nonatomic, readonly) CLLocationCoordinate2D* routeNodeList;
/**驾车路线的地理坐标点个数**/
@property(nonatomic, readonly) NSUInteger routeNodeCount;
/**驾车路线的路段信息，存放的是QRouteSegmentForDrive对象**/
@property(nonatomic, strong) NSArray* routeSegmentList;

/**
 *根据指定坐标点生成一段路线
 *@param routeNodeList 指定的地理坐标点数组
 *@param routeNodeCount 坐标点的个数
 *@return NULL
 */
- (void)setRouteNodeList:(CLLocationCoordinate2D *)routeNodeList withRouteNodeCount:(NSUInteger)routeNodeCount;

@end


/**
 *QRouteQueryResultChoice:路线查询结果的选择，一般是起点或终点需要重新选择时返回的起点或终点的列表
 **/
@interface QRouteQueryResultChoice : NSObject
/**起点的列表，如果为列表中只有一个时，这项不用选择了，存放的是QPlaceInfo对象**/
@property(nonatomic, strong) NSArray* startList;
/**终点的列表，如果为列表中只有一个时，这项不用选择了，存放的是QPlaceInfo对象**/
@property(nonatomic, strong) NSArray* endList;

@end


/**
 *QRouteSearchResult:路线搜索的结果
 *Author:ksnowlv
 **/
@interface QRouteSearchResult : NSObject

/**错误码，见QErrorCode,
 *当errorCode为QRouteSearchResultBusList或QRouteSearchResultDriveList时,data为QRouteQueryResultChoice，
 当errorCode为QRouteSearchResultBusResult时,data为QRoutePlan，
 当errorCode为QRouteSearchResultDriveResult时,data为QRouteInfoForDrive，
 其他为非正常状态
 **/
@property(nonatomic, assign) QErrorCode errorCode;
/**和errorCode有一一对应关系**/
@property(nonatomic, strong) id data;
/**打车信息，当QRouteSearchResultBusList或QRouteSearchResultDriveList打车费用为空**/
@property(nonatomic, strong) QTaxiInfo* taxiInfo;
/**对调用者可以直接忽略**/
@property(nonatomic, strong) id context;

@end


/**
 *QBusStationInfo:公交线站点信息
 *Author:ksnowlv
 **/
@interface QBusStationInfo : NSObject

/**公交站点名称**/
@property(nonatomic, strong) NSString* name;
/**公交站点UID**/
@property(nonatomic, strong) NSString* uid;
/**公交站点地理坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

/**
 *QBusLineInfo:公交线信息
 *Author:ksnowlv
 **/
@interface QBusLineInfo : NSObject

/**公交线UID**/
@property(nonatomic, strong) NSString* uid;
/**公交线返程UID**/
@property(nonatomic, strong) NSString* reverseUid;
/**公交线公告**/
@property(nonatomic, strong) NSString* announcement;
/**公交线名称**/
@property(nonatomic, strong) NSString* name;
/**公交线始发站**/
@property(nonatomic, strong) NSString* startStation;
/**公交线终点站**/
@property(nonatomic, strong) NSString* endStation;
/**公交线首班车时间**/
@property(nonatomic, strong) NSString* startTime;
/**公交线末班车时间**/
@property(nonatomic, strong) NSString* endTime;
/**公交线路程(单位:km)**/
@property(nonatomic, assign) NSInteger distance;
/**公交线全程价格(单位:元)**/
@property(nonatomic, assign) NSInteger price;
/**公交线节点－显示公交线使用**/
@property(nonatomic, readonly) CLLocationCoordinate2D* busNodeList;
/**公交线节点数目－显示公交线使用**/
@property(nonatomic, readonly) NSUInteger busNodeCount;
/**公交线全部站点,存放的是QBusStationInfo对象**/
@property(nonatomic, strong) NSArray* stationList;

/**
 *指定坐标点生成一段折线
 *@param busNodeList    公交线节点数组
 *@param busNodeCount   公交线节点数目
 *@return 
 */
- (void)setBusNodeList:(CLLocationCoordinate2D*)busNodeList widthBusNodeCount:(NSUInteger)busNodeCount;

@end


/**
 *QBusLineSearchResult:公交线搜索结果
 *Author:ksnowlv
 **/
@interface QBusLineSearchResult : NSObject

/**错误码，见QErrorCode,
 *对busLineSearchResult中的errorCode而言
 当errorCode为QBusLineSearchResultBusInfo时,data为QBusInfo,
 其他为非正常状态,可以参见QErrorCode
 **/
@property(nonatomic, assign) QErrorCode errorCode;
/**和errorCode有一一对应关系**/
@property(nonatomic, strong) id data;

@end

/**
 *QOrderExtraInfo:订单信息
 *Author:weizhengli
 **/
@interface QOrderExtraInfo : NSObject

@property (nonatomic, copy) NSString *order_id;         //订单id
@property(nonatomic) int nav_scene;                     //0未定义 从1开始   导航业务场景：接驾 去目的地 点亮厕所 等  目前 0不用   从1开始   1表示去接乘客    2表示去送乘客
@property (nonatomic, copy) NSString *biz_type;         //快车、专车等  用字符串 填英文  能区分快车 专车等

@end

typedef NS_ENUM(NSUInteger, QRouteSearchErrorType) {
    QRouteSearchErrorTypeDiDi = 0,//滴滴错误
    QRouteSearchErrorTypeTX,//腾讯错误
    QRouteSearchErrorTypeNetworkUnable,//网络不可用
    QRouteSearchErrorTypeNetworkFail,//网络连接错误
};

extern NSString * const QRouteSearchErrorDomainSCTX;//司乘同显
extern NSString * const QRouteSearchErrorDomainYZX;//一致性
extern NSString * const QRouteSearchErrorDomainCar;//普通驾车导航
extern NSString * const QRouteSearchErrorDomainWalk;//步行导航

#define QRouteSearchErrorCode_TXError         (-1)
#define QRouteSearchErrorCode_DiDiDataNull   (99998)
#define QRouteSearchErrorCode_PBError        (99999)

/**
 * 路线搜索错误类
 * @param domain 错误域，对应3种场景，司乘同显（QRouteSearchErrorDomainSCTX），一致性（QRouteSearchErrorDomainYZX）和普通导航（QRouteSearchErrorDomainNormal）
 * @param type 错误分类，对应QRouteSearchErrorType枚举
 * @param code 错误码，每种错误分类下对应一组具体的错误码，错误码的取值为
 |-----------------------------------|--------------------------|-----------------------------------
 |                                   |滴滴返回的错误又细分为3种      | res.ret不为0  |取值为res.ret
 |                                   |                          |---------------|-------------------
 |QRouteSearchErrorTypeDiDi          |                          | 数据空         | 取值为：99999
 |                                   |                          |---------------|-------------------
 |                                   |                          | PB解析失败      | 取值为：99998
 |-----------------------------------|--------------------------------------------------------------
 |QRouteSearchErrorTypeTX            |统一取值为-1
 |-----------------------------------|--------------------------------------------------------------
 |QRouteSearchErrorTypeNetworkUnable |网络请求苹果返回的错误码，-1009，-1001等
 |-----------------------------------|--------------------------------------------------------------
 |QRouteSearchErrorTypeNetworkFail   |网络请求苹果返回的错误码，-1009，-1001等
 |-----------------------------------|--------------------------------------------------------------
 */
@interface QRouteSearchError : NSError

@property (nonatomic, assign) QRouteSearchErrorType type;

@end

