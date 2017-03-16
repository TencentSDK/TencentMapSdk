/*
 ============================================================================
 Name           : QPlaceMark.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPolyline declaration
 ============================================================================
 */

#import <CoreLocation/CoreLocation.h>

/**
 *QPlaceMark:地标
 *Author:ksnowlv
 **/
@interface QPlaceMark : NSObject

/**地点名称**/
@property(nonatomic, copy) NSString*   name;
/**地点详细地址**/
@property(nonatomic, copy) NSString*   address;
/**地点所在地理坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;
/**VID**/
@property(nonatomic, copy) NSString* svid;
/**uid**/
@property(nonatomic, copy) NSString* uid;
/**标示是否有街景**/
@property(nonatomic, assign) BOOL isHaveStreetView;
/**
 *俯仰角
 *@param pitchAngle 坐标系X轴与水平面的夹角。当X轴的正半轴位于过坐标原点的水平面之上时，俯仰角为正.
 按习惯，俯仰角θ的范围为：-π/2≤θ≤π/2
 */
@property(nonatomic, assign) float pitchAngle;

/**
 *偏航角 yawAngle 偏离航向的角度 -π≤θ≤π
 */
@property(nonatomic, assign) float yawAngle;

@end
