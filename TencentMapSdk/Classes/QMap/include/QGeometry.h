/*
 ============================================================================
 Name           : QGeometry.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QGeometry declaration
 ============================================================================
 */

#ifndef SOSOMapAPI_QGeometry_h
#define SOSOMapAPI_QGeometry_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

typedef unsigned int QMapColor;
/**
 * 构造QMapColor
 * @param r red 0~255
 * @param g green 0~255
 * @param b blue 0~255
 * @param a alpha 0~255
 * @return QMapColor HexColor
 */
QMapColor QMapColorMake(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

/**
 * 从UIColor返回QMapColor
 */
QMapColor QMapColorFromUIColor(UIColor* color);

/**
 * 从UIColor返回QMapColor
 */
UIColor* UIColorFromQMapColor(QMapColor color);

/**经纬度范围**/
typedef struct {
    CLLocationDegrees latitudeDelta;/**纬度范围**/
    CLLocationDegrees longitudeDelta;/**经度范围**/
} QCoordinateSpan;

/**经纬度区域**/
typedef struct {
	CLLocationCoordinate2D center;/**中心点经纬度坐标**/
	QCoordinateSpan span;/**经纬度范围**/
} QCoordinateRegion;


/**地理坐标点，用直角地理坐标表示,代表世界上的一个地点，可以和经纬度相互转换**/
typedef struct {
    double x;/**横坐标**/
    double y;/**纵坐标**/
} QMapPoint;

/**矩形大小，用直角地理坐标表示**/
typedef struct {
    double width;/**宽度**/
    double height;/**高度**/
} QMapSize;

/**矩形，用直角地理坐标表示**/
typedef struct {
    QMapPoint origin;/**屏幕左上点对应的直角地理坐标**/
    QMapSize size;/**坐标范围**/
} QMapRect;

/**地图缩放比例，提供了地图上的点和屏幕上的点缩放关系**/
typedef CGFloat QZoomScale;

/**经过投影后的世界范围大小，与经纬度（-85，180）投影后的坐标值对应**/
UIKIT_EXTERN const QMapSize QMapSizeWorld;
/**经过投影后的世界范围对应的矩形**/
UIKIT_EXTERN const QMapRect QMapRectWorld;
/**空的直角坐标矩形**/
UIKIT_EXTERN const QMapRect QMapRectNull;
/**空的直角坐标点**/
UIKIT_EXTERN const QMapPoint QMapPointZero;
/*
 *  判断经纬度区域是不是合理的
 *
 *  当经纬度区域是合理的，返回YES，否则，返回NO
 */
BOOL QCoordinateRegionIsValid(QCoordinateRegion region);


/*
 *  判断地图大小是不是合理的
 *
 *  当地图大小是合理的，返回YES，否则，返回NO
 */
BOOL QMapSizeIsValid(QMapSize mapSize);

/*
 *  判断地图区域是不是合理的
 *
 *  当地图区域是合理的，返回YES，否则，返回NO
 */
BOOL QMapRectIsValid(QMapRect mapRect);


/**
 *构造QCoordinateSpan对象
 *@param latitudeDelta 纬度方向的变化量
 *@param longitudeDelta 经度方向的变化量
 *@return 根据指定参数生成的QCoordinateSpan对象
 */
UIKIT_STATIC_INLINE QCoordinateSpan QCoordinateSpanMake(double latitudeDelta, double longitudeDelta)
{
    QCoordinateSpan span;
    span.latitudeDelta = latitudeDelta;
    span.longitudeDelta = longitudeDelta;
    return span;
}

/**
 *构造QCoordinateRegion对象
 *@param centerCoordinate 中心点经纬度坐标
 *@param span 经纬度的范围
 *@return 根据指定参数生成的QCoordinateRegion对象
 */
UIKIT_STATIC_INLINE QCoordinateRegion QCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, QCoordinateSpan span)
{
	QCoordinateRegion region;
	region.center = centerCoordinate;
    region.span = span;
	return region;
}

