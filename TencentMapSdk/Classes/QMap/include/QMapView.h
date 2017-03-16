 /*
 ============================================================================
 Name           : QMapView.h
 Author         : 腾讯地图
 Version        : 2.0
 Copyright      : 腾讯
 Description    : QMapView declaration
 ============================================================================
 */

#import <UIKit/UIKit.h>
#import <MapKit/Mapkit.h>
#import <MapKit/MKFoundation.h>
#import "QAnnotationView.h"
#import "QAnnotation.h"
#import "QOverlay.h"
#import "QOverlayView.h"
#import "QGeometry.h"
#import "QTypes.h"
#import "QUserLocation.h"
#import "QMRoute.h"
#import "QRouteSearch.h"
#import "QOverlay.h"
#import "QTileOverlay.h"
#import "QttsParam.h"
#import "QOverspeedInfo.h"
#import "QRouteInfo.h"

@class RouteResult;
@class QPointAnnotation;
@class QRouteOverlay;
@class QRouteOverlayGroup;
@class QBusStationBubble;
@class QAnnotation;

@protocol QMapViewDelegate;
@protocol QMapNavigationDelegate;
@protocol QDynamicChangeRouteProtocol;

/**
 * QMapView:地图View类,可以显示地图窗口，并且对地图进行相关的操作,如拖动，放缩等
 */
@interface QMapView : UIView

#pragma mark - Delegates
/**
 * 指定地图语言的初始化方法
 * @param frame 地图frame
 * @param language 初始化地图的语言
 */
- (instancetype)initWithFrame:(CGRect)frame mapLanguage:(QMapLanguage)language;

#pragma mark - Delegates
/** 
 * 地图View的Delegate
 */
@property(nonatomic, weak)IBOutlet id <QMapViewDelegate> delegate;

/** 
 * 导航专用的Delegate
 */
@property(nonatomic, weak)IBOutlet id <QMapNavigationDelegate> navDelegate;

#pragma mark - Map appearance
/**
 * 当前地图类型，可设定为普通模式或卫星地图模式
 */
@property(nonatomic, assign) QMapType mapType;

/**
 *是否显示路况
 */
@property(nonatomic)BOOL showTraffic;

/**
 *是否3D模式显示地图
 */
@property(nonatomic)BOOL show3D;

/**
 *  @brief 楼块是否显示2D效果, 默认为NO
 *  @warning SDK2.0 以后2D模式下都不显示楼块的3D效果，只有地图在3D模式下才会显示楼块，所以这个属性在2.0上只在地图3D模式下有作用
 */
@property (nonatomic, assign, getter = isDisable3DBuildingEffect) BOOL disable3DBuildingEffect;

/**
 * 设定是否显示指南针
 */
@property(nonatomic, assign) BOOL showsCompass;

/**
 * 设置地图语言
 */
@property(nonatomic, assign) QMapLanguage mapLanguage;

/**
 * 设置地图比例尺偏移
 * @param offset 比例尺中心的偏移量. 如果offset为CGPointZero则为默认位置
 */
- (void)setScaleViewOffset:(CGPoint) offset;

/**
 * 设置地图比例尺隐藏
 * @param hidden是否隐藏，YES隐藏，否则不隐藏
 */
- (void)setScaleViewHidden:(BOOL)hidden;

/**
 * 获取比例尺的显示状态
 */
- (BOOL)isScaleViewHidden;

/**
 * 设置地图Logo偏移
 * @param offset Logo中心的偏移量. 如果offset为CGPointZero则为默认位置
 */
- (void) setLogoOffSet:(CGPoint)offset;

/**
 * 设置3D模式下是否显示楼块
 * @param isShow是否显示，YES显示，否则不显示
 */
- (void) setIsShowPillarIn3D:(BOOL)isShow;

/*
 * 3D模式下是否显示楼块
 */
- (BOOL) isShowPillarIn3D;

/**
 * 设置指南针偏移
 * @param yOffset 指南针中心Y基于默认位置的偏移量
 */
- (void) setCompassYOffSet:(CGFloat)yOffset;

/**
 * 显示自定义的路况数据
 * @param trafficData 路况数据
 * @param cityName 城市名
 */
-(void)showCustomTraffic:(NSData*)trafficData cityName:(NSString*)cityName;

/**
 * 设置路况的颜色, ABGR格式
 * @param normalColor 普通的路况颜色， 默认 0xff11c7ff（黄色）
 * @param blockColor 拥堵的路况颜色， 默认0xff1e1edc（红色）
 * @param unBlockColor 畅通的路况颜色， 默认0xff68d8a5 （绿色）
 * @param extremeBlockColor 极度拥堵的路况颜色，默认0xff000099 (深红)
 */
- (void)setTrafficColor:(QMapColor)normalColor blockColor:(QMapColor)blockColor unBlockColor:(QMapColor)unBlockColor extremeBlockColor:(QMapColor)extremeBlockColor;

#pragma mark - Others

/**
 * 调试开关，用于输出日志
 */
@property(nonatomic, assign) BOOL isDebug;

/**
 * 如果需要传入非地图Bundle下的图片，请使用getImageFilePathFlag
 * 方法获得路径标识，sdk会根据此标识来加载指定路径下的图片,ImageFilePathFlag后面请跟绝对路径
 * 此方法适合annotation.imageName及路线纹理等指定路径的图片
 */
- (NSString*)getImageFilePathFlag:(NSString*)imageFilePath;

#pragma mark - Gesture

/**
 * 设定地图View能否支持用户长按，默认为NO
 */
@property(nonatomic, getter=isLongPressedEnabled) BOOL longPressedEnabled;

/**
 * 设定地图View能否支持用户多点缩放
 */
