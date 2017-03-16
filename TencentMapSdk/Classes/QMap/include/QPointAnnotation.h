/*
 ============================================================================
 Name           : QPointAnnotation.h
 Author         : 腾讯SOSO地图
 Version        : 1.0
 Copyright      : 腾讯
 Description    : QPointAnnotation declaration
 ============================================================================
 */

#import "QShape.h"

/**
 *QPointAnnotation:点标注
 *Author:ksnowlv
 **/

@interface QPointAnnotation : QShape
{
@package
    CLLocationCoordinate2D _coordinate;
}

/**点的坐标**/
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@end