/**
 *根据中心点和距离生成QCoordinateRegion
 *@param centerCoordinate 中心点坐标
 *@param latitudinalMeters 纬度方向的距离范围，单位：米
 *@param longitudinalMeters 经度方向的距离范围，单位：米
 *@return 根据中心点和距离生成QCoordinateRegion
 */
QCoordinateRegion QCoordinateRegionMakeWithDistance(CLLocationCoordinate2D centerCoordinate, CLLocationDistance latitudinalMeters, CLLocationDistance longitudinalMeters);

/**
 *将经纬度坐标转换为投影后的直角地理坐标
 *@param coordinate 待转换的经纬度坐标
 *@return 转换后的直角地理坐标
 */
QMapPoint QMapPointForCoordinate(CLLocationCoordinate2D coordinate);

/**
 *将投影后的直角地理坐标转换为经纬度坐标
 *@param mapPoint 投影后的直角地理坐标
 *@return 转换后的经纬度坐标
 */
CLLocationCoordinate2D QCoordinateForMapPoint(QMapPoint mapPoint);


/**
 *计算在指定纬度下一个QMapPoint单位对应的米数
 *@param latitude 指定的纬度
 *@return 在指定纬度下一个QMapPoint单位对应的米数
 */
CLLocationDistance QMetersPerMapPointAtLatitude(CLLocationDegrees latitude);

/**
 *计算在指定纬度下一米对应的QMapPoint的单位数
 *@param latitude 指定的纬度
 *@return 在指定纬度下一米对应的QMapPoint的单位数
 */
double QMapPointsPerMeterAtLatitude(CLLocationDegrees latitude);

/**
 *计算指定两点之间的距离
 *@param a 第一个坐标点
 *@param b 第二个坐标点
 *@return 两点之间的距离，单位：米
 */
double QMetersBetweenMapPoints(QMapPoint a, QMapPoint b);

/**
 *构造QMapPoint对象
 *@param x 水平方向的坐标值
 *@param y 垂直方向的坐标值
 *@return 根据指定参数生成的QMapPoint对象
 */
UIKIT_STATIC_INLINE QMapPoint QMapPointMake(double x, double y) {
    return (QMapPoint){x, y};
}

/**
 *构造QMapSize对象
 *@param width 宽度
 *@param height 高度
 *@return 根据指定参数生成的QMapSize对象
 */
UIKIT_STATIC_INLINE QMapSize QMapSizeMake(double width, double height) {
    return (QMapSize){width, height};
}

/**
 *构造QMapRect对象
 *@param x 矩形左上顶点的x坐标值
 *@param y 矩形左上顶点的y坐标值
 *@param width 矩形宽度
 *@param height 矩形高度
 *@return 根据指定参数生成的QMapRect对象
 */
UIKIT_STATIC_INLINE QMapRect QMapRectMake(double x, double y, double width, double height) {
    return (QMapRect){ QMapPointMake(x, y), QMapSizeMake(width, height) };
}

/**
 *获取指定矩形的x轴坐标最小值
 *@param rect 指定的矩形
 *@return x轴坐标最小值
 */
UIKIT_STATIC_INLINE double QMapRectGetMinX(QMapRect rect) {
    return rect.origin.x;
}

/**
 *获取指定矩形的y轴坐标最小值
 *@param rect 指定的矩形
 *@return y轴坐标最小值
 */
UIKIT_STATIC_INLINE double QMapRectGetMinY(QMapRect rect) {
    return rect.origin.y;
}

/**
 *获取指定矩形在x轴中点的坐标值
 *@param rect 指定的矩形
 *@return x轴中点的坐标值
 */
UIKIT_STATIC_INLINE double QMapRectGetMidX(QMapRect rect) {
    return rect.origin.x + rect.size.width / 2.0;
}

/**
 *获取指定矩形在y轴中点的坐标值
 *@param rect 指定的矩形
 *@return y轴中点的坐标值
 */
UIKIT_STATIC_INLINE double QMapRectGetMidY(QMapRect rect) {
    return rect.origin.y + rect.size.height / 2.0;
}