@property(nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;

/**
 * 设定地图View能否支持用户移动地图
 */
@property(nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;

/**
 * 是否支持手势进入3D模式. 默认为YES.
 */
@property (nonatomic, assign, getter=isPitchEnabled) BOOL pitchEnabled;

#pragma mark - Map zoom & map scale

/**
 * @brief 地图比例尺级别
 * @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 */
@property(nonatomic, assign) NSInteger zoomLevel;

/**
 *  @brief 地图比例尺级别，浮点型
 *  @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 */
@property(nonatomic,readonly,assign) CGFloat mapScale;

/**
 * 是否支持按照中心点缩放, 默认为NO.
 */
@property (nonatomic, assign, getter=isStayCenteredDuringZoom) BOOL stayCenteredDuringZoom;

/**
 * 如果不支持按中心点缩放, 则以anchorPoint为缩放中心点
 */
@property(nonatomic, assign) CGPoint anchorPointOfScale;

/**
 * 放大一级比例尺
 */
- (void)zoomIn;

/**
 * 缩小一级比例尺
 */
- (void)zoomOut;

/**
 * 根据指定位置为中心，放大一级比例尺
 * @param x 指定位置x坐标
 * @param y 指定位置y坐标
 * @param animated 是否动画
 */
- (void)zoomInOnPoint:(CGFloat)x y:(CGFloat)y animated:(BOOL)animated;

/**
 * 根据指定位置为中心，缩小一级比例尺
 * @param x 指定位置x坐标
 * @param y 指定位置y坐标
 * @param animated 是否动画
 */
- (void)zoomOutOnPoint:(CGFloat)x y:(CGFloat)y animated:(BOOL)animated;

/**
 *  计算与mapRect相匹配的zoomLevel
 *  @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 *  @param mapRect mapRect
 *  @return 相匹配的zoomLevel
 */
- (NSInteger)zoomLevelFitsMapRect:(QMapRect)mapRect;

/**
 *  计算与region相匹配的zoomLevel
 *  @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 *  @param region region
 *  @return 相匹配的zoomLevel
 */
- (NSInteger)zoomLevelFitsRegion:(QCoordinateRegion)region;

/**
 *  计算与mapRect相匹配的 mapScale
 *  @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 *  @param mapRect mapRect
 *  @return 相匹配的mapScale 浮点型
 */
- (CGFloat) mapScaleFitsMapRect:(QMapRect)mapRect;

/**
 * 计算与mapRect相匹配的 mapScale
 * @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 * @param mapRect mapRect
 * @param insets mapRect四周要预留的边界大小
 * @return 相匹配的mapScale 浮点型
 */
- (CGFloat) mapScaleFitsMapRect:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets;

/**
 * 计算与QCoordinateRegion相匹配的 mapScale
 * @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 * @param region QCoordinateRegion类型
 * @return 相匹配的mapScale 浮点型 mapScale 与
 */
- (CGFloat) mapScaleFitsRegion:(QCoordinateRegion)region;

/**
 * 计算与QCoordinateRegion相匹配的 mapScale
 * @warning mapScale与zoomLevel 没有对应关系, mapScale仅仅用于更精确的表示地图比例尺级别的变化
 * @param region QCoordinateRegion类型
 * @param insets mapRect四周要预留的边界大小
 * @return 相匹配的mapScale 浮点型
 */
- (CGFloat) mapScaleFitsRegion:(QCoordinateRegion)region edgePadding:(UIEdgeInsets)insets;

#pragma mark - Life circle & Memory

/**
 * 清理内存中的地图缓存
 */
-(void) mapHibernate;

/**
 * 在显示MapView的Controlller的ViewWillAppear中调用，开启地图的显示状态。
 */
- (void)viewWillAppear;

/**
 * 在地图消失后调用，停止地图的渲染。
 */
- (void)viewDidDisappear;

#pragma mark - Snapshot

/**
 * 返回当前mapview截图
 * @return UIImage
 */
-(UIImage *) mapViewToUIImage;

#pragma mark - User location

/**
 * 设定是否显示用户位置
 */
@property(nonatomic) BOOL showsUserLocation;

/**
 * 是否隐藏定位精度圈. 默认为NO.
 */
@property(nonatomic, assign) BOOL hideAccuracyCircle;

/**
 * 当前用户位置，返回坐标为经纬度坐标等,非导航下返回的是原始经纬度，导航下返回的是吸附后的经纬度
   只提供了经纬度，title，subtitle等信息
 */
@property(nonatomic, readonly) QUserLocation *userLocation;

/**
 * 返回定位坐标点是否在当前地图可视区域内
 */
@property(nonatomic, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;

/**
 * 返回定位坐标点是否有效
 */
@property (nonatomic, readonly, getter=isUserLocationAvailable) BOOL userLocationAvailable;
/**
 * 返回当前定位点所在的城市
 */
@property (nonatomic, readonly) NSString *currentCity;

/**
 * 设置用户位置的跟踪模式
 */
@property (nonatomic) QMUserTrackingMode userTrackingMode;

/**
 * 设备更新位置信息的最小距离
 */
@property(assign, nonatomic) CLLocationDistance distanceFilter;

/**
 * 位置数据的精度
 */
@property(assign, nonatomic) CLLocationAccuracy desiredAccuracy;

/**
 * 开启罗盘追踪模式
 */
-(void)startTrackingModeFollowWithHeading;

/**
 * 开启罗盘模式
 **/
-(void)startTrackingModeFollow;

/**
 * 关闭罗盘模式
 */
-(void)stopTrakingModeFollowWithHeading;

/**
 * 设定罗盘模式
 * @param userTrackingMode 用户跟随模式
 * @param animated 是否采用动画效果
 */
- (void)setUserTrackingMode:(QMUserTrackingMode)userTrackingMode animated:(BOOL)animated;

/**
 * 设定是否显示用户位置
 * @param bNeedCenterMap 显示用户位置后是否需要居中
 */
-(void)showsUserLocation:(BOOL)showsUserLocation withMapCenter:(BOOL)bNeedCenterMap;

#pragma mark - Region

/**
 * 当前地图的经纬度范围，设定的该范围可能会被调整为适合地图窗口显示的范围
 */
@property(nonatomic) QCoordinateRegion region;

/**
 * 设定当前地图的显示范围
 * @param region 要设定的地图范围，用经纬度的方式表示
 * @param animated 是否采用动画效果
 */
- (void)setRegion:(QCoordinateRegion)region animated:(BOOL)animated;

/**
 * 设定当前地图的显示范围
 * @param region 要设定的地图范围，用经纬度的方式表示
 * @param insets 指定的四周边界大小
 * @param animated 是否采用动画效果
 */
- (void)setRegion:(QCoordinateRegion)region
      edgePadding:(UIEdgeInsets)insets
         animated:(BOOL)animated;

/**
 * 根据当前地图View的窗口大小调整传入的region，返回适合当前地图窗口显示的region，调整过程会保证中心点不改变
 * @param region 待调整的经纬度范围
 * @return 调整后适合当前地图窗口显示的经纬度范围
 */
- (QCoordinateRegion)regionThatFits:(QCoordinateRegion)region;

#pragma mark - Center coordiante

/**
 * 当前地图的中心点，改变该值时，地图的比例尺级别不会发生变化
 */
@property(nonatomic) CLLocationCoordinate2D centerCoordinate;

/**
 * 设定地图中心点坐标
 * @param coordinate 要设定的地图中心点坐标，用经纬度表示
 * @param animated 是否采用动画效果
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

/**
 * 设定地图中心点坐标
 * @param coordinate 目标坐标
 * @param duration   动画时间 (小于等于0.0 无效, 当animated == YES 时有效)
 * @param animated   是否动画
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                   duration:(NSTimeInterval)duration
                   animated:(BOOL)animated;

/**
 * 设定地图中心点坐标和显示级别
 * @param coordinate 要设定的地图中心点坐标，用经纬度表示
 * @param zoomLevel 地图的比例尺级别
 * @param animated 是否采用动画效果
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                  zoomLevel:(int)zoomLevel
                   animated:(BOOL)animated;

/**
 * 设定地图中心点坐标和显示级别
 * @param coordinate 要设定的地图中心点坐标，用经纬度表示
 * @param zoomLevel 地图的比例尺级别
 * @param animated 是否采用动画效果
 * @param curveType 动画曲线类型
 * @param second 动画执行时间，单位秒
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                  zoomLevel:(int)zoomLevel
                   animated:(BOOL)animated
                  curveType:(QMapAnimationCurveType)curveType
                   duration:(NSTimeInterval)duration;

/**
 * 是否需要用聚焦的效果动画设定地图中心点坐标和显示级别,
 * @param coordinate 要设定的地图中心点坐标，用经纬度表示
 * @param zoomLevel 地图的比例尺级别
 * @param animated 是否采用动画效果
 * @param curveType 动画曲线类型
 * @param duration 动画执行时间，单位秒
 * @param bFocusEffect 聚焦效果，当设置前后中心点不在一个屏幕时，先缩小到能显示前后中心点的地图区域，然后再放大到设置后的地图区域, 当animationType 为QMapAnimationCurveNone 此设置无效。
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                  zoomLevel:(int)zoomLevel
                   animated:(BOOL) animated
                  curveType:(QMapAnimationCurveType)curveType
                   duration:(NSTimeInterval)duration
                focusEffect: (BOOL) bFocusEffect;

/**
 * 以anchorPoint偏移设定地图中心点坐标和显示级别
 * @param coordinate 要设定的地图中心点坐标，用经纬度表示
 * @param anchorPoint 以屏幕anchorPoint作为实际的显示中心点（屏幕像素值）
 * @param zoomLevel 地图的比例尺级别
 * @param animated 是否采用动画效果
 * @param curveType 动画曲线类型
 * @param duration 动画执行时间，单位秒
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                anchorPoint:(CGPoint)anchorPoint
                  zoomLevel:(int)zoomLevel
                   animated:(BOOL)animated
                  curveType:(QMapAnimationCurveType)curveType
                   duration:(NSTimeInterval)duration;

/**
 * 设置地图中心点(Anchor Point)下移（可用来根据地图可见区域，调整地图中心点）
 * @param offsetY 锚点的偏移量，正值往下偏移, 上(下)偏移的最大幅度为地图Frame高度的四分之一
 * @param curveType 动画曲线类型
 * @param duration 动画执行时间，单位秒，如果不想要动画，设置duration为0
 * @param completion 动画完成的回调,finished 动画是否完成, animated 是否动画
 */
- (void)setCenterOffsetY:(CGFloat)offsetY
               curveType:(QMapAnimationCurveType)curveType
                  duration:(NSTimeInterval)duration
                completion:(void (^)(BOOL finished, BOOL animated))completion;


#pragma mark - MapRect

/**
 * 当前地图范围，采用直角坐标系表示，向右向下增长
 */
@property(nonatomic) QMapRect visibleMapRect;

/**
 * 设定当前地图的显示范围,采用直角坐标系表示
 * @param mapRect 要设定的地图范围，用直角坐标系表示
 * @param animate 是否采用动画效果
 */
- (void)setVisibleMapRect:(QMapRect)mapRect animated:(BOOL)animated;

/**
 * 根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect，调整过程会保证中心点不改变
 * @param mapRect 待调整的地理范围，采用直角坐标系表示
 * @return 调整后适合当前地图窗口显示的地图范围，采用直角坐标系
 */
- (QMapRect)mapRectThatFits:(QMapRect)mapRect;

/**
 * 根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect，并且在该mapRect四周保留insets指定的边界区域
 * @param mapRect 待调整的地理范围，采用直角坐标系表示
 * @param insets mapRect四周要预留的边界大小
 * @return 调整后适合当前地图窗口显示的地理范围，采用直角坐标系
 */
- (QMapRect)mapRectThatFits:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets;

/**
 * 根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect，调整过程会保证中心点不改变
 * @param mapRect 待调整的地理范围，采用直角坐标系表示
 * @return 调整后适合当前地图窗口显示的地图范围，采用直角坐标系
 */
- (QMapRect)mapRectThatContainsCalloutView:(QMapRect)mapRect;

/**
 * 根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect，调整过程会保证中心点不改变
 * @param mapRect 待调整的地理范围，采用直角坐标系表示
 * @param insets mapRect四周要预留的边界大小
 * @return 调整后适合当前地图窗口显示的地图范围，采用直角坐标系
 */
- (QMapRect)mapRectThatContainsCalloutView:(QMapRect)mapRect edgePadding:(UIEdgeInsets)insets;

/**
 * 根据当前地图View的窗口大小调整传入的mapRect，返回适合当前地图窗口显示的mapRect，调整过程会保证中心点不改变
 * @param mapRect 待调整的地理范围，采用直角坐标系表示
 * @param bCantainsCalloutView 计算的maprect是否需要包含calloutView
 * @param annotations 要包含的annotation 数组
 * @param insets mapRect四周要预留的边界大小
 * @return 调整后适合当前地图窗口显示的地图范围，采用直角坐标系
 */
- (QMapRect)mapRectThatFits: (QMapRect)mapRect
        containsCalloutView:(BOOL)bContainsCalloutView
                annotations:(NSArray*)annotations
                edgePadding:(UIEdgeInsets)insets;
    
/**
 * 设定地图的显示范围,并使mapRect四周保留insets指定的边界区域
 * @param mapRect 要设定的地图范围，用直角坐标系表示
 * @param insets 指定的四周边界大小
 * @param animated 是否采用动画效果
 */
- (void)setVisibleMapRect:(QMapRect)mapRect
              edgePadding:(UIEdgeInsets)insets
                 animated:(BOOL)animated;

/**
 * 设定地图的显示范围,并使mapRect四周保留insets指定的边界区域
 * @param mapRect 要设定的地图范围，用直角坐标系表示
 * @param insets 指定的四周边界大小
 * @param animated 是否采用动画效果
 * @param animated 只在2d下处理可见区域
 */
- (void)setVisibleMapRect:(QMapRect)mapRect
              edgePadding:(UIEdgeInsets)insets
                 animated:(BOOL)animated
                     on2d:(BOOL)on2d;

/**
 * 设定地图的显示范围,并使mapRect四周保留insets指定的边界区域,如果不需要动画，请使用QMapAnimationCurveNone
 * @param mapRect 要设定的地图范围，用直角坐标系表示
 * @param insets 指定的四周边界大小
 * @param animationType 动画类型
 * @param duration 动画时间
 * @param bFocusEffect 聚焦效果，当设置前后中心点不在一个屏幕时，先缩小到能显示前后中心点的地图区域，然后再放大到设置后的地图区域, 当animationType 为QMapAnimationCurveNone 此设置无效。
 */
- (void)setVisibleMapRect:(QMapRect)mapRect
              edgePadding:(UIEdgeInsets)insets
            animationType:(QMapAnimationCurveType)animationType
                 duration:(NSTimeInterval)duration
              focusEffect:(BOOL) bFocusEffect;

#pragma mark - Converting Coordinate System

/**
 * 将经纬度坐标转换为View坐标
 * @param coordinate 待转换的经纬度坐标
 * @param view 指定相对的View
 * @return 转换后的View坐标
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;

/**
 * 将View坐标转换成经纬度坐标
 * @param point 待转换的View坐标
 * @param view point坐标所在的view
 * @return 转换后的经纬度坐标
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView *)view;

/**
 * 将经纬度矩形区域转换为View矩形区域
 * @param region 待转换的经纬度矩形
 * @param view 指定相对的View
 * @return 转换后的View矩形区域
 */
- (CGRect)convertRegion:(QCoordinateRegion)region toRectToView:(UIView *)view;

/**
 * 将View矩形区域转换成经纬度矩形区域
 * @param rect 待转换的View矩形区域
 * @param view rect坐标所在的view
 * @return 转换后的经纬度矩形区域
 */
- (QCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView *)view;

/**
 * 获取反转偏移坐标
 * return 转换后的坐标
 **/
-(CLLocationCoordinate2D)coordinateOffset:(CLLocationCoordinate2D)coordinate;

/**
 * 在当前缩放级别下，基于地图中心点，1 sreen point对应的距离
 * @return 对应的距离(单位为米)
 */
-(CGFloat)metersPerPointForCurrentZoomLevel;

/**
 * 获取反转偏移坐标
 * @param coordinate 火星坐标
 * @return 转换后的坐标
 */
+(CLLocationCoordinate2D)coordinateOffset:(CLLocationCoordinate2D)coordinate;

#pragma mark - Annotation

/*
 * 点击地图是否清除calloutView, 默认为NO
 */
@property(nonatomic,assign)BOOL keepCallout;

/**
 * 当前地图View的已经添加的标注数组
 */
@property(nonatomic, readonly) NSArray *annotations;

/**
 * 向地图窗口添加标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotation 要添加的标注
 */
- (BOOL)addAnnotation:(id <QAnnotation>)annotation;

/**
 * 向地图窗口添加标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotation 要添加的标注
 * @param animated 是否支持动画
 */
- (BOOL)addAnnotation:(id <QAnnotation>)annotation animated:(BOOL)animated;

/**
 * 向地图窗口添加一组标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotations 要添加的标注数组
 */
- (BOOL)addAnnotations:(NSArray *)annotations;

/**
 * 向地图窗口添加一组标注，需要实现QMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotations 要添加的标注数组
 * @param animated 是否支持动画
 */
- (BOOL)addAnnotations:(NSArray *)annotations animated:(BOOL)animated;

/**
 * 移除标注
 * @param annotation 要移除的标注
 */
- (void)removeAnnotation:(id <QAnnotation>)annotation;

/**
 * 移除一组标注
 * @param annotation 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray *)annotations;

/**
 * 查找指定标注对应的View，如果该标注尚未显示，返回nil
 * @param annotation 指定的标注
 * @return 指定标注对应的View
 */
- (QAnnotationView *)viewForAnnotation:(id <QAnnotation>)annotation;

/**
 * 根据指定标识查找一个可被复用的标注View，一般在delegate中使用，用此函数来代替新申请一个View
 * @param identifier 指定标识
 * @return 返回可被复用的标注View
 */
- (QAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/**
 * 将制定的annotation放在最上层渲染.
 *  @param annotation 指定的annotation
 */
- (void)bringAnnotationToFront:(id <QAnnotation>)annotation;

/**
 * 选中指定的标注
 * @param annotation 指定的标注
 * @param animated 是否支持动画
 */
- (void)selectAnnotation:(id <QAnnotation>)annotation animated:(BOOL)animated;

/**
 * 取消指定的标注的选中状态
 * @param annotation 指定的标注
 * @param animated 是否支持动画
 */
- (void)deselectAnnotation:(id <QAnnotation>)annotation animated:(BOOL)animated;

/**
 * 更新annotation的image和锚点
 * @param annotation 要设定的annotation
 * @param imageName 更新的图片,必须带有扩展名
 * @param drawMode 图片的AnchorPoint
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
              imageName:(NSString*)imageName
               drawMode:(ImageDrawMode)drawMode;
/**
 * 更新annotation的坐标
 * @param annotation 要设定的annotation
 * @param coordinate 移动后的坐标点
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation coordinate:(CLLocationCoordinate2D)coordinate ;

/**
 * 更新annotation的坐标,若要同时更新角度，请使用updateAnnotation: coordinate:angle:duration:  animated: 方法
 * @param annotation 要设定的annotation
 * @param coordinate 移动后的坐标点
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
             coordinate:(CLLocationCoordinate2D)coordinate
               duration: (NSTimeInterval)duration
               animated:(BOOL) bAnimated;
/**
 * 更新annotation的旋转角度
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param angle 旋转角度
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation angle:(CGFloat)angle;

/**
 * 更新annotation的旋转角度 ,若要同时更新位置，请使用updateAnnotation: coordinate:angle:duration:  animated: 方法
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param angle 旋转角度
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
                  angle:(CGFloat)angle
               duration:(NSTimeInterval)duration
               animated:(BOOL) bAnimated;

/**
 * 更新annotation的位置和旋转角度
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param coordinate 移动后的坐标点
 * @param angle 旋转角度
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
             coordinate:(CLLocationCoordinate2D)coordinate
                  angle:(CGFloat)angle
               duration: (NSTimeInterval)duration
               animated:(BOOL) bAnimated;

/**
 * 更新annotation的位置和旋转角度
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param angle 旋转角度
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 * @param completion 动画完成时的处理
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
                  angle:(CGFloat)angle
               duration: (NSTimeInterval)duration
               animated:(BOOL) bAnimated
             completion:(void (^)(BOOL finished))completion;

/**
 * 更新annotation的位置和旋转角度
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param mapPoint 地图投影之后的平面坐标点
 * @param angle 旋转角度
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 * @param completion 动画完成时的处理
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
               mapPoint:(QMapPoint)mapPoint
                  angle:(CGFloat)angle
               duration: (NSTimeInterval)duration
               animated:(BOOL) bAnimated
             completion:(void (^)(BOOL finished))completion;
/**
 * 更新annotation的位置和旋转角度
 * @param coordinate 移动后的坐标点
 * @param annotation 要设定的annotation annotation对应的AnnotationView的ImageDrawMode 必须为KIMAGE_MIDDLE_CENTER_MODE
 * @param angle 旋转角度
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 * @param completion 动画完成时的处理
 */
-(void)updateAnnotation:(id<QAnnotation>)annotation
             coordinate:(CLLocationCoordinate2D)coordinate
                  angle:(CGFloat)angle
               duration: (NSTimeInterval)duration
               animated:(BOOL) bAnimated
             completion:(void (^)(BOOL finished))completion;
/**
 * 更新annotation的alpha值
 * @param 目标alpha值
 */
- (void)updateAnnotation:(id<QAnnotation>)annotation alpha:(CGFloat)alpha;

/**
 * 更新annotation的alpha值
 * @param annotation 要设定的annotation
 * @param 目标alpha值
 * @param duration 动画持续的时间
 * @param bAnimated 是否动画
 */
- (void)updateAnnotation:(id<QAnnotation>)annotation
                   alpha:(CGFloat)alpha
                duration:(NSTimeInterval)duration
                animated:(BOOL)bAnimated;

/**
 * 更新annotation的dispLevel
 * @param annotation 要设定的annotation
 * @param dispLevel annotation的优先级
 */
- (void)updateAnnotationDispLevel:(id<QAnnotation>)annotation dispLevel:(int)dispLevel;

/**
 * 按比例缩放annotationView
 * @param scale 放大的比例
 * @param duration 动画持续的时间
 * @param delay 延迟运行动画的时间
 * @param curveType 动画类型
 * @param completion 动画完成后的回调
 */
- (void)updateAnnotation:(id<QAnnotation>)annotation
                   scale:(CGFloat)scale
                duration:(NSTimeInterval)duration
                   delay:(NSTimeInterval)delay
               curveType:(QMapAnimationCurveType)curveType
              completion:(void (^)(BOOL finished))completion;

#pragma mark - Bubbles
/**
 * 点击地图是否清除多气泡, 默认为NO
 */
@property(nonatomic,assign)BOOL keepBubble;

/**
 * 插入一组bus气泡到底图上
 * @param 气泡描述信息的数组，包括站点名＋上车／下车／进站／出站＋线路信息
 */
- (void)insertBusBubble:(NSArray<QBusStationBubble*> *)busBubbles;

/**
 * 移除底图上所有的bus气泡
 */
- (void)removeBusBubble;

/**
 * 隐藏/显示某个气泡
 * @param busBubbles 气泡描述信息数组
 * @param hidden 隐藏/显示气泡
 */
- (void)changeBusBubbles:(NSArray<QBusStationBubble*> *)busBubbles hidden:(BOOL)isHidden;

#pragma mark - Navigation

/**
 * 地图是否在导航状态
 */
@property(assign,nonatomic,readonly)BOOL isNavigation;

/**
 * 地图是否在步行导航状态
 */
@property(assign,nonatomic,readonly)BOOL isWalkNavigation;

/**
 * 地图是否在导航偏航状态时禁止重新规划路线
 */
@property(assign,nonatomic)BOOL forbidRecaculate;

/**
 *用来设置用户选择QMapNaviShowMode2DNorthOverView mode 时的边界值
 */
@property(nonatomic,assign)UIEdgeInsets edgePaddingFor2DNorthOverView;

/**
 * 搜索到驾车线路后开始导航
 * @return 是否成功开启导航
 */
-(BOOL) startNavigation;

/**
 * 搜索到驾车线路后开始导航
 * @param bShowNaviView 是否显示导航窗口
 * @return 是否成功开启导航
 */
-(BOOL)startNavigation:(BOOL)bShowNaviView;

/**
 * 停止导航（导航启动后调用此方法）
 */
-(void)stopNavigation;

/**
 * 继续导航
 */
- (void)continueNavigation;

/**
 * 偏航的重试次数，默认最多重试5次
 * @param count 偏航次数
 */
-(void)setMaxRecalculateRouteCount:(int)count;

/**
 *  设置每次重试延时(单位秒),默认的每次重试延时 10 秒
 *  @param time 重试的timeout时间
 */
-(void)setRecalculateRouteDelayTime:(float)time;

/**
 *搜索到步行线路后开始导航
 *@param bShowNaviView 是否显示导航窗口
 *@return 是否成功开启导航
 */
-(BOOL)startWalkNavigation:(BOOL)bShowNaviView;


/**
 * 停止步行导航（步行导航启动后调用此方法）
 */
-(void)stopWalkNavigation;

#pragma mark - Route

/**
 * 设置路线宽度
 * 传入的是乘过[UIScreen mainScreen].scale之后的值
 * 设置了QMapView的线宽，默认线宽值将失效，如果需要保持每条线的线宽不一致，需要在路线生成后重新设置线宽
 */
@property (nonatomic, assign) NSInteger lineWidth;

/**
 * 返回路线数量
 * @return 返回路线数量
 */
- (int)routeCount;

/**
 * 根据坐标点数组在底图绘制路线
 * @param routedots 经纬度坐标数组
 * @param 点位个数
 */
- (void) showRoute:(CLLocationCoordinate2D *)routedots withCount:(int) count;

/**
 * 根据搜索结果绘制导航路线,并且根据路线区域调整地图显示范围 (automaticAjustVisibleMapRect 为 YES)
 * @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 * @param routeColor 绘制线路颜色
 */
-(void) showSearchRoute:(RouteResult*) routeResult routeColor:(QMRouteColor)routeColor;

/**
 *  根据搜索结果绘制导航路线
 *  @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 *  @param routeColor 绘制线路颜色
 *  @param automaticAjustVisibleMapRect 是否自动调整地图显示范围
 */
- (void)showSearchRoute:(RouteResult*) routeResult
             routeColor:(QMRouteColor)routeColor
automaticAjustVisibleMapRect:(BOOL)automaticAjustVisibleMapRect;

/**
 * 根据搜索结果(途径点算路或一致性算路)绘制导航路线,并且根据路线区域调整地图显示范围  (automaticAjustVisibleMapRect 为 YES)
 * @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 * @param lineArray 线路Array
 */
-(void) showSearchRoute:(RouteResult*) routeResult lineArray:(NSArray*)lineArray;

/**
 * 根据已经生成的导航数据(途径点算路或一致性算路)来绘制路线
 * @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 * @param lineArray 线路Array
 * @param automaticAjustVisibleMapRect 是否自动调整地图显示范围
 */
- (void)showSearchRouteAfterCreate:(RouteResult*) routeResult
                         lineArray:(NSArray*)lineArray
      automaticAjustVisibleMapRect:(BOOL)automaticAjustVisibleMapRect;

/**
 * 根据搜索结果解析导航数据，暂不显示，可以用来对线段数据进行自定义显示
 * @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 */
- (void)createSearchRoute:(RouteResult*) routeResult;

/**
 * 根据搜索结果解析导航数据，得到路线的线段信息
 * @return 返回路线的线段信息
 */
- (QRouteOverlay*)getRouteLineInfo;

/**
 * 清除路线规划
 * @return 是否成功，如返回为NO则表示当前正在导航中
 */
-(BOOL) removeRoute;

/*
 * 从轻导航进入导航后，将轻导航的routeid纪录下来，当导航发生偏航时，需要使用轻导航的routeid
 * @param routeid 导航线路的id
 */
- (void)adjustOriginalRouteid:(NSString *)routeid;

/**
 * 修改路线纹理绘制类型
 * @param routeDrawType      路线绘制类型
 * @param routeIndex         同时绘制多条路线时的路线索引值
 * @param routeGroupIndex    同时绘制多组路线的group索引值
 */
- (void)setRouteDrawType:(QMRouteDrawType)routeDrawType routeIndex:(NSInteger)routeIndex routeGroupIndex:(NSInteger)routeGroupIndex;

/**
 * 设置彩虹蚯蚓线是否绘制两段半圆纹理
 * @param bValue             是否绘制端纹理
 * @param routeIndex         同时绘制多条路线时的路线索引值
 * @param routeGroupIndex    同时绘制多组路线的group索引值
 */
- (void)setRouteDrawCap:(BOOL)bValue routeIndex:(int)routeIndex routeGroupIndex:(NSInteger)routeGroupIndex;


/**
 * 修改路线纹理图片
 * @param textureName        路线纹理图片文件名，包括扩展名，纹理图片资源不能放在asset内需要工程载入图片资源
 * @param param2             设置彩虹蚯蚓纹理，则代表纹理的行数，设置点纹理，则代表纹理间距(icon的倍数)，虚线纹理未使用此参数
 * @param routeIndex         同时绘制多条路线时的路线索引值，-1则对同一groupIndex的所有路线都设置纹理属性
 * @param routeGroupIndex    同时绘制多组路线的group索引值
 * @param routeDrawType      路线绘制类型
 */
- (void)setRouteDrawTexture:(NSString*)textureName param2:(CGFloat)param2
                 routeIndex:(NSInteger)routeIndex routeGroupIndex:(NSInteger)routeGroupIndex routeDrawType:(QMRouteDrawType)routeDrawType;

/**
 * 根据步行搜索结果绘制导航路线 (automaticAjustVisibleMapRect 为 YES)
 * @param routeResult navRouteSearchWithLocation 回调方法返回的RouteResult
 */
-(void)showWalkSearchRoute:(RouteResult*)routeResult;

/**
 *  根据步行搜索结果绘制导航路线
 *  @param automaticAjustVisibleMapRect 是否自动调整地图显示范围
 */
- (void)showWalkSearchRoute:(RouteResult*)routeResult automaticAjustVisibleMapRect:(BOOL)automaticAjustVisibleMapRect;

/**
 * 清除步行路线规划 (stopWalkNavigation时会自动调用)
 * @return 是否成功，如返回为NO则表示当前正在导航中
 */
-(BOOL)removeWalkRoute;

#pragma mark - Route Overlay

/**
 * 在一个已经存在的路线组里增加一条路线
 * routeOverlay         新增路线，之前的路线组里的路线还会保留
 * routeOverlayGroup    要新增路线的路线组
 */
- (void)addRouteOverlay:(QRouteOverlay*)routeOverlay routeOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup;

/**
 * 新增一个路线组
 * routeOverlayGroup    要新增路线的路线组，如果路线组已经增加过，则会清除重新添加路线信息
 */
- (void)addRouteOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup;

/**
 * 删除路线组，删除路线只能通过删除路线组来实现
 * routeOverlayGroup 需要删除的路线组信息
 */
- (void)removeRouteOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup;

/**
 * 删除路线组，删除路线只能通过删除路线组来实现
 * groupIndex 需要删除的路线组索引
 */
- (void)removeRouteOverlayGroupByIndex:(NSInteger)groupIndex;

/**
 * 更新routeOverlayGroup的dispLevel，同Annotation的DispLevel一样
 * 即 默认不设置，1，2，3，4 ....优先级依次降低
 * 2.0的annotation, mapMask, routeOverlay 都有优先级的概念并且优先级可以相互影响
 * routeOverlayGroup 需要更新的路线组信息
 * dispLevel 优先级
 */
- (void)updateRouteOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup dispLevel: (int)dispLevel;

/**
 * 更新routeOverlayGroup的dispLevel，同Annotation的DispLevel一样
 * 即 默认不设置，1，2，3，4 ....优先级依次降低
 * 2.0的annotation, mapMask, routeOverlay 都有优先级的概念并且优先级可以相互影响
 * groupIndex routeOverlayGroup 的groupIndex
 * dispLevel 优先级
 */
- (void)updateRouteOverlayGroupIndex:(NSInteger)groupIndex dispLevel: (int)dispLevel;

/**
 * 更新routeOverlayGroup中带箭头的routeOverlay箭头的spacing,间距会随着地图的放大缩小会在一定范围内变化，变化幅度为spacing 值的0.5 ~ 1.0倍 之间
 * spacing默认值为200，单位为point，所以变化间距为100~200point
 * routeOverlayGroup 需要更新的路线组信息
 * spacing 间距
 */
- (void)updateRouteOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup arrowSpacing: (CGFloat)spacing;

/**
 * 更新routeOverlayGroup中带箭头的routeOverlay箭头的spacing,间距会随着地图的放大缩小会在一定范围内变化，变化幅度为spacing 值的0.5 ~ 1.0倍 之间
 * spacing默认值为200，单位为point，所以变化间距为100~200point
 * groupIndex routeOverlayGroup 的groupIndex
 * spacing 间距
 */
- (void)updateRouteOverlayGroupIndex:(NSInteger)groupIndex arrowSpacing: (CGFloat)spacing;

/**
 * 更新routeOverlayGroup中Type为QMRouteDrawDottedLine的routeOverlay的spacing,间距会随着地图的放大缩小会在一定范围内变化，变化幅度为spacing 值的0.5 ~ 1.0 倍之间,不是这种类型的routeOverlay就不起作用
 * spacing 默认值为60，单位为point，所以变化间距为30~60point
 * routeOverlayGroup 需要更新的路线组信息
 * spacing 间距
 */
- (void)updateRouteOverlayGroup:(QRouteOverlayGroup*)routeOverlayGroup footPrintSpacing: (CGFloat)spacing;

/**
 * 更新routeOverlayGroup中Type为QMRouteDrawDottedLine的routeOverlay的spacing,间距会随着地图的放大缩小会在一定范围内变化，变化幅度为spacing 值的0.5 ~ 1.0 倍之间,不是这种类型的routeOverlay就不起作用
 * spacing 默认值为60，单位为point，所以变化间距为30~60point
 * groupIndex routeOverlayGroup 的groupIndex
 * spacing 间距
 */
- (void)updateRouteOverlayGroupIndex:(NSInteger)groupIndex footPrintSpacing: (CGFloat)spacing;

/**
 * 如果通过setRouteDrawTexture方法直接更新导航路线的纹理
 * 需要传入路线的group索引值，通过此方法可以获取导航路线的group索引值
 */
- (int)getNavigationRouteGroupIndex;

/**
 * 设置高亮的路线，高亮路线在蒙层上面绘制
 * @param bValue             是否设置高亮
 * @param routeIndex         设置高亮路线的路线索引值
 * @param routeGroupIndex    设置高亮路线的group索引值
 */
- (void)setHighLightRoute:(BOOL)bValue routeIndex:(int)routeIndex routeGroupIndex:(NSInteger)routeGroupIndex;



#pragma mark - Map mask
/**
 * 设置底图蒙层(覆盖颜色)
 * @param red， 覆盖颜色红色值(0.0~1.0f)
 * @param green， 覆盖颜色绿色值(0.0~1.0f)
 * @param blue， 覆盖颜色蓝色值(0.0~1.0f)
 * @param alpha， 覆盖颜色alpha值(0.0~1.0f)
 * @param layer， 覆盖颜色层级
 * @param curveType 动画曲线类型
 * @param animateSecond， 动画时间，单位秒，0则不做动画
 */
- (void)setMapMaskColor:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha layer:(QMapMaskColorLayer)layer curveType:(QMapAnimationCurveType)curveType animateSecond:(CGFloat)animateSecond;

/**
 QSearch中没有QMapView实例，但是路线请求参数里还要附带city字段，使用这个方法默认取第一个mapview实例的currentCity
 */
+ (NSString *)city;

@end


/**
 * QMapView(OverlaysAPI):Overlay相关的API
 */
@interface QMapView (OverlaysAPI)

/**
 * 当前mapView中已经添加的Overlay数组
 */
@property (nonatomic, readonly) NSArray *overlays;

/**
 * 向地图窗口添加Overlay，需要实现QMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 * @param overlay 要添加的overlay
 */
- (void)addOverlay:(id <QOverlay>)overlay;

/**
 * 向地图窗口添加一组Overlay，需要实现QMapViewDelegate的-mapView:viewForOverlay:函数来生成标注对应的View
 * @param overlays 要添加的overlay数组
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 * 移除Overlay
 * @param overlay 要移除的overlay
 */
- (void)removeOverlay:(id <QOverlay>)overlay;

/**
 * 移除一组Overlay
 * @param overlays 要移除的overlay数组
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 * 在指定的索引处添加一个Overlay
 * @param overlay 要添加的overlay
 * @param index 指定的索引
 */
- (void)insertOverlay:(id <QOverlay>)overlay atIndex:(NSUInteger)index;

/**
 * 在交换指定索引处的Overlay
 * @param index1 索引1
 * @param index2 索引2
 */
- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2;

/**
 * 在指定的Overlay之上插入一个overlay
 * @param overlay 带添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <QOverlay>)overlay aboveOverlay:(id <QOverlay>)sibling;

/**
 * 在指定的Overlay之下插入一个overlay
 * @param overlay 带添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <QOverlay>)overlay belowOverlay:(id <QOverlay>)sibling;

/**
 * 查找指定overlay对应的View，如果该View尚未创建，返回nil
 * @param overlay 指定的overlay
 * @return 指定overlay对应的View
 */
- (QOverlayView *)viewForOverlay:(id <QOverlay>)overlay;

@end

@interface QMapView (TileOverlay)

/**
 * 当前地图上的tileOverlay数组
 */
@property (nonatomic, readonly) NSArray *tileOverlays;

/**
 * 添加tileOverlay
 * @param tileOverlay 要添加的tileOverlay
 */
- (void)addTileOverlay:(QTileOverlay *)tileOverlay;

/**
 * 移除tileOverlay
 * @param tileOverlay 要移除的tileOverlay
 */
- (void)removeTileOverlay:(QTileOverlay *)tileOverlay;

/**
 * 强制tileOverlay重新加载数据.
 * @param tileOverlay tileOverlay
 */
- (void)reloadTileOverlay:(QTileOverlay *)tileOverlay;

@end

/**
 *  ELDS 系统, 支持定位数据由外部提供.
 */
@interface QMapView (ExternalLocationDataSource)

/**
 *  是否启动"定位数据由外部传入". 默认为NO.
 */
@property (nonatomic, assign) BOOL enableExternalLocationDataSource;

/**
 * 外部提供 GPS 定位数据, 仅当 (enableExternalLocationDataSource == YES && showsUserLocation == YES) 时有效.
 * @param location GCJ-02 类型的 location
 *  location 中成员变量重要性说明:
 *                 必须提供: coordinate, horizontalAccuracy, course
 *                 可选   : speed, altitude, timestamp, verticalAccuracy
 *
 *
 */
- (void)elds_provideLocation:(CLLocation *)location;

/**
 * 外部提供 GPS 定位数据, 仅当 (enableExternalLocationDataSource == YES && showsUserLocation == YES) 时有效.
 * @param location       定位坐标
 * location 中成员变量重要性说明:
 *                 必须提供: coordinate, horizontalAccuracy, course
 *                 可选   : speed, altitude, timestamp, verticalAccuracy
 * @param coordinateType 坐标系类型 目前支持WGS-84 和 GCJ-02 两种.
 */
- (void)elds_provideLocation:(CLLocation *)location coordinateType:(QCoordinateType)coordinateType;

/**
 * 外部提供 heading信息, 仅当 (enableExternalLocationDataSource == YES && showsUserLocation == YES) 时有效.
 * @param heading heading
 */
- (void)elds_provideHeading:(CLHeading *)heading;

/**
 * 外部定位发生error 时提供error信息, 仅当 (enableExternalLocationDataSource == YES && showsUserLocation == YES) 时有效.
 * @param error error
 */
- (void)elds_encounterError:(NSError *)error;

@end

@interface QMapView (DynamicChangeRoute)

/**
 设置动态换路的代理
 
 @param dynamicChangeRouteDelegate 动态换路的代理
 */
- (void)setDynamicChangeRouteDelegate:(id<QDynamicChangeRouteProtocol>)dynamicChangeRouteDelegate;

@end

@interface QMapView (RouteNavigation)

/*
 * app是否在前台运行
 */
@property(nonatomic, readonly) BOOL isInforeGround;

/**
 * 移除电子眼overlay
 */
- (void)removeCameraOverlay;

/**
 * 移除导航路线overlay，包含起点和终点marker
 */
- (void)removeRouteGuidanceOverlay;

/**
 * 移除导航路线
 */
- (void)removeRouteGuidanceGroup;

/**
 * 设置定位icon的显示隐藏状态
 @param hidden 是否隐藏定位icon
 */
- (void)setLocationOverlayHidden:(BOOL)hidden;

/**
 * 设置司乘同显轻导航下擦除模式是否开启
 @param isEraseMode 是否是擦除模式
 */
- (void)setIsEraseRouteMode:(BOOL)isEraseMode;

/**
 * 司乘同显轻导航下是否是擦除模式
 */
- (BOOL)isEraseRouteMode;

/**
 * 挪动地图后，过了delayTime后，地图自动回到挪动前的跟踪模式，在3D导航下应用
 @param block 地图回到挪动前的跟踪模式的响应事件
 @param delayTime 地图在非跟踪模式持续的时间，delayTime过后，执行block，地图回到跟踪模式
 */
- (void)setContinue3DTrackingBlock:(void (^)())block afterTime:(CGFloat)delayTime;

/**
 * 挪动地图后，地图自动回到挪动前的跟踪模式，在司乘同显中应用
 @param block 地图回到跟踪模式的延迟响应事件
 @param delayTime 地图在非跟踪模式持续的时间，delayTime过后，执行block，地图回到跟踪模式
 */
- (void)setContinue2DTrackingBlock:(void (^)())block afterTime:(CGFloat)delayTime;

/**
 * 取消地图自动回到跟踪模式的延迟响应事件
 */
- (void)cancelContinueTrackingBlock;//停止地图自动归位操作
/*
 * 地图是否处于等待回到跟踪模式的状态
 */
- (BOOL)isWaitingForTracking;

/*
 * 获取路线类型为type的路线的剩余显示区域，在司乘同显擦除模式中应用
 */
- (QMapRect)getRouteLineLeftVisibleRect:(int)type;

/*
 * 获取路线类型为type的路线的可见区域
 */
- (QMapRect)getRouteLineVisibleRect:(int)type;

/**
 * 走过的路置灰
 */
- (void)setLocationForNavigation:(QMapPoint *)pPoint
                     nPointIndex:(int)nPointIndex
                      pNextPoint:(QMapPoint *)pNextPoint
                       nDistance:(int)nDistance
                         nOffset:(int)nOffset
                           nType:(int)nType;

/**
 * 刷新某条路的彩虹蚯蚓
 * @param trafficArray 彩虹蚯蚓数组，由RouteTrafficInfo对象组成
 * @param routePointsArray原始路线点串（经纬度坐标），由QRoutePoint对象组成
 * @param routeType 路线类型,也是路线的索引
 */
- (void)refreshRouteLineRainbowWithTraffics:(NSArray *)trafficArray mapPoints:(NSArray *)routePointsArray routeType:(int)routeType;
/*
 * 设置是否是轻导航
 */
- (void)setIsLightNavigating:(BOOL)isLightNavigating;
/*
 * 设置是否是司乘同显
 */
- (void)setIsSCTXNavigating:(BOOL)isSCTXNavigating;

/**
 导航过程中重新计算路线成功，更新诱导引擎，更新路线，更新UI
 重新计算路线的原因可能是偏航，改变目的地，动态换路等
 所有场景（普通导航，司乘同显，一致性）的偏航请求成功后都需要调用这个接口
 @param route 新的路线
 */
- (void)recalculateRouteDidFinishWithResult:(RouteResult *)route;

/**
 一次偏航重试失败（未达到重试上限）
 所有场景（普通导航，司乘同显，一致性）的偏航请求失败后都需要调用这个接口
 @param error 失败原因
 */
- (void)recalculateRouteDidFailWithError:(QRouteSearchError *)error;

/**
 偏航重试失败（达到重试上限）
 所有场景（普通导航，司乘同显，一致性）的偏航请求失败后都需要调用这个接口
 @param error 失败原因
 */
- (void)recalculateRouteDidFailWithErrorFinally:(QRouteSearchError *)error;

/*
 * 设置导航时地图的显示模式
 * 如果导航开始前已经设置了模式，导航后就用设置的模式，否则会自动设置成QMapNaviShowMode3DHeadingBestView
 * 轻导航下设置为QMapNaviShowMode2DNorthBestView和QMapNaviShowMode3DHeadingBestView不生效
 * 默认无动画
 * @param mapNaviShowMode 更改的模式
 */
- (void)setMapNaviShowMode:(QMapNaviShowMode)mapNaviShowMode;

/**
 * 设置导航时地图的显示模式
 * 如果导航开始前已经设置了模式，导航后就用设置的模式，否则会自动设置成QMapNaviShowMode3DHeadingBestView
 * 轻导航下设置为QMapNaviShowMode2DNorthBestView和QMapNaviShowMode3DHeadingBestView不生效
 * @param mapNaviShowMode 更改的模式
 * @param animated 是否做动画
 */
- (void)setMapNaviShowMode:(QMapNaviShowMode)mapNaviShowMode animated:(BOOL)animated;

/**
 * 获取导航时地图的显示模式
 */
- (QMapNaviShowMode)currentMapNaviShowMode;

@end
/**
 *QMapViewDelegate:MapView的Delegate,mapView通过此类来通知用户对应的事件
 **/
@protocol QMapViewDelegate <NSObject>

@optional
/**
 * 根据anntation生成对应的View
 * @param mapView 地图View
 * @param annotation 指定的标注
 * @return 生成的标注View
 */
- (QAnnotationView *)mapView:(QMapView *)mapView viewForAnnotation:(id <QAnnotation>)annotation;

/**
 * 地图区域即将改变时会调用此接口
 * @param mapview 地图View
 * @param animated 是否动画
 * @param bGesture 是否由手势触发
 */
- (void)mapView:(QMapView *)mapView regionWillChangeAnimated:(BOOL)animated gesture:(BOOL)bGesture;

/**
 * 地图区域改变完成后会调用此接口,如果是由手势触发，当触摸结束且地图region改变的动画结束后才会触发此回调
 * @param mapview 地图View
 * @param animated 是否动画
 * @param bGesture region变化结束的时候手指仍然在屏幕上
 */
- (void)mapView:(QMapView *)mapView regionDidChangeAnimated:(BOOL)animated gesture:(BOOL)bGesture;



/**
 * 当mapView新添加annotation views时，调用此接口
 * @param mapView 地图View
 * @param views 新添加的annotation views
 */
- (void)mapView:(QMapView *)mapView didAddAnnotationViews:(NSArray *)views;

/**
 * 当mapView新添加annotationview时，调用此接口
 * @param mapView 地图View
 * @param view 新添加的annotationview
 */
- (void)mapView:(QMapView *)mapView didAddAnnotationView:(QAnnotationView *)view;
/**
 * 当选中一个annotation view时，调用此接口
 * @param mapView 地图View
 * @param view 选中的annotation view
 */
- (void)mapView:(QMapView *)mapView didSelectAnnotationView:(QAnnotationView *)view;

/**
 * 当annotation view的calloutView重新调整后，调用此接口
 * @param mapView 地图View
 * @param view 选中的annotation view
 */
- (void)mapView:(QMapView *)mapView didLayoutCalloutView:(QAnnotationView *)view;


/**
 * 当取消选中一个annotation view时，调用此接口
 * @param mapView 地图View
 * @param views 取消选中的annotation view
 */
- (void)mapView:(QMapView *)mapView didDeselectAnnotationView:(QAnnotationView *)view;

/**
 * 在地图View将要启动定位时，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewWillStartLocatingUser:(QMapView *)mapView;

/**
 * 在地图View停止定位后，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewDidStopLocatingUser:(QMapView *)mapView;

/**
 *用户位置更新后，会调用此函数
 *@param mapView 地图View
 *@param userLocation 新的用户位置
 */
- (void)mapView:(QMapView *)mapView didUpdateUserLocation:(QUserLocation *)userLocation;

/**
 * 定位失败后，会调用此函数
 * @param mapView 地图View
 * @param error 错误号，参考CLError.h中定义的错误号
 */
- (void)mapView:(QMapView *)mapView didFailToLocateUserWithError:(NSError *)error;

/**
 * 根据overlay生成对应的View
 * @param mapView 地图View
 * @param overlay 指定的overlay
 * @return 生成的覆盖物View
 */
- (QOverlayView *)mapView:(QMapView *)mapView viewForOverlay:(id <QOverlay>)overlay;

/**
 * 当mapView新添加overlay view时，调用此接口
 * @param mapView 地图View
 * @param overlayView 新添加的overlayview
 */
- (void)mapView:(QMapView *)mapView didAddOverlayView:(QOverlayView *)overlayView ;

/**
 * 当mapView新添加overlay views时，调用此接口
 * @param mapView 地图View
 * @param overlayViews 新添加的overlay views
 */
- (void)mapView:(QMapView *)mapView didAddOverlayViews:(NSArray *)overlayViews ;

/**
 * 当mapView中有Annotation进行显示时点击地图空白区域调用此接口
 */
-(void)touchesWithOutCallout;

/** 
 * user tracking mode 改变时delegate调用此函数
 *  @param mapView 地图View
 *  @param mode QMUserTrackingMode
 *  @param animated 是否以动画的形式
 */
- (void)mapView:(QMapView *)mapView didChangeUserTrackingMode:(QMUserTrackingMode)mode animated:(BOOL)animated;

/** 
 * AnnotationView CalloutView的accessory control 触摸的时候调用此函数
 * @param mapView 地图View
 * @param view QAnnotationView
 * @param control CalloutView的 left or right accessory control
 */
- (void)mapView:(QMapView *)mapView annotationView:(QAnnotationView *)view calloutAccessoryControlTapped:(UIControl *)control;

/** 
 * AnnotationView的 触摸的时候调用此函数
 * @param mapView 地图View
 * @param view QAnnotationView
 * @param control 被点击的CalloutView，不包括leftAccessoryControl 或者rightAccessoryControl
 */
- (void)mapView:(QMapView *)mapView annotationView:(QAnnotationView *)view calloutViewTapped:(UIControl *)control;


/** 
 * 长按地图屏幕是触发,获得触摸处的经纬度
 * @param mapView 地图View
 * @param coordinate 长按处的经纬度
 */
- (void)mapView:(QMapView *)mapView longPressAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * 点中底图标注后会回调此接口
 * @param mapview 地图View
 * @param mapPoi 标注点信息
 */
- (void)mapView:(QMapView *)mapView onClickedMapPoi:(QMapPoi*)mapPoi;

/**
 * 更新路况后会调用此接口
 * @param mapView 地图View
 * @param cityName 点前路况城市
 */
- (void)mapView:(QMapView *)mapView didUpdateTraffic:(NSString*)cityName;

/**
 * 地图的位置变化时会持续调用此接口
 * @param mapView 地图View
 */
- (void)mapPositionChanged:(QMapView*)mapView;

/**
 * annotation 动画完成之后的回调
 * @param mapView 地图View
 * @param annotation 运行动画的annotation
 * @param key 标记动画类型的key (位移旋转:position, 透明度:alpha)
 * @param finished 动画是否完成
 */
-(void)mapView:(QMapView *)mapView annotation:(QPointAnnotation*)annotation animationKey:(NSString *)key didFinishAnimation:(BOOL)finished;

/**
 * 当修改导航时地图展示的样式时回调本函数
 * @param mapView   地图实例
 * @param mode      地图展示的样式
 * @param animated  是否需要动画
 */
- (void)mapView:(QMapView*)mapView didChangeMapNaviShowingMode:(QMapNaviShowMode)mode animated:(BOOL)animated;

/**
 * @brief  当地图缩放级别发生变化时的回调
 * @param mapView  地图实例
 * @param animated 是否需要动画
 */
- (void)mapView:(QMapView*)mapView didChangeScaleAnimated:(BOOL)animated;

@end

@protocol QMapNavigationDelegate <NSObject>

@optional
-(void) updateRouteResult:(QMRoute*)routeResult;

/**
 tts播报的回调

 @param ttsValue 播报内容结构体
 */
-(void) returnTTSValue:(QttsParam*)ttsParam;

/**
 触发了超速后的回调
 
 @param overspeedInfo 超速内容结构体
 */
- (void)triggerOverspeed:(QOverspeedInfo *)overspeedInfo;

-(void) userLocationErr:(NSString*)locationErr;

/**
 导航结束回调
 
 @param bFinished YES 是自动导航结束， NO 是手动导航结束
 */
-(void) userNavigationEnd:(BOOL)bFinished;

-(void) showRouteFinished;

-(void) userTrackingModeNone;

/**
 *  开始偏航
 */
- (void)recomputeRouteWillStarted;

/**
 *  偏航成功
 *
 *  @param routeSearchResult 路线信息
 */
- (void)recomputeRouteDidFinished:(RouteResult*)routeSearchResult;

/**
 *  一次偏航失败
 *
 *  @param error 失败信息
 */
- (void)recomputeRouteDidFailWithError:(QRouteSearchError *)error;

/**
 *  偏航重试达到最大次数后失败
 *  普通导航和司乘同显都有重试机制，因此在最后一次重试失败后会走这个回调，但是一致性没有重试机制，因此偏航失败后只走这个回调
 *
 *  @param error 失败信息
 */
- (void)recomputeRouteDidFailWithErrorFinally:(QRouteSearchError *)error;

@end
