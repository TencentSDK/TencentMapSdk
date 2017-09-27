//
//  QRouteInfo.h
//  QMapKit
//
//  Created by sanfordzhang on 16/04/15.
//  Copyright (c) 2016年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "QTypes.h"
#import "QGeometry.h"

#define MAX_COLOR_COUNT 16

typedef NS_ENUM(NSUInteger, BezierType) {
    FirstLevelBezier = 0,
    SecondLevelBezier,
    ThirdLevelBezier,
};

/**每个点的经纬度值**/
@interface QRoutePoint : NSObject
@property(nonatomic, assign) CLLocationCoordinate2D coord;
@end


/**每一条路线都会分成几段，一段就是一个QRouteLine**/
@interface QRouteLine : NSObject
/**每一段线都会有n个点，点的信息都保存在QRouteOverlay的arrPoint中
 startNum是这段线的起点的索引位置**/
@property(nonatomic, assign) NSInteger startNum;
/**endNum是这段线的终点的索引位置**/
@property(nonatomic, assign) NSInteger endNum;
/**这段线的颜色纹理索引，是彩虹蚯蚓纹理颜色的索引值，例如绿色是4**/
@property(nonatomic, assign) NSUInteger colorIndex;

/**路线的速度，保留值**/
@property(nonatomic, assign) NSInteger speed;
/**路线的名称，保留值**/
@property(nonatomic, copy) NSString* roadName;
@end

/**每一条路线都是一个QRouteOverlay**/
@interface QRouteOverlay : NSObject
/**每一条路线所有点信息，成员类型是QRoutePoint**/
@property(nonatomic, strong) NSMutableArray* arrPoint;
/**每一条路线的所有分段信息，成员类型是QRouteLine**/
@property(nonatomic, strong) NSMutableArray* arrLine;
/**每一条路线的线宽,单位是Point*/
@property(nonatomic, assign) CGFloat lineWidth;
/**每一条路线的类型，分彩虹蚯蚓，点纹理，虚线类型**/
@property(nonatomic, assign) QMRouteDrawType drawType;

/**彩虹蚯蚓多纹理的行数，彩虹蚯蚓纹理使用的属性**/
@property(nonatomic, assign) int textureRow;

/*箭头纹理名称,如果不在mainBundle下，请用绝对路径*/
@property(nonatomic, strong) NSString* arrowImageName;

/**彩虹蚯蚓点纹理的间距(icon大小的倍数)，点纹理使用的属性**/
@property(nonatomic, assign) CGFloat dottedLineStep;

/**
 * 蚯蚓线上箭头宽度
 *arrowSpacing默认值为100，单位为point，所以变化间距为100~200point
 */
@property(nonatomic, assign)CGFloat arrowSpacing;

/**
 * 点路线的间距
 * footPrintSpacing 默认值为30，单位为point，所以变化间距为30~60point
 */
@property(nonatomic, assign)CGFloat footPrintSpacing;

/**
 * 路线的优先级
 */
@property(nonatomic, assign)NSInteger dispLevel;

/**是否绘制路线上的箭头，只有彩虹蚯蚓才能画箭头**/
@property(nonatomic, assign) BOOL isDrawArrow;

/**是否绘制路线两端的半圆纹理，只有彩虹蚯蚓才能画端纹理**/
@property(nonatomic, assign) BOOL isDrawCap;

/*
 * 彩虹蚯蚓不同的纹理效果在一张图片内
 */
@property(nonatomic, strong) NSString* textureNameMultiLine;

/**
 * 自定义颜色列表,最多16个UIColor, 多出不起作用
 */
@property(nonatomic, strong)NSArray<UIColor *> *colorListForMultiLine;

/**
 * 是否使用 textureNameMultiLine 作为路线颜色
 * 如果为NO, 则使用colorListForMultiLine作为路线颜色
 * 默认为YES, 如果为NO但是colorListForMultiLine无有效的颜色值,则使用textureNameMultiLine
 */
@property(nonatomic, assign)BOOL useTextureForMultiLine;

/**虚线绘制纹理文件名,可用来更换纹理，必须含有扩展名**/
@property(nonatomic, strong) NSString* textureNameImaginaryLine;

/**点线绘制纹理文件名,可用来更换纹理，必须含有扩展名**/
@property(nonatomic, strong) NSString* textureNameDottedLine;

/*贝塞尔曲线阶数
 */
@property (nonatomic,assign) BezierType orderOfBezier;

/*是否使用默认的控制点，如果为YES将不会使用controlPoints属性
 */
@property (nonatomic,assign) BOOL isUserDefaultControl;

/**
 * 贝塞尔曲线控制点数
 */
@property (nonatomic,strong) NSArray* controlPoints;

/**
 * 生成路线对象
 * arrPoint     这条路线所有的点信息
 * arrLine      这条路线所有的分段信息
 */
- (id)initWithArrData:(NSArray*)arrPoint arrLine:(NSArray*)arrLine;

@end

/**所有的线可以分组，一个路线组包含n条路线，
 新增、删除路线可以分组来进行操作**/
@interface QRouteOverlayGroup : NSObject

/**一个路线组包含的所有路线，成员类型是QRouteOverlay**/
@property(nonatomic, strong) NSMutableArray* arrOverlay;
/**一个路线组索引，用来区分组，最多只能新增100个路线组**/
@property(nonatomic, assign) NSInteger groupIndex;

/**
 * 生成路线组对象
 * arrOverlay     这条路线所有的点信息
 * arrLine      这条路线所有的分段信息
 */
- (id)initWithArrData:(NSArray*)arrOverlay;

/**
 * 增加路线
 * routeOverlay     新增路线，之前的路线组里的路线还会保留
 * 要删除路线需要调用QMapView的removeRouteOverlayGroup方法
 */
- (void)addRouteOverlay:(QRouteOverlay*)routeOverlay;

/**
 * 所有点的可见区域
 * arrPoint    可以根据n个点算出她的可见区域
 */
- (QMapRect)visibleRect:(NSArray*)arrPoint;

/**
 * 这个路线组的所有点的可见区域
 */
- (QMapRect)frame;

@end


