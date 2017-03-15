//
//  QSCTXRouteGuidanceApi.hpp
//  QMapKit
//
//  Created by NancyNan on 28/11/2016.
//  Copyright © 2016 Tencent. All rights reserved.
//
//  本文件接口是针对司乘同显的使用，对于导航引擎的封装接口
//

#ifndef QSCTXRouteGuidanceApi_h
#define QSCTXRouteGuidanceApi_h

#ifdef __cplusplus
extern "C"
{
#endif
    
    /**
     司乘同显用到的点，墨卡托坐标，对应于RouteGuidanceMapPoint
     */
    typedef struct _QSCTXMapPoint
    {
        int x;
        int y;
    } QSCTXMapPoint;
    
    /**
     司乘同显用到的GPS点，对应于RouteGuidanceGPSPoint
     */
    typedef struct _QSCTXGPSPoint
    {
        int segmentIndex;				// OUT
        QSCTXMapPoint mapPoint;         // IN OUT
        float heading;					// IN OUT 360, Negative if heading is invalid.
        
        int locationAccuracy;			// IN, Negative if locationAccuracy is invalid.
        float velocity;					// IN, m/s Negative if velocity is invalid.
        long timestamp;					// IN, s Negative if timestamp is invalid.
        int source;						// IN, gps source real 0 simulate 1
    } QSCTXGPSPoint;
    
    /**
     事件点类型，对应于RouteGuidanceEventPointType
     */
    typedef enum {
        kQSCTXEventTypeNone = 0,
        kQSCTXEventTypeIntersection = 1,
        kQSCTXEventTypeSpecialguidance = 20,
        
        kQSCTXEventTypeMax = 0xFFFFFFFF
    } QSCTXEventPointType;
    
    /**
     事件点，对应于RouteGuidanceEventPoint
     */
    typedef struct _QSCTXEventPoint
    {
        QSCTXEventPointType type;
        
        int intersection;					// IN intersection of kRouteGuidanceEventTypeIntersection
        
        int segmentIndex;					// IN						//◊™Õ‰µ„µƒµ¿¬∑øÌ∂».
        int distance; // OUT
    }QSCTXEventPoint;
    
    //纹理索引值是从上往下，0是顶部彩虹蚯蚓第一个颜色
    enum SCTX_COLOR_TRAFFIC_NEW {
        SCTX_CTN_THROUGHED   = 0,        //走过的颜色，区别与其它颜色
        SCTX_CTN_LIGHT_BLUE1 = 1,        //无路况，
        SCTX_CTN_RED         = 2,        //拥堵
        SCTX_CTN_YELLOW      = 3,        //缓行
        SCTX_CTN_GREEN       = 4,        //畅通，公交方案里的公交线路
        SCTX_CTN_LIGHT_BLUE5 = 5,        //无数据用淡蓝
        SCTX_CTN_DARK_BLUE   = 6,        //5
        SCTX_CTN_TRANSPARENT = 7,
        SCTX_CTN_NO_SELECTED = 8,        //CT_LIGHT_BLUE, //走过的颜色，区别与其
        SCTX_CTN_BROWN       = 9,        //褐色，猪肝红
        SCTX_CTN_BLACK       = 10,
        SCTX_CTN_DARK_BLACK  = 11,
        SCTX_CTN_WALK_IN_BUS = 30,       //公交方案里的步行线路需要单独绘制点纹理，单独设置
        SCTX_CTN_BUS_IN_BUS = 31,        //公交方案里的公交线路
        SCTX_CTN_SUB_IN_BUS = 32,        //公交方案里的地铁线路
        //    CTN_WALK_ROUTE = 33,      //步行点纹理全部通过KDottedLine类型来处理，color不再生效
        SCTX_CTN_BUS_LINE = SCTX_CTN_DARK_BLUE,   //公交线的整条线路用深蓝色画
        SCTX_CTN_SUB_LINE = SCTX_CTN_DARK_BLUE,   //地铁线的整条线路用深蓝色画
        SCTX_CTN_NONE = SCTX_CTN_DARK_BLUE,
    };
    
    /**
     创建导航引擎实例

     @return 导航引擎实例
     */
    void *QSCTXRouteGuidanceCreate();
    
    /**
     销毁导航引擎实例

     @param rgHandle 导航引擎实例
     */
    void QSCTXRouteGuidanceDestroy(void *rgHandle);
    
    /**
     传入导航路线数据到引擎

     @param rgHandle 导航引擎实例
     @param route_id 路线ID
     @param mapPoints 点串坐标
     @param mapPointsCount 点串坐标数量
     @param eventPoints 事件点
     @param eventPointsCount 事件点数量
     @return <#return value description#>
     */
    int QSCTXRouteGuidanceSetMapPoints(void *rgHandle, unsigned short *route_id, QSCTXMapPoint *mapPoints, int mapPointsCount, QSCTXEventPoint *eventPoints, int eventPointsCount);

    /**
     定位点更新进行路线吸附

     @param rgHandle 导航引擎实例
     @param gpsPoint GPS定位点数据
     @param matchedPoint 返回的吸附后的点
     */
    void QSCTXRouteGuidanceSetGPSPoint(void *rgHandle, QSCTXGPSPoint *gpsPoint, QSCTXGPSPoint *matchedPoint);
    
    /**
     定位点更新进行路线吸附（无角度吸附）
     
     @param rgHandle 导航引擎实例
     @param gpsPoint GPS定位点数据
     @param matchedPoint 返回的吸附后的点
     */
    void QSCTXRouteGuidanceSetGPSPointNoGpsAngle(void *rgHandle, QSCTXGPSPoint *gpsPoint, QSCTXGPSPoint *matchedPoint);
    
    /**
     根据点串索引返回事件点，sdk use   QSCTXRouteGuidanceGetEventPoint

     @param rgHandle 导航引擎实例
     @param segIndex 点串索引
     @return 返回事件点
     */
    QSCTXEventPoint QSCTXRouteGuidanceGetEventPoint(void *rgHandle, int segIndex);
    
#ifdef __cplusplus
}
#endif

#endif /* QSCTXRouteGuidanceApi_hpp */

