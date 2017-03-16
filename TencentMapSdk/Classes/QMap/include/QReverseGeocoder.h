/*
 ============================================================================
 Name           : QReverseGeocoder.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QReverseGeocoder declaration
 ============================================================================
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import "QTypes.h"

/**前向声明**/
@class QPlaceMark;
@class QReverseGeocoderInternal;
@protocol QReverseGeocoderDelegate;

/**
 *QReverseGeocoder:地址反编码，目前用于地图、街景的所有的反查，区别是是否指定radius属性，如果未指定radius或指定radius为0，
 则进行正常地址反查，如果指定radius则只进行街景反查。
 *Author:ksnowlv
 **/
@interface QReverseGeocoder : NSObject
{
    QReverseGeocoderInternal *_internal;
}

/**
 *根据地理坐标生成QReverseGeocoder对象
 *@param coordinate   地理坐标
 *@return 新生成QReverseGeocoder对象
 */
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**指定街景的搜索半径（单位:m）,如果不指定，会使用默认值，仅发起搜索前设置有效**/
@property(nonatomic, assign) NSUInteger radius;

/**开始查询**/
- (BOOL)start;

/**撤销查询**/
- (void)cancel;

/**delegate**/
@property(nonatomic, weak) id<QReverseGeocoderDelegate> delegate;

/**查询的地理坐标**/
@property(nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**查询的结果**/
@property(nonatomic, readonly) QPlaceMark *placeMark;

/**查询的标识**/
@property(nonatomic, readonly, getter=isQuerying) BOOL querying;

@end


/**
 *QReverseGeocoderDelegate:地址反编码代理
 *Author:ksnowlv
 **/
@protocol QReverseGeocoderDelegate <NSObject>
@required

/**成功时的通知
 *@param geocoder       QReverseGeocoder
 *@param placeMark      查询的结果
 *@return
 */
- (void)reverseGeocoder:(QReverseGeocoder *)geocoder didFindPlacemark:(QPlaceMark *)placeMark;

/**失败时的通知
 *@param geocoder    QReverseGeocoder
 *@param error       见QErrorCode
 *@return
 */
- (void)reverseGeocoder:(QReverseGeocoder *)geocoder didFailWithError:(QErrorCode)error;


@end