/**
 *获取指定矩形的x轴坐标最大值
 *@param rect 指定的矩形
 *@return x轴坐标最大值
 */
UIKIT_STATIC_INLINE double QMapRectGetMaxX(QMapRect rect) {
    return rect.origin.x + rect.size.width;
}

/**
 *获取指定矩形的y轴坐标最大值
 *@param rect 指定的矩形
 *@return y轴坐标最大值
 */
UIKIT_STATIC_INLINE double QMapRectGetMaxY(QMapRect rect) {
    return rect.origin.y + rect.size.height;
}

/**
 *获取指定矩形的宽度
 *@param rect 指定的矩形
 *@return 指定矩形的宽度
 */
UIKIT_STATIC_INLINE double QMapRectGetWidth(QMapRect rect) {
    return rect.size.width;
}

/**
 *获取指定矩形的高度
 *@param rect 指定的矩形
 *@return 指定矩形的高度
 */
UIKIT_STATIC_INLINE double QMapRectGetHeight(QMapRect rect) {
    return rect.size.height;
}

/**
 *判断两个点是否相等
 *@param point1 第一个点
 *@param point2 第二个点
 *@return 如果两点相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL QMapPointEqualToPoint(QMapPoint point1, QMapPoint point2) {
    return point1.x == point2.x && point1.y == point2.y;
}

/**
 *判断两个矩形范围是否相等
 *@param size1 范围1
 *@param size2 范围2
 *@return 如果相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL QMapSizeEqualToSize(QMapSize size1, QMapSize size2) {
    return size1.width == size2.width && size1.height == size2.height;
}

/**
 *判断两个矩形是否相等
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果相等，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL QMapRectEqualToRect(QMapRect rect1, QMapRect rect2) {
    return 
    QMapPointEqualToPoint(rect1.origin, rect2.origin) &&
    QMapSizeEqualToSize(rect1.size, rect2.size);
}

/**
 *判断指定矩形是否为NULL
 *@param rect 指定矩形
 *@return 如果矩形为NULL，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL QMapRectIsNull(QMapRect rect) {
    return isinf(rect.origin.x) || isinf(rect.origin.y);
}

/**
 *判断一个矩形是否为空矩形
 *@param rect 指定矩形
 *@return 如果矩形为空矩形，返回YES，否则返回NO
 */
UIKIT_STATIC_INLINE BOOL QMapRectIsEmpty(QMapRect rect) {
    return QMapRectIsNull(rect) || (rect.size.width == 0.0 && rect.size.height == 0.0);
}

/**
 *将QMapPoint格式化为字符串
 *@param point 指定的标点
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *QStringFromMapPoint(QMapPoint point) {
    return [NSString stringWithFormat:@"{%f, %f}", point.x, point.y];
}

/**
 *将QMapSize格式化为字符串
 *@param size 指定的size
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *QStringFromMapSize(QMapSize size) {
    return [NSString stringWithFormat:@"{%f, %f}", size.width, size.height];
}

/**
 *将QMapRect格式化为字符串
 *@param rect 指定的rect
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString *QStringFromMapRect(QMapRect rect) {
    return [NSString stringWithFormat:@"{%@, %@}", QStringFromMapPoint(rect.origin), QStringFromMapSize(rect.size)];
}

/**
 *  计算矩形和点的并集
 *
 *  @param rect1 矩形
 *  @param point 点
 *
 *  @return 矩形
 */
QMapRect QMapRectUnionPoint(QMapRect rect1, QMapPoint point);

/**
 *  计算两个点形成的矩形
 *
 *  @param point1 点1
 *  @param point2 点2
 *
 *  @return 矩形
 */
QMapRect QMapPointUnion(QMapPoint point1, QMapPoint point2);

/**
 *计算两个矩形的并集
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 两个矩形的并集
 */
QMapRect QMapRectUnion(QMapRect rect1, QMapRect rect2);

/**
 *计算两个矩形的交集
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 两个矩形的交集
 */
