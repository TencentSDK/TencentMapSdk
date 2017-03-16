//
//  QCoordinateTransformer.h
//  QMapKit
//
//  Created by NancyNan on 25/11/2016.
//  Copyright © 2016 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "QSCTXRouteGuidanceApi.h"
#import <CoreLocation/CoreLocation.h>

@interface QCoordinateTransformer : NSObject

//墨卡托坐标转换到像素坐标
+ (int)serverToClientX:(int)serverX;
+ (int)serverToClientY:(int)serverY;

//像素坐标转换到墨卡托坐标
+ (int)clientToServerX:(int)clientX;
+ (int)clientToServerY:(int)clientY;

//经纬度坐标转换到像素坐标
+ (int)longitudeToClientX:(double)longitude;
+ (int)latitudeToClientY:(double)latitude;

//像素坐标转换到经纬度坐标
+ (double)clientXToLongitude:(int)clientX;
+ (double)clientYToLatitude:(int)clientY;

//经纬度坐标转换到墨卡托坐标
+ (int)longitudeToServerX:(double)longitude;
+ (int)latitudeToServerY:(double)latitude;

//墨卡托坐标转换到经纬度坐标
+ (double)serverXToLongitude:(int)serverX;
+ (double)serverYToLatitude:(int)serverY;

//两个像素坐标之间的距离，单位：米
+ (double)distanceBetweenClientPoint1:(QSCTXMapPoint)point1 point2:(QSCTXMapPoint)point2;

//墨卡托坐标转像素坐标
+ (QSCTXMapPoint)SCTXMapPointFromServerPoint:(QSCTXMapPoint) serverPoint;

//经纬度转墨卡托坐标
+ (QSCTXMapPoint)ServerPointFromCoord:(CLLocationCoordinate2D) lnglat;

// 墨卡托坐标转经纬度
+ (CLLocationCoordinate2D)CoordFromServerPoint:(QSCTXMapPoint) mapPoint;

//经纬度转像素坐标
+ (QSCTXMapPoint)SCTXMapPointForCoordinate:(CLLocationCoordinate2D)coordinate;

@end
