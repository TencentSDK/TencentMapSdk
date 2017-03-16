/*
 ============================================================================
 Name           : QGeocoder.h
 Author         : 腾讯SOSO地图API
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QAddressInfo,QGeocoder declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import "QTypes.h"


/**
 *QAddressInfo:地址信息
 *Author:ksnowlv
 **/
@interface QAddressInfo : NSObject

/**所在的省份或直辖市**/
@property(nonatomic, copy) NSString* province;
/**所在的城市**/
@property(nonatomic, copy) NSString* city;
/**所在的地区**/
@property(nonatomic, copy) NSString* district;
/**地理坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

/**前向声明**/
@class QGeocoderInternal;
@protocol QGeocoderDelegate;

/**
 *QGeocoder:地址编码
 *Author:ksnow
 **/
@interface QGeocoder : NSObject
{
    QGeocoderInternal *_internal;
}

/**
 *根据地点生成QGeocoder对象
 *@param address    地点
 *@return 新生成QGeocoder对象
 */
- (id)initWithAddress:(NSString*)address;

/**开始查询**/
- (void)start;

/**撤销查询**/
- (void)cancel;

/**delegate**/
@property(nonatomic, weak) id<QGeocoderDelegate> delegate;

/**地点**/
@property(nonatomic, readonly) NSString* address;

/**查询的结果**/
@property(nonatomic, readonly) QAddressInfo* addressInfo;

/**查询的标识**/
@property(nonatomic, readonly, getter=isQuerying) BOOL querying;

@end

@protocol QGeocoderDelegate <NSObject>
@required

/**成功时的通知
 *@param geocoder       QGeocoder
 *@param placeMarkList  查询的结果
 *@return 
 */
- (void)geocoder:(QGeocoder *)geocoder didFindAddressInfo:(QAddressInfo*) addressInfo;

/**失败时的通知
 *@param geocoder    QGeocoder
 *@param error       见QErrorCode
 *@return 
 */
- (void)geocoder:(QGeocoder *)geocoder didFailWithError:(QErrorCode)error;

@end