QMapRect QMapRectIntersection(QMapRect rect1, QMapRect rect2);

/**
 *将矩形向内缩小dx，dy大小
 *@param rect 指定的矩形
 *@param dx x轴的变化量
 *@param dy y轴的变化量
 *@return 调整后的矩形
 */
QMapRect QMapRectInset(QMapRect rect, double dx, double dy);

/**
 *将矩形原点偏移指定大小
 *@param rect 指定的矩形
 *@param dx x轴的偏移量
 *@param dy y轴的偏移量
 *@return 调整后的矩形
 */
QMapRect QMapRectOffset(QMapRect rect, double dx, double dy);

/**
 *矩形分割，将一个矩形分割为两个矩形
 *@param rect 待分割的矩形
 *@param slice 指针，用来保存分割后被移除的矩形
 *@param remainder 指针，用来保存分割后剩下的矩形
 *@param amount 指定分割的大小，如果设置为负数，则将自动调整为0
 *@param edge 用来指定要从那条边开始分割
 */
void QMapRectDivide(QMapRect rect, QMapRect *slice, QMapRect *remainder, double amount, CGRectEdge edge);

/**
 *判断指定点是否在某矩形内
 *@param rect 指定的矩形
 *@param point 指定的点
 *@return 如果包含，返回YES，否则，返回NO
 */
BOOL QMapRectContainsPoint(QMapRect rect, QMapPoint point);

/**
 *判断矩形rect1是否包含矩形rect2
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果包含，返回YES，否则，返回NO
 */
BOOL QMapRectContainsRect(QMapRect rect1, QMapRect rect2);

/**
 *判断两矩形是否相交
 *@param rect1 矩形1
 *@param rect2 矩形2
 *@return 如果相交，返回YES，否则，返回NO
 */
BOOL QMapRectIntersectsRect(QMapRect rect1, QMapRect rect2);

/**
 *将投影后的直角坐标矩形转换为经纬度表示的范围
 *@param rect 待转换的直角坐标矩形
 *@return 转换后的经纬度范围
 */
QCoordinateRegion QCoordinateRegionForMapRect(QMapRect rect);
QCoordinateRegion QMCoordinateRegionForMapRect(QMapRect rect);

/**
 *判断指定的直角坐标矩形是否跨越了180度经线
 *@param rect 待判断的矩形
 *@return 如果跨越，返回YES，否则返回NO
 */
BOOL QMapRectSpans180thMeridian(QMapRect rect);

/**
 *对于跨越了180经线的矩形，本函数将世界之外的部分进行分割，并将分割下来的矩形转换到地球对面，
 *例如将-185度经线对应的区域转换到5度经线对应的区域，并将转换后的矩形返回
 *@param rect 待处理的矩形
 *@return 返回转换后的矩形
 */
QMapRect QMapRectRemainder(QMapRect rect);

/**
 *将CLLocationCoordinate2D格式化为字符串
 *@param point 指定的标点
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString* _QStringFromLocationCoordinate2D(CLLocationCoordinate2D point) {
    return [NSString stringWithFormat:@"{%f,%f}",point.latitude,point.longitude];
}

/**
 *将QCoordinateSpan格式化为字符串
 *@param span 指定的span
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString* _QStringFromCoordinateSpan(QCoordinateSpan span) {
    return [NSString stringWithFormat:@"{%f, %f}", span.latitudeDelta, span.longitudeDelta];
}

/**
 *将QCoordinateRegion格式化为字符串
 *@param region 指定的region
 *@return 返回转换后的字符串
 */
UIKIT_STATIC_INLINE NSString* _QStringFromCoordinateRegion(QCoordinateRegion region) {
    return [NSString stringWithFormat:@"{%@, %@}", _QStringFromLocationCoordinate2D(region.center), _QStringFromCoordinateSpan(region.span)];
}

CG_INLINE NSString *NSStringFromQMapRect(QMapRect rect) {
    return [NSString stringWithFormat:@"%f,%f,%f,%f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];
}
#endif
