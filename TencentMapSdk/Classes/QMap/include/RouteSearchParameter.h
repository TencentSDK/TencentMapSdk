//
//  RouteSearchParameter.h
//  QQMap
//
//  Created by Nopwang on 5/11/11.
//  Copyright 2011 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QRouteSearch.h"


//typedef enum CalculateFeature_ {
//    CAR_FEATURE_TIME_GOOD  = 0,
//    CAR_FEATURE_FEE_GOOD,
//    CAR_FEATURE_DISTANCE_GOOD,
//    CAR_FEATURE_REALTIME_GOOD
//} CalculateFeature;
typedef enum BusSearchCondition_ {
    BUSSEARCH_COND_EXPRESS  = 0,
    BUSSEARCH_COND_LESS_TRANSFER,
    BUSSEARCH_COND_LESS_WALK,
    BUSSEARCH_COND_RECOMMEND,
    BUSSEARCH_COND_PREFER_SUBWAY,
    BUSSEARCH_COND_PREFER_BUS
} BusSearchCondition;
typedef enum BusResultRecommend_ {
    BUSRECOMMEND_NONE = 0,
    BUSRECOMMEND_EXPRESS ,
    BUSRECOMMEND_LESS_TRANSFER ,
    BUSRECOMMEND_LESS_WALK 
    
} BusSearchRecommendCode;

typedef enum CarSearchCondition_ {
    CARSEARCH_COND_EXPRESS  = 0,
    CARSEARCH_COND_SHORT_DISTANCE = 2,
} CarSearchCondition;

typedef NS_ENUM(NSUInteger, NaviMode) {
    NoneNaviMode,   //非导航模式
    NormalNaviMode, //普通导航模式
    LightNaviMode,  //轻导航模式
};

@interface RouteSearchParameter : NSObject {

}

@property (nonatomic, strong) QPlaceInfo *startPoint;//起点
@property (nonatomic, strong) QPlaceInfo *destPoint;//终点
@property(nonatomic,strong) NSString* city;//城市
@property(nonatomic,assign) float angle;//方向角
@property(nonatomic,assign)NSInteger accuracy;//水平精度
@property(nonatomic,assign)CGFloat speed;//速度
/*第一次算路为空，算路结果中会有args和routeid值，偏航的时候需要带上,routeid是最初路线规划的id，偏航之中不变，nowRouteid是每次偏航算路重新返回的id*/
@property(nonatomic,strong)NSString* routeid;//路线id
@property(nonatomic,strong)NSString* args;//后台返回的路线偏好设置，在偏航请求时需要把这个值带上
@property(nonatomic)NSInteger yawp;//偏航索引
/*每一次路线请求的时候生成一个Id,重算路线时使用*/
@property(nonatomic,strong)NSString* routeSearchId;
@property (nonatomic) NSInteger cond;//驾车搜索类型，0:时间短 2:距离短
@property (nonatomic) BOOL noExpress;//是否走高速
@property (nonatomic) BOOL noToll;//驾车路线搜索参数：是否避免收费道路,默认值NO
@property(nonatomic) BOOL bTraffic;//驾车路线搜索参数：是否结合路况,默认值YES

/*途经点的Array*/
@property(nonatomic,strong)NSArray* lineArray;
@property(nonatomic,strong)NSString* vehicle;//指定车型 　vehicle=bus:大巴，针对超高大型巴士汽车 vehicle=driving (必须为小写字母)普通小客车,缺省值可以不设置
@property(nonatomic,strong)NSArray* routePoints;

@property(nonatomic,strong)NSString* nowRouteId;//每次偏航算路重新返回的id


// 偏航时使用, 第一次路径规划的routeID. 用于驾车导航时.
@property (nonatomic, copy) NSString *standardRouteID;

//新增字段
@property (nonatomic, strong) QOrderExtraInfo *orderExtraInfo;                 //订单相关信息

/*计算jce data*/
-(NSData*)getSearchData:(BOOL)bPh;
-(NSData*)getSearchData:(BOOL)bPh naviMode:(NaviMode)mode PreviousRoutetype:(int)previousRouteType;

/*步行jce*
 参数：isDeviate 是否偏航*/
-(NSData*)getWalkSearchData:(BOOL)isDeviate;

@end
